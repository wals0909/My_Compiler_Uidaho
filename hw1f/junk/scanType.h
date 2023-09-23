#ifndef SCANTYPE_H
#define SCANTYPE_H

struct TokenData {
    int tokenclass;      // token class
    char *tokenStrprint; // string to print tokenClass
    int idIndex;
    int linenum;         // what line did this token occur on?
    char *tokenstr;    //tokeninput
    char charvalue;         
    int numvalue;          
    char *stringvalue;       
    int strlength;
};

#endif
