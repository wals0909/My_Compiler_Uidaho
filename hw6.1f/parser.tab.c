/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


/* Riley Walsh
*  CS445
*  Spring 2023
*/

#include "scanType.h"  // my header file. 
#include "tree.h"
#include "semantic.h"
#include "IOinit.h"
#include "yyerror.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <getopt.h>

extern int yylex();
extern FILE *yyin;
extern int line;       // ERR line number from the scanner!!
extern int numErrors;  // ERR err count
int numWarnings;       // ERR warning count
bool ALLTYPE = false;
bool printOffset = false;
bool opM;

static TreeNode *ROOT;

extern int goffset;
extern SymbolTable symbolTable;

/*void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", line, msg);
    numErrors++;
}*/


#line 112 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMCONST = 4,                   /* NUMCONST  */
  YYSYMBOL_CHARCONST = 5,                  /* CHARCONST  */
  YYSYMBOL_STRINGCONST = 6,                /* STRINGCONST  */
  YYSYMBOL_BOOLCONST = 7,                  /* BOOLCONST  */
  YYSYMBOL_SPEC = 8,                       /* SPEC  */
  YYSYMBOL_KEYWORD = 9,                    /* KEYWORD  */
  YYSYMBOL_INC = 10,                       /* INC  */
  YYSYMBOL_DEC = 11,                       /* DEC  */
  YYSYMBOL_NEQ = 12,                       /* NEQ  */
  YYSYMBOL_LEQ = 13,                       /* LEQ  */
  YYSYMBOL_GEQ = 14,                       /* GEQ  */
  YYSYMBOL_ASGN = 15,                      /* ASGN  */
  YYSYMBOL_ADDASGN = 16,                   /* ADDASGN  */
  YYSYMBOL_MINUSASGN = 17,                 /* MINUSASGN  */
  YYSYMBOL_MULTASGN = 18,                  /* MULTASGN  */
  YYSYMBOL_DIVASGN = 19,                   /* DIVASGN  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_THEN = 21,                      /* THEN  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_BREAK = 24,                     /* BREAK  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_START = 26,                     /* START  */
  YYSYMBOL_STOP = 27,                      /* STOP  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_TO = 29,                        /* TO  */
  YYSYMBOL_DO = 30,                        /* DO  */
  YYSYMBOL_BY = 31,                        /* BY  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_STATIC = 33,                    /* STATIC  */
  YYSYMBOL_BOOL = 34,                      /* BOOL  */
  YYSYMBOL_CHAR = 35,                      /* CHAR  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_PLUS = 37,                      /* PLUS  */
  YYSYMBOL_MINUS = 38,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 39,                    /* DIVIDE  */
  YYSYMBOL_MULT = 40,                      /* MULT  */
  YYSYMBOL_EQUALS = 41,                    /* EQUALS  */
  YYSYMBOL_PERCENT = 42,                   /* PERCENT  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 44,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_QMARK = 46,                     /* QMARK  */
  YYSYMBOL_LBRACKET = 47,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 48,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 49,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 50,                    /* RPAREN  */
  YYSYMBOL_OR = 51,                        /* OR  */
  YYSYMBOL_AND = 52,                       /* AND  */
  YYSYMBOL_LESSTHAN = 53,                  /* LESSTHAN  */
  YYSYMBOL_GREATERTHAN = 54,               /* GREATERTHAN  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_declList = 57,                  /* declList  */
  YYSYMBOL_decl = 58,                      /* decl  */
  YYSYMBOL_varDecl = 59,                   /* varDecl  */
  YYSYMBOL_scopedVarDecl = 60,             /* scopedVarDecl  */
  YYSYMBOL_varDeclList = 61,               /* varDeclList  */
  YYSYMBOL_varDeclInit = 62,               /* varDeclInit  */
  YYSYMBOL_varDeclId = 63,                 /* varDeclId  */
  YYSYMBOL_typeSpec = 64,                  /* typeSpec  */
  YYSYMBOL_funDecl = 65,                   /* funDecl  */
  YYSYMBOL_parms = 66,                     /* parms  */
  YYSYMBOL_parmList = 67,                  /* parmList  */
  YYSYMBOL_parmTypeList = 68,              /* parmTypeList  */
  YYSYMBOL_parmIdList = 69,                /* parmIdList  */
  YYSYMBOL_parmId = 70,                    /* parmId  */
  YYSYMBOL_stmt = 71,                      /* stmt  */
  YYSYMBOL_expStmt = 72,                   /* expStmt  */
  YYSYMBOL_compoundStmt = 73,              /* compoundStmt  */
  YYSYMBOL_localDecls = 74,                /* localDecls  */
  YYSYMBOL_stmtList = 75,                  /* stmtList  */
  YYSYMBOL_matchedif = 76,                 /* matchedif  */
  YYSYMBOL_unmatchedif = 77,               /* unmatchedif  */
  YYSYMBOL_endStmt = 78,                   /* endStmt  */
  YYSYMBOL_iterRange = 79,                 /* iterRange  */
  YYSYMBOL_returnStmt = 80,                /* returnStmt  */
  YYSYMBOL_breakStmt = 81,                 /* breakStmt  */
  YYSYMBOL_exp = 82,                       /* exp  */
  YYSYMBOL_assignop = 83,                  /* assignop  */
  YYSYMBOL_simpleExp = 84,                 /* simpleExp  */
  YYSYMBOL_andExp = 85,                    /* andExp  */
  YYSYMBOL_unaryRelExp = 86,               /* unaryRelExp  */
  YYSYMBOL_relExp = 87,                    /* relExp  */
  YYSYMBOL_relop = 88,                     /* relop  */
  YYSYMBOL_sumExp = 89,                    /* sumExp  */
  YYSYMBOL_sumop = 90,                     /* sumop  */
  YYSYMBOL_mulExp = 91,                    /* mulExp  */
  YYSYMBOL_mulop = 92,                     /* mulop  */
  YYSYMBOL_unaryExp = 93,                  /* unaryExp  */
  YYSYMBOL_unaryop = 94,                   /* unaryop  */
  YYSYMBOL_factor = 95,                    /* factor  */
  YYSYMBOL_mutable = 96,                   /* mutable  */
  YYSYMBOL_immutable = 97,                 /* immutable  */
  YYSYMBOL_call = 98,                      /* call  */
  YYSYMBOL_args = 99,                      /* args  */
  YYSYMBOL_argList = 100,                  /* argList  */
  YYSYMBOL_constant = 101                  /* constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   729

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    78,    79,    82,    83,    84,    87,    91,
      93,    97,   101,   106,   109,   110,   111,   114,   116,   121,
     125,   126,   131,   132,   137,   138,   139,   142,   149,   155,
     156,   157,   158,   161,   162,   165,   166,   167,   168,   171,
     172,   175,   177,   178,   179,   182,   184,   189,   190,   193,
     194,   195,   199,   205,   206,   209,   210,   214,   215,   220,
     221,   222,   224,   229,   231,   233,   240,   241,   244,   249,
     252,   257,   260,   267,   270,   274,   277,   278,   279,   280,
     283,   287,   292,   293,   295,   298,   301,   307,   311,   315,
     319,   324,   329,   331,   332,   333,   334,   337,   338,   339,
     340,   341,   344,   350,   351,   354,   360,   361,   364,   369,
     370,   373,   377,   379,   382,   386,   390,   394,   398,   402,
     407,   411,   412,   415,   419,   424,   428,   429,   432,   436,
     440,   445,   448,   449,   452,   456,   460,   465,   466,   469,
     472,   480,   481,   482,   483,   486,   490,   493,   494,   497,
     498,   499,   502,   506,   511,   517
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMCONST",
  "CHARCONST", "STRINGCONST", "BOOLCONST", "SPEC", "KEYWORD", "INC", "DEC",
  "NEQ", "LEQ", "GEQ", "ASGN", "ADDASGN", "MINUSASGN", "MULTASGN",
  "DIVASGN", "IF", "THEN", "ELSE", "FOR", "BREAK", "RETURN", "START",
  "STOP", "WHILE", "TO", "DO", "BY", "NOT", "STATIC", "BOOL", "CHAR",
  "INT", "PLUS", "MINUS", "DIVIDE", "MULT", "EQUALS", "PERCENT", "COLON",
  "SEMICOLON", "COMMA", "QMARK", "LBRACKET", "RBRACKET", "LPAREN",
  "RPAREN", "OR", "AND", "LESSTHAN", "GREATERTHAN", "$accept", "program",
  "declList", "decl", "varDecl", "scopedVarDecl", "varDeclList",
  "varDeclInit", "varDeclId", "typeSpec", "funDecl", "parms", "parmList",
  "parmTypeList", "parmIdList", "parmId", "stmt", "expStmt",
  "compoundStmt", "localDecls", "stmtList", "matchedif", "unmatchedif",
  "endStmt", "iterRange", "returnStmt", "breakStmt", "exp", "assignop",
  "simpleExp", "andExp", "unaryRelExp", "relExp", "relop", "sumExp",
  "sumop", "mulExp", "mulop", "unaryExp", "unaryop", "factor", "mutable",
  "immutable", "call", "args", "argList", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-149)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,    73,   -32,  -133,  -133,  -133,    26,   102,  -133,  -133,
      28,  -133,    29,    15,   159,  -133,   -13,     3,  -133,  -133,
     323,   130,   168,   308,  -133,    17,  -133,   148,   308,   128,
     220,    31,    44,  -133,  -133,     9,  -133,    69,   135,  -133,
    -133,  -133,  -133,   338,  -133,  -133,  -133,   357,    78,    80,
    -133,  -133,    11,   106,  -133,   623,  -133,  -133,  -133,  -133,
    -133,  -133,    93,    29,  -133,    78,    99,   113,   145,  -133,
      14,    32,   128,   174,  -133,   376,   121,    69,  -133,    81,
     179,    78,   307,   395,   414,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,   642,   661,  -133,  -133,  -133,   680,    69,
    -133,  -133,   192,   224,  -133,  -133,  -133,  -133,  -133,   221,
      81,   203,  -133,   209,   223,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,   376,  -133,  -133,  -133,   433,    69,    80,    69,
    -133,    69,   157,    69,   106,    69,  -133,  -133,  -133,  -133,
     316,  -133,  -133,  -133,   452,  -133,    81,  -133,   181,  -133,
     238,   182,    81,  -133,   238,   236,   147,   471,   247,   226,
     289,  -133,   490,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,   228,   244,  -133,  -133,     6,    -9,  -133,   262,
    -133,   227,  -133,   230,    -8,    50,  -133,  -133,   229,   229,
     259,   509,  -133,  -133,   259,   259,   528,   255,   547,   264,
    -133,  -133,   276,   150,   270,    18,  -133,  -133,  -133,  -133,
      57,    -5,   286,    84,   101,   259,   259,   259,   301,   259,
     566,   229,   229,   585,   229,   229,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,    69,   -17,   282,   284,   162,
     277,   604,   229,   229,   229,   229,    69,    78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    24,    25,    26,     0,     0,     4,     5,
       0,     6,    16,    20,     0,    15,    17,     0,     1,     3,
      29,    20,     0,     0,    23,     0,     9,     0,     0,    31,
       0,     0,    33,    36,    10,     0,     8,     0,   139,   152,
     153,   154,   155,     0,   134,   135,   136,     0,    19,   103,
     106,   109,   113,   121,   126,     0,   132,   137,   138,   142,
     143,    22,     0,    14,    13,    18,    40,    45,    39,    42,
       0,     0,    30,     0,   146,     0,     0,   110,   108,   144,
       0,    92,   137,     0,     0,   119,   115,   117,   123,   124,
     118,   114,   116,     0,     0,   129,   128,   130,     0,   133,
     131,    21,     0,     0,    32,    54,    28,    37,    35,     0,
       0,     0,   150,     0,   147,    95,    96,    97,    98,    99,
     100,   101,     0,   141,    90,    91,     0,   104,   102,   107,
     105,   112,   111,   122,   120,   127,   125,    46,    43,    41,
      56,    27,   140,   145,     0,    93,    94,    89,     0,    53,
       0,     0,   151,   149,     0,     0,     0,     0,     0,     0,
       0,    52,     0,    50,    55,    76,    77,    47,    48,    57,
      78,    79,     0,     0,    12,    51,    59,     0,    67,     0,
      88,     0,    85,     0,    64,     0,    49,    11,     0,     0,
       0,     0,    87,    86,     0,     0,     0,     0,     0,    75,
      60,    74,    47,     0,     0,     0,    63,    71,    62,    70,
      59,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    69,    58,    68,
      66,    73,    83,    65,    72,    82,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,   303,  -133,  -133,    -7,   292,  -133,     2,
    -133,   281,  -133,   249,  -133,   225,   140,  -133,   -59,  -133,
    -133,  -132,  -100,  -133,   108,  -133,  -133,   -40,   250,   -22,
     251,   -30,  -133,  -133,   243,  -133,   253,  -133,   -47,  -133,
    -133,   -23,  -133,  -133,  -133,  -133,  -133
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   149,    14,    15,    16,    30,
      11,    31,    32,    33,    68,    69,   164,   165,   166,   140,
     151,   206,   168,   169,   204,   170,   171,   172,   122,    81,
      49,    50,    51,    93,    52,    94,    53,    98,    54,    55,
      56,    82,    58,    59,   113,   114,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    48,    10,    22,    29,    57,    65,    80,   100,    10,
      72,   106,   190,    78,   241,   104,   222,    17,    61,   167,
      57,    62,   194,    85,    86,    87,    18,   188,   189,    20,
      28,    21,    57,   107,    83,   111,   112,     3,     4,     5,
     105,    74,    83,     3,     4,     5,    83,   220,    88,    89,
     141,   136,    90,   -34,   130,    74,   199,   200,   202,   -34,
      57,    57,    25,   208,    91,    92,     3,     4,     5,    83,
      57,    57,    23,    -7,    12,    57,    13,    24,   221,   189,
     195,    70,   145,   226,   228,   230,   147,   233,    71,   237,
     238,   115,   116,   208,   207,   209,   117,   118,   119,   120,
     121,    83,    -2,     1,   153,     2,    74,    -7,    -7,    -7,
     226,   228,   230,   233,   224,   227,   229,   231,    74,   234,
     183,     1,   110,     2,    38,    39,    40,    41,    42,    83,
      74,   225,    84,    74,    57,   177,     3,     4,     5,    57,
     185,   101,   150,   155,   -44,    95,    96,   173,    97,    63,
     154,    13,    83,    43,     3,     4,     5,   115,   116,    44,
     102,    45,   117,   118,   119,   120,   121,    46,    57,   205,
      47,  -148,   -38,    57,   211,    57,   214,    25,   -38,    35,
     217,   218,    75,   156,    76,    38,    39,    40,    41,    42,
     103,   175,   244,   218,    88,    89,    74,    57,   236,    74,
      57,   205,   157,    26,    27,   158,   159,   160,   105,   161,
     162,    74,    36,    27,    43,     3,     4,     5,    57,   247,
      44,    66,    45,    67,   109,   138,   163,    67,    46,   123,
     156,    47,    38,    39,    40,    41,    42,   115,   116,    12,
     137,    13,   117,   118,   119,   120,   121,   105,   178,   196,
     179,   142,   197,   159,   160,   105,   178,   198,   212,   143,
     156,    43,    38,    39,    40,    41,    42,    44,   144,    45,
     180,   192,   186,   163,   193,    46,    74,   191,    47,   157,
     174,    27,   158,   159,   160,   105,   215,   162,   187,    27,
     181,    43,    38,    39,    40,    41,    42,    44,   216,    45,
     219,   223,   232,   163,   242,    46,   243,   245,    47,    37,
      19,    38,    39,    40,    41,    42,    73,   124,   125,    64,
     108,    43,   117,   118,   119,   120,   121,    44,   139,    45,
     201,   240,   126,   182,   128,    46,   132,     0,    47,    77,
      43,    38,    39,    40,    41,    42,    44,   134,    45,   148,
       3,     4,     5,     0,    46,     0,     0,    47,    79,     0,
      38,    39,    40,    41,    42,     0,    23,    34,   -16,     0,
      43,    24,     0,     0,     0,     0,    44,   110,    45,    38,
      39,    40,    41,    42,    46,     0,     0,    47,     0,    43,
       0,     0,     0,     0,     0,    44,   127,    45,    38,    39,
      40,    41,    42,    46,     0,     0,    47,     0,    43,     0,
       0,     0,     0,     0,    44,   129,    45,    38,    39,    40,
      41,    42,    46,     0,     0,    47,     0,    43,     0,     0,
       0,     0,     0,    44,   146,    45,    38,    39,    40,    41,
      42,    46,     0,     0,    47,     0,    43,     0,     0,     0,
       0,     0,    44,   152,    45,    38,    39,    40,    41,    42,
      46,     0,     0,    47,     0,    43,     0,     0,     0,     0,
       0,    44,   176,    45,    38,    39,    40,    41,    42,    46,
       0,     0,    47,     0,    43,     0,     0,     0,     0,     0,
      44,   184,    45,    38,    39,    40,    41,    42,    46,     0,
       0,    47,     0,    43,     0,     0,     0,     0,     0,    44,
     203,    45,    38,    39,    40,    41,    42,    46,     0,     0,
      47,     0,    43,     0,     0,     0,     0,     0,    44,   210,
      45,    38,    39,    40,    41,    42,    46,     0,     0,    47,
       0,    43,     0,     0,     0,     0,     0,    44,   213,    45,
      38,    39,    40,    41,    42,    46,     0,     0,    47,     0,
      43,     0,     0,     0,     0,     0,    44,   235,    45,    38,
      39,    40,    41,    42,    46,     0,     0,    47,     0,    43,
       0,     0,     0,     0,     0,    44,   239,    45,    38,    39,
      40,    41,    42,    46,     0,     0,    47,     0,    43,     0,
       0,     0,     0,     0,    44,   246,    45,    38,    39,    40,
      41,    42,    46,     0,     0,    47,     0,    43,     0,     0,
       0,     0,     0,    44,    99,    45,    38,    39,    40,    41,
      42,    46,     0,     0,    47,     0,    43,     0,     0,     0,
       0,     0,    44,   131,    45,    38,    39,    40,    41,    42,
      46,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    44,   133,    45,    38,    39,    40,    41,    42,    46,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
      44,   135,    45,    38,    39,    40,    41,    42,    46,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    44,     0,
      45,     0,     0,     0,     0,     0,    46,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      23,    23,     0,    10,     1,    28,    28,    47,    55,     7,
       1,    70,    21,    43,    31,     1,    21,    49,     1,   151,
      43,     4,    30,    12,    13,    14,     0,    21,    22,     1,
      43,     3,    55,     1,    51,    75,    76,    34,    35,    36,
      26,    49,    51,    34,    35,    36,    51,    29,    37,    38,
     109,    98,    41,    50,    84,    49,   188,   189,   190,    50,
      83,    84,    47,   195,    53,    54,    34,    35,    36,    51,
      93,    94,    43,     0,     1,    98,     3,    48,    21,    22,
      30,    50,   122,   215,   216,   217,   126,   219,    44,   221,
     222,    10,    11,   225,   194,   195,    15,    16,    17,    18,
      19,    51,     0,     1,   144,     3,    49,    34,    35,    36,
     242,   243,   244,   245,    30,   215,   216,   217,    49,   219,
     160,     1,     1,     3,     3,     4,     5,     6,     7,    51,
      49,    30,    52,    49,   157,   157,    34,    35,    36,   162,
     162,    48,   140,   150,    45,    39,    40,   154,    42,     1,
     148,     3,    51,    32,    34,    35,    36,    10,    11,    38,
      47,    40,    15,    16,    17,    18,    19,    46,   191,   191,
      49,    50,    44,   196,   196,   198,   198,    47,    50,    49,
      30,    31,    47,     1,    49,     3,     4,     5,     6,     7,
      45,    44,    30,    31,    37,    38,    49,   220,   220,    49,
     223,   223,    20,    44,    45,    23,    24,    25,    26,    27,
      28,    49,    44,    45,    32,    34,    35,    36,   241,   241,
      38,     1,    40,     3,    50,     1,    44,     3,    46,    50,
       1,    49,     3,     4,     5,     6,     7,    10,    11,     1,
      48,     3,    15,    16,    17,    18,    19,    26,     1,    20,
       3,    48,    23,    24,    25,    26,     1,    28,     3,    50,
       1,    32,     3,     4,     5,     6,     7,    38,    45,    40,
      44,    44,    44,    44,    44,    46,    49,    15,    49,    20,
      44,    45,    23,    24,    25,    26,    22,    28,    44,    45,
       1,    32,     3,     4,     5,     6,     7,    38,    22,    40,
      30,    15,     1,    44,    22,    46,    22,    30,    49,     1,
       7,     3,     4,     5,     6,     7,    35,    10,    11,    27,
      71,    32,    15,    16,    17,    18,    19,    38,   103,    40,
     190,   223,    82,    44,    83,    46,    93,    -1,    49,     1,
      32,     3,     4,     5,     6,     7,    38,    94,    40,    33,
      34,    35,    36,    -1,    46,    -1,    -1,    49,     1,    -1,
       3,     4,     5,     6,     7,    -1,    43,    44,    45,    -1,
      32,    48,    -1,    -1,    -1,    -1,    38,     1,    40,     3,
       4,     5,     6,     7,    46,    -1,    -1,    49,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,     1,    40,     3,     4,
       5,     6,     7,    46,    -1,    -1,    49,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,     1,    40,     3,     4,     5,
       6,     7,    46,    -1,    -1,    49,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,     1,    40,     3,     4,     5,     6,
       7,    46,    -1,    -1,    49,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    38,     1,    40,     3,     4,     5,     6,     7,
      46,    -1,    -1,    49,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,     1,    40,     3,     4,     5,     6,     7,    46,
      -1,    -1,    49,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      38,     1,    40,     3,     4,     5,     6,     7,    46,    -1,
      -1,    49,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
       1,    40,     3,     4,     5,     6,     7,    46,    -1,    -1,
      49,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,     1,
      40,     3,     4,     5,     6,     7,    46,    -1,    -1,    49,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,     1,    40,
       3,     4,     5,     6,     7,    46,    -1,    -1,    49,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,     1,    40,     3,
       4,     5,     6,     7,    46,    -1,    -1,    49,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,     1,    40,     3,     4,
       5,     6,     7,    46,    -1,    -1,    49,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,     1,    40,     3,     4,     5,
       6,     7,    46,    -1,    -1,    49,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,     1,    40,     3,     4,     5,     6,
       7,    46,    -1,    -1,    49,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    38,     1,    40,     3,     4,     5,     6,     7,
      46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,     1,    40,     3,     4,     5,     6,     7,    46,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,     1,    40,     3,     4,     5,     6,     7,    46,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    34,    35,    36,    56,    57,    58,    59,
      64,    65,     1,     3,    61,    62,    63,    49,     0,    58,
       1,     3,    61,    43,    48,    47,    44,    45,    43,     1,
      64,    66,    67,    68,    44,    49,    44,     1,     3,     4,
       5,     6,     7,    32,    38,    40,    46,    49,    84,    85,
      86,    87,    89,    91,    93,    94,    95,    96,    97,    98,
     101,     1,     4,     1,    62,    84,     1,     3,    69,    70,
      50,    44,     1,    66,    49,    47,    49,     1,    86,     1,
      82,    84,    96,    51,    52,    12,    13,    14,    37,    38,
      41,    53,    54,    88,    90,    39,    40,    42,    92,     1,
      93,    48,    47,    45,     1,    26,    73,     1,    68,    50,
       1,    82,    82,    99,   100,    10,    11,    15,    16,    17,
      18,    19,    83,    50,    10,    11,    83,     1,    85,     1,
      86,     1,    89,     1,    91,     1,    93,    48,     1,    70,
      74,    73,    48,    50,    45,    82,     1,    82,    33,    60,
      64,    75,     1,    82,    64,    61,     1,    20,    23,    24,
      25,    27,    28,    44,    71,    72,    73,    76,    77,    78,
      80,    81,    82,    61,    44,    44,     1,    84,     1,     3,
      44,     1,    44,    82,     1,    84,    44,    44,    21,    22,
      21,    15,    44,    44,    30,    30,    20,    23,    28,    76,
      76,    71,    76,     1,    79,    84,    76,    77,    76,    77,
       1,    84,     3,     1,    84,    22,    22,    30,    31,    30,
      29,    21,    21,    15,    30,    30,    76,    77,    76,    77,
      76,    77,     1,    76,    77,     1,    84,    76,    76,     1,
      79,    31,    22,    22,    30,    30,     1,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    80,    80,    80,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    84,    84,    84,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    90,    90,    91,    91,    91,    92,    92,
      92,    93,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   101,   101,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     4,     3,     3,     3,     1,     1,     1,     3,     3,
       1,     4,     3,     2,     1,     1,     1,     6,     5,     2,
       4,     3,     5,     1,     0,     3,     1,     3,     1,     2,
       2,     3,     1,     3,     1,     1,     3,     1,     1,     2,
       1,     2,     4,     2,     0,     2,     0,     1,     6,     2,
       4,     6,     4,     4,     2,     6,     6,     2,     6,     6,
       4,     4,     6,     6,     4,     4,     1,     1,     1,     1,
       3,     5,     3,     3,     5,     2,     3,     3,     2,     3,
       2,     2,     1,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     1,     3,     2,     1,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     3,     1,     3,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     1,     2,     4,     2,     1,     0,     3,
       1,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declList  */
