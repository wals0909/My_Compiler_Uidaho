/* Riley Walsh
*  CS445
*  Spring 2023
*/ 

#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"
#include "symbolTable.h"

void generateCode(TreeNode *t, char* infile);
void emitInfo(char* infile);
void emitBegin(TreeNode* t);
void emitInput(TreeNode *t);
void emitStaticGlobal(TreeNode* t);
void emitIO(TreeNode *t);
void emitInit(TreeNode *t);
void emitDecl(TreeNode *t);
void emitExp(TreeNode *t);
void emitStmt(TreeNode *t);


#endif