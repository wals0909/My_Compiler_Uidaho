%{
/* Riley Walsh
*  CS445
*  Spring 2023
*/ 

#include "scanType.h"  // my header file. 
#include <stdio.h>

double vars[26];    

extern int yylex();
extern FILE *yyin;
extern int line;         // ERR line number from the scanner!!
extern int numErrors;    // ERR err count

#define YYERROR_VERBOSE
void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", line, msg);
    numErrors++;
}

%}

%union {
    TokenData *tokenData;
}

%token <tokenData> SYMBOL ID DEFINITION BOOLCONST NUMCONST CHARCONST STRINGCONST PLUSEQ DBLMINUS LESSEQ TO INC GEQ LEQ NEQ BY

%%
tokenlist     : tokenlist token
              | token
              ;

token         : SYMBOL                  {printf("Line %d Token: %s\n", $1->linenum, $1->tokenstr);}
              | ID                      {printf("Line %d Token: %s Value: %s\n", $1->linenum, $1->tokenStrprint, $1->tokenstr);} 
              | DEFINITION              {printf("Line %d Token: %s\n", $1->linenum, $1->stringvalue);}
              | BOOLCONST               {printf("Line %d Token: %s Value: %d Input: %s\n", $1->linenum, $1->tokenStrprint, $1->nvalue, $1->tokenstr);}
              | NUMCONST                {printf("Line %d Token: %s Value: %d  Input: %s\n", $1->linenum, $1->tokenStrprint, $1->nvalue, $1->tokenstr);}
              | CHARCONST               {printf("Line %d Token: %s Value: \'%c\'  Input: %s\n", $1->linenum, $1->tokenStrprint, $1->cvalue, $1->tokenstr);}
              | STRINGCONST             {printf("Line %d Token: %s Value: %s  Len: %d  Input: %s\n", $1->linenum, $1->tokenStrprint, $1->stringvalue, $1->strlength, $1->tokenstr);}
              | PLUSEQ                  {printf("Line %d Token: ADDASS\n", $1->linenum);}
              | DBLMINUS                {printf("Line %d Token: DEC\n", $1->linenum);}
              | LESSEQ                  {printf("Line %d Token: ASGN\n", $1->linenum);}
              | TO                      {printf("Line %d Token: TO\n", $1->linenum);}
              | INC                     {printf("Line %d Token: INC\n", $1->linenum);}
              | GEQ                     {printf("Line %d Token: GEQ\n", $1->linenum);}
              | LEQ                     {printf("Line %d Token: LEQ\n", $1->linenum);}
              | NEQ                     {printf("Line %d Token: NEQ\n", $1->linenum);}
              | BY                      {printf("Line %d Token: BY\n", $1->linenum);}
              ;

%%
extern int yydebug;
int main(int argc, char *argv[])
{
    if (argc > 1) {
        if ((yyin = fopen(argv[1], "r"))) {
            // file open successful
        }
        else {
            // failed to open file
            printf("ERROR: failed to open \'%s\'\n", argv[1]);
            exit(1);
        }
    }

    // init variables a through z
    for (int i=0; i<26; i++) vars[i] = 0.0;

    // do the parsing
    numErrors = 0;
    yyparse();

   // printf("Number of errors: %d\n", numErrors);   // ERR
    return 0;
}
