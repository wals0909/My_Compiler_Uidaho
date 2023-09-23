   
/* Riley Walsh
*  CS445
*  Spring 2023
*/ 

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "semantic.h"

#define MAXCHILDREN 3

using namespace std;

struct symErrors {
    int lineno;
    char* errorMsg;
};

vector<symErrors> errBuffer;

char Buffer[256]; 
int nErrors; 
int nWarnings;
bool scopeDepth = true;
bool Flag = false;
bool loop = false;
bool range = false;
int loopDepth = 1;
int rangePos = 0;
int linenoFunc;
char *nameofFunc;
int linenoRet;
bool forloop = false;
bool flagArraysize = false;
int loffset = 0;
int goffset = 0;

TreeNode *temp = NULL;
ExpType functionReturnType;
ExpType actualReturnType;
SymbolTable symbolTable;

//function returns symbol table
SymbolTable returnSymbolTable() {
    return symbolTable;
}

//function prints error messages. 
void PrintErrorss(){
    for(int i = 0; i < errBuffer.size(); i++){
        printf("%s", errBuffer[i].errorMsg);
    }
}

//Function checks each node. 
void check(TreeNode *t, int& nErrors, int& nWarnings){

    if(t == NULL){
        return;
    }
    switch(t->nodekind){
        case DeclK:
            checkDecl(t, nErrors, nWarnings);
            break;

        case StmtK:
            checkStmt(t, nErrors, nWarnings);
            break;

        case ExpK:
            checkExp(t, nErrors, nWarnings);
            break;
    }

    if(t->sibling != NULL){
        check(t->sibling, nErrors, nWarnings);
    }
}

//function analizes semantics first by checking for keyword "main"
void semanticAnalysis(TreeNode *t, int& errors, int& warnings){

    check(t, nErrors, nWarnings);

    symbolTable.applyToAll(Warninit);
    symbolTable.applyToAllGlobal(Warninit);
 
    TreeNode *mainCheck = (TreeNode*)symbolTable.lookup("main");
    if(mainCheck == NULL){
        printError(16, 0, 0, NULL, NULL, NULL, 0);
    }
    else if(mainCheck != NULL){
        
        if(mainCheck->nodekind == DeclK && mainCheck->subkind.decl != FuncK){

                printError(16, 0, 0, NULL, NULL, NULL, 0);
        }
        else if(mainCheck->child[0] != NULL && mainCheck->child[0]->subkind.decl == ParamK){
            printError(16, 0, 0, NULL, NULL, NULL, 0);
        }
    }

    PrintErrorss();
    errors = nErrors;
    warnings = nWarnings;
}

//function checks to see if warnings were used.
void Warninit(std::string symbol, void* t){

    TreeNode* currentNode = (TreeNode *)symbolTable.lookup(symbol.c_str());     

    if(!currentNode->wasUsed && !currentNode->isGlobal){

        
        if(currentNode->subkind.decl == FuncK && !currentNode->errWasUsed && strcmp(currentNode->attr.name, "main")){
            currentNode->errWasUsed = true;
            printError(21, currentNode->lineno, 0, currentNode->attr.name, NULL, NULL, 0);
        }
        
        else if(currentNode->subkind.decl == ParamK && !currentNode->errWasUsed && strcmp(currentNode->attr.name, "main")){
            currentNode->errWasUsed = true;
            printError(20, currentNode->lineno, 0, currentNode->attr.name, NULL, NULL, 0);
        }

        else{
            currentNode->errWasUsed = true;
            printError(17, currentNode->lineno, 0, currentNode->attr.name, NULL, NULL, 0);
        }
    }

    else if(!currentNode->wasUsed && currentNode->isGlobal && currentNode->subkind.decl == FuncK){
        
        if(strcmp(currentNode->attr.name, "main") && !currentNode->errWasUsed){
            currentNode->errWasUsed = true;
            //change to 20 was 21
            printError(21, currentNode->lineno, 0, currentNode->attr.name, NULL, NULL, 0);
        }
    }

    else if(!currentNode->wasUsed && currentNode->isGlobal && !currentNode->errWasUsed){
         currentNode->errWasUsed = true;
         printError(17, currentNode->lineno, 0, currentNode->attr.name, NULL, NULL, 0);
    }
}

//function prints errors for arrays.
void errorsArray(TreeNode *t)
{

   TreeNode *leftNode = NULL;
   TreeNode *rightNode = NULL;

   leftNode = t->child[0];
   rightNode = t->child[1];


   if(t->child[0]->subkind.exp == IdK)
   {

      leftNode = (TreeNode*)symbolTable.lookup(t->child[0]->attr.name);
      
      if(leftNode != NULL)
      {
         t->child[0]->expType = leftNode->expType;
         t->expType = leftNode->expType;
      }


      if(leftNode == NULL || !leftNode->isArray)
      {
         printError(15, t->lineno, 0, t->child[0]->attr.name, NULL, NULL, 0);
      }
   }
   else
   {
      printError(15, t->lineno, 0, t->child[0]->attr.name, NULL, NULL, 0);
   }
   if(t->child[1] != NULL)
   {
      if(t->child[1]->expType != Integer && t->child[1]->expType != UndefinedType)
      {

          if(t->child[1]->subkind.decl == ParamK && t->child[1]->subkind.exp != CallK && t->child[1]->expType == Void){
        
          }
          else{
            printError(14, t->lineno, 0, t->child[0]->attr.name, ExpTypetwo(t->child[1]->expType), NULL, 0);
          }
          
      }
   }
   if(t->child[1] != NULL && t->child[1]->subkind.exp == IdK)
   {
      
      if(rightNode != NULL && rightNode->isArray == true)
      {
         printError(13, t->lineno, 0, rightNode->attr.name, NULL, NULL, 0); //
      }
      if(rightNode != NULL)
      {
         t->child[1]->expType = rightNode->expType;
      }
   }

}