#line 75 "parser.y"
                                                                                { ROOT = (yyvsp[0].tree) ;}
#line 1744 "parser.tab.c"
    break;

  case 3: /* declList: declList decl  */
#line 78 "parser.y"
                                                                                { (yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1750 "parser.tab.c"
    break;

  case 4: /* declList: decl  */
#line 79 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1756 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 82 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1762 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 83 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1768 "parser.tab.c"
    break;

  case 7: /* decl: error  */
#line 84 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1774 "parser.tab.c"
    break;

  case 8: /* varDecl: typeSpec varDeclList SEMICOLON  */
#line 87 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); 
                                                                                  setType((yyval.tree), (yyvsp[-2].type)); 
                                                                                  yyerrok; }
#line 1782 "parser.tab.c"
    break;

  case 9: /* varDecl: error varDeclList SEMICOLON  */
#line 91 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1789 "parser.tab.c"
    break;

  case 10: /* varDecl: typeSpec error SEMICOLON  */
#line 93 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1796 "parser.tab.c"
    break;

  case 11: /* scopedVarDecl: STATIC typeSpec varDeclList SEMICOLON  */
#line 97 "parser.y"
                                                                                {(yyval.tree) = (yyvsp[-1].tree); (yyval.tree)->isStatic = true; 
                                                                                  setType((yyval.tree), (yyvsp[-2].type)); 
                                                                                  yyerrok; }
#line 1804 "parser.tab.c"
    break;

  case 12: /* scopedVarDecl: typeSpec varDeclList SEMICOLON  */
#line 101 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); 
                                                                                  setType((yyval.tree), (yyvsp[-2].type)); 
                                                                                  yyerrok; }
