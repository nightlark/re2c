/* Generated by re2c */
#line 1 "header/header_01.re"
// re2c $INPUT -o $OUTPUT --header header_01.h
#line 4 "header/header_01.re"


#include "header_01.h"

bool lex(const char *YYCURSOR)
{
    
#line 13 "header/header_01.c"
{
	char yych;
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy4;
		default: goto yy2;
	}
yy2:
	++YYCURSOR;
#line 15 "header/header_01.re"
	{ return false; }
#line 25 "header/header_01.c"
yy4:
	++YYCURSOR;
#line 14 "header/header_01.re"
	{ return true; }
#line 30 "header/header_01.c"
}
#line 16 "header/header_01.re"

}
/* Generated by re2c */

bool lex(const char *);
