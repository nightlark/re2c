#include "src/parse/conf_parser.h"
const char* DEFAULT_SYNTAX_GO =
    "// supported feature lists -----------------------------------------------------\n"
    "\n"
    "supported_apis = [\"simple\", \"generic\", \"record\"];\n"
    "supported_api_styles = [\"free-form\", \"functions\"];\n"
    "supported_code_models = [\"goto-label\", \"loop-switch\", \"recursive-functions\"];\n"
    "supported_targets = [\"code\", \"dot\"];\n"
    "supported_features = [\"nested-ifs\", \"bitmaps\"];\n"
    "\n"
    "\n"
    "// language-specific options ---------------------------------------------------\n"
    "\n"
    "semicolons = 0;\n"
    "implicit_bool_conversion = 0;\n"
    "backtick_quoted_strings = 1;\n"
    "single_quoted_strings = 0;\n"
    "indentation_sensitive = 0;\n"
    "wrap_blocks_in_braces = 1;\n"
    "\n"
    "\n"
    "// immutable configurations (command-line only options) ------------------------\n"
    "\n"
    "conf:target = code;\n"
    "conf:code-model = goto-label;\n"
    "conf:input-encoding = ascii;\n"
    "conf:date = 1;\n"
    "conf:version = 1;\n"
    "conf:conditions = 0;\n"
    "conf:storable-state = 0;\n"
    "conf:flex-syntax = 0;\n"
    "conf:verbose = 0;\n"
    "conf:line-dirs = 1;\n"
    "\n"
    "\n"
    "// mutable configurations ------------------------------------------------------\n"
    "\n"
    "conf:api = custom;\n"
    "conf:api:style = free-form;\n"
    "conf:api:sigil = \"@@\";\n"
    "conf:define:YYGETCOND:naked = 0;\n"
    "conf:define:YYSETCOND:naked = 0;\n"
    "conf:define:YYSETCOND@cond = \"@@\";\n"
    "conf:define:YYGETSTATE:naked = 0;\n"
    "conf:define:YYSETSTATE:naked = 0;\n"
    "conf:define:YYSETSTATE@state = \"@@\";\n"
    "conf:define:YYFILL@len = \"@@\";\n"
    "conf:define:YYFILL:naked = 0;\n"
    "conf:define:YYFN = [\"<undefined-function-name>;<undefined-function-type>\"];\n"
    "conf:yyfn:sep = \";\";\n"
    "conf:variable:yycond = \"yycond\";\n"
    "conf:variable:yyctable = \"yyctable\";\n"
    "conf:variable:yyaccept = \"yyaccept\";\n"
    "conf:variable:yytarget = \"yytarget\";\n"
    "conf:variable:yystate = \"yystate\";\n"
    "conf:variable:yynmatch = \"yynmatch\";\n"
    "conf:variable:yypmatch = \"yypmatch\";\n"
    "conf:variable:yyrecord = \"yyrecord\";\n"
    "conf:variable:yych = \"yych\";\n"
    "conf:variable:yych:conversion = 0;\n"
    "conf:variable:yych:literals = char_or_hex;\n"
    "conf:variable:yych:emit = (code_model.recursive_functions ? 0 : 1);\n"
    "conf:variable:yybm = \"yybm\";\n"
    "conf:variable:yybm:hex = 0;\n"
    "conf:variable:yyfill = \"\";\n"
    "conf:variable:yystable = \"\"; // deprecated\n"
    "conf:header = \"\";\n"
    "conf:eof = -1;\n"
    "conf:sentinel = -1;\n"
    "conf:yyfill:enable = 1;\n"
    "conf:yyfill:parameter = 1;\n"
    "conf:yyfill:check = 1;\n"
    "conf:tags = 0;\n"
    "conf:leftmost-captures = 0;\n"
    "conf:posix-captures = 0;\n"
    "conf:tags:prefix = \"yyt\";\n"
    "conf:invert-captures = 0;\n"
    "conf:cond:abort = 1;\n"
    "conf:cond:prefix = \"yyc_\";\n"
    "conf:cond:enumprefix = \"yyc\";\n"
    "conf:cond:divider@cond = \"@@\";\n"
    "conf:cond:goto@cond = \"@@\";\n"
    "conf:state:abort = (code_model.goto_label ? 0 : 1); // historically disabled for goto/label\n"
    "conf:state:nextlabel = 0;\n"
    "conf:bit-vectors = 0;\n"
    "conf:debug-output = 0;\n"
    "conf:computed-gotos = 0;\n"
    "conf:computed-gotos:threshold = 9;\n"
    "conf:nested-ifs = 0;\n"
    "conf:case-insensitive = 0;\n"
    "conf:case-inverted = 0;\n"
    "conf:case-ranges = 0;\n"
    "conf:unsafe = 0;\n"
    "conf:monadic = 0;\n"
    "conf:encoding:ebcdic = 0;\n"
    "conf:encoding:utf32 = 0;\n"
    "conf:encoding:ucs2 = 0;\n"
    "conf:encoding:utf16 = 0;\n"
    "conf:encoding:utf8 = 0;\n"
    "conf:encoding-policy = ignore;\n"
    "conf:empty-class = match-empty;\n"
    "conf:indent:string = \"\\t\";\n"
    "conf:indent:top = 0;\n"
    "conf:label:prefix = \"yy\";\n"
    "conf:label:yyfill = \"yyFillLabel\";\n"
    "conf:label:yyloop = \"yyl\"; // In Go `continue` statements have labels, use it to avoid ambiguity.\n"
    "conf:label:yyNext = \"yyNext\";\n"
    "conf:label:start = 0;\n"
    "\n"
    "\n"
    "// mutable code configuration --------------------------------------------------\n"
    "\n"
    "conf:define:YYBACKUP = \"YYBACKUP\";\n"
    "conf:define:YYBACKUPCTX = \"YYBACKUPCTX\";\n"
    "conf:define:YYCONDTYPE = \"YYCONDTYPE\";\n"
    "conf:define:YYCOPYMTAG = sigil \"{lhs} = \" sigil \"{rhs}\";\n"
    "conf:define:YYCOPYSTAG = sigil \"{lhs} = \" sigil \"{rhs}\";\n"
    "conf:define:YYCTYPE = \"YYCTYPE\";\n"
    "conf:define:YYCTXMARKER = (api.generic ? \"YYCTXMARKER\" : (api.record ? yyrecord \".\") \"yyctxmarker\");\n"
    "conf:define:YYCURSOR = (api.generic ? \"YYCURSOR\" : (api.record ? yyrecord \".\") \"yycursor\");\n"
    "conf:define:YYDEBUG = \"YYDEBUG\";\n"
    "conf:define:YYFILL = \"YYFILL\";\n"
    "conf:define:YYGETACCEPT = sigil \"{var}\";\n"
    "conf:define:YYGETCOND = \"YYGETCONDITION\"; // historic default\n"
    "conf:define:YYGETSTATE = \"YYGETSTATE\";\n"
    "conf:define:YYINPUT = (api.generic ? \"YYINPUT\" : (api.record ? yyrecord \".\") \"yyinput\");\n"
    "conf:define:YYLESSTHAN = \"YYLESSTHAN\";\n"
    "conf:define:YYLIMIT = (api.generic ? \"YYLIMIT\" : (api.record ? yyrecord \".\") \"yylimit\");\n"
    "conf:define:YYMARKER = (api.generic ? \"YYMARKER\" : (api.record ? yyrecord \".\") \"yymarker\");\n"
    "conf:define:YYMAXFILL = \"YYMAXFILL\";\n"
    "conf:define:YYMAXNMATCH = \"YYMAXNMATCH\";\n"
    "conf:define:YYMTAGN = \"YYMTAGN\";\n"
    "conf:define:YYMTAGP = \"YYMTAGP\";\n"
    "conf:define:YYPEEK = \"YYPEEK\";\n"
    "conf:define:YYRESTORE = \"YYRESTORE\";\n"
    "conf:define:YYRESTORECTX = \"YYRESTORECTX\";\n"
    "conf:define:YYRESTORETAG = \"YYRESTORETAG\";\n"
    "conf:define:YYSETACCEPT = sigil \"{var} = \" sigil \"{val}\";\n"
    "conf:define:YYSETCOND = \"YYSETCONDITION\"; // historic default\n"
    "conf:define:YYSETSTATE = \"YYSETSTATE\";\n"
    "conf:define:YYSHIFT = \"YYSHIFT\";\n"
    "conf:define:YYSHIFTSTAG = \"YYSHIFTSTAG\";\n"
    "conf:define:YYSHIFTMTAG = \"YYSHIFTMTAG\";\n"
    "conf:define:YYSKIP = \"YYSKIP\";\n"
    "conf:define:YYSTAGN = \"YYSTAGN\";\n"
    "conf:define:YYSTAGP = \"YYSTAGP\";\n"
    "conf:tags:expression = (api.record ? yyrecord \".\") sigil;\n"
    "conf:tags:negative = (api.generic ? \"@@\" : \"-1\");\n"
    "conf:cond:divider = \"/* *********************************** */\";\n"
    "conf:cond:goto = \"goto \" sigil;\n"
    "\n"
    "\n"
    "// code templates --------------------------------------------------------------\n"
    "\n"
    "code:var_local = topindent (have_init? name \" := \" init : \"var \" name \" \" type) nl;\n"
    "code:var_global = topindent \"var \" name \" \" type (have_init? \" = \" init) nl;\n"
    "\n"
    "code:const_local = topindent \"const \" name \" = \" init nl;\n"
    "code:const_global = code:const_local;\n"
    "\n"
    "code:array_local =\n"
    "    topindent name \" := [\" size \"]\" type \"{\" nl indent\n"
    "        [row: topindent [elem{0:-2}: elem \", \"] [elem{-1}: elem \",\"] nl]\n"
    "    dedent topindent \"}\" nl;\n"
    "code:array_global =\n"
    "    topindent \"var \" name \" = {\" nl indent\n"
    "        [row: topindent [elem{0:-2}: elem \", \"] [elem{-1}: elem \",\"] nl]\n"
    "    dedent topindent \"}\" nl;\n"
    "code:array_elem = array \"[\" index \"]\";\n"
    "\n"
    "code:type_int = \"int\";\n"
    "code:type_uint = \"uint\";\n"
    "code:type_cond_enum = <undefined>;\n"
    "code:type_yybm = \"byte\";\n"
    "code:type_yytarget = <undefined>;\n"
    "\n"
    "code:assign = topindent lhs \" = \" rhs nl;\n"
    "\n"
    "code:cmp_eq = \"==\";\n"
    "code:cmp_ne = \"!=\";\n"
    "code:cmp_lt = \"<\";\n"
    "code:cmp_gt = \">\";\n"
    "code:cmp_le = \"<=\";\n"
    "code:cmp_ge = \">=\";\n"
    "\n"
    "code:if_then_else =\n"
    "    [branch{0}: topindent \"if (\" cond \") {\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    [branch{1:-1}: topindent \"} else \" (have_cond? \"if (\" cond \") \") \"{\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:if_then_else_oneline = <undefined>;\n"
    "\n"
    "code:switch =\n"
    "    topindent \"switch (\" expr \") {\" nl\n"
    "    [case: case]\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch_cases =\n"
    "    [case{0:-2}: topindent case nl\n"
    "        indent topindent \"fallthrough\" dedent nl]\n"
    "    [case{-1}: topindent case nl]\n"
    "        indent [stmt: stmt] dedent;\n"
    "\n"
    "code:switch_cases_oneline = <undefined>;\n"
    "\n"
    "code:switch_case_range = \"case \" [val{0}: val] [val{1:-1}: \",\" val] \":\";\n"
    "\n"
    "code:switch_case_default = \"default:\";\n"
    "\n"
    "code:loop =\n"
    "    (loop_label? label \":\" nl)\n"
    "    topindent \"for {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:goto = topindent \"goto \" label nl;\n"
    "\n"
    "code:enum =\n"
    "    \"const (\" nl indent\n"
    "        [elem{0}:    topindent elem \" = \" (have_init ? init : \"iota\") nl]\n"
    "        [elem{1:-1}: topindent elem (have_init ? \" = \" init) nl]\n"
    "    dedent \")\" nl;\n"
    "\n"
    "code:enum_elem = name;\n"
    "\n"
    "code:fndecl = <undefined>;\n"
    "\n"
    "code:fndef =\n"
    "    topindent \"func \" name \"(\"\n"
    "        [arg{0:-2}: argname \" \" argtype \", \"]\n"
    "        [arg{-1}:   argname \" \" argtype]\n"
    "    \")\" (have_type ? \" \" type) \" {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    \"}\" nl;\n"
    "\n"
    "code:fncall =\n"
    "    topindent (have_retval ? retval \" = \") name \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \")\" nl;\n"
    "\n"
    "code:tailcall =\n"
    "    topindent (have_retval ? \"return \") name \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \")\" nl;\n"
    "\n"
    "code:recursive_functions = [fn: fndef nl];\n"
    "\n"
    "code:fingerprint =\n"
    "    \"// Code generated by re2go\"\n"
    "    (have_version? \" \" version)\n"
    "    (have_date? \" on \" date)\n"
    "    \", DO NOT EDIT.\" nl;\n"
    "\n"
    "code:line_info = \"//line \\\"\" file \"\\\":\" line nl;\n"
    "\n"
    "code:abort = topindent \"panic(\\\"internal lexer error\\\")\" nl;\n"
    "\n"
    "code:yydebug =\n"
    "    topindent (api.generic\n"
    "        ? YYDEBUG (api_style.functions ? \"()\")\n"
    "    : (api.record\n"
    "        ? YYDEBUG \"(\" yyrecord \")\"\n"
    "        : YYDEBUG \"(\" state \", \" yych \")\"\n"
    "    )) nl;\n"
    "\n"
    "code:yypeek =\n"
    "    topindent yych (code_model.recursive_functions ? \" := \" : \" = \") (api.generic\n"
    "        ? YYPEEK (api_style.functions ? \"()\")\n"
    "        : (cast ? YYCTYPE \"(\") YYINPUT \"[\" YYCURSOR \"]\" (cast ? \")\")\n"
    "    ) nl;\n"
    "\n"
    "code:yyskip =\n"
    "    topindent (api.generic\n"
    "        ? YYSKIP (api_style.functions ? \"()\")\n"
    "        : YYCURSOR \" += 1\"\n"
    "    ) nl;\n"
    "\n"
    "code:yybackup =\n"
    "    topindent (api.generic\n"
    "        ? YYBACKUP (api_style.functions ? \"()\")\n"
    "        : YYMARKER \" = \" YYCURSOR\n"
    "    ) nl;\n"
    "\n"
    "code:yybackupctx =\n"
    "    topindent (api.generic\n"
    "        ? YYBACKUPCTX (api_style.functions ? \"()\")\n"
    "        : YYCTXMARKER \" = \" YYCURSOR\n"
    "    ) nl;\n"
    "\n"
    "code:yyskip_yypeek = <undefined>;\n"
    "code:yypeek_yyskip = <undefined>;\n"
    "code:yyskip_yybackup = <undefined>;\n"
    "code:yybackup_yyskip = <undefined>;\n"
    "code:yybackup_yypeek = <undefined>;\n"
    "code:yyskip_yybackup_yypeek = <undefined>;\n"
    "code:yybackup_yypeek_yyskip = <undefined>;\n"
    "\n"
    "code:yyrestore =\n"
    "    topindent (api.generic\n"
    "        ? YYRESTORE (api_style.functions ? \"()\")\n"
    "        : YYCURSOR \" = \" YYMARKER\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestorectx =\n"
    "    topindent (api.generic\n"
    "        ? YYRESTORECTX (api_style.functions ? \"()\")\n"
    "        : YYCURSOR \" = \" YYCTXMARKER\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestoretag =\n"
    "    topindent (api.generic\n"
    "        ? YYRESTORETAG (api_style.functions ? \"(\" tag \")\")\n"
    "        : YYCURSOR \" = \" tag\n"
    "    ) nl;\n"
    "\n"
    "code:yyshift =\n"
    "    topindent (api.generic\n"
    "        ? YYSHIFT (api_style.functions ? \"(-\" offset \")\")\n"
    "        : YYCURSOR \" -= \" offset\n"
    "    ) nl;\n"
    "\n"
    "code:yyshiftstag =\n"
    "    (nested ? topindent \"if (\" tag \" != \" neg \") {\" nl indent)\n"
    "        topindent (api.generic\n"
    "            ? YYSHIFTSTAG (api_style.functions ? \"(\" tag \", -\" offset \")\")\n"
    "            : tag \" -= \" offset\n"
    "        ) nl\n"
    "    (nested ? dedent topindent \"}\" nl);\n"
    "\n"
    "code:yyshiftmtag =\n"
    "    topindent YYSHIFTMTAG (api_style.functions ? \"(\" tag \", -\" offset \")\") nl;\n"
    "\n"
    "code:yystagp =\n"
    "    topindent (api.generic\n"
    "        ? YYSTAGP (api_style.functions ? \"(\" tag \")\")\n"
    "        : tag \" = \" YYCURSOR\n"
    "    ) nl;\n"
    "\n"
    "code:yymtagp =\n"
    "    topindent YYMTAGP (api_style.functions ? \"(\" tag \")\") nl;\n"
    "\n"
    "code:yystagn =\n"
    "    topindent (api.generic\n"
    "        ? YYSTAGN (api_style.functions ? \"(\" tag \")\")\n"
    "        : tag \" = \" neg\n"
    "    ) nl;\n"
    "\n"
    "code:yymtagn =\n"
    "    topindent YYMTAGN (api_style.functions ? \"(\" tag \")\") nl;\n"
    "\n"
    "code:yycopystag =\n"
    "    topindent (api.generic\n"
    "        ? YYCOPYSTAG // function style is not supported, as there's no sensible default\n"
    "        : lhs \" = \" rhs\n"
    "    ) nl;\n"
    "\n"
    "code:yycopymtag =\n"
    "    topindent (api.generic\n"
    "        ? YYCOPYMTAG // function style is not supported, as there's no sensible default\n"
    "        : lhs \" = \" rhs\n"
    "    ) nl;\n"
    "\n"
    "code:yygetaccept =\n"
    "    (api.generic\n"
    "        ? YYGETACCEPT // function style is not supported, as there's no sensible default\n"
    "        : (api.record & (storable_state | code_model.recursive_functions) ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetaccept =\n"
    "    topindent (api.generic\n"
    "        ? YYSETACCEPT // function style is not supported, as there's no sensible default\n"
    "        : (api.record & (storable_state | code_model.recursive_functions) ? yyrecord \".\")\n"
    "            var \" = \" val\n"
    "    ) nl;\n"
    "\n"
    "code:yygetcond =\n"
    "    (api.generic\n"
    "        ? YYGETCOND (api_style.functions ? \"()\")\n"
    "        : (api.record ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetcond =\n"
    "    topindent (api.generic\n"
    "        ? YYSETCOND (api_style.functions ? \"(\" val \")\")\n"
    "        : (api.record ? yyrecord \".\") var \" = \" val \n"
    "    ) nl;\n"
    "\n"
    "code:yygetstate =\n"
    "    (api.generic\n"
    "        ? YYGETSTATE (api_style.functions ? \"()\")\n"
    "        : (api.record ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetstate =\n"
    "    topindent (api.generic\n"
    "        ? YYSETSTATE (api_style.functions ? \"(\" val \")\")\n"
    "        : (api.record ? yyrecord \".\") var \" = \" val\n"
    "    ) nl;\n"
    "\n"
    "code:yylessthan =\n"
    "    (api.generic\n"
    "        ? YYLESSTHAN (api_style.functions ? \"(\" need \")\")\n"
    "        : (many\n"
    "            ? \"(\" YYLIMIT \" - \" YYCURSOR \") < \" need\n"
    "            : YYLIMIT \" <= \" YYCURSOR));\n"
    ;
