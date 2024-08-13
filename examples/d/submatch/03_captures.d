/* Generated by re2d */
#line 1 "d/submatch/03_captures.re"
// re2d $INPUT -o $OUTPUT
module main;

struct SemVer { int major, minor, patch; };

private int s2n(const(char)* s, const(char)* e) { // pre-parsed string to number
    int n = 0;
    for (; s < e; ++s) n = n * 10 + (*s - '0');
    return n;
}

private bool lex(const(char)* str, ref SemVer ver) {
    const(char)* yycursor = str, yymarker;

    // Final tag variables available in semantic action.
    
#line 20 "d/submatch/03_captures.d"
const(char)* yytl0;
const(char)* yytl1;
const(char)* yytl2;
const(char)* yytl3;
const(char)* yytr0;
const(char)* yytr1;
const(char)* yytr2;
const(char)* yytr3;
#line 16 "d/submatch/03_captures.re"


    // Intermediate tag variables used by the lexer (must be autogenerated).
    
#line 34 "d/submatch/03_captures.d"
const(char)* yyt1;
const(char)* yyt2;
const(char)* yyt3;
const(char)* yyt4;
const(char)* yyt5;
#line 19 "d/submatch/03_captures.re"


    
#line 44 "d/submatch/03_captures.d"
{
	char yych;
	yych = *yycursor;
	switch (yych) {
		case '0': .. case '9':
			yyt1 = yycursor;
			goto yy3;
		default: goto yy1;
	}
yy1:
	++yycursor;
yy2:
#line 34 "d/submatch/03_captures.re"
	{ return false; }
#line 59 "d/submatch/03_captures.d"
yy3:
	yych = *(yymarker = ++yycursor);
	switch (yych) {
		case '.': goto yy4;
		case '0': .. case '9': goto yy6;
		default: goto yy2;
	}
yy4:
	yych = *++yycursor;
	switch (yych) {
		case '0': .. case '9':
			yyt2 = yycursor;
			goto yy7;
		default: goto yy5;
	}
yy5:
	yycursor = yymarker;
	goto yy2;
yy6:
	yych = *++yycursor;
	switch (yych) {
		case '.': goto yy4;
		case '0': .. case '9': goto yy6;
		default: goto yy5;
	}
yy7:
	yych = *++yycursor;
	switch (yych) {
		case 0x00:
			yyt3 = yycursor;
			yyt4 = null;
			yyt5 = null;
			goto yy8;
		case '.':
			yyt3 = yycursor;
			yyt5 = yycursor;
			goto yy9;
		case '0': .. case '9': goto yy7;
		default: goto yy5;
	}
yy8:
	++yycursor;
	yytl1 = yyt1;
	yytl2 = yyt2;
	yytr2 = yyt3;
	yytl3 = yyt5;
	yytr3 = yyt4;
	yytl0 = yyt1;
	yytr0 = yycursor;
	yytr1 = yyt2;
	yytr1 -= 1;
#line 28 "d/submatch/03_captures.re"
	{
            ver.major = s2n(yytl1, yytr1);
            ver.minor = s2n(yytl2, yytr2);
            ver.patch = yytl3 ? s2n(yytl3 + 1, yytr3) : 0;
            return true;
        }
#line 118 "d/submatch/03_captures.d"
yy9:
	yych = *++yycursor;
	if (yych <= 0x00) goto yy5;
	goto yy11;
yy10:
	yych = *++yycursor;
yy11:
	switch (yych) {
		case 0x00:
			yyt4 = yycursor;
			goto yy8;
		case '0': .. case '9': goto yy10;
		default: goto yy5;
	}
}
#line 35 "d/submatch/03_captures.re"

}

void main() {
    SemVer v;
    assert(lex("23.34", v) && v.major == 23 && v.minor == 34 && v.patch == 0);
    assert(lex("1.2.999", v) && v.major == 1 && v.minor == 2 && v.patch == 999);
    assert(!lex("1.a", v));
}
