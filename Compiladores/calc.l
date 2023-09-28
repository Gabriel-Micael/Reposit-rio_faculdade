%{
#include "calc.h"
void yyerror(char *);
%}

%%
[0-9]+ {yylval = atoi(yytext);
	return NUM;}
"+"	return MAIS;
"-"	return MENOS;
"*"	return VEZES;
"div"	return DIV;
"("	return ABRE;
")"	return FECHA;
\n	return ENTER;
[ \t]+	/*saltar espaços e tabulações*/
.	yyerror("caracter invalido");
%%


int yywrap(void){
	return 1;
}
