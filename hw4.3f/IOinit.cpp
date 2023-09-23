#include "IOinit.h"
#include "symbolTable.h"
#include "semantic.h"
#include "tree.h"
#include "scanType.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

extern SymbolTable symbolTable;

//Function returns a newIOnode. 
TreeNode *newIOnode(DeclKind kind){
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;

    for(i = 0; i<MAXCHILDREN; i++){
        t->child[i] = NULL;
        t->sibling = NULL;
        t->expType = Void;
        t->nodekind = DeclK;
        t->subkind.decl = kind;
    }

    return t;
}
//Function to initialize IO routine checks.
void InitializeIO(){

   std::string nameIO[] = {"output", "outputb", "outputc", "input", "inputb", "inputc", "outnl"};
   ExpType paramIO[] = {Integer, Boolean, Char, Void, Void, Void, Void};
   ExpType expTypeIO[] = {Void, Void, Void, Integer, Boolean, Char, Void};
   
   TreeNode* SetupIOnode; 
   TreeNode* temp;

   for(int i = 0; i < 7; i++){

       SetupIOnode = newIOnode(FuncK);
       SetupIOnode->attr.name = strdup(nameIO[i].c_str());
       SetupIOnode->lineno = -1;
       SetupIOnode->expType = expTypeIO[i];
       SetupIOnode->isDeclared = true;
       SetupIOnode->isInit = true;
       SetupIOnode->wasUsed = true;
       SetupIOnode->IOinit = true;

       symbolTable.insert(SetupIOnode->attr.name, (TreeNode*) SetupIOnode);

       if(paramIO[i] != Void){
           temp = newIOnode(ParamK);
           temp->attr.name = strdup("dummy");
           temp->lineno = -1;
           temp->expType - paramIO[i];
           SetupIOnode->child[0] = temp;
       }
       else{
           SetupIOnode->child[0] = NULL;
       }
   }
   

}

