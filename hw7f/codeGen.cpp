/* Riley Walsh
*  CS445
*  Spring 2023
*/ 

#include <string.h>
#include "codeGen.h"
#include "emitcode.h"

#define MAXCHILDREN 3

using namespace std;

int tempOffset = - 2;
int sizeCmpnd = 0;
int IdTemp;
int thenLoc = 0, breakLoc = 0;
int nestThen = 0;
bool arrOpk;
bool mpCall = false;
bool nestCall = false;
bool nestAsgn = false;
int forLoopy = false;
bool inIF = false;
bool flagStmt = false;
bool isUnary = false;

extern int goffset;
extern int loffset;

FILE *code;
extern SymbolTable symbolTable;

//function to genrate code
void generateCode(TreeNode *t, char* infile){

    code = fopen(infile, "w");

    emitComment((char*)"C- compiler version C-S21 ");
    emitComment((char*)"Built: Apr 18, 2023");
    emitComment((char*)"Author: Riley Walsh ");
    emitComment((char*)"File compiled: ", infile);
    emitComment((char*)"");
    emitIO(t);
    emitBegin(t);
    emitInit(t);
    fclose(code);

}

//function to Emit compiler info
void emitInfo(char* infile){

    emitComment((char*)"C- compiler version C-S21");
    emitComment((char*)"Built: Apr 18, 2023");
    emitComment((char*)"Author: Riley Walsh");
    emitComment((char*)"File compiled: ", infile);
    emitSkip(1);
}

//Function to recursively call for emitting, rather then redeclaring
void emitBegin(TreeNode* t){
    if(t == NULL){
        return;
    }
    else{
        switch(t->nodekind){

            case DeclK:
            emitDecl(t);
            break;

            case StmtK:
            emitStmt(t);
            break;

            case ExpK:
            emitExp(t);
            break;
        }
    }
    if(t->sibling != NULL && !mpCall){
        emitBegin(t->sibling);
    }
}

void emitInput(TreeNode* t){
  
    while(t->sibling != NULL){
        emitBegin(t);
    }
}

