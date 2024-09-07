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
			case ARRAY:
				// printf("(%d,STR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,ARRAY,\"%s\")\n", yylineno, yytext);
			    break;
			case BOOLEAN:
				// printf("(%d,CHAR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,BOOLEAN,\"%s\")\n", yylineno, yytext);
			    break;
			case CHAR:
				// printf("(%d,KEY,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,CHAR,\"%s\")\n", yylineno, yytext);
			    break;
			case ELSE:
				// printf("(%d,SYM,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,ELSE,\"%s\")\n", yylineno, yytext);
			    break;
			case FALSE:
				// printf("(%d,SYMC,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,FALSE,\"%s\")\n", yylineno, yytext);
			    break;
			case FOR:
				// printf("(%d,ERROR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,FOR,\"%s\")\n", yylineno, yytext);
                            break;
                        case FUNCTION:
				// printf("(%d,ID,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,FUNCTION,\"%s\")\n", yylineno, yytext);
			    break;
			case IF:
				// printf("(%d,NUM,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,IF,\"%s\")\n", yylineno, yytext);
			    break;
			case INTEGER:
				// printf("(%d,STR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,INTEGER,\"%s\")\n", yylineno, yytext);
			    break;
			case PRINT:
				// printf("(%d,CHAR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,PRINT,\"%s\")\n", yylineno, yytext);
			    break;
			case RETURN:
				// printf("(%d,KEY,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,RETURN,\"%s\")\n", yylineno, yytext);
			    break;
			case STRING:
				// printf("(%d,SYM,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,STRING,\"%s\")\n", yylineno, yytext);
			    break;
			case TRUE:
				// printf("(%d,SYMC,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,TRUE,\"%s\")\n", yylineno, yytext);
			    break;
			case VOID:
				// printf("(%d,ERROR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,VOID,\"%s\")\n", yylineno, yytext);
                            break;
                        case WHILE:
				// printf("(%d,ERROR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,WHILE,\"%s\")\n", yylineno, yytext);
                            break;
                        case LTE:
				// printf("(%d,ID,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,LTE,\"%s\")\n", yylineno, yytext);
			    break;
			case GTE:
				// printf("(%d,NUM,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,GTE,\"%s\")\n", yylineno, yytext);
			    break;
			case EQU:
				// printf("(%d,STR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,EQU,\"%s\")\n", yylineno, yytext);
			    break;
			case NEQ:
				// printf("(%d,CHAR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,NEQ,\"%s\")\n", yylineno, yytext);
			    break;
			case AND:
				// printf("(%d,KEY,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,AND,\"%s\")\n", yylineno, yytext);
			    break;
			case OR:
				// printf("(%d,SYM,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,OR,\"%s\")\n", yylineno, yytext);
			    break;
			case STR:
				// printf("(%d,SYMC,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,STR,\"%s\")\n", yylineno, yytext);
			    break;
			case ERROR:
				// printf("(%d,ERROR,\"%s\")\n", yylineno, yytext);
				fprintf(yyout, "(%d,ERROR,\"%s\")\n", yylineno, yytext);
                            break;

		}
	}
	fclose(yyout);
}

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