#line 1812 "parser.tab.c"
    break;

  case 13: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 106 "parser.y"
                                                                                { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree)); 
                                                                                  yyerrok; }
#line 1819 "parser.tab.c"
    break;

  case 14: /* varDeclList: varDeclList COMMA error  */
#line 109 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1825 "parser.tab.c"
    break;

  case 15: /* varDeclList: varDeclInit  */
#line 110 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1831 "parser.tab.c"
    break;

  case 16: /* varDeclList: error  */
#line 111 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1837 "parser.tab.c"
    break;

  case 17: /* varDeclInit: varDeclId  */
#line 114 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1843 "parser.tab.c"
    break;

  case 18: /* varDeclInit: varDeclId COLON simpleExp  */
#line 116 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-2].tree); 
                                                                                  if((yyvsp[-2].tree) != NULL){
                                                                                      (yyval.tree)->child[0] = (yyvsp[0].tree);
                                                                                    } }
#line 1852 "parser.tab.c"
    break;

  case 19: /* varDeclInit: error COLON simpleExp  */
#line 121 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 1859 "parser.tab.c"
    break;

  case 20: /* varDeclId: ID  */
#line 125 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(VarK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr; }
#line 1865 "parser.tab.c"
    break;

  case 21: /* varDeclId: ID LBRACKET NUMCONST RBRACKET  */
