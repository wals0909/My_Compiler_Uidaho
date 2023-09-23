
BIN = parser
CC = g++

FLES = tree.c symbolTable.cpp semantic.cpp IOinit.cpp yyerrorr.cpp
SRCS = $(BIN).y  $(BIN).l
HDRS = scanType.h tree.h symbolTable.h semantic.h IOinit.h yyerrorr.h
OBJS = lex.yy.o $(BIN).tab.o 

$(BIN) : $(OBJS)
	$(CC) $(OBJS) $(FLES) -o c-

lex.yy.c : $(BIN).l $(BIN).tab.h $(HDRS)
	flex $(BIN).l 

$(BIN).tab.h $(BIN).tab.c : $(BIN).y 
	bison -v -t -d $(BIN).y 

clean :
	rm -f *~ $(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).output

tar:
	tar -cvf $(BIN).tar $(HDRS) $(SRCS) $(FLES) makefile