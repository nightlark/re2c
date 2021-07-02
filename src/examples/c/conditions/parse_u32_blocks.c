/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i
#include <stdint.h>
#include <limits.h>
#include <assert.h>

static const uint64_t ERROR = ~0lu;
enum YYCONDTYPE {
};


template<int BASE> static void adddgt(uint64_t &u, unsigned int d)
{
    u = u * BASE + d;
    if (u > UINT32_MAX) u = ERROR;
}

static uint64_t parse_u32(const char *s)
{
    const char *YYMARKER;
    uint64_t u = 0;

    
{
	char yych;
	yych = *s;
	switch (yych) {
	case '0':	goto yy4;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy6;
	default:	goto yy2;
	}
yy2:
	++s;
	{ return ERROR; }
yy4:
	yych = *(YYMARKER = ++s);
	switch (yych) {
	case 'B':
	case 'b':	goto yy8;
	case 'X':
	case 'x':	goto yy10;
	default:	goto yy5;
	}
yy5:
	{ goto oct; }
yy6:
	++s;
	s -= 1;
	{ goto dec; }
yy8:
	yych = *++s;
	switch (yych) {
	case '0':
	case '1':	goto yy11;
	default:	goto yy9;
	}
yy9:
	s = YYMARKER;
	goto yy5;
yy10:
	yych = *++s;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy13;
	default:	goto yy9;
	}
yy11:
	++s;
	s -= 1;
	{ goto bin; }
yy13:
	++s;
	s -= 1;
	{ goto hex; }
}

bin:
    
{
	char yych;
	yych = *s;
	switch (yych) {
	case 0x00:	goto yy17;
	case '0':
	case '1':	goto yy21;
	default:	goto yy19;
	}
yy17:
	++s;
	{ return u; }
yy19:
	++s;
	{ return ERROR; }
yy21:
	++s;
	{ adddgt<2>(u, s[-1] - '0'); goto bin; }
}

oct:
    
{
	char yych;
	yych = *s;
	switch (yych) {
	case 0x00:	goto yy25;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy29;
	default:	goto yy27;
	}
yy25:
	++s;
	{ return u; }
yy27:
	++s;
	{ return ERROR; }
yy29:
	++s;
	{ adddgt<8>(u, s[-1] - '0'); goto oct; }
}

dec:
    
{
	char yych;
	yych = *s;
	switch (yych) {
	case 0x00:	goto yy33;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy37;
	default:	goto yy35;
	}
yy33:
	++s;
	{ return u; }
yy35:
	++s;
	{ return ERROR; }
yy37:
	++s;
	{ adddgt<10>(u, s[-1] - '0'); goto dec; }
}

hex:
    
{
	char yych;
	yych = *s;
	switch (yych) {
	case 0x00:	goto yy41;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy45;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	goto yy47;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy49;
	default:	goto yy43;
	}
yy41:
	++s;
	{ return u; }
yy43:
	++s;
	{ return ERROR; }
yy45:
	++s;
	{ adddgt<16>(u, s[-1] - '0');      goto hex; }
yy47:
	++s;
	{ adddgt<16>(u, s[-1] - 'A' + 10); goto hex; }
yy49:
	++s;
	{ adddgt<16>(u, s[-1] - 'a' + 10); goto hex; }
}

}

int main()
{
    assert(parse_u32("1234567890") == 1234567890);
    assert(parse_u32("0b1101") == 13);
    assert(parse_u32("0x7Fe") == 2046);
    assert(parse_u32("0644") == 420);
    assert(parse_u32("9999999999") == ERROR);
    assert(parse_u32("") == ERROR);
    return 0;
}