#line 126 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(VarK, (yyvsp[-3].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                                  (yyval.tree)->isArray = true;
                                                                                  (yyval.tree)->arrLength = (yyvsp[-1].tokenData)->nvalue;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-3].tokenData); (yyval.tree)->expType = UndefinedType;}
#line 1875 "parser.tab.c"
    break;

  case 22: /* varDeclId: ID LBRACKET error  */
#line 131 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1881 "parser.tab.c"
    break;

  case 23: /* varDeclId: error RBRACKET  */
#line 132 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok;}
#line 1888 "parser.tab.c"
    break;

  case 24: /* typeSpec: BOOL  */
#line 137 "parser.y"
                                                                                { (yyval.type) = Boolean; }
#line 1894 "parser.tab.c"
    break;

  case 25: /* typeSpec: CHAR  */
#line 138 "parser.y"
                                                                                { (yyval.type) = Char; }
#line 1900 "parser.tab.c"
    break;

  case 26: /* typeSpec: INT  */
#line 139 "parser.y"
                                                                                { (yyval.type) = Integer; }
#line 1906 "parser.tab.c"
    break;

  case 27: /* funDecl: typeSpec ID LPAREN parms RPAREN compoundStmt  */
#line 142 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenstr);
                                                                                  (yyval.tree)->expType = (yyvsp[-5].type);                                                                              
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1916 "parser.tab.c"
    break;

  case 28: /* funDecl: ID LPAREN parms RPAREN compoundStmt  */
