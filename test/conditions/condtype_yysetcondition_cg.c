/* Generated by re2c */
#line 1 "conditions/condtype_yysetcondition_cg.re"
// re2c $INPUT -o $OUTPUT -cg
#include <stdio.h>

// changing this to '#if 1' changes program behaviour
#if 0
#    define yyca 1
#    define yycb 0
#else
#    define yyca 0
#    define yycb 1
#endif

int main ()
{
	int cond = yyca;
	char * YYCURSOR = "aaaaaaaabb";
#define YYSETCONDITION(c) cond = c
#define YYGETCONDITION() cond
	for (;;)
	{

#line 25 "conditions/condtype_yysetcondition_cg.c"
{
	unsigned char yych;
	static void* yyctable[2] = {
		&&yyc_b,
		&&yyc_a
	};
	goto *yyctable[YYGETCONDITION()];
/* *********************************** */
yyc_b:
	++YYCURSOR;
#line 25 "conditions/condtype_yysetcondition_cg.re"
	{ printf ("b\n"); break; }
#line 38 "conditions/condtype_yysetcondition_cg.c"
/* *********************************** */
yyc_a:
	yych = *YYCURSOR;
	if (yych == 'a') goto yy2;
	++YYCURSOR;
	YYSETCONDITION(yycb);
#line 28 "conditions/condtype_yysetcondition_cg.re"
	{ printf ("a => b\n"); continue; }
#line 47 "conditions/condtype_yysetcondition_cg.c"
yy2:
	++YYCURSOR;
#line 27 "conditions/condtype_yysetcondition_cg.re"
	{ printf ("a\n");      continue; }
#line 52 "conditions/condtype_yysetcondition_cg.c"
}
#line 29 "conditions/condtype_yysetcondition_cg.re"

	}
	return 0;
}
conditions/condtype_yysetcondition_cg.re:21:0: warning: condition numbers may change, use '/*!conditions:re2c*/' directive to generate reliable condition identifiers [-Wcondition-order]
