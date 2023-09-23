

#ifndef SEMANTIC 
#define SEMANTIC

#include "tree.h"
#include "symbolTable.h"
#include "scanType.h"

SymbolTable returnSymbolTable();
void check(TreeNode *t, int& nErrors, int& nWarnings);
void semanticAnalysis(TreeNode *t, int& errors, int& warnings);
void Warninit(std::string, void*);
void errorsArray(TreeNode *t);
void errorsParam(TreeNode *funcFound, TreeNode *t, TreeNode *ffParm, TreeNode *tParm, int paramCount);
void checkDecl(TreeNode *t, int& nErrors, int& nWarnings);
void recursiveASSK(TreeNode *c1);
void recursiveOps(TreeNode *t, TreeNode* child);
void checkStmt(TreeNode *t, int& nErrors, int& nWarnings);
void checkExp(TreeNode *t, int& nErrors, int& nWarnings);
void getExpTypes(const char* string, bool isBinary, bool &unaryErrors, ExpType &left, ExpType &right, ExpType &rightT);
char* ExpTypetwo(ExpType type);
void getReturnType(const char* string, bool isBinary, ExpType &childReturnType);
void printError(int errCode, int linenum, int explaineno, char* s1, char* s2, char* s3, int i);

#endif