//function prints errors for params.
void errorsParam(TreeNode *funcFound, TreeNode *t, TreeNode *ffParm, TreeNode *tParm, int paramCount){
    

    if(ffParm->sibling == NULL && tParm->sibling != NULL){
        printError(38, t->lineno, funcFound->lineno, t->attr.name, NULL, NULL, 0);
    }

    else if(ffParm->sibling != NULL && tParm->sibling == NULL){
        printError(37, t->lineno, funcFound->lineno, t->attr.name, NULL, NULL, 0);
    }
  
    if(tParm->expType != UndefinedType){
        
        if(ffParm->expType != tParm->expType && !tParm->errDecl && !funcFound->IOinit){
            
             if(ffParm->expType == Char && tParm->expType == CharInt){
                ;
            }
            else{
                printError(25, t->lineno, funcFound->lineno, funcFound->attr.name, ExpTypetwo(ffParm->expType), ExpTypetwo(tParm->expType), paramCount);               
            }
                   
            if(ffParm->isArray && !tParm->isArray){
                printError(28, t->lineno, funcFound->lineno, funcFound->attr.name, NULL, NULL, paramCount);
            }

            else if(!ffParm->isArray && tParm->isArray){
                printError(36, t->lineno, funcFound->lineno, funcFound->attr.name, NULL, NULL, paramCount);
            }
 
     
        }
   
        else if(ffParm->isArray && !tParm->isArray){
            printError(28, t->lineno, funcFound->lineno, funcFound->attr.name, NULL, NULL, paramCount);
        }

        else if(!ffParm->isArray && tParm->isArray){
            printError(36, t->lineno, funcFound->lineno, funcFound->attr.name, NULL, NULL, paramCount);
        }
       
    }

    paramCount++;

    if(ffParm->sibling != NULL && tParm->sibling != NULL){
    errorsParam(funcFound, t, ffParm->sibling, tParm->sibling, paramCount);
    }
} 