#line 149 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenstr);
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[-4].tokenData);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 1926 "parser.tab.c"
    break;

  case 29: /* funDecl: typeSpec error  */
#line 155 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1932 "parser.tab.c"
    break;

  case 30: /* funDecl: typeSpec ID LPAREN error  */
#line 156 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1938 "parser.tab.c"
    break;

  case 31: /* funDecl: ID LPAREN error  */
#line 157 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1944 "parser.tab.c"
    break;

  case 32: /* funDecl: ID LPAREN parms RPAREN error  */
#line 158 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1950 "parser.tab.c"
    break;

  case 33: /* parms: parmList  */
#line 161 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ; }
#line 1956 "parser.tab.c"
    break;

  case 34: /* parms: %empty  */
#line 162 "parser.y"
                                                                                { (yyval.tree) = NULL ; }
#line 1962 "parser.tab.c"
    break;

  case 35: /* parmList: parmList SEMICOLON parmTypeList  */
#line 165 "parser.y"
                                                                                { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1968 "parser.tab.c"
    break;

  case 36: /* parmList: parmTypeList  */
#line 166 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ; }
#line 1974 "parser.tab.c"
    break;

  case 37: /* parmList: parmList SEMICOLON error  */
#line 167 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1980 "parser.tab.c"
    break;

  case 38: /* parmList: error  */
#line 168 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1986 "parser.tab.c"
    break;

  case 39: /* parmTypeList: typeSpec parmIdList  */
#line 171 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); setType((yyval.tree), (yyvsp[-1].type)); }
#line 1992 "parser.tab.c"
    break;

  case 40: /* parmTypeList: typeSpec error  */
#line 172 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 1998 "parser.tab.c"
    break;

  case 41: /* parmIdList: parmIdList COMMA parmId  */
#line 175 "parser.y"
                                                                                { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree)); 
                                                                                  yyerrok; }
