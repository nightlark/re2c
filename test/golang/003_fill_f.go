// Code generated by re2c, DO NOT EDIT.
//line "golang/003_fill_f.re":1
//go:generate re2go $INPUT -o $OUTPUT -f
package main

import "fmt"
import "os"

//line "golang/003_fill_f.go":10
var YYMAXFILL int = 2
//line "golang/003_fill_f.re":7

var SIZE int = 11

type YYCTYPE byte
type Input struct {
	file   *os.File
	data   []byte
	cursor int
	marker int
	token  int
	limit  int
	eof    bool
	state  int
}

const (
	lexError = iota
	lexNeedMoreSpace
	lexNeedMoreInput
	lexResume
	lexEnd
	lexNumber1
	lexNumber2
	lexSpace
)

func fill(in *Input, need int) int {
	// End of input has already been reached, nothing to do.
	if in.eof {
		fmt.Println("fill error: unexpected EOF")
		return lexError
	}

	// Check if after moving the current lexeme to the beginning
	// of buffer there will be enough free space.
	if SIZE-(in.cursor-in.token) < need {
		fmt.Println("fill error: lexeme too long")
		return lexNeedMoreSpace
	}

	// Discard everything up to the start of the current lexeme,
	// shift buffer contents and adjust offsets.
	copy(in.data[0:], in.data[in.token:in.limit])
	in.cursor -= in.token
	in.marker -= in.token
	in.limit -= in.token
	in.token = 0

	// Read new data (as much as possible to fill the buffer).
	n, _ := in.file.Read(in.data[in.limit:SIZE])
	in.limit += n
	fmt.Printf("fill(%d): %v '%s'\n", need, in.data[:in.limit+1],
		string(in.data[:in.limit]))

	// If read less than expected, this is the end of input.
	in.eof = in.limit < SIZE

	// If end of input, add padding so that the lexer can read
	// the remaining characters at the end of buffer.
	if in.eof {
		for i := 0; i < YYMAXFILL; i += 1 {
			in.data[in.limit+i] = 0
		}
		in.limit += YYMAXFILL
	}

	return lexResume
}

func Lex(in *Input) (int, int) {
	var yych YYCTYPE

	
//line "golang/003_fill_f.go":86
	switch (in.state) {
	default:
		goto yy0
	case 0:
		goto yyFillLabel0
	case 1:
		goto yyFillLabel1
	case 2:
		goto yyFillLabel2
	case 3:
		goto yyFillLabel3
	}
yy0:
	in.state = 0
	if (in.limit-in.cursor < 1) {
		return lexNeedMoreInput, 1
	}
yyFillLabel0:
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case 0x00:
		goto yy2
	case ' ':
		goto yy4
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy6
	default:
		goto yy3
	}
yy2:
	in.cursor += 1
	in.state = -1
//line "golang/003_fill_f.re":94
	{
		fmt.Println("end")
		return lexEnd, 0
	}
//line "golang/003_fill_f.go":124
yy3:
	in.cursor += 1
	in.state = -1
//line "golang/003_fill_f.re":89
	{
		fmt.Println("error")
		return lexError, 0
	}
//line "golang/003_fill_f.go":133
yy4:
	in.cursor += 1
	in.state = 1
	if (in.limit-in.cursor < 1) {
		return lexNeedMoreInput, 1
	}
yyFillLabel1:
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case ' ':
		goto yy4
	default:
		goto yy5
	}
yy5:
	in.state = -1
//line "golang/003_fill_f.re":109
	{
		return lexSpace, 0
	}
//line "golang/003_fill_f.go":154
yy6:
	in.cursor += 1
	in.marker = in.cursor
	in.state = 2
	if (in.limit-in.cursor < 2) {
		return lexNeedMoreInput, 2
	}
yyFillLabel2:
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case '-':
		goto yy8
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy6
	default:
		goto yy7
	}
yy7:
	in.state = -1
//line "golang/003_fill_f.re":99
	{
		fmt.Printf("number-1: %v\n", string(in.data[in.token:in.cursor]))
		return lexNumber1, 0
	}
//line "golang/003_fill_f.go":179
yy8:
	in.cursor += 1
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy10
	default:
		goto yy9
	}
yy9:
	in.cursor = in.marker
	goto yy7
yy10:
	in.cursor += 1
	in.state = 3
	if (in.limit-in.cursor < 1) {
		return lexNeedMoreInput, 1
	}
yyFillLabel3:
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy10
	default:
		goto yy11
	}
yy11:
	in.state = -1
//line "golang/003_fill_f.re":104
	{
		fmt.Printf("number-2: %v\n", string(in.data[in.token:in.cursor]))
		return lexNumber2, 0
	}
//line "golang/003_fill_f.go":213
//line "golang/003_fill_f.re":112

}

func test(data string) int {
	tmpfile := "input.txt"

	f, _ := os.Create(tmpfile)
	f.WriteString(data)
	f.WriteString("\000") // lexer expects NULL-terminator
	f.Seek(0, 0)

	defer func() {
		f.Close()
		os.Remove(tmpfile)
	}()

	in := &Input{
		file:   f,
		data:   make([]byte, SIZE+YYMAXFILL),
		cursor: SIZE,
		marker: SIZE,
		token:  SIZE,
		limit:  SIZE,
		eof:    false,
	}

	need := 1
	result := lexNeedMoreInput
loop:
	for {
		switch result {
		case lexError:
			break loop
		case lexEnd:
			break loop
		case lexNeedMoreInput:
			result = fill(in, need)
			if result != lexResume {
				break loop
			}
		default:
			in.token = in.cursor
			in.state = 0
		}
		result, need = Lex(in)
	}

	return result
}

func main() {
	var s string

	// Succeeds, the lexer has enough characters ahead.
	s = "     123456789      "
	if test(s) != lexEnd {
		panic("expected 'number: 123456789'")
	}

	// Fails, there is no space for the needed characters.
	s = "     1234567890     "
	if test(s) != lexNeedMoreSpace {
		panic("expected 'fill error: lexeme too long'")
	}

	// Succeeds, the lexer has enough characters ahead
	// (although the same lexeme length as the previous case,
	// YYFILL argument is smaller in this state).
	s = "     12345-6789     "
	if test(s) != lexEnd {
		panic("expected 'number: 12345-6789'")
	}

	// Fails, there is no space for any characters.
	s = "     12345-67890     "
	if test(s) != lexNeedMoreSpace {
		panic("expected 'fill error: lexeme too long'")
	}

	// Fails, invalid input.
	s = "?#!*"
	if test(s) != lexError {
		panic("expected 'error'")
	}

	fmt.Println("OK")
}
