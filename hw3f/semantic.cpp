
/* Riley Walsh
*  CS445
*  Spring 2023
*/ 

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
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

TreeNode *temp = NULL;

ExpType functionReturnType;
SymbolTable symbolTable;

//function returns symbol table
SymbolTable returnSymbolTable() {
    return symbolTable;
}

//function prints error messages. 
void printErrorss(){
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
        printErrors(16, 0, 0, NULL, NULL, NULL, 0);
    }
    else if(mainCheck != NULL){
        if(mainCheck->nodekind == DeclK && mainCheck->subkind.decl != FuncK){
            printErrors(16, 0, 0, NULL, NULL, NULL, 0);
            
        }
        else if(mainCheck->child[0] != NULL && mainCheck->child[0]->subkind.decl == ParamK){
            printErrors(16, 0, 0, NULL, NULL, NULL, 0);
        }
    }

    printErrorss();
    errors = nErrors;
    warnings = nWarnings;
}

//function checks to see if warnings were used. 
void Warninit(std::string symbol, void* t){

    TreeNode* currentNode;

    currentNode = (TreeNode *)symbolTable.lookup(symbol.c_str());       

    if(!currentNode->wasUsed && !currentNode->isGlobal){
        printErrors(17, currentNode->lineno, 0, currentNode->attr.name, NULL, NULL, 0);
    }
}

bool compare(const symErrors& f, const symErrors& s){
    return f.lineno < s.lineno;
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
         printErrors(15, t->lineno, 0, t->child[0]->attr.name, NULL, NULL, 0);
      }
   }
   else
   {
      printErrors(15, t->lineno, 0, t->child[0]->attr.name, NULL, NULL, 0);
   }
   if(t->child[1] != NULL)
   {
      if(t->child[1]->expType != Integer && t->child[1]->expType != UndefinedType)
      {
         printErrors(14, t->lineno, 0, t->child[0]->attr.name, ExpTypetwo(t->child[1]->expType), NULL, 0);
      }
   }
   if(t->child[1] != NULL && t->child[1]->subkind.exp == IdK)
   {
      if(rightNode != NULL && rightNode->isArray == true)
      {
         printErrors(13, t->lineno, 0, rightNode->attr.name, NULL, NULL, 0); //
      }
      if(rightNode != NULL)
      {
         t->child[1]->expType = rightNode->expType;
      }
   }

}

//function checks declaration nodes
void checkDecl(TreeNode *t, int& nErrors, int& nWarnings){

    if(symbolTable.depth() == 1){
        t->isGlobal = true;
    }
    else{
        t->isGlobal = false;
    }

    TreeNode *declared;
    if(t->subkind.decl != VarK && !symbolTable.insert(t->attr.name, t)){
        declared = (TreeNode*)symbolTable.lookup(t->attr.name);
        printErrors(0, t->lineno, declared->lineno, t->attr.name, NULL, NULL, 0);
    }

    switch(t->subkind.decl){
            
        case VarK:

            if(t->child[0] != NULL){
            for(int i = 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
            } 
            }      

           if(t->sibling != NULL){
                if(t->isStatic && t->lineno == t->sibling->lineno){
                    t->sibling->isStatic = t->isStatic;
                }
            }    
           
           if(!symbolTable.insert(t->attr.name, t)){
               TreeNode* exists = (TreeNode*)symbolTable.lookup(t->attr.name);
               printErrors(0, t->lineno, exists->lineno, t->attr.name, NULL, NULL, 0);
           }

        if(t->child[0] != NULL){

            if(t->expType != t->child[0]->expType){

                    if(t->expType == Char && t->child[0]->expType == CharInt){
                        ; // do nothing
                    }
            }
             else if(t->child[0]->expType == Void && t->child[0]->subkind.exp == IdK){
                       //do nothing 
                    }

             t->isInit = true;
             t->isDeclared = true;
        }
          else{
               t->isDeclared = true;
           }

           break;

        case FuncK:

            temp = t;
            symbolTable.enter(t->attr.name);

            scopeDepth = false;
            functionReturnType = t->expType;
            
            for(int i = 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
            }

            symbolTable.applyToAll(Warninit);
            symbolTable.leave();

            temp = NULL;

            break;
        
        case ParamK:
    
            for(int i = 0; i < MAXCHILDREN; i++){
                
                check(t->child[i], nErrors, nWarnings);
                if(t->child[0] != NULL){
                    t->child[0]->isInit = true;
                }
            }
            t->isInit = true;
            break;

    }
}