#line 2005 "parser.tab.c"
    break;

  case 42: /* parmIdList: parmId  */
#line 177 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2011 "parser.tab.c"
    break;

  case 43: /* parmIdList: parmIdList COMMA error  */
#line 178 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2017 "parser.tab.c"
    break;

  case 44: /* parmIdList: error  */
#line 179 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2023 "parser.tab.c"
    break;

  case 45: /* parmId: ID  */
#line 182 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[0].tokenData));(yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenstr); }
#line 2029 "parser.tab.c"
    break;

  case 46: /* parmId: ID LBRACKET RBRACKET  */
#line 184 "parser.y"
                                                                                { (yyval.tree) = newDeclNode(ParamK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-2].tokenData)->tokenstr); 
                                                                                  (yyval.tree)->isArray = true;}
#line 2037 "parser.tab.c"
    break;

  case 47: /* stmt: matchedif  */
#line 189 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2043 "parser.tab.c"
    break;

  case 48: /* stmt: unmatchedif  */
#line 190 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2049 "parser.tab.c"
    break;

  case 49: /* expStmt: exp SEMICOLON  */
#line 193 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); }
#line 2055 "parser.tab.c"
    break;

  case 50: /* expStmt: SEMICOLON  */
#line 194 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2061 "parser.tab.c"
    break;

  case 51: /* expStmt: error SEMICOLON  */
#line 195 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 2068 "parser.tab.c"
    break;

  case 52: /* compoundStmt: START localDecls stmtList STOP  */
#line 199 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(CompoundK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); 
                                                                                  yyerrok; }
#line 2077 "parser.tab.c"
    break;

  case 53: /* localDecls: localDecls scopedVarDecl  */
