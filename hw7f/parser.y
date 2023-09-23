%{

/* Riley Walsh
*  CS445
*  Spring 2023
*/

#include "scanType.h"  // my header file. 
#include "tree.h"
#include "semantic.h"
#include "IOinit.h"
#include "yyerror.h"
#include "tree.h"
#include "codeGen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <getopt.h>
#include <iostream>
#include <fstream>

extern int yylex();
extern FILE *yyin;
extern int line;       // ERR line number from the scanner!!
extern int numErrors;  // ERR err count
int numWarnings;       // ERR warning count
bool ALLTYPE = false;
bool printOffset = false;
bool opM;
bool onlyM;

static TreeNode *ROOT;

extern int goffset;
extern SymbolTable symbolTable;

/*void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", line, msg);
    numErrors++;
}*/

%}
// Note added new definition for verbose based on my compiler error message.
// My compiler said this is the new way to define error verbose.
// Old definition works just fine on school server/compiler. 

%define parse.error verbose

// this is included in the tab.h file
// so scanType.h must be included before the tab.h file!!!!
%union {
    ExpType type;           // For passing ALLTYPE ( i.e. pass a type in a decl like in or bool)
    TokenData *tokenData;   // For terminals. Token data comes from yylex() in the $ vars
    TreeNode *tree;         // For nonterminals. Add these nodes as you build the tree. 
}

%token <tokenData> ID NUMCONST CHARCONST STRINGCONST BOOLCONST SPEC KEYWORD
%token <tokenData> INC DEC NEQ LEQ GEQ ASGN ADDASGN MINUSASGN MULTASGN DIVASGN
%token <tokenData> IF THEN ELSE FOR BREAK RETURN START STOP WHILE TO DO BY NOT
%token <tokenData> STATIC BOOL CHAR INT 
%token <tokenData> PLUS MINUS DIVIDE MULT EQUALS PERCENT
%token <tokenData> COLON SEMICOLON COMMA QMARK 

%token <tokenData> LBRACKET RBRACKET LPAREN RPAREN OR AND LESSTHAN GREATERTHAN
%type <type>    typeSpec
%type <tree>    declList decl varDecl scopedVarDecl varDeclList varDeclInit varDeclId
%type <tree>    iterRange breakStmt exp assignop simpleExp andExp unaryRelExp
%type <tree>    relExp relop sumExp sumop mulExp mulop unaryExp unaryop
%type <tree>    funDecl parms parmList parmTypeList parmIdList parmId
%type <tree>    stmt expStmt compoundStmt localDecls stmtList returnStmt endStmt
%type <tree>    factor mutable immutable call args argList constant matchedif unmatchedif

%%

// note program isn't declared, its a bison cmd. 
// Pass root as treenode, declarationlist to be read last
program             :       declList                                            { ROOT = $1 ;}
                    ;

declList            :       declList decl                                       { $$ = addSibling($1, $2); }
                    |       decl                                                { $$ = $1; }
                    ;

decl                :       varDecl                                             { $$ = $1; }       
                    |       funDecl                                             { $$ = $1; }
                    |       error                                               { $$ = NULL; }
                    ;

varDecl             :       typeSpec varDeclList SEMICOLON                      { $$ = $2; 
                                                                                  setType($$, $1); 
                                                                                  yyerrok; }

                    |       error varDeclList SEMICOLON                         { $$ = NULL; 
                                                                                  yyerrok; }
                    |       typeSpec error SEMICOLON                            { $$ = NULL; 
                                                                                  yyerrok; }
                    ;

scopedVarDecl       :       STATIC typeSpec varDeclList SEMICOLON               {$$ = $3; $$->isStatic = true; 
                                                                                  setType($$, $2); 
                                                                                  yyerrok; }

                    |       typeSpec varDeclList SEMICOLON                      { $$ = $2; 
                                                                                  setType($$, $1); 
                                                                                  yyerrok; }
                    ;

varDeclList         :       varDeclList COMMA varDeclInit                       { $$ = addSibling($1, $3); 
                                                                                  yyerrok; }

                    |       varDeclList COMMA error                             { $$ = NULL; }
                    |       varDeclInit                                         { $$ = $1; }
                    |       error                                               { $$ = NULL; }
                    ;

varDeclInit         :       varDeclId                                           { $$ = $1; }

                    |       varDeclId COLON simpleExp                           { $$ = $1; 
                                                                                  if($1 != NULL){
                                                                                      $$->child[0] = $3;
                                                                                    } }

                    |       error COLON simpleExp                               { $$ = NULL; 
                                                                                  yyerrok; }
                    ;
                