//function checks declaration nodes
void checkDecl(TreeNode *t, int& nErrors, int& nWarnings){
  
    if(symbolTable.depth() == 1){
        t->isGlobal = true;
        t->memT = Global;
    }
    else if(t->isStatic){
        t->memT = LocalStatic;
        t->isGlobal = false;
    }
    else{
        t->memT = Local;
        t->isGlobal = false;
    }

    TreeNode *declared;
    if(t->subkind.decl != VarK && !symbolTable.insert(t->attr.name, t)){
        TreeNode* declared = (TreeNode*)symbolTable.lookup(t->attr.name);
        printError(0, t->lineno, declared->lineno, t->attr.name, NULL, NULL, 0);
    }

    switch(t->subkind.decl){
        case ParamK:

            for(int i = 0; i < MAXCHILDREN; i++){
                
                check(t->child[i], nErrors, nWarnings);
                if(t->child[0] != NULL){
                    t->child[0]->isInit = true;
                }
            }
            t->isInit = true;
            t->mOffset = loffset;           
            t->mSize = 1;
            t->memT = Parameter;
            loffset--;


            break;
        case VarK:

           if(t->child[0] != NULL){

                for(int i = 0; i < MAXCHILDREN; i++){
                    check(t->child[i], nErrors, nWarnings);
                }
           }

           if(!symbolTable.insert(t->attr.name, t)){
               TreeNode* exists = (TreeNode*)symbolTable.lookup(t->attr.name);
               printError(0, t->lineno, exists->lineno, t->attr.name, NULL, NULL, 0);
           }         

           if(t->sibling != NULL){

                if(t->isStatic && t->lineno == t->sibling->lineno && t->expType == t->sibling->expType){
                    t->sibling->isStatic = t->isStatic;
                    
                    if(!t->isGlobal){
                        t->memT = LocalStatic;
                    }

                }
            }

           if(t->child[0] != NULL){

               if(t->child[0]->subkind.exp == IdK || t->child[0]->subkind.exp == CallK){
                   
                   printf("VarK initializer checks: %s %d\n", t->child[0]->attr.name, t->lineno);
               }

               else if(t->child[0]->subkind.exp == OpK){

                   if(t->child[0] != NULL && t->child[0]->child[1] == NULL){

                       if(strcmp(t->child[0]->attr.name, "-") && !t->isArray){
                     
                        if(strcmp(t->child[0]->attr.name, "not") && t->child[0]->child[0]->subkind.exp != ConstantK){                              
                                printError(32, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                printf("VarK initializer checks: %s %d\n", t->child[0]->attr.name, t->lineno);
                           }
                       }
                   }

                   else if(t->child[0]->child[0] != NULL && t->child[0]->child[1] != NULL){
                       recursiveOps(t, t->child[0]);
                   }
               }

               if(t->expType != t->child[0]->expType){

                   if(t->expType == Char && t->child[0]->expType == CharInt){
                        ; // do nothing
                   }

                   else if(t->expType == Integer && t->child[0]->expType == CharInt){
                        char charInsert[] = "char";
                        printError(33, t->lineno, 0, t->attr.name, ExpTypetwo(t->expType), charInsert, 0);
                   }

                   else if(t->child[0]->expType == Void && t->child[0]->subkind.exp == IdK){
                       //do nothing 
                   }

                   else{
                        printError(33, t->lineno, 0, t->attr.name, ExpTypetwo(t->expType), ExpTypetwo(t->child[0]->expType), 0);
                   }
               }
          
               if(t->isArray && !t->child[0]->isArray){
                   printError(35, t->lineno, 0, t->attr.name, NULL, NULL, 0);
               }

               if(!t->isArray && t->child[0]->isArray){
                   printError(34, t->lineno, 0, t->attr.name, NULL, NULL, 0);
               }

               t->isInit = true;
               t->isDeclared = true;        
            }
            else{
                t->isDeclared = true;
            }
            if(t->isArray){
                t->mSize = t->arrLength + 1;
            }
            else{
                t->mSize = 1;
            }

            if(t->isGlobal || t->isStatic){

                if(t->isArray){
                    t->mOffset = goffset - 1;
                }
                else{
                    t->mOffset = goffset;
                }

                    goffset -= t->mSize;
            }    

           else{

               if(t->isArray){
                    t->mOffset = loffset - 1;
               }
               else{
                    t->mOffset = loffset;
               }

                    loffset -= t->mSize;
           }

           break;

        case FuncK:
            loffset = 0;
            loffset -= 2;
            
            temp = t;
            Flag = false;

            symbolTable.enter(t->attr.name);

            scopeDepth = false;
            functionReturnType = t->expType;
            nameofFunc = t->attr.name;
            linenoFunc = t->lineno;
            
            for(int i = 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
            }

            if(Flag == false && t->expType != Void){
                printError(19, t->lineno, 0, ExpTypetwo(functionReturnType), t->attr.name, NULL, 0);
            }

            symbolTable.applyToAll(Warninit);
            symbolTable.leave();
            temp = NULL;

            t->mSize = 0;
            TreeNode* childz = t->child[0];

            while(childz != NULL){

                t->mSize--;
                childz = childz->sibling;
            }

            t->mOffset = 0;
            t->mSize -= 2;
            

            break;

        
    }
}

//check for recursive assignments.
void recursiveASSK(TreeNode *c1){

    if(c1->child[0] != NULL){
        c1->child[0]->isInit = true;
    }
}
 
 //Check for recursive operators.
void recursiveOps(TreeNode *t, TreeNode *child){

    if(child->child[0] != NULL && child->child[1] != NULL){

        if(child->child[0]->subkind.exp == OpK){

            recursiveOps(t, child->child[0]);
        }

        if(child->child[1]->subkind.exp == OpK){
            recursiveOps(t, child->child[1]);
        }

        else if(child->child[0]->subkind.exp == IdK || child->child[1]->subkind.exp == IdK){
            printError(32, t->lineno, 0, t->attr.name, NULL, NULL, 0);
        }
    }

    else if(child->child[0] != NULL && child->child[1] == NULL){
  
        if(strcmp(child->attr.name, "not")){
        printError(32, t->lineno, 0, t->attr.name, NULL, NULL, 0);
        }
    }
}

//Function checks statement nodes
void checkStmt(TreeNode *t, int& nErrors, int& nWarnings){

    int forSize;

    switch(t->subkind.stmt){
        case IfK:
            
            loop = true;
            symbolTable.enter(t->attr.name);
            loopDepth++;
       
            scopeDepth = false;
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[0]){
                    check(t->child[i], nErrors, nWarnings);
                }
            }  

            if(t->child[0]->expType != Boolean && t->child[0]->subkind.exp != OpK && !t->child[0]->errDecl){
                char ifStmt[] = "if";
                printError(27, t->lineno, 0, ifStmt, ExpTypetwo(t->child[0]->expType), NULL, 0 );
            }

            if(t->child[0]->isArray){
                char ifStmt[] = "if";
                printError(23, t->lineno, 0, ifStmt, NULL, NULL, 0);
            }  
            
            loopDepth--;

            symbolTable.applyToAll(Warninit);

            if(loopDepth == 1){
                loop = false;
            }
            symbolTable.leave();
            scopeDepth = true;
            break;

        case WhileK:
            loop = true;
            symbolTable.enter(t->attr.name);
            loopDepth ++;
            scopeDepth = false;

            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                check(t->child[i], nErrors, nWarnings);

                if(i < 1){

                    if(t->child[0]->isArray){
                        char whileStmt[] = "while";
                        printError(23, t->lineno, 0, whileStmt, NULL, NULL, 0);
                    }

                    if(t->child[0]->expType != Boolean && t->child[0]->subkind.exp != OpK && !t->child[0]->errDecl){
                        char whileStmt[] = "while";
                        printError(27, t->lineno, 0, whileStmt, ExpTypetwo(t->child[0]->expType), NULL, 0 );
                    }
          
            }
                }
            }

            loopDepth--;

            symbolTable.applyToAll(Warninit);

            if(loopDepth == 1){
                loop = false;
            }
            symbolTable.leave();
            scopeDepth = true;
            break;

        case ForK:
            loopDepth++;
            symbolTable.enter(t->attr.name);
            scopeDepth = false;
            loop = true;
            forloop = true;
            forSize = loffset;
            
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){

                check(t->child[i], nErrors, nWarnings);
                t->child[0]->isInit = true;
                t->child[1]->isInit = true;
                }
            }

            loopDepth--;

            if(loopDepth == 1){
                loop = false;
            }
                forloop = false;
                symbolTable.applyToAll(Warninit);
                symbolTable.leave();
                scopeDepth = true;
                t->memT = None;
                t->mSize = loffset;
                loffset = forSize;

            break;

      

        case ReturnK:

            linenoRet = t->lineno;
            Flag = true;
           
            check(t->child[0], nErrors, nWarnings);

            if(t->child[0] != NULL){

                actualReturnType = t->child[0]->expType;

                if(temp == NULL){
                    break;
                }

                else if(t->child[0]->isArray){
                   
                    printError(10, t->lineno, 0, NULL, NULL, NULL, 0);
                }

                else if(t->child[0]->child[0] != NULL){
                    if(t->child[0]->child[0]->isArray){

                        if(!strcmp(t->child[0]->attr.name, "[") && !strcmp(t->child[0]->attr.name, "*")){
                            
                            printError(10, t->lineno, 0, NULL, NULL, NULL, 0);
                        }
                    }
                }
            
                if(functionReturnType != actualReturnType && actualReturnType != Void && functionReturnType != Void){

                    if(!(functionReturnType == Char && actualReturnType == CharInt)){
                        printError(31, linenoRet, linenoFunc, nameofFunc, ExpTypetwo(functionReturnType), ExpTypetwo(actualReturnType), 0);
                    }
                }
                else if(functionReturnType == Void){
                    printError(29, linenoRet, linenoFunc, nameofFunc, NULL, NULL, 0);
                }

                else if(functionReturnType != actualReturnType && functionReturnType != Void && t->child[0]->subkind.exp == CallK){
                    
                    if(!(functionReturnType == Char && actualReturnType == CharInt)){
                        printError(31, linenoRet, linenoFunc, nameofFunc, ExpTypetwo(functionReturnType), ExpTypetwo(actualReturnType), 0);
                    }
                }
            }

            else if(t->child[0] == NULL){

                if(functionReturnType != Void){
                    printError(30, linenoRet, linenoFunc, nameofFunc, ExpTypetwo(functionReturnType), NULL, 0);
                }
            }

            break;

        case BreakK:

            if(!loop){
                printError(22, t->lineno, 0, NULL, NULL, NULL, 0);
            }
            break;

        case RangeK:

            range = true;
            rangePos;
    
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                    rangePos++;

                        if(t->child[i]->child[0] != NULL && t->child[i]->child[0]->isArray){
                            t->child[i]->child[0]->arrayIndex  = true;
                        }

                        else if(rangePos == 1){
                            if(t->child[0]->subkind.exp == IdK){
                                TreeNode* valFound = (TreeNode*)symbolTable.lookup(t->child[0]->attr.name);
                                if(valFound == NULL){
                                    printError(1, t->lineno, 0, t->child[0]->attr.name, NULL, NULL, 0); 
                                    t->errDecl = true;
                                }
                                else{
                                    valFound->wasUsed = true;
                                }
                            }
                        }

                    check(t->child[i], nErrors, nWarnings);
                    loffset--;
                }
            }

            range = false;
            rangePos = 0;

            break;

        case CompoundK:

            bool currScope = scopeDepth;
            int cSize = loffset;

            if(currScope){
                
                symbolTable.enter("compound");
            }
            else{
                scopeDepth = true;
            }

            for(int i = 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
            }

            if(currScope){
                symbolTable.applyToAll(Warninit);
                symbolTable.leave();
            }

            t->mSize = loffset;
            loffset = cSize;
            t->memT = None;

            break;

    }

}

