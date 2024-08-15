%{
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int yylval;
%}
%option yylineno

SPACING    [\n\t\r]*
ID         [a-zA-Z][a-zA-Z0-9_]{0,255}
NUM        [0-9]+
ARRAY      \[[0-9]+
COMMENT    "//".*
KEYWORD    (array|boolean|char|else|false|for|function|if|integer|print|return|string|true|void|while)
SYMBOL_C   "<="|">="|"=="|"!="|"&&"|"||"
SYMBOL     [+\-*/%!<>=:;,()[\]{}\\]
CHAR       '([^\\']|\\[0abefnrtvdws\\\'])'
STRING     (\"[^\n"]+\"|\"\")

ERROR      .
 
%%

\n                { }
{COMMENT}         { }
{SPACING}         { }
{KEYWORD}         { return KEY; }
{SYMBOL_C}        { return SYMC; }
{SYMBOL}          { return SYM; }
{CHAR}/\n         { return CHAR; }
{STRING}          { return STR; }
{IDENTIFIER}      { return ID; }
{INT}+            { yylval = atoi(yytext); return NUM; }
{ERROR}           { return ERROR; }

%%

int yywrap() {
    return 1;
}
