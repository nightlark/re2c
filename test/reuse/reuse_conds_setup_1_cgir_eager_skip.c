/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -cgi --eager-skip

enum YYCONDTYPE {
	yycr1,
	yycr2
};


void scan(unsigned char* in)
{

{
	YYCTYPE yych;
	static void* yyctable[2] = {
		&&yyc_r1,
		&&yyc_r2
	};
	goto *yyctable[YYGETCONDITION()];
/* *********************************** */
yyc_r1:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '1') {
		if (yych == '\n') goto yy1;
		if (yych <= '0') {
			++YYCURSOR;
			goto yy2;
		}
		++YYCURSOR;
		goto yy3;
	} else {
		if (yych <= 'a') {
			if (yych <= '`') {
				++YYCURSOR;
				goto yy2;
			}
			++YYCURSOR;
			goto yy4;
		} else {
			if (yych <= 'b') {
				++YYCURSOR;
				goto yy5;
			}
			if (yych <= 'c') {
				++YYCURSOR;
				goto yy6;
			}
			++YYCURSOR;
			goto yy2;
		}
	}
yy1:
yy2:
	{ return "SETUP-r1"; }
	{ return "."; }
yy3:
	{ return "SETUP-r1"; }
	{ return "1"; }
yy4:
	{ return "SETUP-r1"; }
	{ return "a"; }
yy5:
	{ return "SETUP-r1"; }
	{ return "b"; }
yy6:
	{ return "SETUP-r1"; }
	{ return "c"; }
/* *********************************** */
yyc_r2:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '`') {
		if (yych != '\n') {
			++YYCURSOR;
			goto yy8;
		}
	} else {
		if (yych <= 'a') {
			++YYCURSOR;
			goto yy9;
		}
		if (yych == 'c') {
			++YYCURSOR;
			goto yy10;
		}
		++YYCURSOR;
		goto yy8;
	}
yy8:
	{ return "SETUP-r2"; }
	{ return "."; }
yy9:
	{ return "SETUP-r2"; }
	{ return "a"; }
yy10:
	{ return "SETUP-r2"; }
	{ return "c"; }
}


}

void scan(unsigned short* in)
{

{
	YYCTYPE yych;
	static void* yyctable[2] = {
		&&yyc_r1,
		&&yyc_r2
	};
	goto *yyctable[YYGETCONDITION()];
/* *********************************** */
yyc_r1:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '2') {
		if (yych == '\n') goto yy12;
		if (yych <= '1') {
			++YYCURSOR;
			goto yy13;
		}
		++YYCURSOR;
		goto yy14;
	} else {
		if (yych <= 'a') {
			if (yych <= '`') {
				++YYCURSOR;
				goto yy13;
			}
			++YYCURSOR;
			goto yy15;
		} else {
			if (yych <= 'b') {
				++YYCURSOR;
				goto yy16;
			}
			if (yych <= 'c') {
				++YYCURSOR;
				goto yy17;
			}
			++YYCURSOR;
			goto yy13;
		}
	}
yy12:
yy13:
	{ return "SETUP-r1"; }
	{ return "."; }
yy14:
	{ return "SETUP-r1"; }
	{ return "2"; }
yy15:
	{ return "SETUP-r1"; }
	{ return "a"; }
yy16:
	{ return "SETUP-r1"; }
	{ return "b"; }
yy17:
	{ return "SETUP-r1"; }
	{ return "c"; }
/* *********************************** */
yyc_r2:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '`') {
		if (yych != '\n') {
			++YYCURSOR;
			goto yy19;
		}
	} else {
		if (yych <= 'a') {
			++YYCURSOR;
			goto yy20;
		}
		if (yych == 'c') {
			++YYCURSOR;
			goto yy21;
		}
		++YYCURSOR;
		goto yy19;
	}
yy19:
	{ return "."; }
yy20:
	{ return "a"; }
yy21:
	{ return "c"; }
}

}
reuse/reuse_conds_setup_1_cgir_eager_skip.re:15:2: warning: control flow in condition 'r1' is undefined for strings that match '\xA', use default rule '*' [-Wundefined-control-flow]
reuse/reuse_conds_setup_1_cgir_eager_skip.re:15:2: warning: control flow in condition 'r2' is undefined for strings that match '\xA', use default rule '*' [-Wundefined-control-flow]
reuse/reuse_conds_setup_1_cgir_eager_skip.re:26:0: warning: control flow in condition 'r1' is undefined for strings that match '\xA', use default rule '*' [-Wundefined-control-flow]
reuse/reuse_conds_setup_1_cgir_eager_skip.re:26:0: warning: control flow in condition 'r2' is undefined for strings that match '\xA', use default rule '*' [-Wundefined-control-flow]
