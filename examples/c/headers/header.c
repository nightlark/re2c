/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --header src/lexer/lexer.h
#include <assert.h>
#include "src/lexer/lexer.h" // generated by re2c



int lex(LexerState *st) {
    
{
	char yych;
	yych = *st->cur;
	switch (yych) {
		case 'x': goto yy4;
		default: goto yy2;
	}
yy2:
	++st->cur;
yy3:
	{ return 1; }
yy4:
	yych = *(st->mar = ++st->cur);
	switch (yych) {
		case 'x':
			st->yyt1 = st->cur;
			goto yy5;
		default: goto yy3;
	}
yy5:
	yych = *++st->cur;
	switch (yych) {
		case 'x':
			st->yyt2 = st->cur;
			goto yy7;
		default: goto yy6;
	}
yy6:
	st->cur = st->mar;
	goto yy3;
yy7:
	yych = *++st->cur;
	switch (yych) {
		case 'x':
			st->yyt3 = st->cur;
			goto yy8;
		default: goto yy6;
	}
yy8:
	yych = *++st->cur;
	switch (yych) {
		case 'x':
			st->yyt1 = st->cur;
			goto yy10;
		default: goto yy9;
	}
yy9:
	st->cur = st->yyt1;
	{ return 0; }
yy10:
	yych = *++st->cur;
	switch (yych) {
		case 'x': goto yy11;
		default:
			st->yyt1 = st->yyt2;
			goto yy9;
	}
yy11:
	yych = *++st->cur;
	switch (yych) {
		case 'x': goto yy12;
		default:
			st->yyt1 = st->yyt3;
			goto yy9;
	}
yy12:
	yych = *++st->cur;
	switch (yych) {
		case 'x': goto yy13;
		default: goto yy9;
	}
yy13:
	yych = *++st->cur;
	switch (yych) {
		case 'x': goto yy14;
		default: goto yy9;
	}
yy14:
	++st->cur;
	goto yy9;
}

}

int main() {
    LexerState st;
    st.str = st.cur = "xxxxxxxx";
    assert(lex(&st) == 0 && st.cur - st.str == 4);
    return 0;
}
/* Generated by re2c */


typedef struct {
    const char *str, *cur, *mar;
    const char *yyt1; const char *yyt2; const char *yyt3; 
} LexerState;

c/headers/header.re:24:24: warning: trailing context has 4th degree of nondeterminism [-Wnondeterministic-tags]