#line 205 "parser.y"
                                                                                { (yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 2083 "parser.tab.c"
    break;

  case 54: /* localDecls: %empty  */
#line 206 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2089 "parser.tab.c"
    break;

  case 55: /* stmtList: stmtList stmt  */
#line 209 "parser.y"
                                                                                { (yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 2095 "parser.tab.c"
    break;

  case 56: /* stmtList: %empty  */
#line 210 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2101 "parser.tab.c"
    break;

  case 57: /* matchedif: endStmt  */
#line 214 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2107 "parser.tab.c"
    break;

  case 58: /* matchedif: IF simpleExp THEN matchedif ELSE matchedif  */
#line 215 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 2116 "parser.tab.c"
    break;

  case 59: /* matchedif: IF error  */
#line 220 "parser.y"
                                                                                 { (yyval.tree) = NULL; }
#line 2122 "parser.tab.c"
    break;

  case 60: /* matchedif: IF error ELSE matchedif  */
#line 221 "parser.y"
                                                                                 { (yyval.tree) = NULL; yyerrok; }
#line 2128 "parser.tab.c"
    break;

  case 61: /* matchedif: IF error THEN matchedif ELSE matchedif  */
#line 222 "parser.y"
                                                                                 { (yyval.tree) = NULL; yyerrok; }
#line 2134 "parser.tab.c"
    break;

  case 62: /* matchedif: WHILE simpleExp DO matchedif  */
#line 224 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2143 "parser.tab.c"
    break;

  case 63: /* matchedif: WHILE error DO matchedif  */
#line 229 "parser.y"
                                                                                 { (yyval.tree) = NULL; 
                                                                                   yyerrok; }
#line 2150 "parser.tab.c"
    break;

  case 64: /* matchedif: WHILE error  */
#line 231 "parser.y"
                                                                                 { (yyval.tree) = NULL; }
#line 2156 "parser.tab.c"
    break;

  case 65: /* matchedif: FOR ID ASGN iterRange DO matchedif  */
#line 233 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->child[0]->expType = Integer;
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 2167 "parser.tab.c"
    break;

  case 66: /* matchedif: FOR ID ASGN error DO matchedif  */
#line 240 "parser.y"
                                                                                 { (yyval.tree) = NULL; yyerrok; }
#line 2173 "parser.tab.c"
    break;

  case 67: /* matchedif: FOR error  */
#line 241 "parser.y"
                                                                                 { (yyval.tree) = NULL; }
#line 2179 "parser.tab.c"
    break;

  case 68: /* unmatchedif: IF simpleExp THEN matchedif ELSE unmatchedif  */
#line 244 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 2188 "parser.tab.c"
    break;

  case 69: /* unmatchedif: IF error THEN matchedif ELSE unmatchedif  */
#line 249 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 2195 "parser.tab.c"
    break;

  case 70: /* unmatchedif: WHILE simpleExp DO unmatchedif  */
#line 252 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2204 "parser.tab.c"
    break;

  case 71: /* unmatchedif: WHILE error DO unmatchedif  */
#line 257 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 2211 "parser.tab.c"
    break;

  case 72: /* unmatchedif: FOR ID ASGN iterRange DO unmatchedif  */
#line 260 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                                  (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                                  (yyval.tree)->child[0]->expType = Integer;
                                                                                  (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 2222 "parser.tab.c"
    break;

  case 73: /* unmatchedif: FOR ID ASGN error DO unmatchedif  */
#line 267 "parser.y"
                                                                                { (yyval.tree) = NULL;
                                                                                  yyerrok; }
#line 2229 "parser.tab.c"
    break;

  case 74: /* unmatchedif: IF simpleExp THEN stmt  */
#line 270 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2237 "parser.tab.c"
    break;

  case 75: /* unmatchedif: IF error THEN matchedif  */
#line 274 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2243 "parser.tab.c"
    break;

  case 76: /* endStmt: expStmt  */
#line 277 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2249 "parser.tab.c"
    break;

  case 77: /* endStmt: compoundStmt  */
#line 278 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2255 "parser.tab.c"
    break;

  case 78: /* endStmt: returnStmt  */
#line 279 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2261 "parser.tab.c"
    break;

  case 79: /* endStmt: breakStmt  */
#line 280 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2267 "parser.tab.c"
    break;

  case 80: /* iterRange: simpleExp TO simpleExp  */
#line 283 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2275 "parser.tab.c"
    break;

  case 81: /* iterRange: simpleExp TO simpleExp BY simpleExp  */
#line 287 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[2] = (yyvsp[0].tree);}
#line 2284 "parser.tab.c"
    break;

  case 82: /* iterRange: simpleExp TO error  */
#line 292 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2290 "parser.tab.c"
    break;

  case 83: /* iterRange: error BY error  */
#line 293 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 2297 "parser.tab.c"
    break;

  case 84: /* iterRange: simpleExp TO simpleExp BY error  */
#line 295 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2303 "parser.tab.c"
    break;

  case 85: /* returnStmt: RETURN SEMICOLON  */
#line 298 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;}
#line 2310 "parser.tab.c"
    break;

  case 86: /* returnStmt: RETURN exp SEMICOLON  */
#line 301 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenstr; 
                                                                                  (yyval.tree)->expType = (yyvsp[-1].tree)->expType;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree);
                                                                                  yyerrok; }
#line 2320 "parser.tab.c"
    break;

  case 87: /* returnStmt: RETURN error SEMICOLON  */
#line 307 "parser.y"
                                                                                { (yyval.tree) = NULL; 
                                                                                  yyerrok; }
#line 2327 "parser.tab.c"
    break;

  case 88: /* breakStmt: BREAK SEMICOLON  */
#line 311 "parser.y"
                                                                                { (yyval.tree) = newStmtNode(BreakK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr; }
#line 2334 "parser.tab.c"
    break;

  case 89: /* exp: mutable assignop exp  */
#line 315 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2342 "parser.tab.c"
    break;

  case 90: /* exp: mutable INC  */
#line 319 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree); }
#line 2351 "parser.tab.c"
    break;

  case 91: /* exp: mutable DEC  */
#line 324 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree); }
#line 2360 "parser.tab.c"
    break;

  case 92: /* exp: simpleExp  */
#line 329 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2366 "parser.tab.c"
    break;

  case 93: /* exp: error assignop exp  */
#line 331 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2372 "parser.tab.c"
    break;

  case 94: /* exp: mutable assignop error  */
#line 332 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2378 "parser.tab.c"
    break;

  case 95: /* exp: error INC  */
#line 333 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2384 "parser.tab.c"
    break;

  case 96: /* exp: error DEC  */
#line 334 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2390 "parser.tab.c"
    break;

  case 97: /* assignop: ASGN  */
#line 337 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;}
#line 2396 "parser.tab.c"
    break;

  case 98: /* assignop: ADDASGN  */
#line 338 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;}
#line 2402 "parser.tab.c"
    break;

  case 99: /* assignop: MINUSASGN  */
#line 339 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;}
#line 2408 "parser.tab.c"
    break;

  case 100: /* assignop: MULTASGN  */
#line 340 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;}
#line 2414 "parser.tab.c"
    break;

  case 101: /* assignop: DIVASGN  */
#line 341 "parser.y"
                                                                                { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData)); (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;}
#line 2420 "parser.tab.c"
    break;

  case 102: /* simpleExp: simpleExp OR andExp  */
#line 344 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2430 "parser.tab.c"
    break;

  case 103: /* simpleExp: andExp  */
#line 350 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2436 "parser.tab.c"
    break;

  case 104: /* simpleExp: simpleExp OR error  */
#line 351 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2442 "parser.tab.c"
    break;

  case 105: /* andExp: andExp AND unaryRelExp  */
#line 354 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree);}
#line 2452 "parser.tab.c"
    break;

  case 106: /* andExp: unaryRelExp  */
#line 360 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2458 "parser.tab.c"
    break;

  case 107: /* andExp: andExp AND error  */
#line 361 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2464 "parser.tab.c"
    break;

  case 108: /* unaryRelExp: NOT unaryRelExp  */
#line 364 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;
                                                                                  (yyval.tree)->child[0] = (yyvsp[0].tree);}
#line 2473 "parser.tab.c"
    break;

  case 109: /* unaryRelExp: relExp  */
#line 369 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2479 "parser.tab.c"
    break;

  case 110: /* unaryRelExp: NOT error  */
#line 370 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2485 "parser.tab.c"
    break;

  case 111: /* relExp: sumExp relop sumExp  */
#line 373 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 2493 "parser.tab.c"
    break;

  case 112: /* relExp: sumExp relop error  */
#line 377 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2499 "parser.tab.c"
    break;

  case 113: /* relExp: sumExp  */
#line 379 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree) ;}
#line 2505 "parser.tab.c"
    break;

  case 114: /* relop: LESSTHAN  */
#line 382 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2513 "parser.tab.c"
    break;

  case 115: /* relop: LEQ  */
#line 386 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2521 "parser.tab.c"
    break;

  case 116: /* relop: GREATERTHAN  */
#line 390 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2529 "parser.tab.c"
    break;

  case 117: /* relop: GEQ  */
#line 394 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2537 "parser.tab.c"
    break;

  case 118: /* relop: EQUALS  */
#line 398 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2545 "parser.tab.c"
    break;

  case 119: /* relop: NEQ  */
#line 402 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean;}
#line 2553 "parser.tab.c"
    break;

  case 120: /* sumExp: sumExp sumop mulExp  */
#line 407 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 2561 "parser.tab.c"
    break;

  case 121: /* sumExp: mulExp  */
#line 411 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2567 "parser.tab.c"
    break;

  case 122: /* sumExp: sumExp sumop error  */
#line 412 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2573 "parser.tab.c"
    break;

  case 123: /* sumop: PLUS  */
#line 415 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2581 "parser.tab.c"
    break;

  case 124: /* sumop: MINUS  */
#line 419 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2589 "parser.tab.c"
    break;

  case 125: /* mulExp: mulExp mulop unaryExp  */
#line 424 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                                  (yyval.tree)->child[1] = (yyvsp[0].tree); }
#line 2597 "parser.tab.c"
    break;

  case 126: /* mulExp: unaryExp  */
#line 428 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2603 "parser.tab.c"
    break;

  case 127: /* mulExp: mulExp mulop error  */
#line 429 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2609 "parser.tab.c"
    break;

  case 128: /* mulop: MULT  */
#line 432 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2617 "parser.tab.c"
    break;

  case 129: /* mulop: DIVIDE  */
#line 436 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2625 "parser.tab.c"
    break;

  case 130: /* mulop: PERCENT  */
#line 440 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2633 "parser.tab.c"
    break;

  case 131: /* unaryExp: unaryop unaryExp  */
#line 445 "parser.y"
                                                                                { (yyval.tree)  = (yyvsp[-1].tree);
                                                                                  (yyval.tree)->child[0] = (yyvsp[0].tree); }
#line 2640 "parser.tab.c"
    break;

  case 132: /* unaryExp: factor  */
#line 448 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2646 "parser.tab.c"
    break;

  case 133: /* unaryExp: unaryop error  */
#line 449 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2652 "parser.tab.c"
    break;

  case 134: /* unaryop: MINUS  */
#line 452 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2660 "parser.tab.c"
    break;

  case 135: /* unaryop: MULT  */
#line 456 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2668 "parser.tab.c"
    break;

  case 136: /* unaryop: QMARK  */
#line 460 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)) ;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Integer;}
#line 2676 "parser.tab.c"
    break;

  case 137: /* factor: mutable  */
#line 465 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2682 "parser.tab.c"
    break;

  case 138: /* factor: immutable  */
#line 466 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2688 "parser.tab.c"
    break;

  case 139: /* mutable: ID  */
#line 469 "parser.y"
                                                                                { (yyval.tree) = newExpNode(IdK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenstr); }
#line 2695 "parser.tab.c"
    break;

  case 140: /* mutable: ID LBRACKET exp RBRACKET  */
#line 472 "parser.y"
                                                                                { (yyval.tree) = newExpNode(OpK, (yyvsp[-2].tokenData)); 
                                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenstr;
                                                                                  (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->child[0]->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                                  (yyval.tree)->child[0]->isArray = true;
                                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); }
#line 2706 "parser.tab.c"
    break;

  case 141: /* immutable: LPAREN exp RPAREN  */
#line 480 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); yyerrok; }
#line 2712 "parser.tab.c"
    break;

  case 142: /* immutable: call  */
#line 481 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2718 "parser.tab.c"
    break;

  case 143: /* immutable: constant  */
#line 482 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2724 "parser.tab.c"
    break;

  case 144: /* immutable: LPAREN error  */
#line 483 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2730 "parser.tab.c"
    break;

  case 145: /* call: ID LPAREN args RPAREN  */
#line 486 "parser.y"
                                                                                { (yyval.tree) = newExpNode(CallK, (yyvsp[-3].tokenData));
                                                                                  (yyval.tree)->attr.name = strdup((yyvsp[-3].tokenData)->tokenstr);
                                                                                  (yyval.tree)->child[0] = (yyvsp[-1].tree);}
#line 2738 "parser.tab.c"
    break;

  case 146: /* call: error LPAREN  */
#line 490 "parser.y"
                                                                                { (yyval.tree) = NULL; yyerrok; }
#line 2744 "parser.tab.c"
    break;

  case 147: /* args: argList  */
#line 493 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2750 "parser.tab.c"
    break;

  case 148: /* args: %empty  */
#line 494 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2756 "parser.tab.c"
    break;

  case 149: /* argList: argList COMMA exp  */
#line 497 "parser.y"
                                                                                { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree)); yyerrok; }