void emitStaticGlobal(TreeNode* t){

    if(t != NULL){

        if(t->nodekind == DeclK && t->subkind.decl == VarK){

            if(t->memT == Global || t->isStatic){

                if(t->isArray){

                    emitRM((char *)"LDC", 3, t->mSize - 1, 6,(char *)"load size of array", (char *) t->attr.name);
				    emitRM((char *)"ST", 3, t->mOffset + 1, 0,(char *)"save size of array", (char *) t->attr.name);
                }
                else{

                    if(t->child[0] != NULL){
                    emitBegin(t->child[0]);
                    emitRM((char *)"ST", 3, t->mOffset, 0,(char *)"Store variable",(char *)t->attr.name);
                    }
                }
            }
        }

        for(int i = 0; i < MAXCHILDREN; i++){
            emitStaticGlobal(t->child[i]);
        }
        if(t->sibling != NULL){
            emitStaticGlobal(t->sibling);
        }
    }
    
}
//Function to emit IO 
void emitIO(TreeNode *t){

    emitSkip(1);
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));
	emitComment((char *)("FUNCTION input"));
	TreeNode *curIO = (TreeNode*)symbolTable.lookup((char *)("input"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->codeLine = emitSkip(0)-1;
	curIO->attr.name = (char *) "input";
	emitRO((char *)"IN", 2, 2, 2,(char *)("Grab int input"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3,(char *)("Return"));
	emitComment((char *)("END FUNCTION input"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

    emitComment((char *)("FUNCTION inputb"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("inputb"));
	emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
	curIO->codeLine = emitSkip(0)-1;
	curIO->attr.name = (char *) "inputb";
	emitRO((char *)"INB", 2, 2, 2, (char *)("Grab bool input"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));
	emitComment((char *)("END FUNCTION inputb"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

    emitComment((char *)("FUNCTION inputc"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("inputc"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->codeLine = emitSkip(0)-1;
	curIO->attr.name = (char *) "inputc";
	emitRO((char *)"INC", 2, 2, 2, (char *)("Grab char input"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));
	emitComment((char *)("END FUNCTION inputc"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

    emitComment((char *)("FUNCTION output"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("output"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->codeLine = emitSkip(0)-1;
	curIO->attr.name = (char *) "output";
	emitRM((char *)"LD", 3, -2, 1,(char *)("Load parameter"));
    emitRO((char *)"OUT",3,3,3,(char *)("Output integer"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3,(char *)("Return"));
	emitComment((char *)("END FUNCTION output"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

	emitComment((char *)("FUNCTION outputb"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("outputb"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->codeLine = emitSkip(0)-1;
	curIO->attr.name = (char *) "outputb";
	emitRM((char *)"LD", 3, -2, 1,(char *)("Load parameter"));
	emitRO((char *)"OUTB", 3, 3, 3, (char *)("Output bool"));
	emitRM((char *)"LD",3,-1,1,(char *)("Load return address"));
	emitRM((char *)"LD",1,0,1,(char *)("Adjust fp"));
	emitRM((char *)"JMP",7,0,3,(char *)("Return"));
	emitComment((char *)("END FUNCTION outputb"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

	emitComment((char *)("FUNCTION outputc"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("outputc"));
	emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
	curIO->codeLine = emitSkip(0)-1;
	curIO->attr.name = (char *) "outputc";
	emitRM((char *)"LD", 3, -2, 1, (char *)("Load parameter"));
	emitRO((char *)"OUTC", 3, 3, 3, (char *)("Output char"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));
	emitComment((char *)("END FUNCTION outputc"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

	emitComment((char *)("FUNCTION outnl"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("outnl"));
	emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
	curIO->codeLine = emitSkip(0)-1;
	curIO->attr.name = (char *) "outnl";
	emitRO((char *)"OUTNL", 3, 3, 3, (char *)("Output a newline"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));
	emitComment((char *)("END FUNCTION outnl"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));
}

void emitInit(TreeNode *t){

    TreeNode* mainFunc;
	
	int bp = emitSkip(0)-1;
	emitNewLoc(0);
	mainFunc = (TreeNode*)symbolTable.lookup("main"); 
	emitRM((char *)"JMP", 7, bp, 7, (char *)("Jump to init [backpatch]"));
	emitComment((char *)("INIT"));
	emitSkip(bp);
	emitRM((char *)"LDA", 1, 0 + goffset, 0, (char *)("set first frame at end of globals"));
	emitRM((char *)"ST", 1, 0, 1, (char *)("store old fp (point to self)"));
	emitComment((char *)("INIT GLOBALS AND STATICS"));
	emitStaticGlobal(t);
	emitComment((char *)("END INIT GLOBALS AND STATICS"));
	emitRM((char *)"LDA", 3, 1, 7, (char *)("Return address in ac"));
	bp = emitSkip(0);
	emitRM((char *)"JMP", 7, (mainFunc->codeLine-bp-1), 7, (char *)("Jump to main"));
	emitRO((char *)"HALT", 0, 0, 0, (char *)("DONE!"));
	emitComment((char *)("END INIT"));
}

//emit code Decl node.
void emitDecl(TreeNode *t){

    switch(t->subkind.decl){

        case ParamK:

            for(int i = 0; i < MAXCHILDREN; i++){
                emitBegin(t->child[i]);
            }
        break;

        case VarK:

            if((!t->isGlobal && !t->isStatic)){

                if(t->isArray){

                    emitRM((char*)"LDC", 3, t->mSize - 1, 6, (char*)"load array size 124", (char*)t->attr.name);
                    emitRM((char*)"ST", 3, t->mOffset + 1, 1, (char*)"save array size", (char*)t->attr.name);

                    if(t->child[0] != NULL){
                        emitBegin(t->child[0]);
                        emitRM((char *)"LDA", 3, t->child[0]->mOffset, 0, (char *)"Load address of char array");
                        emitRM((char *)"LDA", 4, t->mOffset, 1, (char *)"address of lhs");

                        emitRM((char *)"LD", 5, 1, 3, (char *)"size of rhs");
                        emitRM((char *)"LD", 6, 1, 4, (char *)"size of lhs");

                        emitRO((char *)"SWP", 5, 6, 6, (char *)"pick smallest size");

                        emitRO((char *)"MOV", 4, 3, 5, (char *)"array op =");
                    }

                }
                else{
                    
                    if(t->child[0] != NULL){

                        if(t->isArray){
                        emitRM((char*)"ST", 3, t->mOffset + 1, 1, (char*)"save array size", (char*)t->attr.name);
                        }
                        else{
                            emitBegin(t->child[0]);
                            emitRM((char*)"ST", 3, t->mOffset, 1, (char*)"store variable 136", (char*)t->attr.name);
                        }
                    }
                }
            }
            break;

        case FuncK:

            t->codeLine = emitSkip(0);

            TreeNode* cntSiblings;
            int pcount;
            int IdTemp = tempOffset;

            cntSiblings = t->child[0];

            if(cntSiblings != NULL){

                for(pcount = 0; cntSiblings != NULL; pcount++){
                    cntSiblings = cntSiblings->sibling;
                }

                if(!(t->child[1]->nodekind == StmtK && t->child[1]->subkind.stmt == CompoundK)){

                    tempOffset -= pcount + 2;
                    emitComment((char*)"TOFF:", tempOffset);
                }
            }

            t->emitLoc = emitSkip(0) - 1;

            emitComment((char *)("FUNCTION"), (char *) t->attr.name);
            emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");

            for(int i = 0; i < MAXCHILDREN; i++){
                
                if(t->child[i] != NULL){
                    emitBegin(t->child[i]);
                }
            }

            emitComment((char *)("Add standard closing in case there is no return statement"));
			emitRM((char *)"LDC", 2, 0, 6, (char *)"Set return value to 0");
			emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
			emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
			emitRM((char *)"JMP", 7, 0, 3,(char *)("Return"));
			emitComment((char *)("END FUNCTION"), (char *) t->attr.name);

            tempOffset = IdTemp;
            emitComment((char*)"TOFF:", tempOffset);
            break;

    }

}
//function to emite code for exp node
void emitExp(TreeNode *t){

    TreeNode *leftSide;
    TreeNode *rightSide;
    TreeNode *callLookup;

    if(t->child[0] != NULL){

        leftSide = t->child[0];
    }
    else{
        leftSide = NULL;
    }
    if(t->child[1] != NULL){

        rightSide = t->child[1];
    }
    else{
        rightSide = NULL;
    }

    switch(t->subkind.exp){

        case AssignK:

            emitComment((char*)("ASSIGNMENT EXPRESSION"));

            if(!strcmp(t->attr.name, "<=")){

                if(!strcmp(t->child[0]->attr.name, "[")){

                    emitBegin(leftSide->child[1]);
                    
                    emitRM((char *)"ST", 3, tempOffset, 1, (char *)("Push index 373"));
                    tempOffset--;
                    emitComment((char*)"TOFF:", tempOffset);

                    if(rightSide->subkind.exp == AssignK){
                    
                        if(!strcmp(rightSide->attr.name, "<=")){
                            nestAsgn = true;
                        }
                    }
                    emitBegin(rightSide);
                    
                    tempOffset++;
                    emitComment((char*)"TOFF:", tempOffset);
                    emitRM((char *)"LD", 4, tempOffset, 1,(char *)("Pop index")); 

                    if(leftSide->child[0]->memT == Global || leftSide->child[0]->memT == LocalStatic){
                        emitRM((char *)"LDA", 5, leftSide->child[0]->mOffset, 0, (char *)("Load address of base of array 383"), (char *)leftSide->child[0]->attr.name);
                    }
                    else{
                        if(t->child[1]->child[1] != NULL){
                            emitRM((char *)"LD", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 493"), (char *)leftSide->child[0]->attr.name);

                        }
                        else if(nestAsgn){
                            emitRM((char *)"LD", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 497"), (char *)leftSide->child[0]->attr.name);
                        }
                        //might need to remove
                        else if(t->child[0]->child[1]->subkind.exp == IdK && t->child[1]->subkind.exp == ConstantK && inIF){
                             emitRM((char *)"LD", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 500"), (char *)leftSide->child[0]->attr.name);
                        }
                        
                        else{
                            emitRM((char *)"LDA", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 390"), (char *)leftSide->child[0]->attr.name);
                        }
                    }
                    emitRO((char *)"SUB", 5, 5, 4, (char *)("Compute offset of value"));
					emitRM((char *)"ST", 3, 0, 5, (char *)("Store variable"), (char *)leftSide->child[0]->attr.name);
                    nestAsgn = false;
                }
                else if(leftSide->isArray && rightSide->isArray){

                    if(leftSide->expType == Char && rightSide->expType == Char){
                        emitRM((char *)"LDA", 3, rightSide->mOffset, 1, (char *)"Load address of char array", rightSide->attr.name);
                        emitRM((char *)"LDA", 4, leftSide->mOffset, 1, (char *)"address of lhs");

                        emitRM((char *)"LD", 5, 1, 3, (char *)"size of rhs");
                        emitRM((char *)"LD", 6, 1, 4, (char *)"size of lhs");

                        emitRO((char *)"SWP", 5, 6, 6, (char *)"pick smallest size");

                        emitRO((char *)"MOV", 4, 3, 5, (char *)"array op =");
                    }
                }
     
                else if(leftSide->memT == LocalStatic && rightSide->memT == LocalStatic){
                    emitRM((char *)"LD", 3, t->child[1]->mOffset, 0, (char *)("1 Load variable 797"), t->child[1]->attr.name);
                    flagStmt = true;
                    isUnary = true;
                    emitBegin(leftSide);

                }
 
                else{
                    emitBegin(rightSide);
                    flagStmt = true;
                    isUnary = true;
                    emitBegin(leftSide);
                    
                }
            }

            else if(rightSide == NULL){

                flagStmt = false;
                isUnary = true;

                emitBegin(leftSide);

                if(!strcmp(leftSide->attr.name, "[")){

                    leftSide = leftSide->child[0];
                    arrOpk = true;
                }

                if(!strcmp(t->attr.name, "++"))
				{
					emitRM((char *)"LDA", 3, 1, 3, (char *)("increment value of"), (char *)leftSide->attr.name);
				}
				else if(!strcmp(t->attr.name, "--"))
				{
					emitRM((char *)"LDA", 3, -1, 3, (char *)("decrement value of"), (char *)leftSide->attr.name);
				}
	
                if(arrOpk){
                   emitRM((char *)"ST", 3, 0, 5,(char *)("Store variable"), (char *)leftSide->attr.name); 
                }
                else{
				    emitRM((char *)"ST", 3, leftSide->mOffset, 1,(char *)("Store variable"), (char *)leftSide->attr.name);
                }
                leftSide = t->child[0];
            }

            else{

                if(!strcmp(leftSide->attr.name, "[")){

                   emitBegin(leftSide->child[1]);
                   emitRM((char *)"ST", 3, tempOffset, 1, (char *)("Push index 446"));

                   tempOffset--;
                   emitComment((char*)"TOFF:", tempOffset);

                   if(rightSide->child[1] != NULL){
                   emitRM((char *)"LDA", 3, rightSide->child[0]->mOffset, 0, (char *)("Load address of base of array 446"), (char *)rightSide->child[0]->attr.name);
                   emitRM((char *)"ST", 3, tempOffset, 1, (char *)"Push left side");
                   emitBegin(rightSide->child[1]);
                   emitRM((char *)"LD", 4, tempOffset, 1, (char *)"Pop left into ac1");
                   emitBegin(rightSide->child[0]);
                   emitRO((char *)"SUB", 3, 4, 3, (char *)"Compute location from index");
                   emitRM((char *)"LD", 3, 0, 3, (char *)"Load array element");

                   tempOffset++;
                   emitComment((char*)"TOFF:", tempOffset);

                   emitRM((char *)"LD", 4, tempOffset, 1, (char *)("Pop index"));
                   emitRM((char *)"LDA", 5, leftSide->child[0]->mOffset, 0, (char *)("Load address of base of array 458"), (char *)leftSide->child[0]->attr.name);
                   emitRO((char *)"SUB", 5, 5, 4, (char *)"Compute offset of value");
                   emitRM((char *)"LD", 4, 0, 5, (char *) "Load LHS variable 499");
                   }
                   else{
                       emitBegin(rightSide);
                       tempOffset++;
                       emitComment((char*)"TOFF:", tempOffset);
                       emitRM((char *)"LD", 4, tempOffset, 1, (char *)"Pop index");
                       emitRM((char *)"LD", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 458"), (char *)leftSide->child[0]->attr.name);
                       emitRO((char *)"SUB", 5, 5, 4, (char *)"Compute offset of value");
                       emitRM((char *)"LD", 4, 0, 5, (char *) "Load LHS variable 508");
                   }

                   
                   
                    if(!strcmp(t->attr.name, "+=")){

                        emitRO((char *)"ADD", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "-=")){
                        emitRO((char *)"SUB", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "/=")){
                        emitRO((char *)"DIV", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "*=")){
                        emitRO((char *)"MUL", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                   
                    //store
                    if(leftSide->child[0] != NULL){
                        emitRM((char *)"ST", 3, leftSide->mOffset, 5, (char *)("Store variable"),(char *)leftSide->child[0]->attr.name);
                    }
                    else{
                        emitRM((char *)"ST", 3, leftSide->mOffset, 5, (char *)("Store variable"),(char *)leftSide->attr.name);
                    }
                    
                }
                else{

                    flagStmt = false;
                    emitBegin(rightSide);
                    isUnary = false;
                    emitBegin(leftSide);

                    if(!strcmp(t->attr.name, "+=")){

                        emitRM((char *)"LD", 4, leftSide->mOffset, 0, (char *) "Load LHS var");
                        emitRO((char *)"ADD", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "-=")){
                        emitRM((char *)"LD", 4, leftSide->mOffset, 0, (char *) "Load LHS var");
                        emitRO((char *)"SUB", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }                
                    else if(!strcmp(t->attr.name, "/=")){
                        emitRM((char *)"LD", 4, leftSide->mOffset, 0, (char *) "Load LHS var");
                        emitRO((char *)"DIV", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "*=")){
                        emitRM((char *)"LD", 4, leftSide->mOffset, 0, (char *) "Load LHS var");
                        emitRO((char *)"MUL", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                
                    if(leftSide->memT == Global || leftSide->memT == LocalStatic){

                        emitRM((char *)"ST", 3, leftSide->mOffset, 0, (char *)("Store variable"), (char *)leftSide->attr.name);
                    }
                    else{

                        emitRM((char *)"ST", 3, leftSide->mOffset, 1, (char *)("Store variable"), (char *)leftSide->attr.name);
                        
                    }

                    isUnary = true;
                }
            }

            break;

    

        case ConstantK:

            if(t->expType == Integer){
                emitRM((char *)"LDC", 3, t->attr.value, 6,(char *)"Load Integer constant");
            }

            else if(t->expType == Boolean){

                int boolVal;

                if(!strcmp(t->attr.name, "true")){
                    boolVal = 1;
                }
                else{
                    boolVal = 0;
                }
                emitRM((char *)"LDC", 3, boolVal, 6,(char *)"Load Boolean constant");
            }
            else if(t->expType == Char){
                emitRM((char *)"LDC", 3, t->attr.cvalue, 6,(char *)"Load Character constant");
            }
            else if(t->expType == CharInt){
                emitStrLit(t->mOffset, t->attr.string);
            }

            break;

            case OpK:

            emitComment((char*)("OP EXPRESSION"));
            
            if(rightSide == NULL){

                emitBegin(t->child[0]);

                if(!strcmp(t->attr.name, "-")){

                    emitRO((char *)"NEG", 3, 3, 3, (char *)("Op unary -"), (char *)t->attr.name);
                }

                else if(!strcmp(t->attr.name, "*")){

                    if(t->child[0]->memT == Global || t->child[0]->memT == LocalStatic){

                        emitRM((char *)"LDA", 3, leftSide->mOffset, 0, (char *)("Load address of base of array 540"), (char *)leftSide->attr.name);
                    }
                    else if(t->child[0]->memT == Parameter){
                        emitRM((char *)"LD", 3, leftSide->mOffset, 1, (char *)("Load address of base of array 543"), (char *)leftSide->attr.name);
                    }
                    else{
                        emitRM((char *)"LDA", 3, leftSide->mOffset, 1, (char *)("Load address of base of array 546"), (char *)leftSide->attr.name);
                    }
                    emitRM((char *)"LD", 3, 1, 3, (char *)("Load array size 669"));
                }

                else if(!strcmp(t->attr.name, "NOT") || !strcmp(t->attr.name, "not")){

                    emitRM((char *)"LDC", 4, 1, 6, (char *)("Load 1"));
					emitRO((char *)"XOR", 3, 3, 4, (char *)("Op XOR to get logical not"));
                }
                else if(!strcmp(t->attr.name, "?")){

                    emitRO((char *)"RND", 3, 3, 6, (char *)("Op unary"), (char *)t->attr.name);
                }
              
            }

            else{

                
                flagStmt = false;

                if(!strcmp(t->attr.name, "[")){

                    if(isUnary == false || leftSide->expType == Char){
                        if(leftSide->isArray){

                            if(leftSide->memT == Global || leftSide->memT == LocalStatic){
                                emitRM((char *)"LDA", 3, leftSide->mOffset, 0, (char *)"1 Load address of base of array 578", (char*)leftSide->attr.name);
                            }
                            
                            else if(leftSide->memT == Parameter){
                                emitRM((char *)"LD", 3, leftSide->mOffset, 1, (char *)"2 Load address of base of array 583", (char*)leftSide->attr.name);
                            }
                            
                            else{
                                emitRM((char *)"LDA", 3, leftSide->mOffset, 1, (char *)"2 Load address of base of array 587", (char*)leftSide->attr.name);
                            }

                            emitRM((char *)"ST", 3, tempOffset, 1, (char *)"Push left side");
                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                            
                            
                            emitBegin(t->child[1]);
                            

                            tempOffset++;
                            emitComment((char*)"TOFF:", tempOffset);

                            emitRM((char *)"LD", 4, tempOffset, 1, (char *)"1 Pop left into ac1");
                            emitRO((char *)"SUB", 3, 4, 3, (char *)"1 Compute location from index");
                            emitRM((char *)"LD", 3, 0, 3, (char *)"1 Load array element");

                        }
                    }
                    else{

                        if(leftSide->isArray){

                        tempOffset--;
                        emitComment((char*)"TOFF:", tempOffset);

                        emitBegin(rightSide);

                        tempOffset++;
                        emitComment((char*)"TOFF:", tempOffset);

                        if(leftSide->memT == Global || leftSide->memT == LocalStatic){
                             emitRM((char *)"LDA", 5, leftSide->mOffset, 0, (char *)"1 Load address of base of array 620", (char*)leftSide->attr.name);
                        }
                        else if(leftSide->memT == Parameter){
                            emitRM((char *)"LD", 5, leftSide->mOffset, 1, (char *)"2 Load address of base of array 623", (char*)leftSide->attr.name);
                        }
                        else{
                            emitRM((char *)"LDA", 5, leftSide->mOffset, 1, (char *)"3 Load address of base of array 626", (char*)leftSide->attr.name);
                        }

                        emitRO((char *)"SUB", 5, 5, 3, (char *)"2 Compute location from index");
                        emitRM((char *)"LD", 3, 0, 5, (char *)"2 Load array element");

                        }


                    }
                }

                else if(leftSide->isArray && rightSide->isArray){
                    emitRM((char *)"LDA", 3, leftSide->mOffset, 1, (char *)"2 Load address of base of array 814", (char*)leftSide->attr.name);
                    emitRM((char *)"ST", 3, tempOffset, 1, (char *)"Push left side");
                    emitRM((char *)"LDA", 3, rightSide->mOffset, 1, (char *)"2 Load address of base of array 814", (char*)rightSide->attr.name);
                    emitRM((char*)"LD", 4, tempOffset, 1, (char*)("Load Left into ac1"), (char*)t->attr.name);
                    emitRM((char*)"LD", 5, 1, 3, (char*)("AC2 <= |RHS|"));
                    emitRM((char*)"LD", 6, 1, 4, (char*)("AC3 <= |LHS|"));
                    emitRM((char*)"LDA", 2, 0, 5, (char*)("R2 <= |RHS|"));
                    emitRO((char *)"SWP", 5, 6, 6, (char *)"pick smallest size");
                    emitRM((char*)"LD", 6, 1, 4, (char*)("AC3 <= |LHS|"));
                    emitRO((char*)"CO", 4, 3, 5, (char*)("setup array compare LHS vs RHS"));
                    emitRO((char*)"TNE", 5, 4, 3, (char*)("if not equal then test"));
                    emitRO((char*)"JNZ", 5, 2, 7, (char*)("jump not equal"));
                    emitRM((char*)"LDA", 3, 0, 2, (char*)("AC1 <= |RHS|"));
                    emitRM((char*)"LDA", 4, 0, 6, (char*)("AC <= |LHS|"));
                }
                else{

                    emitBegin(t->child[0]); 

                    emitRM((char*)"ST", 3, tempOffset, 1, (char*)("Push the left side 677"));
                    tempOffset--;
                    emitComment((char*)"TOFF:", tempOffset);


                    emitBegin(t->child[1]);

                    tempOffset++;
                    emitComment((char*)"TOFF:", tempOffset);
                    emitRM((char*)"LD", 4, tempOffset, 1, (char*)("Load Left into 1"), (char*)t->attr.name);
                }
                

                if(!strcmp(t->attr.name, "AND") || !strcmp(t->attr.name, "and")){
                    emitRO((char *)"AND", 3, 4, 3, (char *)("Op AND"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "OR") || !strcmp(t->attr.name, "or")){
                    emitRO((char *)"OR", 3, 4, 3, (char *)("Op OR"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, ">")){
                    emitRO((char *)"TGT", 3, 4, 3, (char *)("Op >"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "<")){
                    emitRO((char *)"TLT", 3, 4, 3, (char *)("Op <"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "!<")){
                    emitRO((char *)"TGE", 3, 4, 3, (char *)("Op !<"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "!>")){
                    emitRO((char *)"TLE", 3, 4, 3, (char *)("Op !>"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "/")){
                    emitRO((char *)"DIV", 3, 4, 3, (char *)("Op /"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "%")){
                    emitRO((char *)"MOD", 3, 4, 3, (char *)("Op %"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "*")){
                    emitRO((char *)"MUL", 3, 4, 3, (char *)("Op *"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "=")){
                    emitRO((char *)"TEQ", 3, 4, 3, (char *)("Op =="), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "!=")){
                    emitRO((char *)"TNE", 3, 4, 3, (char *)("Op !="), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "+")){
                    emitRO((char *)"ADD", 3, 4, 3, (char *)("Op +"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "-")){
                    emitRO((char *)"SUB", 3, 4, 3, (char *)("Op -"), (char *)t->attr.name);
                }
             

            }

            break;

            case CallK:{
            
                int IdTemp = tempOffset;

                emitComment((char*)("CALL EXPRESSION"));

                int pCount = 0;
                bool hasChild = false;

                TreeNode* curFunc = (TreeNode*)symbolTable.lookup(t->attr.name);

                emitComment((char*)"CALL", t->attr.name);

                if(t->child[0] != NULL){

                    hasChild = true;
                    TreeNode* getParams = t->child[0];

                    for(int i = 0; i < MAXCHILDREN; i++){
                        if(getParams != NULL){

                            getParams = getParams->sibling;
                            pCount++;
                        }
                    }

                    if(pCount == 1){

                        if(t->child[0]->subkind.exp == IdK && !t->child[0]->isArray){
                            if(t->child[0]->isInit){
                            tempOffset--;
                            IdTemp--;
                            emitComment((char*)"TOFF:", tempOffset);
                            }
                        }

                        emitRM((char *)"ST", 1, tempOffset, 1, (char *)("1 Store fp in ghost frame for"), (char *)t->attr.name);

                        emitComment((char*)"Param 1");

                        if(t->child[0]->subkind.exp == IdK && !t->child[0]->isInit){

                            if(t->child[0]->memT == Global || t->child[0]->memT == LocalStatic){

                                if(t->child[0]->isArray){
                                    emitRM((char *)"LDA", 3, t->child[0]->mOffset, 0, (char *)("Load address of base of array 908"), t->child[0]->attr.name);
                                    tempOffset--;
                                }
                                else{
                                    emitRM((char *)"LD", 3, t->child[0]->mOffset, 0, (char *)("1 variable"), t->child[0]->attr.name);
                                }
                            
                            }
                            else if(t->child[0]->memT == Parameter){
                                
                                if(!t->child[0]->isArray){

                                }
                            }

                            else if(t->child[0]->memT == Local){
                                if(t->child[0]->isArray){
                                    if(t->child[0]->expType != Char){
                                        emitRM((char *)"LDA", 3, t->child[0]->mOffset, 1, (char *)("load address of base of array 916"), t->child[0]->attr.name);
                                    }
                                tempOffset--;
                                }
                            }
                        }

                        tempOffset-= pCount;
                        emitComment((char*)"TOFF:", tempOffset);

                        if(!t->child[0]->isArray){

                            tempOffset -= pCount;
                            flagStmt = false;
                        }
           
                        emitComment((char*)"TOFF:", tempOffset);

                        if(t->child[0]->subkind.exp == CallK){
                            nestCall = true;
                        }
                        
                        emitBegin(t->child[0]);
                    
                        if(t->child[0]->expType == CharInt){
                            callLookup = (TreeNode*)symbolTable.lookup(t->attr.name);
                            if(callLookup != NULL){
                  
                                if(callLookup->child[0]->isArray){
                          
                                    emitRM((char *)"LDA", 3, t->child[0]->mOffset, 0, (char *)"Load address of char array");
                                    tempOffset--;
                                }
                            }
                        }

                        emitRM((char *)"ST", 3, tempOffset, 1,(char *)"Push parameter 1001");
                        emitComment((char *)("Param end"), t->attr.name);
                        emitRM((char *)"LDA", 1, IdTemp, 1,(char *)"1 Ghost frame becomes new active frame");
                        
                    }

                    else if(pCount > 1){

                        int parmIterator = 1;
                        TreeNode *curChild;

                        emitComment((char*)"TOFF:", tempOffset);

                        emitRM((char *)"ST", 1, tempOffset, 1, (char *)("2 Store fp in ghost frame for"), (char *)t->attr.name);

                        if(t->child[0]->subkind.exp == IdK || t->child[0]->subkind.exp == OpK){

                            curChild = (TreeNode*)symbolTable.lookup(t->child[0]->attr.name);

                            if(curChild == NULL){

                            curChild = t->child[0];
                            }

                        }
                        else{
                            curChild = t->child[0];
                        }
                        tempOffset--;
                        emitComment((char*)"TOFF:", tempOffset);


                        if(t->child[0]->subkind.exp != ConstantK && !strcmp(t->child[0]->attr.name, "[")){
                            
                            if(t->child[0] != NULL){
                                
                                mpCall = true;
                                tempOffset--;
                                emitComment((char*)"TOFF:", tempOffset);
                                emitComment((char *)("1035 Param"), parmIterator);

                                emitBegin(t->child[0]);
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)("Push parameter 1064"));
                                t->codeLine -= 1;

                                if(t->child[0]->sibling != NULL){
                                    curChild = t->child[0]->sibling;
                                }
                                parmIterator++;
                                mpCall = false;


                            }
                        }

                        while(curChild != NULL){

                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                            emitComment((char *)("1071 Param"), parmIterator);

                            if(curChild->isArray){

                                if(curChild->memT == Global || curChild->memT == LocalStatic){           

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 0, (char *)("Load address of base of array 1025"), (char *)curChild->attr.name);
                           
                                }
                                else{

                                    if(t->child[0]->subkind.exp == OpK){

                                        emitRM((char *)"LD", 3, curChild->mOffset, 1, (char *)("Load address of base of array 1119"), (char *)curChild->attr.name);
                                    }
                                    else{

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 1, (char *)("Load address of base of array 1123"), (char *)curChild->attr.name);
                                    }                                   
                                }
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)("1101 Push parameter"));
                            }

                            else if(curChild->subkind.exp == OpK || curChild->subkind.exp == IdK){

                                mpCall = true;
                                emitBegin(curChild);
                                                           
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)("1115 Push parameter"));
                                mpCall = false;
                                
                            }
                            
                            else{
                                
                                if(curChild->expType == Integer){
                                    emitRM((char *)"LDC", 3, curChild->attr.value, 6, (char *)"Load integer constant");
                                }
                                else if(curChild->expType == Boolean){
                                    
                                    int boolVal;

                                    if(!strcmp(curChild->attr.name, "true")){
                                        boolVal = 1;
                                    }
                                    else{
                                        boolVal = 0;
                                    }
                                    emitRM((char *)"LDC", 3, boolVal, 6,(char *)"Load Boolean constant");
                                }
                                else if(curChild->expType == Char){
                                    emitRM((char *)"LDC", 3, curChild->attr.value, 6, (char *)"Load character constant");
                                }
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)"3 Push parameter");
                            }

                            parmIterator++;
                            if(curChild->sibling != NULL){
                                curChild = curChild->sibling;
                            }
                            else{
                                curChild = NULL;
                            }
                        }
                        emitComment((char *)("Param end"), t->attr.name);
					    emitRM((char *)"LDA", 1, IdTemp, 1,(char *)"Ghost frame becomes new active frame");

                    }
                }

                else if(pCount == 0){
                    emitRM((char *)"ST", 1, IdTemp, 1, (char *)("3 Store fp in ghost frame for"), (char *)t->attr.name);
                    emitComment((char *)("Param end"), t->attr.name);
                    emitRM((char *)"LDA", 1, tempOffset, 1,(char *)"Ghost frame becomes new active frame");
                }

                curFunc = (TreeNode*)symbolTable.lookup(t->attr.name);
                emitRM((char *)"LDA", 3, 1, 7,(char *)"Return address in ac");
                int backpatch = emitSkip(0);
                emitRM((char *)"JMP",7, curFunc->codeLine - backpatch - 1, 7, (char *)("CALL OUTPUT"), t->attr.name);       
                emitRM((char *)"LDA", 3, 0, 2,(char *)"Save the result in ac");
                emitComment((char *)("CALL end"), t->attr.name);

                tempOffset = IdTemp;
                emitComment((char*)"TOFF:", tempOffset);

                break;
            }
            case IdK:

            if(flagStmt){

                if(t->memT == Global || t->memT == LocalStatic){
                    if(!t->isArray){
                        emitRM((char *)"ST", 3, t->mOffset, 0,(char *)("Store variable"), t->attr.name);
                        flagStmt = false;
                    }
                }
                else if(t->memT == Parameter){
                    emitRM((char *)"ST", 3, t->mOffset, 1, (char *)("Store variable"), t->attr.name);
                    flagStmt = false;
                }
                else if(t->memT == Local){
                    if(!t->isArray){
                        emitRM((char *)"ST", 3, t->mOffset, 1, (char *)("Store variable"), t->attr.name);
                        flagStmt = false;
                    }
                }
              

            }
 
            else{

                if(t->memT == Global || t->memT == LocalStatic){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LDA", 3, t->mOffset, 0, (char *)("1 Load address of base of array 671"), t->attr.name);
                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 0, (char *)("1 Load variable 797"), t->attr.name);
                        }
                    }
                    else{
                        
                    }
                }

                else if(t->memT == Local){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LDA", 3, t->mOffset, 1, (char *)("2 Load address of base of array 783"), t->attr.name);

                            emitComment((char*)"TOFF:", tempOffset);
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("2 Load variable 815"), t->attr.name);
                            
                        }
                    }
                    else{
                        if(!t->isInit){
                            if(t->isArray){
                      
                            }
                            else{
                                
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("1 load variable 851"), t->attr.name);
                            }
                        }
                        else if(t->isInit && !t->isArray){
                            
                        }
                        
                    }
                }

                else if(t->memT == LocalStatic){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LDA", 3, t->mOffset, 0, (char *)("3 Load address of base of array 802"), t->attr.name);
                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 0, (char *)("3 Load variable 833"), t->attr.name);
                        }
                    }
                    else{
                        
                    }
                }

                else if(t->memT == Parameter){

                    if(isUnary){
                        
                        if(t->isArray && t->expType != Char){
                            emitRM((char *)" LDA", 3, t->mOffset, 1, (char *)("4 Load address of base of array 820"), t->attr.name);
                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                        }
                        else{
                            if(t->expType != Char){
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("4 Load variable 851"), t->attr.name);
                            }
                        }
                    }
                    else{
                        
                        if(!t->isInit){
                            if(t->isArray){
                                tempOffset--;
                                 emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("load address of base of array 836"), t->attr.name);
                            }
                            else{
                                
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("1 load variable 861"), t->attr.name);
                            }
                        }
                        else if(t->isInit && !t->isArray){
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("1 load variable 861"), t->attr.name);
                        }
                        
                    }
                }
            }

            break;
    }
}
//function to emit stmt node
void emitStmt(TreeNode* t){

    int whileLoc = 0, tmpBloc = 0, whileSkp = 0, ldaLoc = 0, forCdrn = 0, elseLoc = 0;
    int forOff = 0, forLoc = 0, forSkp = 0;

    switch(t->subkind.stmt){

        case IfK:

            emitComment((char*)("IF"));
            flagStmt = false;
            inIF = true;

            emitBegin(t->child[0]);
            emitComment((char*)("THEN"));

            elseLoc = 0;
            thenLoc = emitSkip(1);
            if(t->child[1]->subkind.stmt == IfK){
                nestThen = thenLoc--;
            }            

            emitBegin(t->child[1]);

            if(t->child[2] != NULL){

                elseLoc = emitSkip(1);
            }

            if(t->child[1]->subkind.stmt != IfK){

            backPatchAJumpToHere((char*)"JZR", 3, thenLoc, (char *)("Jump around the THEN if false [backpatch]"));
            }
            else{
                
                backPatchAJumpToHere((char*)"JZR", 3, nestThen, (char *)("Jump around the THEN if false [backpatch]"));
            }

            if(t->child[2] != NULL){

                emitComment((char*)"ELSE");
                emitBegin(t->child[2]);
                backPatchAJumpToHere((char*)"JMP", 7, elseLoc, (char *)("Jump around the ELSE [backpatch]"));

            }

            emitComment((char*)"END IF");
            inIF = false;

            break;
       
        case ForK:

            tempOffset -= 3;
            forLoopy = true;
            emitComment((char*)("TOFF: "), tempOffset);

            emitComment((char*)("FOR"));

            forOff = tempOffset;

            emitBegin(t->child[0]);

            emitBegin(t->child[1]);

            forLoc = emitSkip(0);

            emitRM((char *)"LD", 4, forOff + 3, 1, (char *)"loop index");
            emitRM((char *)"LD", 5, forOff + 2, 1, (char *)"stop value");
            emitRM((char *)"LD", 3, forOff + 1, 1, (char *)"step value");
            emitRO((char *)"SLT", 3, 4, 5, (char *)"Op <");
            emitRM((char *)"JNZ", 3, 1, 7, (char *)"Jump to loop body");
            
            forSkp = emitSkip(1);

            emitBegin(t->child[2]);

            emitRM((char *)"LD", 3, forOff + 3, 1, (char *)"Load index");
            emitRM((char *)"LD", 5, forOff + 1, 1, (char *)"Load step");

            emitRO((char *)"ADD", 3, 3, 5, (char *)"increment");

            emitRM((char *)"ST", 3, forOff + 3, 1, (char *)"store back to index");
            emitGotoAbs(forLoc, (char *)"go to beginning of loop");
            backPatchAJumpToHere(forSkp, (char *)"Jump past loop [backpatch]");

            emitComment((char*)("END FOR"));
            forLoopy = false;
            
            break;

        case WhileK:

            whileLoc = emitSkip(0);
            flagStmt = false;
            emitComment((char*)("WHILE"));
            
            emitBegin(t->child[0]);
            tmpBloc = breakLoc;
            breakLoc = emitSkip(0);
            emitRM((char *)"JNZ", 3, 1, 7, (char *)("Jump to while part"));
            emitComment((char*)("DO"));
            whileSkp = emitSkip(1);
            
            emitBegin(t->child[1]);
            emitRM((char*)"JMP", 7, whileLoc - emitSkip(0) - 1, 7, (char*)("go to the beginning of the loop"));
            ldaLoc = emitSkip(0);
            backPatchAJumpToHere(whileSkp, (char *)("Jump past loop [backpatch]"));
            breakLoc = tmpBloc;
            emitNewLoc(ldaLoc);
            emitComment((char*)("END WHILE"));

            break;

        case RangeK:

            emitBegin(t->child[0]);
            emitRM((char *)"ST", 3, tempOffset + 3, 1, (char *)"save starting value in index variable");

            emitBegin(t->child[1]);
            emitRM((char *)"ST", 3, tempOffset + 2, 1, (char *)"save stop value");

            if (t->child[2] != NULL)
            {
                emitBegin(t->child[2]);
                emitRM((char *)"ST", 3, tempOffset + 1, 1, (char *)"save step value");
            }

            else
            {
                emitRM((char *)"LDC", 3, 1, 6, (char *)"default increment by 1");
                emitRM((char *)"ST", 3, tempOffset + 1, 1, (char *)"save step value");
            }

            break;


        
        case ReturnK:

            emitComment((char*)("RETURN"));
            flagStmt = false;
            emitBegin(t->child[0]);

            if(t->child[0] != NULL){
                emitRM((char *)"LDA", 2, 0, 3, (char *)("Copy result to ret register"));
            }
            emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
			emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
			emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));

            break;

        case CompoundK:

            sizeCmpnd = tempOffset;
            emitComment((char*)("COMPOUND"));
            if(!forLoopy){
                tempOffset = t->mSize;
            }
            emitComment((char*)"TOFF: ", tempOffset);
            for(int i = 0; i < MAXCHILDREN; i++){
                
                if(t != NULL){
                    emitBegin(t->child[i]);
                }
            }
            emitComment((char*)("Compound Body"));
            tempOffset = sizeCmpnd;
            emitComment((char*)"TOFF: ", tempOffset);

            
            emitComment((char*)("END COMPOUND"));
            break;

        case BreakK:

            emitComment((char*)("BREAK"));
            emitRM((char *)"JMP", 7, breakLoc - emitSkip(0), 7, (char *)("break"));
            break;


    }
}
