
#include "tree.h"
#include "scanType.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int WSC = 0;

// Function Adds a TreeNode to a list of siblings.
TreeNode *addSibling(TreeNode *t, TreeNode *s){
    
    if (t!=NULL) {
        TreeNode *tmp;
        
        tmp = t;
        while (tmp->sibling!=NULL) tmp = tmp->sibling;
        tmp->sibling = s;
        return t;
    }
    return s;

    if(t == NULL){
        return s;   
    }
    else if(s == NULL){
        return t;
    }
}

// Function Passes the type attributes down the sibling list.
void setType(TreeNode *t, ExpType type){

    while (t != NULL) {
        t->expType = type;
        t = t->sibling;
    }

}

/* Function newDeclNode creates a new declaration
 * node for syntax tree construction
 */
TreeNode *newDeclNode(DeclKind kind, TokenData* token){
    TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if( t==NULL){
        printf("Out of memory error at line %d\n", token->lineno);
    }
    else{
        for(i=0; i<MAXCHILDREN; i++){
            t->child[i] = NULL;
            t->sibling = NULL;
            t->nodekind = DeclK;
            t->subkind.decl = kind;
            t->lineno = token->lineno;
            t->expType = Void;
            t->attr.name = strdup(token->tokenstr);
        }
    }

    return t;
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode *newStmtNode(StmtKind kind, TokenData *token){
    TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if( t==NULL){
        printf("Out of memory error at line %d\n", token->lineno);
    }
    else{
        for(i=0; i<MAXCHILDREN; i++){
            t->child[i] = NULL;
            t->sibling = NULL;
            t->nodekind = StmtK;
            t->subkind.stmt = kind;
            t->lineno = token->lineno;
            t->expType = Void;
            t->attr.name = strdup(token->tokenstr);
        }
    }

    return t;
}

/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode *newExpNode(ExpKind kind, TokenData *token){
    TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if( t==NULL){
        printf("Out of memory error at line %d\n", token->lineno);
    }  
    else{
        for(i=0; i<MAXCHILDREN; i++){
            t->child[i] = NULL;
            t->sibling = NULL;
            t->nodekind = ExpK;
            t->subkind.exp = kind;
            t->lineno = token->lineno;
            t->expType = Void;
        }
    }

    return t;
}


// function to print Tree, uses some recursion 
void printTree(TreeNode *tree, int nsiblings){
   
    while(tree != NULL){
        switch(tree->nodekind){
            case DeclK:
                switch(tree->subkind.decl){

                    case FuncK:
                        switch(tree->expType){
                            case Void:
                                printf("Func: %s returns type void [line: %d]\n", tree->attr.name, tree->lineno);
                                break;
                            case Integer:
                                printf("Func: %s returns type int [line: %d]\n", tree->attr.name, tree->lineno);
                                break;
                            case Boolean:
                                printf("Func: %s returns type bool [line: %d]\n", tree->attr.name, tree->lineno);
                                break;
                            case Char:
                                printf("Func: %s returns type char [line: %d]\n", tree->attr.name, tree->lineno);
                                break;
                            case CharInt:
                                printf("Func: %s returns type CharInt [line: %d]\n", tree->attr.name, tree->lineno);
                                break;
                            case Equal:
                                printf("Func: %s returns type Equal [line: %d]\n", tree->attr.name, tree->lineno);
                                break;
                            case UndefinedType:
                                printf("ERROR FUNC: Undefined Type [line: %d]\n",tree->lineno);
                                break;
                            default:
                                printf("ERROR FUNC: Undefined Type [line: %d]\n",tree->lineno);
                                break;
                        
                        }
                        break;

                    case ParamK:
                        switch(tree->expType){
                            case Integer:
                                if(tree->isArray){
                                    printf("Parm: %s of array of type int [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                    printf("Parm: %s of type int [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                break;
                            case Boolean:
                                if(tree->isArray){
                                    printf("Parm: %s of array of type bool [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                    printf("Parm: %s of type bool [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                break;
                            case Char:
                                if(tree->isArray){
                                    printf("Parm: %s of array of type char [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                    printf("Parm: %s of type char [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                break;
                            case CharInt:
                                if(tree->isArray){
                                printf("Parm: %s of array of CharInt [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                printf("Parm: %s of type CharInt [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                            case Equal:
                                if(tree->isArray){
                                printf("Parm: %s of array of type Equal [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                printf("Parm: %s of type Equal [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                            case UndefinedType:
                                printf("ERROR PARM: Undefined Type [line: %d]\n",tree->lineno);
                                break;
                            default:
                                printf("ERROR EXP: Default [line: %d]\n",tree->lineno);
                                break;
                                
                        }
                        break;

                    case VarK:
                        switch(tree->expType)
                        {   
                            case Integer:
                                if(tree->isArray){
                                    printf("Var: %s of array of type int [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else if(tree->isStatic){
                                    printf("Var: %s of static type int [line: %d]\n",tree->attr.name,tree->lineno);
                                 }
                                else{
                                    printf("Var: %s of type int [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                break;
                            case Boolean:
                                if(tree->isArray){
                                    printf("Var: %s of array of type bool [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                    printf("Var: %s of type bool [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                break;
                            case Char:
                                if(tree->isArray){
                                    printf("Var: %s of array of type char [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                    printf("Var: %s of type char [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                break;
                             case CharInt:
                                if(tree->isArray){
                                    printf("Var: %s of array of type charInt [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                    printf("Var: %s of type charInt [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                break;   
                             case Equal:
                                if(tree->isArray){
                                    printf("Var: %s of array of type Equal[line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                else{
                                    printf("Var: %s of type Equal [line: %d]\n", tree->attr.name, tree->lineno);
                                }
                                break;   
                            case UndefinedType:
                                printf("ERROR VAR: Undefined Type [line: %d]\n",tree->lineno);
                                break;
                            default:
                                printf("ERROR VAR: Default [line: %d]\n",tree->lineno);
                                break;
                            
                      
                        }
                        break; 
                        default:
                            printf("error\n");
                            break;

                }
                break;
            //beginning of my statements
            case StmtK:
                switch(tree->subkind.stmt){
                    
                    case IfK:
                        printf("If [line: %d]\n", tree->lineno);
                        break;

                    case WhileK:
                        printf("While [line: %d]\n", tree->lineno);
                        break;

                    case NullK:
                        printf("NULL [line: %d]\n", tree->lineno);
                        break;
                    
                    case ReturnK:
                        printf("Return [line: %d]\n", tree->lineno);
                        break;

                    case ForK:
                        printf("For [line: %d]\n", tree->lineno);
                        break;

                    case BreakK:
                        printf("Break [line: %d]\n", tree->lineno);
                        break;

                    case CompoundK:
                        printf("Compound [line: %d]\n", tree->lineno);
                        break;

                    case RangeK:
                        printf("Range [line: %d]\n", tree->lineno);
                        break;

                    default:
                        break;
                }
                break;

            case ExpK:
                switch(tree->subkind.exp){
                    case OpK:
                        if(tree->child[1] == NULL && !strcmp(tree->attr.name, "-")){
                            printf("Op: chsign [line: %d]\n", tree->lineno);
                        }
                        else if(tree->child[1] == NULL && !strcmp(tree->attr.name, "*")){
                            printf("Op: sizeof [line: %d]\n", tree->lineno);
                        }
                        else{
                            printf("Op: %s [line: %d]\n", tree->attr.name, tree->lineno);
                        }
                        break;
                        
                    case ConstantK:
                        switch (tree->expType){
                        case Integer:
                            printf("Const %d [line: %d]\n", tree->attr.value, tree->lineno);
                            break;
                        
                        case CharInt:
                            printf("Const %s [line: %d]\n", tree->attr.string, tree->lineno);
                            break;

                        case Char:
                            printf("Const \'%c\' [line: %d]\n",tree->attr.cvalue, tree->lineno);
                            break;

                        case Boolean:
                            printf("Const %s [line: %d]\n", tree->attr.name, tree->lineno);
                            break;

                        default:
                            break;

                        }
                        break;

                    case InitK:
                        break;

                    case IdK:
                        printf("Id: %s [line: %d]\n", tree->attr.name, tree->lineno);
                        break;

                    case AssignK:
                        printf("Assign: %s [line: %d]\n", tree->attr.name, tree->lineno);
                        break; 

                    case CallK:
                        printf("Call: %s [line: %d]\n", tree->attr.name, tree->lineno);
                        break;

                    default:
                        printf("ERROR %i Unknown ExpNode subkind Line: %d\n", CallK, tree->lineno);
                        break;
                }
                break;

            default:
                printf("Unknown node type: %d Line: %d\n", tree->nodekind, tree->lineno);
                break;
        }

        if(tree == NULL){
            printf("Tree is empty, or Null\n");
        }
    
        int i; 
          for(i = 0; i < MAXCHILDREN; i++){
            if(tree->child[i] != NULL){
                WSC++;
                printWhiteSpace(WSC);
                printf("Child: %d ", i);
                printTree(tree->child[i], 0);
                WSC--;
            }
        }

           if(tree->sibling != NULL){
            nsiblings++;
            printWhiteSpace(WSC);
            printf("Sibling: %d ", nsiblings);
        }

    

        tree = tree->sibling;
    }
}
    
//Function to print white spaces
void printWhiteSpace(int WS){
    int i;
    for(i = 0; i < WS; i++){
        printf(".   ");
    }
}