#line 2762 "parser.tab.c"
    break;

  case 150: /* argList: exp  */
#line 498 "parser.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 2768 "parser.tab.c"
    break;

  case 151: /* argList: argList COMMA error  */
#line 499 "parser.y"
                                                                                { (yyval.tree) = NULL; }
#line 2774 "parser.tab.c"
    break;

  case 152: /* constant: NUMCONST  */
#line 502 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                                                                                  (yyval.tree)->expType = Integer; }
#line 2782 "parser.tab.c"
    break;

  case 153: /* constant: CHARCONST  */
#line 506 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->thisTokenData = (yyvsp[0].tokenData);
                                                                                  (yyval.tree)->expType = Char; }
#line 2791 "parser.tab.c"
    break;

  case 154: /* constant: STRINGCONST  */
#line 511 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.string = strdup((yyvsp[0].tokenData)->stringvalue);
                                                                                  (yyval.tree)->isArray = true;
                                                                                  (yyval.tree)->arrLength = (yyvsp[0].tokenData)->strlength;
                                                                                  (yyval.tree)->expType = CharInt; }
#line 2801 "parser.tab.c"
    break;

  case 155: /* constant: BOOLCONST  */
#line 517 "parser.y"
                                                                                { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                                  (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue;
                                                                                  (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                                  (yyval.tree)->expType = Boolean; }
#line 2810 "parser.tab.c"
    break;


#line 2814 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 523 "parser.y"


extern int yydebug;
int main(int argc, char *argv[])
{

    int selOption = 0;
    bool printROOT = 0;
    numErrors = 0;
    numWarnings = 0;

    while((selOption = getopt(argc, argv, "dDpPMh")) != -1){

        switch(selOption){

            case 'p':
                printROOT = true;
                ALLTYPE = false;
                break;
       
            case 'P':
                printROOT = true;
                ALLTYPE = true;
                break;

            case 'd':
                yydebug = 1;
                break;           
           
            case 'D':
                symbolTable.debug(1);
                break;

            case 'M':               
                printROOT = true;
                ALLTYPE = true;
                opM = true;
                printOffset = true;
                break;

            case 'h':
                printf("usage: -c [options] [sourcefile]\n");
                printf("options:\n");
                printf("-d     - turn on parser debugging\n");
                printf("-D     - turn on symbol table debugging\n");
                printf("-h     - print this usage message\n");
                printf("-p     - print the abstract syntax tree\n");
                printf("-P     - print the abstract syntax tree plus type information\n");
                break;

            default:
                exit(1);
        }
    }

    if(argc >1){
        if((yyin = fopen(argv[argc-1], "r"))) {
            // file open successful
        }
        else {
            // failed to open file
            printf("ERROR(ARGLIST): source file \"%s\" could not be opened.\n", argv[1]);
            numErrors++;
            printf("Number of warnings: %d\n", numWarnings);
            printf("Number of errors: %d\n", numErrors);
            exit(1);
        }
    }

    initErrorProcessing();
    yyparse();

    if(printROOT && !ALLTYPE && numErrors == 0){
        printTree(ROOT, 0, ALLTYPE);
    }
    else if(printROOT && ALLTYPE && numErrors == 0){
        InitializeIO();
        semanticAnalysis(ROOT, numErrors, numWarnings);

        if(numErrors < 1)
        {  
            printTree(ROOT, 0, ALLTYPE);

            if(printOffset){
                printf("Offset for end of global space: %d\n", goffset);
            }

        }
    }

    printf("Number of warnings: %d\n", numWarnings);
    printf("Number of errors: %d\n", numErrors);

    return 0;
}