//Function checks statement nodes
void checkStmt(TreeNode *t, int& nErrors, int& nWarnings){

    switch(t->subkind.stmt){
        case IfK:
            loop = true;
            symbolTable.enter(t->attr.name);
            scopeDepth = false;
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[0]){
                check(t->child[i], nErrors, nWarnings);
                }
            }
            loop = false;
            symbolTable.leave();
            scopeDepth = true;
            break;

        case ForK:
            loop = true;
            symbolTable.enter(t->attr.name);
            scopeDepth = false;

            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                check(t->child[i], nErrors, nWarnings);
                
                t->child[0]->isInit = true;
                t->child[1]->isInit = true;
                }
            }
                loop = false;
                symbolTable.applyToAll(Warninit);
                symbolTable.leave();
                scopeDepth = true;
            break;
       
        case WhileK:
            loop = true;
            symbolTable.enter(t->attr.name);
            scopeDepth = false;
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                check(t->child[i], nErrors, nWarnings);
                }
            }
                loop = false;
                symbolTable.applyToAll(Warninit);
                symbolTable.leave();
                scopeDepth = true;

            break;

        case ReturnK:
            check(t->child[0], nErrors, nWarnings);
            if(t->child[0] != NULL){
    
                if(temp == NULL){
                    break;
                }
                else{
                    if(t->child[0]->isArray){
                        printErrors(10, t->lineno, 0, NULL, NULL, NULL, 0);
                    }
                }
            }
            break;

        case BreakK:
            break;

        case RangeK:
            range = true;
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                    check(t->child[i], nErrors, nWarnings);
                }
            }

            range = false;

            break;

        case CompoundK:
            bool keepCurScope = scopeDepth;
            if(keepCurScope){
                symbolTable.enter("compound");
            }
            else{
                scopeDepth = true;
            }

            for(int j = 0; j < MAXCHILDREN; j++){
                check(t->child[j], nErrors, nWarnings);
            }

            if(keepCurScope){
                symbolTable.applyToAll(Warninit);
                symbolTable.leave();
            }

            break;

    }

}