varDeclId           :       ID                                                  { $$ = newDeclNode(VarK, $1); $$->attr.name = $1->tokenstr; } 
                    |       ID LBRACKET NUMCONST RBRACKET                       { $$ = newDeclNode(VarK, $1); 
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->isArray = true;
                                                                                  $$->arrLength = $3->nvalue;
                                                                                  $$->thisTokenData = $1; $$->expType = UndefinedType;}
                    |       ID LBRACKET error                                   { $$ = NULL; }
                    |       error RBRACKET                                      { $$ = NULL; 
                                                                                  yyerrok;}
                    ;
//make sure to add typespecifiers for the parameters/etc!
typeSpec            :       BOOL                                                { $$ = Boolean; }
                    |       CHAR                                                { $$ = Char; }
                    |       INT                                                 { $$ = Integer; }
                    ;

funDecl             :       typeSpec ID LPAREN parms RPAREN compoundStmt        { $$ = newDeclNode(FuncK, $2);
                                                                                  $$->attr.name = strdup($2->tokenstr);
                                                                                  $$->expType = $1;
                                                                                  //$$->thisTokenData = $2;
                                                                                  $$->child[0] = $4;
                                                                                  $$->child[1] = $6; }


                    |       ID LPAREN parms RPAREN compoundStmt                 { $$ = newDeclNode(FuncK, $1);
                                                                                  $$->attr.name = strdup($1->tokenstr);
                                                                                  //$$->expType = $1;
                                                                                  $$->thisTokenData = $1;
                                                                                  $$->child[0] = $3;
                                                                                  $$->child[1] = $5; }

                    |       typeSpec error                                      { $$ = NULL; }
                    |       typeSpec ID LPAREN error                            { $$ = NULL; }
                    |       ID LPAREN error                                     { $$ = NULL; }
                    |       ID LPAREN parms RPAREN error                        { $$ = NULL; }  
                    ;

parms               :       parmList                                            { $$ = $1 ; }
                    |       %empty                                              { $$ = NULL ; } //epsilon
                    ;

parmList            :       parmList SEMICOLON parmTypeList                     { $$ = addSibling($1, $3);}  //declaring multiple arguments in a function decl
                    |       parmTypeList                                        { $$ = $1 ; }
                    |       parmList SEMICOLON error                            { $$ = NULL; }
                    |       error                                               { $$ = NULL; }
                    ;

parmTypeList        :       typeSpec parmIdList                                 { $$ = $2; setType($$, $1); }
                    |       typeSpec error                                      { $$ = NULL; }
                    ;

parmIdList          :       parmIdList COMMA parmId                             { $$ = addSibling($1, $3); 
                                                                                  yyerrok; }
                    |       parmId                                              { $$ = $1; }
                    |       parmIdList COMMA error                              { $$ = NULL; }
                    |       error                                               { $$ = NULL; }
                    ;

parmId              :       ID                                                  { $$ = newDeclNode(ParamK, $1);$$->attr.name = strdup($1->tokenstr); }

                    |       ID LBRACKET RBRACKET                                { $$ = newDeclNode(ParamK, $1); 
                                                                                  $$->attr.name = strdup($1->tokenstr); 
                                                                                  $$->isArray = true;}
                    ;

stmt                :       matchedif                                           { $$ = $1; }                                    
                    |       unmatchedif                                         { $$ = $1; }
                    ;

expStmt             :       exp SEMICOLON                                       { $$ = $1; }
                    |       SEMICOLON                                           { $$ = NULL; }
                    |       error SEMICOLON                                     { $$ = NULL; 
                                                                                  yyerrok; }
                    ;

