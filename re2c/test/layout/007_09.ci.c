/* Generated by re2c */

{
	YYCTYPE yych;
	switch (YYGETCONDITION()) {
	case yycx: goto yyc_x;
	case yycy: goto yyc_y;
	}
/* *********************************** */
yyc_x:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy5;
	default:	goto yy3;
	}
yy3:
	++YYCURSOR;
	{}
yy5:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy5;
	default:	goto yy7;
	}
yy7:
	YYSETCONDITION(yycz);
	{}
/* *********************************** */
yyc_y:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR++;
	YYSETCONDITION(yycx);
	{}
}
re2c: warning: line 2: rule in condition 'x' matches empty string [-Wmatch-empty-string]
