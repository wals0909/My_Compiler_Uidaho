%{
    
/* Riley Walsh
*  CS445
*  Spring 2023
*/ 

#include "scanType.h"  // my header.
#include "tree.h"  // Tree Struct 
#include "parser.tab.h"  // flex/Bison header

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int line = 1;
int numErrors;    // ERR err count
int WrdLength;
int i;

extern int numWarnings; //add this for yyerror warning count!

// function for removing uneeded chars. 
void removeChar(char *str, char word){

     bool IsChar = false;
     char *start, *end;
   
    for(start = end = str; *str != '\0'; start++){

        *end = *start;
      
        if(*end != word){
            IsChar = false;
            end++;
        }
        else{
            if(IsChar){
                IsChar = false;
                end++;           
            }
            else{
                IsChar = true;
            }
        }
        str++;
    }
    *end = '\0';
    
   
}

// Function changes lower case char to upper case. 
void UpperCase(char *Letter){
    while(*Letter){
        //use toupper function given in c.
        *Letter = toupper((unsigned char) *Letter);
        Letter++;
    }

    return;
}

// Function gets length of string
static size_t StrLength (char *svalue){
    return strlen(svalue)-2;
}


static int setValue(int lineno, int tokenClass,  char *svalue)
{
    yylval.tokenData = new TokenData;

    yylval.tokenData->lineno = lineno;
    yylval.tokenData->tokenstr = strdup(svalue);

    switch(tokenClass){

		 case ID:
			yylval.tokenData->tokenStrprint = strdup("ID");
            yylval.tokenData->idIndex = svalue[0] - 'a';
            
            break;

        case BOOLCONST:
            yylval.tokenData->tokenStrprint = strdup("BOOLCONST");

            if(strcmp(svalue, "false") == 0){
                yylval.tokenData->nvalue = 0;
            }
            else{
                yylval.tokenData->nvalue = 1;
            }
            break;
       
        case NUMCONST:
            yylval.tokenData->tokenStrprint = strdup("NUMCONST");
            yylval.tokenData->nvalue = atoi(svalue);
            break;

        case CHARCONST:
            WrdLength = strlen(svalue);

             // if str length is 3 assign it to svalue first index. 
            if(WrdLength == 3){
                yylval.tokenData->cvalue = svalue[1];
            }

            if(WrdLength > 3){
			
                // check for \ escape (92), n is (110), 0 is (48). 
                if(svalue[1] == 92 && svalue[2] != 110 && svalue[2] != 48){
                    yylval.tokenData->cvalue = svalue[2];
                }
               
			    else if(svalue[1] == 92 && svalue[2] != 110 && svalue[2] == 48){
                    yylval.tokenData->cvalue = '\0';
                }
				
                else if(svalue[1] == 92 && svalue[2] == 110 && svalue[2] != 48){
                    yylval.tokenData->cvalue = '\n';
                }
                            
                else if(svalue[1] != 92){
                    //add this for yyerror warning count!
                    numWarnings++;
                    
                     printf("WARNING(%d): character is %d characters long and not a single character: \'%s\'. The first char will be used.\n", line, (WrdLength-2), svalue);
                     yylval.tokenData->cvalue = svalue[1];
                }
            }

            yylval.tokenData->tokenStrprint = strdup("CHARCONST");
            break;
            
        case STRINGCONST:
            // use simple for loop to parse for \n newline
            for(i = 0; i <= strlen(svalue); i++){
  		        if(svalue[1] == 92 && svalue[2] == 110 && svalue[2] != 48){

  			        svalue[2] = '\n';       
 		        }
    
	        }
            
            removeChar(svalue, '\\');

            yylval.tokenData->tokenStrprint = strdup("STRINGCONST");
            yylval.tokenData->stringvalue = strdup(svalue);
            yylval.tokenData->strlength = StrLength(svalue);
          
            break;
      
        case GEQ:
        yylval.tokenData->tokenStrprint = strdup("GEQ");
        break;

        case INC:
        yylval.tokenData->tokenStrprint = strdup("INC");
        break;

        case DEC:
        yylval.tokenData->tokenStrprint = strdup("DEC");
        break;

        case NEQ:
        yylval.tokenData->tokenStrprint = strdup("NEQ");
        break;
        
        case LEQ:
        yylval.tokenData->tokenStrprint = strdup("LEQ");
        break;

        case ASGN:
        yylval.tokenData->tokenStrprint = strdup("ASGN");
        break;

        case ADDASGN:
        yylval.tokenData->tokenStrprint = strdup("ADDASGN");
        break;
       
    }
        
    return tokenClass;
}

%}