//function checks expression nodes. 
void checkExp(TreeNode *t, int& nErrors, int& nWarnings){
 
    bool leftStr, rightStr, isBinary, leftArr, rightArr, leftIndx, rightIndx, leftInit, leftDecl, rightInit, rightDecl, throwError;
    leftStr = rightStr = isBinary = leftArr = rightArr = leftIndx = rightIndx = leftInit = leftDecl = rightInit = rightDecl = throwError = false;

    ExpType leftSide, rightSide, returnType, leftExpected, rightExpected, childReturnType;
    leftSide = rightSide = returnType = leftExpected = rightExpected = childReturnType = UndefinedType;

    bool rightErr, leftErr, unaryErrors;
    rightErr = leftErr = unaryErrors = false;

    TreeNode* valFound = NULL;
    TreeNode* leftNode = NULL;
    TreeNode* rightNode = NULL;

    switch(t->subkind.exp) {
        case AssignK:
        case OpK:

            if(!strcmp(t->attr.name, "<=")){

                if(t->child[0] != NULL){
                    
                    if(t->child[0]->child[0]!=NULL && !strcmp(t->child[0]->attr.name, "[")){
                        t->child[0]->child[0]->isInit = true;

                        if(t->child[0]->child[1] != NULL){
                            t->child[0]->child[1]->isInit = true;

                            if(t->child[0]->child[1]->child[0] != NULL && t->child[0]->child[1]->child[1] != NULL){

                            if(t->child[0]->child[1]->subkind.exp == OpK){
                                t->child[0]->child[1]->child[0]->isInit = true;
                                t->child[0]->child[1]->child[1]->isInit = true;
                            }
                            }
                        }

                        else if(t->child[0]->child[1]->child[0] != NULL){
                            t->child[0]->child[1]->child[0]->isInit = true;
                        }

                    }

                    else if(t->child[1] !=NULL && t->child[1]->expType == Void){

                        if(!strcmp(t->child[1]->attr.name, "<=")){
                            t->child[0]->isInit = true;
                        }

                        if(t->child[1]->subkind.exp == CallK){
                            t->child[0]->isInit = true;
                        }

                        else if(!strcmp(t->child[1]->attr.name, "[")){

                            char* lhs = strdup(t->child[0]->attr.name);
                            char* rhs = strdup(t->child[1]->child[0]->attr.name);

                            if(strcmp(lhs, rhs)){
                                t->child[0]->isInit = true;
                            }

                        }
                        else if(t->child[0]!=NULL && t->child[1]!=NULL){
    
                            if(t->child[0]->subkind.exp == IdK && !t->child[0]->isInit){
        
                                if(t->child[1]->subkind.exp == IdK){

                                    char* lhs = strdup(t->child[0]->attr.name);
                                    char* rhs = strdup(t->child[1]->attr.name);

                                    if(strcmp(lhs, rhs)){
                                        t->child[0]->isInit = true;
                                    }
                                }

                                else if(t->child[1]->subkind.exp == AssignK){
                                    recursiveASSK(t->child[1]);
                                    t->child[0]->isInit = true;
                                }
                            }
                        }

                        else{
                        //do nothing
                        }
                    }
                   
                    else {

                        if(t->child[1] != NULL && t->child[1]->child[0] != NULL){
    
                            if(t->child[1]->child[0]->subkind.exp == IdK){

                                char *lhstwo = strdup(t->child[1]->child[0]->attr.name);
                                char *rhstwo = strdup(t->child[0]->attr.name);
                               
                                if(strcmp(rhstwo, lhstwo)){
                                    t->child[0]->isInit = true;
             
                                }
                            }

                            else{
                                t->child[0]->isInit = true;
                            }
                            

                        }

                        else{
                            t->child[0]->isInit = true;
                        }
                    }
                }

            }

            if(!strcmp(t->attr.name, "*")){
                flagArraysize = true;
            }

            if(strcmp(t->attr.name, "<=")){
                if(t->child[0] != NULL){
                    t->child[0]->wasUsed = true;
                    
                }
                if(t->child[1] != NULL){
                    t->child[1]->wasUsed = true;
                }
             //assignk   
                if(t->subkind.exp == AssignK){
                    t->child[0]->isInit = true;
                }
            }

            for(int i= 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
            }

            flagArraysize = false;

            if(t->child[0] != NULL){
                leftNode = t->child[0];
                leftSide = leftNode->expType;
                leftArr = leftNode->isArray;

                if(leftNode->child[0] != NULL){
                    leftArr = false; 
                    leftIndx = true; 
                }
                if(leftNode->nodekind == ExpK){
                    if(leftNode->subkind.exp == CallK){
                        leftArr = false;
                    }
                    if(leftNode->subkind.exp == ConstantK){
                        leftStr = true;
                    }
                }
            }

            if(t->child[1] != NULL){
                rightNode = t->child[1];
                rightSide = rightNode->expType;
                rightArr = rightNode->isArray;
                

                if(rightNode->child[0] != NULL){
                    rightArr = false; 
                    rightIndx = true; 
                }
                if(rightNode->nodekind == ExpK){
                    if(rightNode->subkind.exp == CallK){
                        rightArr = false;
                    }
                    if(rightNode->subkind.exp == ConstantK){
                        rightStr = true;
                    }
                }
                isBinary = true;
            }

            getExpTypes(t->attr.name, isBinary, unaryErrors, leftExpected, rightExpected, returnType);

            if(leftSide == Void && !(leftNode->nodekind == ExpK && leftNode->subkind.exp == CallK)){
                leftErr = true;
            }
            if(rightSide == Void && !(rightNode->nodekind == ExpK && rightNode->subkind.exp == CallK)){
                rightErr = true;
            }

            if(!isBinary && !leftErr){
 
                if(leftSide != leftExpected && leftExpected != UndefinedType){

                    if(!strcmp(t->attr.name, "-")){
                        char uMinus[] = "chsign";
                        printError(9, t->lineno, 0, uMinus, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                    }

                    else{
                        printError(9, t->lineno, 0, t->attr.name, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                    }
                }

                else if(!strcmp(t->attr.name, "not") && leftSide != leftExpected){

                    printError(9, t->lineno, 0, t->attr.name, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                }

                else if(!strcmp(t->attr.name, "*") && (!leftArr && leftSide != UndefinedType)){
                    char uSizeof[] = "sizeof";
                    printError(8, t->lineno, 0, uSizeof, NULL, NULL, 0);
                } 

                if(leftArr){
                    if(strcmp(t->attr.name, "*") != 0){

                        if(!strcmp(t->attr.name, "-")){
                            char uMinus[] = "chsign";
                            printError(7, t->lineno, 0, uMinus, NULL, NULL, 0);
                        }
                        else{
                            printError(7, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                        }
                    }
                }
            }
                else{
                    if(!unaryErrors){

                        if(!strcmp(t->attr.name, "[")){
                            errorsArray(t);
                        }
                
                        else if(leftSide != rightSide && !leftErr && !rightErr){

                            if(!strcmp(ExpTypetwo(leftSide), "int") && !strcmp(ExpTypetwo(rightSide), "CharInt")){
                                char diffCharInt[] = "char";
                                 printError(2, t->lineno, 0, t->attr.name, ExpTypetwo(leftSide), diffCharInt, 0);
                            }
                            else if(!strcmp(ExpTypetwo(leftSide), "char") && !strcmp(ExpTypetwo(rightSide), "CharInt")){
                                ; //do nothing
                            }

                            else if(!strcmp(t->attr.name, "<=") && t->child[1]->subkind.exp == OpK){


                                if(!strcmp(t->child[1]->attr.name, "[") && t->child[1]->child[0] != NULL){
                                
                                    if(t->child[1]->child[0]->expType != t->child[0]->expType){
                                        printError(2, t->lineno, 0, t->attr.name, ExpTypetwo(leftSide), ExpTypetwo(t->child[1]->child[0]->expType), 0);
                                    }
                                }
                                else{
                           
                                    getReturnType(t->child[1]->attr.name, isBinary, childReturnType);
                                    
                                    if(childReturnType != t->child[0]->expType){
                                        printError(2, t->lineno, 0, t->attr.name, ExpTypetwo(leftSide), ExpTypetwo(childReturnType), 0);
                                    }
                                    
                                    else if(t->child[1]->child[1] != NULL && t->child[1]->child[1]->subkind.exp == CallK){
                                        printError(2, t->lineno, 0, t->attr.name, ExpTypetwo(leftSide), ExpTypetwo(childReturnType), 0);
                                    }
                                }
                            }
                            else{
                                
                                if(t->child[0]->subkind.exp != CallK || (t->child[0]->subkind.exp != t->child[1]->subkind.exp && leftSide == Void)){
                                
                                    if(t->child[0]->subkind.exp == CallK && leftSide == Void && t->child[1]->subkind.exp == ConstantK){
                                        ;
                                    }
                                    else{
                                        printError(2, t->lineno, 0, t->attr.name, ExpTypetwo(leftSide), ExpTypetwo(rightSide), 0);
                                    }
                                }
                                else{}
                            }
                        }                                               
                    }

                    if(!(leftExpected == UndefinedType || rightExpected == UndefinedType)){
                        
                        if(leftExpected == CharInt || rightExpected == CharInt){

                            ;
                        }

                        else if(leftSide == rightSide && leftNode->subkind.exp == CallK && rightNode->subkind.exp == CallK){

                             TreeNode* lhs = (TreeNode*)symbolTable.lookup(t->child[0]->attr.name);
                             TreeNode* rhs = (TreeNode*)symbolTable.lookup(t->child[1]->attr.name);

                             if(lhs != NULL && rhs != NULL){

                                 if(lhs->subkind.decl == FuncK && rhs->subkind.decl == FuncK && !lhs->IOinit && !rhs->IOinit){
                                     if(t->child[0]->expType == Void && t->child[1]->expType == Void){
                                     printError(3, t->lineno, 0, t->attr.name, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                                     printError(4, t->lineno, 0, t->attr.name, ExpTypetwo(rightExpected), ExpTypetwo(rightSide), 0);
                                     }
                                     
                                 }

                             }
                        }
                        else{
                            
                            if(leftSide != leftExpected && !leftErr){

                               
                                if(leftSide == rightSide && t->child[0]->subkind.exp == CallK){
                                    ;
                                }
                                
                                else if(leftSide == Void && t->child[0]->subkind.exp == CallK && t->child[1]->subkind.exp != ConstantK){
                                    printError(3, t->lineno, 0, t->attr.name, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                                }
                                else if(leftSide != Void){
                                    printError(3, t->lineno, 0, t->attr.name, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                                }
                                
                            }

                            if(rightSide != rightExpected && !rightErr && rightSide != UndefinedType){

                                if(rightSide == Void && t->child[1]->subkind.exp == CallK && t->child[0]->subkind.exp != ConstantK){
                                    printError(4, t->lineno, 0, t->attr.name, ExpTypetwo(rightExpected), ExpTypetwo(rightSide), 0);
                                }
                                else if(rightSide != Void){
                                    printError(4, t->lineno, 0, t->attr.name, ExpTypetwo(rightExpected), ExpTypetwo(rightSide), 0);
                                }
                            }
                        }
                    }

                    if(leftArr || rightArr){

                        if(strcmp(t->attr.name, "<=") && leftExpected != UndefinedType){
                            if(!strcmp(t->attr.name, "<") || !strcmp(t->attr.name, ">") || !strcmp(t->attr.name, "=") || !strcmp(t->attr.name, "!>") || !strcmp(t->attr.name, "!<") || !strcmp(t->attr.name, "><")){
                         
                                 if(leftArr && !rightArr){
                                printError(5, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                }

                                else if(!leftArr && rightArr){
                                printError(6, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                }
                            }

                            else{
                            printError(7, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                            }
                        }
                        
                        else{
                            if(!strcmp(t->attr.name, "[")){
                                ;
                            }

                            else if((leftArr && !rightArr) || (!leftArr && rightArr)){

                                if(leftArr && !rightArr){
                                printError(5, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                }

                                else if(!leftArr && rightArr){
                                    printError(6, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                }
                            }
                        }
                    }
                }

            if(returnType != UndefinedType){
                t->expType = returnType;
            }
            else{
                t->expType = leftSide;
            }
            break;

        case ConstantK:
            for(int i = 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
            }
    
            if(range){
                   if(forloop){


                    if(t->expType != Integer)
                    {
                        char intExpect[] = "int";
                        printError(26, t->lineno, 0, intExpect, ExpTypetwo(t->expType), NULL, rangePos);
                    }
                   }
               }

            if(t->expType == CharInt){

                t->memT = Global;               
                t->mSize = t->arrLength + 1;
                t->mOffset = goffset - 1;
                goffset -= t->mSize;
            }

            break;

        case IdK:
            valFound = (TreeNode*)symbolTable.lookup(t->attr.name);

            if(valFound == NULL){

                if(range && rangePos == 1){
                    t->isDeclared = true;
                }

                else{
                    printError(1, t->lineno, 0, t->attr.name, NULL, NULL, 0); 
                    t->errDecl = true;    
                }           
            }

            else if(range){

                if(forloop){

                    t->isArray = valFound->isArray;
                    t->expType = valFound->expType;
                    t->mSize = valFound->mSize;
                    t->mOffset = valFound->mOffset;
                    t->memT = valFound->memT;

                    if(rangePos >= 1 && !valFound->isInit){
                        if(valFound->isDeclared == true){

                            if(!valFound->isInit && !valFound->warningReported && !valFound->isStatic && !valFound->isGlobal){

                                if(!t->isInit){
                                    valFound->warningReported = true;
                                    valFound->wasUsed = true;
                                    printError(18, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                }
                                
                                else{
                                    valFound->isInit = true;
                                }
                            }
                    
                        }
                    }

                    if(t->expType != Integer && rangePos >= 1)
                    {
                        if(!flagArraysize){

                            if(!strcmp(t->attr.name, "main")){
                                printError(12, t->lineno, 0, t->attr.name, NULL, NULL, 0);  
                            }
                            else{
                                char intExpect[] = "int";
                                printError(26, t->lineno, 0, intExpect, ExpTypetwo(t->expType), NULL, rangePos);
                            }
                        }

                    }


                    else if(rangePos > 1 && valFound->isInit){
                        valFound->wasUsed = true;
                    }

                    if(valFound->isArray && !flagArraysize && !t->arrayIndex ){
                        printError(24, t->lineno, 0, NULL, NULL, NULL, rangePos);
                    }

                    t->arrayIndex  = false;

                }

                t->isInit = true;
            }

            else{

                 if(valFound->isDeclared == true){
                
                 if(!valFound->isInit && !valFound->warningReported && !valFound->isStatic && !valFound->isGlobal){
                     if(!t->isInit){
                        valFound->warningReported = true;
                        printError(18, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                     }
                     else{
                         valFound->isInit = true;
                     }
                 }
                 }

                if(valFound->subkind.decl == FuncK){
                    printError(12, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                    valFound->wasUsed = true;
                    break;
                }
                else{
                    t->isGlobal = valFound->isGlobal;
                    t->isStatic = valFound->isStatic;
                    t->expType = valFound->expType;
                    t->isArray = valFound->isArray;    
                    t->mSize = valFound->mSize;
                    t->mOffset = valFound->mOffset;
                    t->memT = valFound->memT;

                    if(!range && valFound->subkind.decl != FuncK){
                    valFound->wasUsed = true;
                    }
                }

                if(t->child[0] != NULL){
                    check(t->child[0], nErrors, nWarnings);
                    
                    if(!t->isArray){

                        break;
                    }

                    if(t->child[0]->expType == Void && !(t->child[0]->nodekind == ExpK && t->child[0]->subkind.exp == CallK)){

                        break;
                    }

                    else{

                        if(t->child[0]->expType != Integer){
                            printError(14, t->lineno, 0, t->attr.name, ExpTypetwo(t->child[0]->expType), NULL, 0);
                        }
 
                        if(t->child[0]->isArray && t->child[0]->child[0] == NULL){
                            printError(13, t->lineno, 0, t->child[0]->attr.name, NULL, NULL, 0);
                        }
                    }
                }
            }
            break;

        case CallK:
            int paramCount = 1;
            TreeNode* funcFound;

            if(t->subkind.exp == CallK){
                funcFound = (TreeNode*)symbolTable.lookup(t->attr.name);
                if(funcFound == NULL){
                    printError(1, t->lineno, 0, t->attr.name, NULL, NULL, 0);  
                        t->errDecl = true; 
                }
                else{
                   
                }
            }

             for(int i = 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
                }

            if(funcFound != NULL){
                t->isGlobal = funcFound->isGlobal;
                t->isStatic = funcFound->isStatic;
                t->expType = funcFound->expType;
                t->isArray = funcFound->isArray;             
                funcFound->wasUsed = true;
                t->mSize = funcFound->mSize;
                t->mOffset = funcFound->mOffset;
                t->memT = funcFound->memT;

                if(funcFound->subkind.decl != FuncK){
                    printError(11, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                }
                
                else if(range){

                    if(forloop){

                        if(t->expType != Integer)
                        {

                            if(!strcmp(t->attr.name, "main")){
                                printError(12, t->lineno, 0, t->attr.name, NULL, NULL, 0);                               
                            }

                            else{
                                char intExpect[] = "int";
                                printError(26, t->lineno, 0, intExpect, ExpTypetwo(t->expType), NULL, rangePos);
                            }
                        }
                    }
                }

                else{

                    if(funcFound->child[0] != NULL && t->child[0] != NULL){
                       errorsParam(funcFound, t, funcFound->child[0], t->child[0], paramCount);
                    }

                    else if(funcFound->child[0] != NULL && t->child[0] == NULL){
                        printError(37, t->lineno, funcFound->lineno, t->attr.name, NULL, NULL, 0);
                    }

                    else if(funcFound->child[0] == NULL && t->child[0] != NULL){
                        printError(38, t->lineno, funcFound->lineno, t->attr.name, NULL, NULL, 0);
                    }

                }
            }
      
            break;        
    }

}

//function gets all expected types. 
void getExpTypes(const char* strng, bool isBinary, bool &unaryErrors, ExpType &left, ExpType &right, ExpType &rightT){

    std::string unaryOps[6] = {"not", "*", "?", "-", "--", "++"};

    std::string binaryOps[18] = {"+", "-", "*", "/", "%", "+=", "-=", "*=", "/=", ">", "<", "!<", "!>", "==", "!=", "=", "and", "or"};
    std::string op(strng);
    unaryErrors = false;

    if(!isBinary){

        for(int i = 0; i < 6; i++){

            if(op == unaryOps[i]){

                if(i == 0){
                    left = right = rightT = Boolean;
                }

                if(i == 1){
                    left = right = UndefinedType;
                    rightT = Integer;
                }

                if(i >= 2){
                    left = right = rightT = Integer;
                }
            }
        }
    }
    else{

        for(int i = 0; i < 18; i++){

            if(op == binaryOps[i]){

                if(i >= 0 && i <= 8){
                    left = right = rightT = Integer;
                    unaryErrors = true;
                }
  
                if(i >= 9 && i <= 12){
                    left = right = CharInt; 
                    rightT = Boolean;
                }

                if(i >= 13 && i <=14){
                    left = right = UndefinedType;
                    rightT = Boolean;
                }

                if(i == 15){
                    left = right = UndefinedType;
                    rightT = Boolean;
                }

                if(i >= 16){
                    left = right = rightT = Boolean;
                    unaryErrors = true;
                }

            }
        }
    }

}

//Second exptype print statment function(other one is in tree.c) returns exptype.
char* ExpTypetwo(ExpType type){
    switch(type){
       
        case Void:
            return strdup("void");
        case Integer:
            return strdup("int");
        case Boolean:
            return strdup("bool");
        case Char:
            return strdup("char");
        case CharInt:
            return strdup("CharInt");
        case Equal:
            return strdup("Equal");
        case UndefinedType:
            return strdup("undefined type");
        default:
            return strdup("expType not found\n");
    }
}

//Returns the returntype of opk. 
void getReturnType(const char* strng, bool isBinary, ExpType &rightT){

    std::string unaryOps[6] = {"not", "*", "?", "-", "--", "++"};

    std::string binaryOps[18] = {"+", "-", "*", "/", "%", "+=", "-=", "*=", "/=", ">", "<", "!<", "!>", "==", "!=", "=", "and", "or"};
    std::string op(strng);

    if(!isBinary){

        for(int i = 0; i < 6; i++){

            if(op == unaryOps[i]){

                if(i == 0){
                    rightT = Boolean;
                }
                
                if(i == 1){
                    
                    rightT = Integer;
                }

                if(i >= 2){
                    rightT = Integer;
                }
            }
        }
    }
    else{

        for(int i = 0; i < 18; i++){

            if(op == binaryOps[i]){

                if(i >= 0 && i <= 8){
                    rightT = Integer;
                }

                if(i >= 9 && i <= 12){
                    rightT = Boolean;
                }

                if(i >= 13 && i <=14){
                    rightT = Boolean;
                }

                if(i == 15){
                    rightT = Boolean;
                }

                if(i >= 16){
                    rightT = Boolean;
                }

            }
        }
    }

}

//prints all errors based on the error code.
void printError(int errCode, int lineno, int reasonNum, char* s1, char* s2, char* s3, int i){

    if(errCode > 16 && errCode < 22){
        nWarnings++;
    }
    else{
        nErrors++;
    }

    
    switch(errCode){

        case 0: 
            sprintf(Buffer, "ERROR(%d): Symbol '%s' is already declared at line %d.\n", lineno, s1, reasonNum);
            break;

        case 1:
            sprintf(Buffer, "ERROR(%d): Symbol '%s' is not declared.\n", lineno, s1);
            break;

        case 2: 
            sprintf(Buffer, "ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is type %s.\n", lineno, s1, s2, s3);
            break;

        case 3:
            sprintf(Buffer, "ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", lineno, s1, s2, s3);
            break;

        case 4:
            sprintf(Buffer, "ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", lineno, s1, s2, s3);
            break;

        case 5: 
            sprintf(Buffer, "ERROR(%d): '%s' requires both operands be arrays or not but lhs is an array and rhs is not an array.\n", lineno, s1);
            break;

        case 6:
            sprintf(Buffer, "ERROR(%d): '%s' requires both operands be arrays or not but lhs is not an array and rhs is an array.\n", lineno, s1);
            break;

        case 7: 
            sprintf(Buffer, "ERROR(%d): The operation '%s' does not work with arrays.\n", lineno, s1);
            break;

        case 8: 
            sprintf(Buffer, "ERROR(%d): The operation '%s' only works with arrays.\n", lineno, s1);
            break;

        case 9:
            sprintf(Buffer, "ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", lineno, s1, s2, s3);
            break;

        case 10: 
            sprintf(Buffer, "ERROR(%d): Cannot return an array.\n", lineno);
            break;

        case 11: 
            sprintf(Buffer, "ERROR(%d): '%s' is a simple variable and cannot be called.\n", lineno, s1);
            break;

        case 12:
            sprintf(Buffer, "ERROR(%d): Cannot use function '%s' as a variable.\n", lineno, s1);
            break;

        case 13:
            sprintf(Buffer, "ERROR(%d): Array index is the unindexed array '%s'.\n", lineno, s1);
            break;

        case 14: 
            sprintf(Buffer, "ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", lineno, s1, s2);
            break;

        case 15: 
            sprintf(Buffer, "ERROR(%d): Cannot index nonarray '%s'.\n", lineno, s1);
            break;

        case 16: 
            sprintf(Buffer, "ERROR(LINKER): A function named 'main' with no parameters must be defined.\n");
            break;

        case 17: 
            sprintf(Buffer, "WARNING(%d): The variable '%s' seems not to be used.\n", lineno, s1);
            break;

        case 18:
            sprintf(Buffer, "WARNING(%d): Variable '%s' may be uninitialized when used here.\n", lineno, s1);
            break;

        case 19: 
            sprintf(Buffer, "WARNING(%d): Expecting to return type %s but function '%s' has no return statement.\n", lineno, s1, s2);
            break;

        case 20:
            sprintf(Buffer, "WARNING(%d): The parameter '%s' seems not to be used.\n", lineno, s1);
            break;
            
        case 21:
            sprintf(Buffer, "WARNING(%d): The function '%s' seems not to be used.\n", lineno, s1);
            break;

        case 22: 
            sprintf(Buffer, "ERROR(%d): Cannot have a break statement outside of loop.\n", lineno);
            break;

        case 23:
            sprintf(Buffer, "ERROR(%d): Cannot use array as test condition in %s statement.\n", lineno, s1);
            break;

        case 24:
            sprintf(Buffer, "ERROR(%d): Cannot use array in position %d in range of for statement.\n", lineno, i);
            break;

        case 25:
            sprintf(Buffer, "ERROR(%d): Expecting type %s in parameter %d of call to '%s' declared on line %d but got type %s.\n", lineno, s2, i, s1, reasonNum, s3);
            break;

        case 26:
            sprintf(Buffer, "ERROR(%d): Expecting type %s in position %d in range of for statement but got type %s.\n", lineno, s1, i, s2);
            break;

        case 27:
            sprintf(Buffer, "ERROR(%d): Expecting Boolean test condition in %s statement but got type %s.\n", lineno, s1, s2);
            break;

        case 28:
            sprintf(Buffer, "ERROR(%d): Expecting array in parameter %d of call to '%s' declared on line %d.\n", lineno, i, s1, reasonNum);
            break;

        case 29:
            sprintf(Buffer, "ERROR(%d): Function '%s' at line %d is expecting no return value, but return has a value.\n", lineno, s1, reasonNum);
            break;

        case 30:
            sprintf(Buffer, "ERROR(%d): Function '%s' at line %d is expecting to return type %s but return has no value.\n", lineno, s1, reasonNum, s2);
            break;

        case 31:
            sprintf(Buffer, "ERROR(%d): Function '%s' at line %d is expecting to return type %s but returns type %s.\n", lineno, s1, reasonNum, s2, s3);
            break;

        case 32:
            sprintf(Buffer, "ERROR(%d): Initializer for variable '%s' is not a constant expression.\n", lineno, s1);
            break;

        case 33:
            sprintf(Buffer, "ERROR(%d): Initializer for variable '%s' of type %s is of type %s\n", lineno, s1, s2, s3);
            break;

        case 34:
            sprintf(Buffer, "ERROR(%d): Initializer for variable '%s' requires both operands be arrays or not but variable is not an array and rhs is an array.\n", lineno, s1);
            break;

        case 35:
            sprintf(Buffer, "ERROR(%d): Initializer for variable '%s' requires both operands be arrays or not but variable is an array and rhs is not an array.\n", lineno, s1);
            break;
        
        case 36:
            sprintf(Buffer, "ERROR(%d): Not expecting array in parameter %d of call to '%s' declared on line %d.\n", lineno, i, s1, reasonNum);
            break;

        case 37:
            sprintf(Buffer, "ERROR(%d): Too few parameters passed for function '%s' declared on line %d.\n", lineno, s1, reasonNum);
            break;

        case 38:
            sprintf(Buffer, "ERROR(%d): Too many parameters passed for function '%s' declared on line %d.\n", lineno, s1, reasonNum);
    }

    symErrors all;
    all.lineno = lineno;
    all.errorMsg = strdup(Buffer);
    errBuffer.push_back(all);
}







