#include <ctype.h>
#include <stdio.h>
#include <iomanip>

#include "config.h"
#include "src/adfa/adfa.h"
#include "src/codegen/output.h"
#include "src/codegen/helpers.h"
#include "src/encoding/enc.h"
#include "src/msg/msg.h"
#include "src/msg/warn.h"
#include "src/options/opt.h"
#include "src/skeleton/skeleton.h"
#include "src/util/check.h"
#include "src/util/string_utils.h"

namespace re2c {

OutputBlock::OutputBlock(InputBlock kind, const std::string& name, const loc_t& loc)
    : kind(kind),
      name(name),
      loc(loc),
      code(nullptr),
      used_yyaccept(false),
      have_user_code(false),
      conds(),
      stags(),
      mtags(),
      svars(),
      mvars(),
      opts(nullptr),
      dfas(),
      max_fill(1),
      max_nmatch(1),
      start_label(nullptr),
      fill_goto(),
      fn_common(nullptr),
      relops()
    {}

OutputBlock::~OutputBlock() {
    delete opts;
}

Output::Output(OutAllocator& alc, Msg& msg)
    : allocator(alc),
      msg(msg),
      cblocks(),
      hblocks(),
      pblocks(&cblocks),
      tmpblocks(),
      label_counter(0),
      fill_label_counter(0),
      state_goto(false),
      cond_enum_autogen(true),
      warn_condition_order(true),
      need_header(false),
      done_mtag_defs(false),
      skeletons(),
      scratchbuf(allocator),
      current_block(nullptr),
      total_opts(nullptr),
      fn_common(nullptr)
    {}

Output::~Output() {
    for (OutputBlock* b : cblocks) delete b;
    for (OutputBlock* b : hblocks) delete b;
}

void Output::header_mode(bool on) {
    pblocks = on ? &hblocks : &cblocks;
}

bool Output::in_header() const {
    return pblocks == &hblocks;
}

OutputBlock& Output::block() {
    return current_block == nullptr ? *pblocks->back() : *current_block;
}

void Output::set_current_block(OutputBlock* block) {
    current_block = block;
}

void Output::gen_raw(const uint8_t* s, const uint8_t* e, bool newline) {
    if (s != e && block().opts->target == Target::CODE) {
        // scan for non-whitespace characters
        bool& code = block().have_user_code;
        for (const uint8_t* p = s; !code && p < e; ++p) {
            code = !isspace(*p);
        }
        gen_stmt(code_raw(allocator, s, static_cast<size_t>(e - s)));
    }
    if (newline && e > s && e[-1] != '\n') {
        // Insert newline unless the block ends in a newline.
        gen_stmt(code_newline(allocator));
    }
}

void Output::gen_stmt(Code* stmt) {
    append(block().code, stmt);
}

Ret Output::new_block(Opt& opts, InputBlock kind, std::string name, const loc_t& loc) {
    // Prefix autogenerated names with a special symbol to avoid collision with user-defined names.
    // Embed line information in the autogenerated name to make it easier to correlate names with
    // source code.
    if (kind == InputBlock::USE) {
        // `use:re2c` blocks have autogenerated names that differ from the name of the `rules:re2c`
        // block that they are using, so the user cannot reference a `use:re2c` block in any way.
        // (They can easily achieve the same goal with the help of the `!use` directive in a normal
        // block.)
        name = "#line_" + to_string(loc.line) + "_block_use_" + name;
    } else if (name.empty()) {
        // Append block number, as the line may be non-unique (it is possible to have multiple
        // blocks on the same line, included files may define blocks at the same line, and line
        // directives may reset line number).
        name = "#line_" + to_string(loc.line) + "_block_" + to_string(pblocks->size());
    }

    // Check that the new block has a unique name.
    for (const OutputBlock* b : *pblocks) {
        if (b->name == name) {
            RET_FAIL(msg.error(loc,
                               "block named '%s' is already defined on line %u",
                               name.c_str(), b->loc.line));
        }
    }

    OutputBlock* block = new OutputBlock(kind, name, loc);
    pblocks->push_back(block);

    block->code = code_list(allocator);

    CHECK_RET(opts.snapshot(&block->opts));

    // start label hapens to be the only option that must be reset for each new block
    opts.reset_group_label_start();

    return Ret::OK;
}

Ret Output::gen_prolog(Opt& opts, const loc_t& loc) {
    header_mode(true);
    CHECK_RET(new_block(opts, InputBlock::GLOBAL, "", loc));
    gen_stmt(code_fingerprint(allocator));

    header_mode(false);
    CHECK_RET(new_block(opts, InputBlock::GLOBAL, "", loc));
    gen_stmt(code_fingerprint(allocator));
    if (block().opts->line_dirs) gen_stmt(code_line_info_input(allocator, loc));

    if (block().opts->target == Target::SKELETON) {
        gen_stmt(emit_skeleton_prolog(*this));
    }

    return Ret::OK;
}

void Output::gen_epilog() {
    const opt_t* opts = block().opts;

    // For special targets (skeleton and .dot) merge header into the output file.
    if (opts->target != Target::CODE && need_header) {
        need_header = false;
        cblocks.insert(cblocks.end(), hblocks.begin(), hblocks.end());
        hblocks.clear();
    }

    if (opts->target == Target::SKELETON) {
        gen_stmt(emit_skeleton_epilog(*this));
    }
}

Scratchbuf& Scratchbuf::unchecked_label(const Label& l) {
    CHECK(l.index != Label::NONE);
    os << l.index;
    return *this;
}

Scratchbuf& Scratchbuf::label(const Label& l) {
    CHECK(l.used);
    return unchecked_label(l);
}

Scratchbuf& Scratchbuf::yybm_char(uint32_t u, const opt_t* opts, int width) {
    if (opts->bitmaps_hex) {
        print_hex(os, u, opts);
    } else {
        u32_width(u, width);
    }
    return *this;
}

Scratchbuf& Scratchbuf::u32_width(uint32_t u, int width) {
    os << std::setw(width);
    os << u;
    return *this;
}

Scratchbuf& Scratchbuf::exact_uint(size_t width) {
    if (width == sizeof(char)) {
        os << "unsigned char";
    } else if (width == sizeof(short)) {
        os << "unsigned short";
    } else if (width == sizeof(int)) {
        os << "unsigned int";
    } else if (width == sizeof(long)) {
        os << "unsigned long";
    } else {
        os << "uint" << width * 8 << "_t";
    }
    return *this;
}

const char* Scratchbuf::flush() {
    const size_t len = os.str().length();
    char* e = alc.alloct<char>(len + 1);
    memcpy(e, os.str().c_str(), len);
    e[len] = 0;
    os.str("");
    return e;
}

} // namespace re2c