%option noyywrap

%%

[ \t]+                          ;
"##".*                          ;
\n                              {line++;}
\'\'                            { printf("ERROR(%d): Empty character ''. Characters ignored.\n", line); numErrors++; }

"int"                           { return setValue(line, INT, yytext); }
"begin"                         { return setValue(line, START, yytext); }
"if"                            { return setValue(line, IF, yytext); }
"then"                          { return setValue(line, THEN, yytext); }
"return"                        { return setValue(line, RETURN, yytext); }
"else"                          { return setValue(line, ELSE, yytext); }
"end"                           { return setValue(line, STOP, yytext); }
"bool"                          { return setValue(line, BOOL, yytext); }
"char"                          { return setValue(line, CHAR, yytext); }
"static"                        { return setValue(line, STATIC, yytext); }
"and"                           { return setValue(line, AND, yytext); }
"or"                            { return setValue(line, OR, yytext); }
"not"                           { return setValue(line, NOT, yytext); }
"for"                           { return setValue(line, FOR, yytext); }
"to"                            { return setValue(line, TO, yytext); }
"by"                            { return setValue(line, BY, yytext); }
"break"                         { return setValue(line, BREAK, yytext); }
"while"                         { return setValue(line, WHILE, yytext); }
"do"                            { return setValue(line, DO, yytext); }
"step"                          {return setValue(line, BY, yytext);}

"true"                          { return setValue(line, BOOLCONST, yytext); }
"false"                         { return setValue(line, BOOLCONST, yytext); }

[a-zA-Z]([a-zA-Z]|[0-9])*       {return setValue(line, ID, yytext);}
[0-9]+                          {return setValue(line, NUMCONST, yytext);}

\'(\\.|[^\n\'])*\'              {return setValue(line, CHARCONST, yytext);}
\"(\\.|[^\\\n\"])*\"            {return setValue(line, STRINGCONST, yytext);} 

"+="                            {return setValue(line, ADDASGN, yytext);}
"--"                            {return setValue(line, DEC, yytext);}
"<="                            {return setValue(line, ASGN, yytext);}
".."                            {return setValue(line, TO, yytext);}
"++"                            {return setValue(line, INC, yytext);}
"!<"                            {return setValue(line, GEQ, yytext);}
"!>"                            {return setValue(line, LEQ, yytext);}
"!="                            {return setValue(line, NEQ, yytext);}
"-="                            {return setValue(line, MINUSASGN, yytext); }
"*="                            {return setValue(line, MULTASGN, yytext); }
"/="                            {return setValue(line, DIVASGN, yytext); }

";"                             { return setValue(line, SEMICOLON, yytext); }
"="                             { return setValue(line, EQUALS, yytext); }
","                             { return setValue(line, COMMA, yytext); }
"("                             { return setValue(line, LPAREN, yytext); }
")"                             { return setValue(line, RPAREN, yytext); }         
"["                             { return setValue(line, LBRACKET, yytext); }
"]"                             { return setValue(line, RBRACKET, yytext); }
"*"                             { return setValue(line, MULT, yytext); }
"+"                             { return setValue(line, PLUS, yytext); }
"-"                             { return setValue(line, MINUS, yytext); }             
":"                             { return setValue(line, COLON, yytext); }
"%"                             { return setValue(line, PERCENT, yytext); }
"<"                             { return setValue(line, LESSTHAN, yytext); }
">"                             { return setValue(line, GREATERTHAN, yytext); }
"/"                             { return setValue(line, DIVIDE, yytext); }
"?"                             { return setValue(line, QMARK, yytext); } 

.                                   {printf("ERROR(%d): Invalid or misplaced input character: \'%c\'. Character Ignored.\n", line, yytext[0]); numErrors++;}

%%
