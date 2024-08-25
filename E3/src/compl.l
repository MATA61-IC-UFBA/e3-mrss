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
ARRAY      \[[([0-9]+|(\"[^\n]+\"|\"\")|(\'[^\n]+\'|\'\'))]+,[([0-9]+|(\"[^\n]+\"|\"\")|\'[^\n]\')]\] 
BOOLEAN    (true|false)
CHAR       \'[^\n]\'
ELSE       "else"
FALSE      "false"
FOR        "for"
FUNCTION   "function"
IF         "if"
INTEGER    "integer"
PRINT      "print"
RETURN     "return"
STRING     "string"
TRUE       "true"
VOID       "void"
WHILE      "while"
LTE        "<="
GTE        ">="
EQU        "=="
NEQ        "!="
AND        "&&"
OR         "||"
STR        "string"
COMMENT    "//".*
SYMBOL     [+\-*/%!<>=:;,()[\]{}\\]
STRING     (\"[^\n]+\"|\"\")
ERROR      .
 
%%

\n                { }
{COMMENT}         { }
{SPACING}         { }

{INT}+         { yylval = atoi(yytext); return NUM; }
{CHAR}         { return CHAR; }
{ELSE}         { return ELSE; }
{FALSE}        { return FALSE; }
{FOR}          { return FOR; }
{FUNCTION}     { return FUNCTION; }
{IF}           { return IF; }
{INTEGER}      { return INTEGER; }
{PRINT}        { return PRINT; }
{CHAR}         { yylval = yytext; return CHAR; }
{RETURN}       { return RETURN; }
{FALSE}        { return FALSE; }
{STRING}       { yylval = yytext; return STRING; }
{TRUE}         { return TRUE; }
{VOID}         { return VOID; }
{WHILE}        { return WHILE; }
{LTE}          { return LTE; }
{GTE}          { return GTE; }
{EQU}          { return EQU; }
{NEQ}          { return NEQ; }
{AND}          { return AND; }
{FALSE}           { return FALSE; }
{FOR}          { return FOR; }
{ERROR}        { yylval = yytext; return ERROR; }


RETURN,
        STRING,
        TRUE,
        VOID,
        WHILE, 
        LTE,
        GTE,
        EQU,
        NEQ,
        AND,
        OR,
	STR,
	ERROR





%%

int yywrap() {
    return 1;
}
