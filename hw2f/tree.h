
#define MAXCHILDREN 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "scanType.h"

// Kind of Operators
// these are the token numbers for the operators same as in flex
typedef int OpKind;

// Kind of statments
typedef enum {DeclK, StmtK, ExpK} NodeKind;
//enum NodeKind {DeclK, StmtK, ExpK};

// Subkinds of Declarations
typedef enum {VarK, FuncK, ParamK} DeclKind;

//Subkinds of Statements
typedef enum {NullK, IfK, WhileK, ForK, CompoundK, ReturnK, BreakK, RangeK} StmtKind;

//Subkinds of Expressions
typedef enum {OpK, ConstantK, IdK, AssignK, InitK, CallK} ExpKind;

// ExpType is used for type checking (void means no type or value, undedfined type means undefined)
typedef enum {Void, Integer, Boolean, Char, CharInt, Equal, UndefinedType} ExpType;

//What kind of Scoping is used? (decided during typing)
typedef enum {None, Local, Global, Parameter, LocalStatic} VarKind;

typedef struct treeNode{
    // connectivity in the tree
    struct treeNode *child[MAXCHILDREN];        // children of the node
    struct treeNode *sibling;                   // siblings for the node

    //what kind of node
    int lineno;                                 // lineno relevant to this node
    NodeKind nodekind;                          // type of this node

    union                                       //subtype of type
    {
        DeclKind decl;                          // used when DeclK
        StmtKind stmt;                          // used when StmtK
        ExpKind exp;                            // used when ExpK
    } subkind;

    union                                       // relevant data to type -> attr
    {
        OpKind op;                              // type of token (same as in bison)
        int value;                              // used when an integer constant or boolean
        unsigned char cvalue;                   // used when a character
        char *string;                           // used when a string constant
        char *name;                             // used when IdK
    } attr;
       
    ExpType expType;                            // used when ExpK for type checking
    bool isArray;                               // is this an array
    bool isStatic;                              // is staticly allocated
    const char * varType;

} TreeNode;

// tree functions
TreeNode *addSibling(TreeNode *t, TreeNode *s);
void setType(TreeNode *t, ExpType type);
TreeNode *newDeclNode(DeclKind kind, TokenData* token);
TreeNode *newStmtNode(StmtKind kind, TokenData* token);
TreeNode *newExpNode(ExpKind kind, TokenData* token); 
void printTree(TreeNode *t, int nSiblings);
void printWhiteSpace(int WS);
