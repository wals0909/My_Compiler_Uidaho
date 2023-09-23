%{
    
/* Riley Walsh
*  CS445
*  Spring 2023
*/ 

#include "scanType.h"  // my header. 
#include "parser.tab.h"  // flex/Bison header

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int line = 1;
int numErrors;    // ERR err count
int WrdLength;
int i;

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


static int setValue(int linenum, int tokenClass,  char *svalue)
{
    yylval.tokenData = new TokenData;

    yylval.tokenData->linenum = linenum;
    yylval.tokenData->tokenstr = strdup(svalue);

    switch(tokenClass){
		case SYMBOL:
            break;

		 case ID:
			yylval.tokenData->tokenStrprint = strdup("ID");
            yylval.tokenData->idIndex = svalue[0] - 'a';
            break;

        case DEFINITION:
            UpperCase(svalue);  
			yylval.tokenData->stringvalue = strdup(svalue);
            
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
      
            }
            
    

    return tokenClass;
}

%}

%option noyywrap

%%


[ \t]+
"##".*
\n                                  {line++;}

"%"|"*"|"("|")"|"-"                 {return setValue(line, SYMBOL, yytext);}
"["|"]"|":"|";"                     {return setValue(line, SYMBOL, yytext);}
"<"|">"|"?"|","|"/"                 {return setValue(line, SYMBOL, yytext);}
"="|"+"                             {return setValue(line, SYMBOL, yytext);}

"int"                               {return setValue(line, DEFINITION, yytext);}
"if"                                {return setValue(line, DEFINITION, yytext);}
"or"                                {return setValue(line, DEFINITION, yytext);}
"not"                               {return setValue(line, DEFINITION, yytext);}
"by"                                {return setValue(line, DEFINITION, yytext);}
"else"                              {return setValue(line, DEFINITION, yytext);}
"then"                              {return setValue(line, DEFINITION, yytext);}
"for"                               {return setValue(line, DEFINITION, yytext);}
"break"                             {return setValue(line, DEFINITION, yytext);}
"return"                            {return setValue(line, DEFINITION, yytext);}
"bool"                              {return setValue(line, DEFINITION, yytext);}
"char"                              {return setValue(line, DEFINITION, yytext);}
"static"                            {return setValue(line, DEFINITION, yytext);}
"and"                               {return setValue(line, DEFINITION, yytext);}
"begin"                             {return setValue(line, DEFINITION, yytext);}
"end"                               {return setValue(line, DEFINITION, yytext);}
"do"                                {return setValue(line, DEFINITION,  yytext);}
"while"                             {return setValue(line, DEFINITION, yytext);}
"true"                              {return setValue(line, BOOLCONST, yytext);}
"false"                             {return setValue(line, BOOLCONST, yytext);}

"step"                              {return setValue(line, BY, yytext);}

\'(\\.|[^\n\'])*\'                  {return setValue(line, CHARCONST, yytext);}
\"(\\.|[^\\\n\"])*\"                {return setValue(line, STRINGCONST, yytext);}   

[a-zA-Z]([a-zA-Z]|[0-9])*           {return setValue(line, ID, yytext);}
[0-9]+                              {return setValue(line, NUMCONST, yytext);}

"+="                                {return setValue(line, PLUSEQ, yytext);}
"--"                                {return setValue(line, DBLMINUS, yytext);}
"<="                                {return setValue(line, LESSEQ, yytext);}
".."                                {return setValue(line, TO, yytext);}
"++"                                {return setValue(line, INC, yytext);}
"!<"                                {return setValue(line, GEQ, yytext);}
"!>"                                {return setValue(line, LEQ, yytext);}
"!="                                {return setValue(line, NEQ, yytext);}

.                                   {printf("ERROR(%d): Invalid or misplaced input character: \'%c\'. Character Ignored.\n", line, yytext[0]); numErrors++;}

%%