//function checks expression nodes. 
void checkExp(TreeNode *t, int& nErrors, int& nWarnings){

    bool leftStr, rightStr, isBinary, leftArr, rightArr, leftIndx, rightIndx, leftInit, leftDecl, rightInit, rightDecl, throwError;
    leftStr = rightStr = isBinary = leftArr = rightArr = leftIndx = rightIndx = leftInit = leftDecl = rightInit = rightDecl = throwError = false;

    ExpType leftSide, rightSide, returnType, leftExpected, rightExpected;
    leftSide = rightSide = returnType = leftExpected = rightExpected = UndefinedType;

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
                                  
          
                    if(t->child[0]->child[0]!=NULL && !strcmp(t->child[0]->attr.name, "[" )){
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
                            }
                        }
                 
                        else{
                        //do nothing 
                        }
                    }
                   
                    else {
                        t->child[0]->isInit = true;
                    }
                }

            }

            if(strcmp(t->attr.name, "<=")){
                if(t->child[0] != NULL){
                    t->child[0]->wasUsed = true;
                    
                }
                if(t->child[1] != NULL){
                    t->child[1]->wasUsed = true;
                }
            }

            for(int i= 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
            }

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
                        printErrors(9, t->lineno, 0, uMinus, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                    }

                    else{
                        printErrors(9, t->lineno, 0, t->attr.name, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                    }
                }

                else if(!strcmp(t->attr.name, "not") && leftSide != leftExpected){

                    printErrors(9, t->lineno, 0, t->attr.name, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                }

                else if(!strcmp(t->attr.name, "*") && (!leftArr && leftSide != UndefinedType)){
                    char uSizeof[] = "sizeof";
                    printErrors(8, t->lineno, 0, uSizeof, NULL, NULL, 0);
                } 

                if(leftArr){
                    if(strcmp(t->attr.name, "*") != 0){

                        if(!strcmp(t->attr.name, "-")){
                            char uMinus[] = "chsign";
                            printErrors(7, t->lineno, 0, uMinus, NULL, NULL, 0);
                        }
                        else{
                            printErrors(7, t->lineno, 0, t->attr.name, NULL, NULL, 0);
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
                                 printErrors(2, t->lineno, 0, t->attr.name, ExpTypetwo(leftSide), diffCharInt, 0);
                            }
                            else if(!strcmp(ExpTypetwo(leftSide), "char") && !strcmp(ExpTypetwo(rightSide), "CharInt")){
                                ; //do nothing
                            }
                            else{
                                 printErrors(2, t->lineno, 0, t->attr.name, ExpTypetwo(leftSide), ExpTypetwo(rightSide), 0);
                            }
                        }
                    }

                    if(!(leftExpected == UndefinedType || rightExpected == UndefinedType)){
                        
                        if(leftExpected == CharInt || rightExpected == CharInt){
                            ;
                        }
                        else{
                            if(leftSide != leftExpected && !leftErr){
                                printErrors(3, t->lineno, 0, t->attr.name, ExpTypetwo(leftExpected), ExpTypetwo(leftSide), 0);
                            }
                            if(rightSide != rightExpected && !rightErr && rightSide != UndefinedType){
                                printErrors(4, t->lineno, 0, t->attr.name, ExpTypetwo(rightExpected), ExpTypetwo(rightSide), 0);
                            }
                        }
                    }


                    if(leftArr || rightArr){
   
                        if(strcmp(t->attr.name, "!>") && leftExpected != UndefinedType){
                            if(!strcmp(t->attr.name, "<") || !strcmp(t->attr.name, ">") || !strcmp(t->attr.name, "=") || !strcmp(t->attr.name,"!<") || !strcmp(t->attr.name, "<=") || !strcmp(t->attr.name, "><")){

                                 if(leftArr && !rightArr){
                                printErrors(5, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                }
                                else if(!leftArr && rightArr){
                                
                                printErrors(6, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                }
                            }

                            else{
                            printErrors(7, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                            }
                        }
                        
                        else{
                            if(!strcmp(t->attr.name, "[")){
                                ;
                            }
                            else if((leftArr && !rightArr) || (!leftArr && rightArr)){
                                if(leftArr && !rightArr){
                                printErrors(5, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                                }
                                else if(!leftArr && rightArr){
                                  
                                    printErrors(6, t->lineno, 0, t->attr.name, NULL, NULL, 0);
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

        case IdK:
            valFound = (TreeNode*)symbolTable.lookup(t->attr.name);

            if(valFound == NULL){

                if(range){
                    t->isDeclared = true;
                }
                else{
                printErrors(1, t->lineno, 0, t->attr.name, NULL, NULL, 0);     
                }           
            }
            else if(range){
                t->isInit = true;
            }

            else{

                 if(valFound->isDeclared == true){
                    
                 if(!valFound->isInit && !valFound->warningReported && !valFound->isStatic && !valFound->isGlobal){
                     if(!t->isInit){
                        valFound->warningReported = true;
  
                        printErrors(18, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                     }
                     else{
                         valFound->isInit = true;
                     }
                 }
                 }

                if(valFound->subkind.decl == FuncK){
                    printErrors(12, t->lineno, 0, t->attr.name, NULL, NULL, 0);

                    break;
                }
                else{

                    t->expType = valFound->expType;
                    t->isArray = valFound->isArray;
                    t->isGlobal = valFound->isGlobal;
                    t->isStatic = valFound->isStatic;
          
                    if(!range){
                    valFound->wasUsed = true;
                    }
                }


                if(t->child[0] != NULL){
                    check(t->child[0], nErrors, nWarnings);
                    if(t->child[0]->expType == Void && !(t->child[0]->nodekind == ExpK && t->child[0]->subkind.exp == CallK)){

                        break;
                    }
                    if(!t->isArray){
                    
                        break;
                    }
                    else{

                        if(t->child[0]->expType != Integer){
                            printErrors(14, t->lineno, 0, t->attr.name, ExpTypetwo(t->child[0]->expType), NULL, 0);
                        }
          
                        if(t->child[0]->isArray && t->child[0]->child[0] == NULL){
                            printErrors(13, t->lineno, 0, t->child[0]->attr.name, NULL, NULL, 0);
                        }
                    }
                }
            }
            break;

        case ConstantK:
            for(int i = 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
            }
            break;

        case CallK:
            TreeNode* funcFound;
         
            if(t->subkind.exp == CallK){
                funcFound = (TreeNode*)symbolTable.lookup(t->attr.name);
                if(funcFound == NULL){
                    printErrors(1, t->lineno, 0, t->attr.name, NULL, NULL, 0);   
                }
            }
            

            for(int i = 0; i < MAXCHILDREN; i++){
                check(t->child[i], nErrors, nWarnings);
 
            }

            if(funcFound != NULL){
                t->expType = funcFound->expType;
                t->isArray = funcFound->isArray;
                t->isGlobal = funcFound->isGlobal;
                t->isStatic = funcFound->isStatic;
                funcFound->wasUsed = true;

                if(funcFound->subkind.decl != FuncK){
                    printErrors(11, t->lineno, 0, t->attr.name, NULL, NULL, 0);
                }
            }
      
            break;        
    }

}

//function gets all expected types. 
void getExpTypes(const char* strng, bool isBinary, bool &unaryErrors, ExpType &left, ExpType &right, ExpType &rightT){

    std::string unaryOps[6] = {"not", "*", "?", "-", "--", "++"};

    std::string binaryOps[18] = {"+", "-", "*", "/", "%", "+=", "-=", "*=", "/=", ">", "<", "!<","!>", "==", "!=", "=", "and", "or"};
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
                    left = right = rightT = UndefinedType;
                }
                if(i >= 16){
                    left = right = rightT = Boolean;
                    unaryErrors = true;
                }

            }
        }
    }

}

//function returns all expected types.
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

//prints all errors based on the error code.
void printErrors(int errCode, int lineno, int explaineno, char* s1, char* s2, char* s3, double d){

    if(errCode > 16){
        nWarnings++;
    }
    else{
        nErrors++;
    }

    switch(errCode){

       
        case 0: 
            sprintf(Buffer, "ERROR(%d): Symbol '%s' is already declared at line %d.\n", lineno, s1, explaineno);
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
            sprintf(Buffer, "ERROR(LINKER): A function named 'main()' must be defined.\n");
            break;

     
        case 17: 
            sprintf(Buffer, "WARNING(%d): The variable '%s' seems not to be used.\n", lineno, s1);
            break;

        case 18:
            sprintf(Buffer, "WARNING(%d): Variable '%s' may be uninitialized when used here.\n", lineno, s1);
            break;
    }


    symErrors all;
    all.lineno = lineno;
    all.errorMsg = strdup(Buffer);
    errBuffer.push_back(all);
}

