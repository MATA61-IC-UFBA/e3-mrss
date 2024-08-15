// main.c for T1 - Lexical Analysis for compL

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

/* interface to lexer */

extern int yylineno; /* from lexer */
extern char *yytext;
extern int yylex();
extern int yylval;

int main(int argc, char **argv) {
	token_t token;

	extern FILE *yyin;
	extern FILE *yyout;

	if (argc > 2) {
		if(!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr,"erro na abertura do arquivo de entrada %s\n",argv[1]);
			return (1);
		}
		if(!(yyout = fopen(argv[2], "w"))) {
			fprintf(stderr,"erro na criacao do arquivo de saida %s\n",argv[2]);
			return (1);
		}
	}
	else {
		fprintf(stderr,"erro no número de argumentos de entrada\n");
		return (1);
	}

	while ((token = yylex())) {
		switch (token) {
			case ID:
				// printf("(%d,ID,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,ID,\"%s\")\n", yylineno, yytext);
			    break;
			case NUM:
				// printf("(%d,NUM,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,NUM,\"%s\")\n", yylineno, yytext);
			    break;
			case STR:
				// printf("(%d,STR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,STR,\"%s\")\n", yylineno, yytext);
			    break;
			case CHAR:
				// printf("(%d,CHAR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,CHAR,\"%s\")\n", yylineno, yytext);
			    break;
			case KEY:
				// printf("(%d,KEY,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,KEY,\"%s\")\n", yylineno, yytext);
			    break;
			case SYM:
				// printf("(%d,SYM,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,SYM,\"%s\")\n", yylineno, yytext);
			    break;
			case SYMC:
				// printf("(%d,SYMC,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,SYMC,\"%s\")\n", yylineno, yytext);
			    break;
			case ERROR:
				// printf("(%d,ERROR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,ERROR,\"%s\")\n", yylineno, yytext);

		}
	}
	fclose(yyout);
}

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

