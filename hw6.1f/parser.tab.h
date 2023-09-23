/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    NUMCONST = 259,                /* NUMCONST  */
    CHARCONST = 260,               /* CHARCONST  */
    STRINGCONST = 261,             /* STRINGCONST  */
    BOOLCONST = 262,               /* BOOLCONST  */
    SPEC = 263,                    /* SPEC  */
    KEYWORD = 264,                 /* KEYWORD  */
    INC = 265,                     /* INC  */
    DEC = 266,                     /* DEC  */
    NEQ = 267,                     /* NEQ  */
    LEQ = 268,                     /* LEQ  */
    GEQ = 269,                     /* GEQ  */
    ASGN = 270,                    /* ASGN  */
    ADDASGN = 271,                 /* ADDASGN  */
    MINUSASGN = 272,               /* MINUSASGN  */
    MULTASGN = 273,                /* MULTASGN  */
    DIVASGN = 274,                 /* DIVASGN  */
    IF = 275,                      /* IF  */
    THEN = 276,                    /* THEN  */
    ELSE = 277,                    /* ELSE  */
    FOR = 278,                     /* FOR  */
    BREAK = 279,                   /* BREAK  */
    RETURN = 280,                  /* RETURN  */
    START = 281,                   /* START  */
    STOP = 282,                    /* STOP  */
    WHILE = 283,                   /* WHILE  */
    TO = 284,                      /* TO  */
    DO = 285,                      /* DO  */
    BY = 286,                      /* BY  */
    NOT = 287,                     /* NOT  */
    STATIC = 288,                  /* STATIC  */
    BOOL = 289,                    /* BOOL  */
    CHAR = 290,                    /* CHAR  */
    INT = 291,                     /* INT  */
    PLUS = 292,                    /* PLUS  */
    MINUS = 293,                   /* MINUS  */
    DIVIDE = 294,                  /* DIVIDE  */
    MULT = 295,                    /* MULT  */
    EQUALS = 296,                  /* EQUALS  */
    PERCENT = 297,                 /* PERCENT  */
    COLON = 298,                   /* COLON  */
    SEMICOLON = 299,               /* SEMICOLON  */
    COMMA = 300,                   /* COMMA  */
    QMARK = 301,                   /* QMARK  */
    LBRACKET = 302,                /* LBRACKET  */
    RBRACKET = 303,                /* RBRACKET  */
    LPAREN = 304,                  /* LPAREN  */
    RPAREN = 305,                  /* RPAREN  */
    OR = 306,                      /* OR  */
    AND = 307,                     /* AND  */
    LESSTHAN = 308,                /* LESSTHAN  */
    GREATERTHAN = 309              /* GREATERTHAN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "parser.y"

    ExpType type;           // For passing ALLTYPE ( i.e. pass a type in a decl like in or bool)
    TokenData *tokenData;   // For terminals. Token data comes from yylex() in the $ vars
    TreeNode *tree;         // For nonterminals. Add these nodes as you build the tree. 

#line 124 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
