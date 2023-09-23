%{
// CS445 

// this *order* of these includes is mandatory
#include "scanType.h"  // TokenData Type
#include "parser.tab.h"  // token definitions from the bison

// extra includes for necesary packges or functions
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
    // create the pass-back data space
    yylval.tokenData = new TokenData;

    yylval.tokenData->linenum = linenum;
    yylval.tokenData->tokenstr = strdup(svalue);
    yylval.tokenData->tokenclass = tokenClass;

    switch(tokenClass){
		case SYMBOL:
            break;

		 case ID:
			yylval.tokenData->tokenStrprint = strdup("ID");
            yylval.tokenData->idIndex = svalue[0] - 'a';
            break;

        case OTHER:
			yylval.tokenData->stringvalue = strdup(svalue);
            UpperCase(svalue);  
            break;

        case BOOLCONST:
            yylval.tokenData->tokenStrprint = strdup("BOOLCONST");

            if(strcmp(svalue, "false") == 0){
                yylval.tokenData->numvalue = 0;
            }
            else{
                yylval.tokenData->numvalue = 1;
            }
            break;
       
        case NUMCONST:
            yylval.tokenData->tokenStrprint = strdup("NUMCONST");
            yylval.tokenData->numvalue = atoi(svalue);
            break;

        case CHARCONST:
  
            WrdLength = strlen(svalue);

             // if str length is 3 assign it to svalue first index. 
            if(WrdLength == 3){
                yylval.tokenData->charvalue = svalue[1];
            }

            if(WrdLength > 3){
			
                // check for \ escape (92), n is (110), 0 is (48). 
                if(svalue[1] == 92 && svalue[2] != 110 && svalue[2] != 48){
                    yylval.tokenData->charvalue = svalue[2];
                }
               
			    else if(svalue[1] == 92 && svalue[2] != 110 && svalue[2] == 48){
                    yylval.tokenData->charvalue = '\0';
                }
				
                else if(svalue[1] == 92 && svalue[2] == 110 && svalue[2] != 48){
                    yylval.tokenData->charvalue = '\n';
                }
                            
                else if(svalue[1] != 92){
                    printf("WARNING(%d): character is %d characters long and not a single character:\n", line, (WrdLength-2));
                     yylval.tokenData->charvalue = svalue[1];
                }
            }

            yylval.tokenData->tokenStrprint = strdup("CHARCONST");
            break;
            
        case STRINGCONST:
           
            int i;
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

"<"|">"|"("|")"|"["|"]"             {return setValue(line, SYMBOL, yytext);}
"="|"-"|"*"|"/"|"%"                 {return setValue(line, SYMBOL, yytext);}
":"|";"|"?"|","|"+"                 {return setValue(line, SYMBOL, yytext);}



"true"                              {return setValue(line, BOOLCONST, yytext);}
"false"                             {return setValue(line, BOOLCONST, yytext);}



"int"                               {return setValue(line, OTHER, yytext);}
"dec"                               {return setValue(line, OTHER, yytext);}
"bool"                              {return setValue(line, OTHER, yytext);}
"char"                              {return setValue(line, OTHER, yytext);}
"static"                            {return setValue(line, OTHER, yytext);}
"and"                               {return setValue(line, OTHER, yytext);}
"or"                                {return setValue(line, OTHER, yytext);}
"not"                               {return setValue(line, OTHER, yytext);}
"by"                                {return setValue(line, OTHER, yytext);}
"addasgn"                           {return setValue(line, OTHER, yytext);}
"asgn"                              {return setValue(line, OTHER, yytext);}
"inc"                               {return setValue(line, OTHER, yytext);}
"geq"                               {return setValue(line, OTHER, yytext);}
"leq"                               {return setValue(line, OTHER, yytext);}
"neq"                               {return setValue(line, OTHER, yytext);}
"if"                                {return setValue(line, OTHER, yytext);}
"else"                              {return setValue(line, OTHER, yytext);}
"then"                              {return setValue(line, OTHER, yytext);}
"for"                               {return setValue(line, OTHER, yytext);}
"break"                             {return setValue(line, OTHER, yytext);}
"return"                            {return setValue(line, OTHER, yytext);}
"begin"                             {return setValue(line, OTHER, yytext);}
"end"                               {return setValue(line, OTHER, yytext);}
"do"                                {return setValue(line, OTHER,  yytext);}
"while"                             {return setValue(line, OTHER, yytext);}

"+="                                {return setValue(line, PLUSEQ, yytext);}
"--"                                {return setValue(line, DBLMINUS, yytext);}
"<="                                {return setValue(line, LESSEQ, yytext);}
".."                                {return setValue(line, TO, yytext);}
"++"                                {return setValue(line, INC, yytext);}
"!<"                                {return setValue(line, CEQ, yytext);}
"!>"                                {return setValue(line, LEQ, yytext);}
"!="                                {return setValue(line, NEQ, yytext);}

[a-zA-Z]([a-zA-Z]|[0-9])*           {return setValue(line, ID, yytext);}
[0-9]+                              {return setValue(line, NUMCONST, yytext);}

\'(\\.|[^\n\'])*\'                  {return setValue(line, CHARCONST, yytext);}
\"(\\.|[^\\\n\"])*\"                {return setValue(line, STRINGCONST, yytext);}   
.                                   {printf("ERROR(%d): Invalid or misplaced input character: \'%c\'. Character Ignored.\n", line, yytext[0]); numErrors++;}

%%