compoundStmt        :       START localDecls stmtList STOP                      { $$ = newStmtNode(CompoundK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $3; 
                                                                                  yyerrok; }
                    ;

localDecls          :       localDecls scopedVarDecl                            { $$ = addSibling($1, $2); }
                    |       %empty                                              { $$ = NULL; }
                    ;

stmtList            :       stmtList stmt                                       { $$ = addSibling($1, $2); }
                    |       %empty                                              { $$ = NULL; }
                    ;

//Dangling else statement fix using matching/unmatching.
matchedif           :       endStmt                                             { $$ = $1; }
                    |       IF simpleExp THEN matchedif ELSE matchedif          { $$ = newStmtNode(IfK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;
                                                                                  $$->child[2] = $6;}

                    |       IF error                                             { $$ = NULL; }
                    |       IF error ELSE matchedif                              { $$ = NULL; yyerrok; }
                    |       IF error THEN matchedif ELSE matchedif               { $$ = NULL; yyerrok; }

                    |       WHILE simpleExp DO matchedif                        { $$ = newStmtNode(WhileK, $1);
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;}

                    |       WHILE error DO matchedif                             { $$ = NULL; 
                                                                                   yyerrok; }
                    |       WHILE error                                          { $$ = NULL; }

                    |       FOR ID ASGN iterRange DO matchedif                  { $$ = newStmtNode(ForK, $1);
                                                                                  $$->child[0] = newDeclNode(VarK, $2);
                                                                                  $$->child[0]->expType = Integer;
                                                                                  $$->attr.name = $3->tokenstr;
                                                                                  $$->child[1] = $4;
                                                                                  $$->child[2] = $6;}

                    |       FOR ID ASGN error DO matchedif                       { $$ = NULL; yyerrok; }
                    |       FOR error                                            { $$ = NULL; }
                    ;

unmatchedif         :       IF simpleExp THEN matchedif ELSE unmatchedif        { $$ = newStmtNode(IfK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;
                                                                                  $$->child[2] = $6;}

                    |       IF error THEN matchedif ELSE unmatchedif            { $$ = NULL; 
                                                                                  yyerrok; }

                    |       WHILE simpleExp DO unmatchedif                      { $$ = newStmtNode(WhileK, $1);
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;}

                    |       WHILE error DO unmatchedif                          { $$ = NULL; 
                                                                                  yyerrok; }

                    |       FOR ID ASGN iterRange DO unmatchedif                { $$ = newStmtNode(ForK, $1);
                                                                                  $$->child[0] = newDeclNode(VarK, $2);
                                                                                  $$->child[0]->expType = Integer;
                                                                                  $$->attr.name = $3->tokenstr;
                                                                                  $$->child[1] = $4;
                                                                                  $$->child[2] = $6;}

                    |       FOR ID ASGN error DO unmatchedif                    { $$ = NULL;
                                                                                  yyerrok; }

                    |       IF simpleExp THEN stmt                              { $$ = newStmtNode(IfK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;}

                    |       IF error THEN matchedif                             { $$ = NULL; yyerrok; }
                    ;

endStmt             :       expStmt                                             { $$ = $1; }
                    |       compoundStmt                                        { $$ = $1; }
                    |       returnStmt                                          { $$ = $1; }
                    |       breakStmt                                           { $$ = $1; }
                    ;

iterRange           :       simpleExp TO simpleExp                              { $$ = newStmtNode(RangeK, $2);
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;}

                    |       simpleExp TO simpleExp BY simpleExp                 { $$ = newStmtNode(RangeK, $2);
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;
                                                                                  $$->child[2] = $5;}

                    |       simpleExp TO error                                  { $$ = NULL; }
                    |       error BY error                                      { $$ = NULL; 
                                                                                  yyerrok; }
                    |       simpleExp TO simpleExp BY error                     { $$ = NULL; }
                    ;

returnStmt          :       RETURN SEMICOLON                                    { $$ = newStmtNode(ReturnK, $1);
                                                                                  $$->attr.name = $1->tokenstr;}

                    |       RETURN exp SEMICOLON                                { $$ = newStmtNode(ReturnK, $1); 
                                                                                  $$->attr.name = $1->tokenstr; 
                                                                                  $$->expType = $2->expType;
                                                                                  $$->child[0] = $2;
                                                                                  yyerrok; }

                    |       RETURN error SEMICOLON                              { $$ = NULL; 
                                                                                  yyerrok; }
                    ;

breakStmt           :       BREAK SEMICOLON                                     { $$ = newStmtNode(BreakK, $1);
                                                                                  $$->attr.name = $1->tokenstr; }
                    ;

exp                 :       mutable assignop exp                                { $$ = $2;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;}

                    |       mutable INC                                         { $$ = newExpNode(AssignK, $2);
                                                                                  $$->attr.name = $2->tokenstr;
                                                                                  $$->expType = Integer;
                                                                                  $$->child[0] = $1; }

                    |       mutable DEC                                         { $$ = newExpNode(AssignK, $2);
                                                                                  $$->attr.name = $2->tokenstr;
                                                                                  $$->expType = Integer;
                                                                                  $$->child[0] = $1; }

                    |       simpleExp                                           { $$ = $1; }
                    
                    |       error assignop exp                                  { $$ = NULL; yyerrok; }
                    |       mutable assignop error                              { $$ = NULL; }
                    |       error INC                                           { $$ = NULL; yyerrok; }
                    |       error DEC                                           { $$ = NULL; yyerrok; }
                    ;

assignop            :       ASGN                                                { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenstr;}
                    |       ADDASGN                                             { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenstr;}
                    |       MINUSASGN                                           { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenstr;}
                    |       MULTASGN                                            { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenstr;}
                    |       DIVASGN                                             { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenstr;}
                    ;

simpleExp           :       simpleExp OR andExp                                 { $$ = newExpNode(OpK, $2);
                                                                                  $$->attr.name = $2->tokenstr;
                                                                                  $$->expType = Boolean;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;}

                    |       andExp                                              { $$ = $1; }
                    |       simpleExp OR error                                  { $$ = NULL; }
                    ;

andExp              :       andExp AND unaryRelExp                              { $$ = newExpNode(OpK, $2);
                                                                                  $$->attr.name = $2->tokenstr;
                                                                                  $$->expType = Boolean;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;}

                    |       unaryRelExp                                         { $$ = $1; }
                    |       andExp AND error                                    { $$ = NULL; }
                    ;

unaryRelExp         :       NOT unaryRelExp                                     { $$ = newExpNode(OpK, $1);
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Boolean;
                                                                                  $$->child[0] = $2;}

                    |       relExp                                              { $$ = $1; }
                    |       NOT error                                           { $$ = NULL; }
                    ;

relExp              :       sumExp relop sumExp                                 { $$  = $2;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3; }

                    |       sumExp relop error                                  { $$ = NULL; } 

                    |       sumExp                                              { $$ = $1 ;}
                    ;

relop               :       LESSTHAN                                            { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Boolean;}

                    |       LEQ                                                 { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Boolean;}

                    |       GREATERTHAN                                         { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Boolean;}

                    |       GEQ                                                 { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Boolean;}

                    |       EQUALS                                              { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Boolean;}

                    |       NEQ                                                 { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Boolean;}
                    ;

sumExp              :       sumExp sumop mulExp                                 { $$  = $2;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3; }

                    |       mulExp                                              { $$ = $1; }
                    |       sumExp sumop error                                  { $$ = NULL; }
                    ;

sumop               :       PLUS                                                { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Integer;}

                    |       MINUS                                               { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Integer;}
                    ;

mulExp              :       mulExp mulop unaryExp                               { $$  = $2;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3; }

                    |       unaryExp                                            { $$ = $1; }
                    |       mulExp mulop error                                  { $$ = NULL; }
                    ;

mulop               :       MULT                                                { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Integer;}

                    |       DIVIDE                                              { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Integer;}

                    |       PERCENT                                             { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Integer;}
                    ;

unaryExp            :       unaryop unaryExp                                    { $$  = $1;
                                                                                  $$->child[0] = $2; }

                    |       factor                                              { $$ = $1; }
                    |       unaryop error                                       { $$ = NULL; }
                    ;

unaryop             :       MINUS                                               { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Integer;}

                    |       MULT                                                { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Integer;}

                    |       QMARK                                               { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Integer;}
                    ;

factor              :       mutable                                             { $$ = $1; }
                    |       immutable                                           { $$ = $1; }
                    ;

mutable             :       ID                                                  { $$ = newExpNode(IdK, $1);
                                                                                  $$->attr.name = strdup($1->tokenstr); }

                    |       ID LBRACKET exp RBRACKET                            { $$ = newExpNode(OpK, $2); 
                                                                                  $$->attr.name = $2->tokenstr;
                                                                                  $$->child[0] = newExpNode(IdK, $1);
                                                                                  $$->child[0]->attr.name = $1->tokenstr;
                                                                                  $$->child[0]->isArray = true;
                                                                                  $$->child[1] = $3; }
                    ;

immutable           :       LPAREN exp RPAREN                                   { $$ = $2; yyerrok; }
                    |       call                                                { $$ = $1; }
                    |       constant                                            { $$ = $1; }
                    |       LPAREN error                                        { $$ = NULL; }
                    ;

call                :       ID LPAREN args RPAREN                               { $$ = newExpNode(CallK, $1);
                                                                                  $$->attr.name = strdup($1->tokenstr);
                                                                                  $$->child[0] = $3;}

                    |       error LPAREN                                        { $$ = NULL; yyerrok; }
                    ;

args                :       argList                                             { $$ = $1; }
                    |       %empty                                              { $$ = NULL; }
                    ;

argList             :       argList COMMA exp                                   { $$ = addSibling($1, $3); yyerrok; }
                    |       exp                                                 { $$ = $1; }
                    |       argList COMMA error                                 { $$ = NULL; }
                    ;

constant            :       NUMCONST                                            { $$ = newExpNode(ConstantK, $1);
                                                                                  $$->attr.value = $1->nvalue;
                                                                                  $$->expType = Integer; }

                    |       CHARCONST                                           { $$ = newExpNode(ConstantK, $1);
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->thisTokenData = $1;
                                                                                  $$->expType = Char;
                                                                                  $$->attr.cvalue = $1->cvalue; }

                    |       STRINGCONST                                         { $$ = newExpNode(ConstantK, $1);
                                                                                  $$->attr.string = strdup($1->stringvalue);
                                                                                  $$->isArray = true;
                                                                                  $$->arrLength = $1->strlength;
                                                                                  $$->expType = CharInt; }

                    |       BOOLCONST                                           { $$ = newExpNode(ConstantK, $1);
                                                                                  $$->attr.value = $1->nvalue;
                                                                                  $$->attr.name = $1->tokenstr;
                                                                                  $$->expType = Boolean; }
                    ;

%%

extern int yydebug;
int main(int argc, char *argv[])
{

    int selOption = 0;
    bool printROOT = 0;
    numErrors = 0;
    numWarnings = 0;
    int options;
    bool doStuff = true;

    while((selOption = getopt(argc, argv, "dDpPMh")) != -1){

        switch(selOption){
       
            case 'p':
                printROOT = true;
                ALLTYPE = false;
                options = 0;
                doStuff = false;
                break;
       
            case 'P':
                printROOT = true;
                ALLTYPE = true;
                options = 1;
                doStuff = false;
                break;

            case 'd':
                yydebug = 1;
                break;           
           
            case 'D':
                symbolTable.debug(1);
                break;

            case 'M':               
                printROOT = true;
                ALLTYPE = true;
                opM = true;
                printOffset = true;
                options = 1;
                doStuff = false;
                onlyM = true;
                break;

            case 'h':
                printf("usage: -c [options] [sourcefile]\n");
                printf("options:\n");
                printf("-d     - turn on parser debugging\n");
                printf("-D     - turn on symbol table debugging\n");
                printf("-h     - print this usage message\n");
                printf("-p     - print the abstract syntax tree\n");
                printf("-P     - print the abstract syntax tree plus type information\n");
                break;

            default:
                exit(1);
        }
       
    }

    if(doStuff == true){
        options = 1;
        opM = true;
        ALLTYPE = true;
        onlyM = false;
    }    


    if(argc > optind){
        if((yyin = fopen(argv[argc-1], "r"))) {
            // file open successful
        }
        else {
            //failed to open
            printf("ERROR(ARGLIST): source file \"%s\" could not be opened.\n", argv[1]);
            numErrors++;
            printf("Number of warnings: %d\n", numWarnings);
            printf("Number of errors: %d\n", numErrors);
            exit(1);
        }
    }

    initErrorProcessing();
    yyparse();

    if(printROOT && options == 0 && numErrors == 0){
        printTree(ROOT, 0, ALLTYPE);
    }
    else if(options == 1 && numErrors == 0){

        InitializeIO();
        semanticAnalysis(ROOT, numErrors, numWarnings);

        if(numErrors < 1 && onlyM)
        {
            printTree(ROOT, 0, ALLTYPE);
         
        }
 
    }
   
    //codegen
    if(numErrors == 0){
        char *fileName;
        int numArgs = argc;
        
        char *out = argv[numArgs-1];
        int fileLen = strlen(out);
        fileName = (char *)malloc(fileLen + 1);
        strcpy(fileName, out);
        fileName[fileLen - 2] = 't';
        fileName[fileLen - 1] = 'm';

        generateCode( ROOT,fileName);      
    } 


    if(printOffset){
        printf("Offset for end of global space: %d\n", goffset);
    }
    printf("Number of warnings: %d\n", numWarnings);
    printf("Number of errors: %d\n", numErrors);

    return 0;

}