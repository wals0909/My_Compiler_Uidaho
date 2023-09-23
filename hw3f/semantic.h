/* Riley Walsh
*  CS445
*  Spring 2023
*/ 

#ifndef SEMANTIC 
#define SEMANTIC

#include "tree.h"
#include "symbolTable.h"
#include "scanType.h"

SymbolTable returnSymbolTable();
void check(TreeNode *t, int& nErrors, int& nWarnings);
void semanticAnalysis(TreeNode *t, int& errors, int& warnings);
void Warninit(std::string, void*);
void arrayErrors(TreeNode *t);
void checkDecl(TreeNode *t, int& nErrors, int& nWarnings);
void checkStmt(TreeNode *t, int& nErrors, int& nWarnings);
void checkExp(TreeNode *t, int& nErrors, int& nWarnings);
void getExpTypes(const char* string, bool isBinary, bool &unaryErrors, ExpType &left, ExpType &right, ExpType &rightT);
char* ExpTypetwo(ExpType type);
void printErrors(int errCode, int linenum, int explaineno, char* s1, char* s2, char* s3, double d);

#endif