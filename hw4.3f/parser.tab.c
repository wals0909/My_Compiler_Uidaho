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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>  
#include <getopt.h>

extern int yylex();
extern FILE *yyin;
extern int line;       // ERR line number from the scanner!!
extern int numErrors;  // ERR err count
int numWarnings;       // ERR warning count
bool ALLTYPE = false;

static TreeNode *ROOT;

extern SymbolTable symbolTable;

#define YYERROR_VERBOSE
void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", line, msg);
    numErrors++;
}


#line 110 "parser.tab.c"

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
  YYSYMBOL_ASGN = 7,                       /* ASGN  */
  YYSYMBOL_ADDASGN = 8,                    /* ADDASGN  */
  YYSYMBOL_SUBASS = 9,                     /* SUBASS  */
  YYSYMBOL_INC = 10,                       /* INC  */
  YYSYMBOL_DEC = 11,                       /* DEC  */
  YYSYMBOL_GEQ = 12,                       /* GEQ  */
  YYSYMBOL_LEQ = 13,                       /* LEQ  */
  YYSYMBOL_NEQ = 14,                       /* NEQ  */
  YYSYMBOL_MULASS = 15,                    /* MULASS  */
  YYSYMBOL_DIVASS = 16,                    /* DIVASS  */
  YYSYMBOL_INT = 17,                       /* INT  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_BY = 21,                        /* BY  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_THEN = 23,                      /* THEN  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_BOOL = 27,                      /* BOOL  */
  YYSYMBOL_CHAR = 28,                      /* CHAR  */
  YYSYMBOL_STATIC = 29,                    /* STATIC  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_BEGN = 31,                      /* BEGN  */
  YYSYMBOL_FINISH = 32,                    /* FINISH  */
  YYSYMBOL_DO = 33,                        /* DO  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_TO = 35,                        /* TO  */
  YYSYMBOL_BOOLCONST = 36,                 /* BOOLCONST  */
  YYSYMBOL_QUESTION = 37,                  /* QUESTION  */
  YYSYMBOL_LESS = 38,                      /* LESS  */
  YYSYMBOL_GREAT = 39,                     /* GREAT  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_EQUAL = 41,                     /* EQUAL  */
  YYSYMBOL_MULT = 42,                      /* MULT  */
  YYSYMBOL_DIV = 43,                       /* DIV  */
  YYSYMBOL_MOD = 44,                       /* MOD  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_OBRACKET = 46,                  /* OBRACKET  */
  YYSYMBOL_CBRACKET = 47,                  /* CBRACKET  */
  YYSYMBOL_MINUS = 48,                     /* MINUS  */
  YYSYMBOL_COLON = 49,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 50,                 /* SEMICOLON  */
  YYSYMBOL_OPAREN = 51,                    /* OPAREN  */
  YYSYMBOL_CPAREN = 52,                    /* CPAREN  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_declarationList = 55,           /* declarationList  */
  YYSYMBOL_declaration = 56,               /* declaration  */
  YYSYMBOL_varDeclaration = 57,            /* varDeclaration  */
  YYSYMBOL_scopedtypespecificer = 58,      /* scopedtypespecificer  */
  YYSYMBOL_vardeclarationList = 59,        /* vardeclarationList  */
  YYSYMBOL_varDeclarationInit = 60,        /* varDeclarationInit  */
  YYSYMBOL_varDeclarationId = 61,          /* varDeclarationId  */
  YYSYMBOL_typespec = 62,                  /* typespec  */
  YYSYMBOL_funDeclaration = 63,            /* funDeclaration  */
  YYSYMBOL_parameters = 64,                /* parameters  */
  YYSYMBOL_parameterList = 65,             /* parameterList  */
  YYSYMBOL_parameterTypeList = 66,         /* parameterTypeList  */
  YYSYMBOL_parameterIdList = 67,           /* parameterIdList  */
  YYSYMBOL_parameterId = 68,               /* parameterId  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_matched = 70,                   /* matched  */
  YYSYMBOL_unmatched = 71,                 /* unmatched  */
  YYSYMBOL_expstatement = 72,              /* expstatement  */
  YYSYMBOL_statementEnd = 73,              /* statementEnd  */
  YYSYMBOL_compoundstatement = 74,         /* compoundstatement  */
  YYSYMBOL_localdeclaration = 75,          /* localdeclaration  */
  YYSYMBOL_statementList = 76,             /* statementList  */
  YYSYMBOL_iterRange = 77,                 /* iterRange  */
  YYSYMBOL_returnstatement = 78,           /* returnstatement  */
  YYSYMBOL_breakstatement = 79,            /* breakstatement  */
  YYSYMBOL_asgnop = 80,                    /* asgnop  */
  YYSYMBOL_exp = 81,                       /* exp  */
  YYSYMBOL_simpleExp = 82,                 /* simpleExp  */
  YYSYMBOL_andExp = 83,                    /* andExp  */
  YYSYMBOL_relExp = 84,                    /* relExp  */
  YYSYMBOL_unaryRelExp = 85,               /* unaryRelExp  */
  YYSYMBOL_operator = 86,                  /* operator  */
  YYSYMBOL_sumExp = 87,                    /* sumExp  */
  YYSYMBOL_sumop = 88,                     /* sumop  */
  YYSYMBOL_mulExp = 89,                    /* mulExp  */
  YYSYMBOL_mulop = 90,                     /* mulop  */
  YYSYMBOL_unaryExp = 91,                  /* unaryExp  */
  YYSYMBOL_unaryop = 92,                   /* unaryop  */
  YYSYMBOL_mutable = 93,                   /* mutable  */
  YYSYMBOL_immutable = 94,                 /* immutable  */
  YYSYMBOL_factor = 95,                    /* factor  */
  YYSYMBOL_call = 96,                      /* call  */
  YYSYMBOL_args = 97,                      /* args  */
  YYSYMBOL_argList = 98,                   /* argList  */
  YYSYMBOL_constant = 99                   /* constant  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    70,    71,    74,    75,    79,    83,    88,
      92,    93,    97,    98,   102,   106,   114,   115,   116,   122,
     131,   138,   139,   144,   145,   149,   153,   154,   157,   160,
     166,   167,   170,   171,   176,   181,   189,   199,   204,   208,
     213,   224,   225,   228,   229,   230,   231,   236,   243,   244,
     247,   248,   251,   255,   263,   266,   274,   279,   283,   287,
     291,   295,   301,   306,   308,   313,   321,   327,   331,   337,
     340,   344,   347,   352,   355,   359,   364,   368,   373,   377,
     383,   387,   390,   394,   400,   404,   407,   411,   415,   421,
     424,   427,   431,   435,   441,   444,   453,   454,   455,   458,
     459,   463,   469,   470,   473,   474,   476,   480,   485,   491
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMCONST",
  "CHARCONST", "STRINGCONST", "ASGN", "ADDASGN", "SUBASS", "INC", "DEC",
  "GEQ", "LEQ", "NEQ", "MULASS", "DIVASS", "INT", "IF", "OR", "NOT", "BY",
  "ELSE", "THEN", "FOR", "BREAK", "RETURN", "BOOL", "CHAR", "STATIC",
  "AND", "BEGN", "FINISH", "DO", "WHILE", "TO", "BOOLCONST", "QUESTION",
  "LESS", "GREAT", "PLUS", "EQUAL", "MULT", "DIV", "MOD", "COMMA",
  "OBRACKET", "CBRACKET", "MINUS", "COLON", "SEMICOLON", "OPAREN",
  "CPAREN", "$accept", "program", "declarationList", "declaration",
  "varDeclaration", "scopedtypespecificer", "vardeclarationList",
  "varDeclarationInit", "varDeclarationId", "typespec", "funDeclaration",
  "parameters", "parameterList", "parameterTypeList", "parameterIdList",
  "parameterId", "statement", "matched", "unmatched", "expstatement",
  "statementEnd", "compoundstatement", "localdeclaration", "statementList",
  "iterRange", "returnstatement", "breakstatement", "asgnop", "exp",
  "simpleExp", "andExp", "relExp", "unaryRelExp", "operator", "sumExp",
  "sumop", "mulExp", "mulop", "unaryExp", "unaryop", "mutable",
  "immutable", "factor", "call", "args", "argList", "constant", YY_NULLPTR
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

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,   -30,  -133,  -133,  -133,    28,    58,  -133,  -133,    60,
    -133,    38,  -133,  -133,    42,    39,  -133,     7,    84,    47,
      56,  -133,   103,    38,   110,  -133,    74,    68,    76,  -133,
      95,    38,    87,    86,    93,  -133,    50,  -133,  -133,  -133,
      74,  -133,  -133,  -133,  -133,    74,   127,   121,  -133,  -133,
     214,    89,  -133,   208,  -133,  -133,  -133,  -133,  -133,   105,
      84,  -133,  -133,  -133,  -133,    95,    74,    74,  -133,   102,
     127,   231,    74,    74,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,   208,   208,  -133,  -133,  -133,   208,  -133,  -133,
    -133,    41,  -133,   109,  -133,   107,   112,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,    74,   121,  -133,   -29,    89,
    -133,    38,  -133,   110,     9,  -133,  -133,    74,  -133,   110,
      52,    74,   164,   118,   183,  -133,    74,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,   119,  -133,    53,  -133,
      85,    25,  -133,  -133,   120,    -3,  -133,  -133,   124,    74,
      74,  -133,   124,  -133,   149,   140,   -13,   143,  -133,  -133,
     124,   124,    74,   159,  -133,  -133,  -133,  -133,   -11,    74,
     175,    74,  -133,    74,    96,    29,    -2,   127,   159,    74,
     159,   158,   148,   159,   159
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    16,    18,    17,     0,     2,     4,     6,     0,
       5,    22,     1,     3,    14,     0,    11,    12,     0,     0,
      21,    24,     0,    22,     0,     7,     0,    28,    25,    27,
       0,     0,     0,     0,    14,    10,    94,   106,   107,   109,
       0,   108,    93,    92,    91,     0,    13,    67,    73,    69,
      71,    81,    85,     0,    99,   100,    90,    97,    98,     0,
       0,    49,    20,    23,    15,     0,     0,   103,    72,     0,
      63,    99,     0,     0,    75,    77,    79,    76,    74,    82,
      78,    83,     0,     0,    86,    87,    88,     0,    89,    29,
      26,    51,    19,     0,   105,     0,   102,    96,    57,    58,
      59,    64,    65,    60,    61,     0,    66,    68,    70,    80,
      84,     0,    48,     0,     0,    95,   101,     0,    62,     0,
       0,     0,     0,     0,     0,    47,     0,    42,    50,    30,
      31,    43,    32,    44,    46,    45,     0,   104,     0,     9,
       0,     0,    56,    54,     0,     0,    41,     8,     0,     0,
       0,    55,     0,    38,    30,     0,     0,     0,    34,    39,
       0,     0,     0,     0,    33,    37,    35,    40,    52,     0,
       0,     0,    36,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,   176,  -133,  -133,   -65,   167,  -133,     1,
    -133,   169,  -133,   163,  -133,   137,    51,  -111,   -70,  -133,
    -133,   -21,  -133,  -133,  -132,  -133,  -133,  -133,   -41,   -26,
     126,  -133,   -20,  -133,   122,  -133,   117,  -133,   -48,  -133,
     -43,  -133,  -133,  -133,  -133,  -133,  -133
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   112,    15,    16,    17,    18,
      10,    19,    20,    21,    28,    29,   128,   158,   130,   131,
     132,   133,    91,   114,   155,   134,   135,   105,   136,    70,
      47,    48,    49,    82,    50,    83,    51,    87,    52,    53,
      54,    55,    56,    57,    95,    96,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,     9,    71,   129,    69,    88,    72,     9,    72,    62,
     173,    79,    36,    37,    38,    39,    72,    72,   157,    81,
      68,    11,   162,    71,    71,    93,    94,   121,    12,    40,
     152,   180,   149,   122,   123,   124,   179,   154,   150,   110,
      61,   125,   150,   126,    92,    41,    42,   182,   120,   164,
     166,    43,   172,   107,   138,     2,    26,    44,     2,   127,
      45,     1,    71,    14,   118,     3,     4,   181,     3,     4,
     111,    71,   164,   166,    71,     2,   137,    36,    37,    38,
      39,    71,   159,   144,    24,     3,     4,    27,    22,    25,
     165,   167,   113,    23,    40,   140,    66,    24,    24,    30,
     145,    67,   139,   147,    72,    71,    31,    32,   148,    71,
      41,    42,   119,    34,    59,    72,    43,    71,    71,   178,
      71,    60,    44,   156,   156,    45,    61,    36,    37,    38,
      39,    84,    85,    86,    64,    71,   168,    71,    65,    22,
      71,    71,   121,   174,    40,   176,    72,   177,   122,   123,
     124,    73,    89,   156,    97,    61,   115,   117,   126,   116,
      41,    42,    36,    37,    38,    39,    43,   141,   142,   146,
     151,   160,    44,   161,   127,    45,   163,   169,   175,    40,
     183,   184,    13,   170,   123,   124,    36,    37,    38,    39,
      61,    35,    33,   171,    63,    41,    42,    90,   106,   153,
     109,    43,     0,    40,   108,     0,     0,    44,     0,   127,
      45,    36,    37,    38,    39,     0,     0,     0,     0,    41,
      42,     0,     0,     0,     0,    43,    74,    75,    76,     0,
       0,    44,     0,   143,    45,     0,     0,     0,    98,    99,
     100,   101,   102,     0,    41,    42,   103,   104,     0,     0,
      43,     0,    77,    78,    79,    80,    44,     0,     0,    45,
       0,     0,    81
};

static const yytype_int16 yycheck[] =
{
      26,     0,    45,   114,    45,    53,    19,     6,    19,    30,
      21,    40,     3,     4,     5,     6,    19,    19,   150,    48,
      40,    51,    35,    66,    67,    66,    67,    18,     0,    20,
      33,    33,     7,    24,    25,    26,     7,   148,    13,    87,
      31,    32,    13,    34,    65,    36,    37,   179,   113,   160,
     161,    42,   163,    73,   119,    17,    49,    48,    17,    50,
      51,     3,   105,     3,   105,    27,    28,   178,    27,    28,
      29,   114,   183,   184,   117,    17,   117,     3,     4,     5,
       6,   124,   152,   124,    45,    27,    28,     3,    46,    50,
     160,   161,    91,    51,    20,   121,    46,    45,    45,    52,
     126,    51,    50,    50,    19,   148,    50,     4,    23,   152,
      36,    37,   111,     3,    46,    19,    42,   160,   161,    23,
     163,    45,    48,   149,   150,    51,    31,     3,     4,     5,
       6,    42,    43,    44,    47,   178,   162,   180,    52,    46,
     183,   184,    18,   169,    20,   171,    19,   173,    24,    25,
      26,    30,    47,   179,    52,    31,    47,    45,    34,    52,
      36,    37,     3,     4,     5,     6,    42,     3,    50,    50,
      50,    22,    48,    33,    50,    51,    33,    18,     3,    20,
      22,    33,     6,    24,    25,    26,     3,     4,     5,     6,
      31,    24,    23,    34,    31,    36,    37,    60,    72,   148,
      83,    42,    -1,    20,    82,    -1,    -1,    48,    -1,    50,
      51,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    42,    12,    13,    14,    -1,
      -1,    48,    -1,    50,    51,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    -1,    36,    37,    15,    16,    -1,    -1,
      42,    -1,    38,    39,    40,    41,    48,    -1,    -1,    51,
      -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    17,    27,    28,    54,    55,    56,    57,    62,
      63,    51,     0,    56,     3,    59,    60,    61,    62,    64,
      65,    66,    46,    51,    45,    50,    49,     3,    67,    68,
      52,    50,     4,    64,     3,    60,     3,     4,     5,     6,
      20,    36,    37,    42,    48,    51,    82,    83,    84,    85,
      87,    89,    91,    92,    93,    94,    95,    96,    99,    46,
      45,    31,    74,    66,    47,    52,    46,    51,    85,    81,
      82,    93,    19,    30,    12,    13,    14,    38,    39,    40,
      41,    48,    86,    88,    42,    43,    44,    90,    91,    47,
      68,    75,    74,    81,    81,    97,    98,    52,     7,     8,
       9,    10,    11,    15,    16,    80,    83,    85,    87,    89,
      91,    29,    58,    62,    76,    47,    52,    45,    81,    62,
      59,    18,    24,    25,    26,    32,    34,    50,    69,    70,
      71,    72,    73,    74,    78,    79,    81,    81,    59,    50,
      82,     3,    50,    50,    81,    82,    50,    50,    23,     7,
      13,    50,    33,    69,    70,    77,    82,    77,    70,    71,
      22,    33,    35,    33,    70,    71,    70,    71,    82,    18,
      24,    34,    70,    21,    82,     3,    82,    82,    23,     7,
      33,    70,    77,    22,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    80,    80,    80,
      80,    80,    81,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    90,    91,
      91,    92,    92,    92,    93,    93,    94,    94,    94,    95,
      95,    96,    97,    97,    98,    98,    99,    99,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     3,
       3,     1,     1,     3,     1,     4,     1,     1,     1,     6,
       5,     1,     0,     3,     1,     2,     3,     1,     1,     3,
       1,     1,     1,     6,     4,     6,     6,     6,     4,     4,
       6,     2,     1,     1,     1,     1,     1,     4,     2,     0,
       2,     0,     3,     5,     2,     3,     2,     1,     1,     1,
       1,     1,     3,     1,     2,     2,     3,     1,     3,     1,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     3,     1,     1,     1,
       1,     4,     1,     0,     3,     1,     1,     1,     1,     1
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
  case 2: /* program: declarationList  */
#line 66 "parser.y"
                                                                 { ROOT = (yyvsp[0].tree);}
#line 1346 "parser.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 70 "parser.y"
                                                                 { (yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1352 "parser.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 71 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1358 "parser.tab.c"
    break;

  case 5: /* declaration: funDeclaration  */
#line 74 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1364 "parser.tab.c"
    break;

  case 6: /* declaration: varDeclaration  */
#line 75 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1370 "parser.tab.c"
    break;

  case 7: /* varDeclaration: typespec vardeclarationList SEMICOLON  */
#line 79 "parser.y"
                                                              { (yyval.tree) = (yyvsp[-1].tree); setType((yyval.tree), (yyvsp[-2].type)); }
#line 1376 "parser.tab.c"
    break;

  case 8: /* scopedtypespecificer: STATIC typespec vardeclarationList SEMICOLON  */
#line 83 "parser.y"
                                                               { (yyval.tree) = (yyvsp[-1].tree); 
                                                                   (yyval.tree)->isStatic = true; 
                                                                   setType((yyval.tree), (yyvsp[-2].type));
                                                                  }
#line 1385 "parser.tab.c"
    break;

  case 9: /* scopedtypespecificer: typespec vardeclarationList SEMICOLON  */
#line 88 "parser.y"
                                                               { (yyval.tree) = (yyvsp[-1].tree); setType((yyval.tree), (yyvsp[-2].type));}
#line 1391 "parser.tab.c"
    break;

  case 10: /* vardeclarationList: vardeclarationList COMMA varDeclarationInit  */
#line 92 "parser.y"
                                                                 { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1397 "parser.tab.c"
    break;

  case 11: /* vardeclarationList: varDeclarationInit  */
#line 93 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1403 "parser.tab.c"
    break;

  case 12: /* varDeclarationInit: varDeclarationId  */
#line 97 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1409 "parser.tab.c"
    break;

  case 13: /* varDeclarationInit: varDeclarationId COLON simpleExp  */
#line 98 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[-2].tree); (yyvsp[-2].tree)->child[0] = (yyvsp[0].tree);}
#line 1415 "parser.tab.c"
    break;

  case 14: /* varDeclarationId: ID  */
#line 102 "parser.y"
                                                                 { (yyval.tree) = newDeclNode(VarK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                 }
#line 1423 "parser.tab.c"
    break;

  case 15: /* varDeclarationId: ID OBRACKET NUMCONST CBRACKET  */
#line 106 "parser.y"
                                                                 { (yyval.tree) = newDeclNode(VarK, (yyvsp[-3].tokenData));       
                                                                   (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                   (yyval.tree)->isArray = true;
                                                                   (yyval.tree)->thisTokenData = (yyvsp[-3].tokenData); 
                                                                   (yyval.tree)->expType = UndefinedType;
                                                                 }
#line 1434 "parser.tab.c"
    break;

  case 16: /* typespec: INT  */
#line 114 "parser.y"
                                                              { (yyval.type) = Integer; }
#line 1440 "parser.tab.c"
    break;

  case 17: /* typespec: CHAR  */
#line 115 "parser.y"
                                                                 { (yyval.type) = Char; }
#line 1446 "parser.tab.c"
    break;

  case 18: /* typespec: BOOL  */
#line 116 "parser.y"
                                                                 { (yyval.type) = Boolean;}
#line 1452 "parser.tab.c"
    break;

  case 19: /* funDeclaration: typespec ID OPAREN parameters CPAREN compoundstatement  */
#line 124 "parser.y"
                                                                 { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));     
                                                                   (yyval.tree)->attr.name = (yyvsp[-4].tokenData)->tokenstr;
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                   (yyval.tree)->expType = (yyvsp[-5].type);
                                                                 }
#line 1463 "parser.tab.c"
    break;

  case 20: /* funDeclaration: ID OPAREN parameters CPAREN compoundstatement  */
#line 131 "parser.y"
                                                                 { (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData));   
                                                                   (yyval.tree)->attr.name = (yyvsp[-4].tokenData)->tokenstr;
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                 }
#line 1473 "parser.tab.c"
    break;

  case 21: /* parameters: parameterList  */
#line 138 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1479 "parser.tab.c"
    break;

  case 22: /* parameters: %empty  */
#line 139 "parser.y"
                                                                 { (yyval.tree) = NULL; }
#line 1485 "parser.tab.c"
    break;

  case 23: /* parameterList: parameterList SEMICOLON parameterTypeList  */
#line 144 "parser.y"
                                                                 { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1491 "parser.tab.c"
    break;

  case 24: /* parameterList: parameterTypeList  */
#line 145 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1497 "parser.tab.c"
    break;

  case 25: /* parameterTypeList: typespec parameterIdList  */
#line 149 "parser.y"
                                                              { (yyval.tree) = (yyvsp[0].tree); setType((yyval.tree), (yyvsp[-1].type)); }
#line 1503 "parser.tab.c"
    break;

  case 26: /* parameterIdList: parameterIdList COMMA parameterId  */
#line 153 "parser.y"
                                                                 { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1509 "parser.tab.c"
    break;

  case 27: /* parameterIdList: parameterId  */
#line 154 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1515 "parser.tab.c"
    break;

  case 28: /* parameterId: ID  */
#line 157 "parser.y"
                                                                 { (yyval.tree) = newDeclNode(ParamK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr; 
                                                                 }
#line 1523 "parser.tab.c"
    break;

  case 29: /* parameterId: ID OBRACKET CBRACKET  */
#line 160 "parser.y"
                                                                 { (yyval.tree) = newDeclNode(ParamK, (yyvsp[-2].tokenData));
                                                                   (yyval.tree)->isArray = true;
                                                                   (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenstr; 
                                                                 }
#line 1532 "parser.tab.c"
    break;

  case 30: /* statement: matched  */
#line 166 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1538 "parser.tab.c"
    break;

  case 31: /* statement: unmatched  */
#line 167 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1544 "parser.tab.c"
    break;

  case 32: /* matched: statementEnd  */
#line 170 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1550 "parser.tab.c"
    break;

  case 33: /* matched: IF simpleExp THEN matched ELSE matched  */
#line 171 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData)); 
                                                                   (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[2] = (yyvsp[0].tree);
                                                                 }
#line 1560 "parser.tab.c"
    break;

  case 34: /* matched: WHILE simpleExp DO matched  */
#line 176 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                 }
#line 1570 "parser.tab.c"
    break;

  case 35: /* matched: FOR ID ASGN iterRange DO matched  */
#line 181 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                   (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                   (yyval.tree)->child[0]->expType = Integer;
                                                                   (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                   (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[2] = (yyvsp[0].tree);
                                                                   
                                                                 }
#line 1583 "parser.tab.c"
    break;

  case 36: /* matched: FOR ID LEQ iterRange DO matched  */
#line 189 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                   (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                   (yyval.tree)->child[0]->expType = Integer;
                                                                   (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                   (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[2] = (yyvsp[0].tree);
                                                                   
                                                                 }
#line 1596 "parser.tab.c"
    break;

  case 37: /* unmatched: IF simpleExp THEN matched ELSE unmatched  */
#line 199 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(IfK, (yyvsp[-5].tokenData)); 
                                                                   (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[2] = (yyvsp[0].tree); 
                                                                 }
#line 1606 "parser.tab.c"
    break;

  case 38: /* unmatched: IF simpleExp THEN statement  */
#line 204 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tokenData));              
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree); 
                                                                 }
#line 1615 "parser.tab.c"
    break;

  case 39: /* unmatched: WHILE simpleExp DO unmatched  */
#line 208 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                 }
#line 1625 "parser.tab.c"
    break;

  case 40: /* unmatched: FOR ID ASGN iterRange DO unmatched  */
#line 213 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(ForK, (yyvsp[-5].tokenData));
                                                                   (yyval.tree)->child[0] = newDeclNode(VarK, (yyvsp[-4].tokenData));
                                                                   (yyval.tree)->child[0]->expType = Integer;
                                                                   (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                   (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[2] = (yyvsp[0].tree);
                                                                   
                                                                 }
#line 1638 "parser.tab.c"
    break;

  case 41: /* expstatement: exp SEMICOLON  */
#line 224 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[-1].tree); }
#line 1644 "parser.tab.c"
    break;

  case 42: /* expstatement: SEMICOLON  */
#line 225 "parser.y"
                                                                 { (yyval.tree) = NULL; }
#line 1650 "parser.tab.c"
    break;

  case 43: /* statementEnd: expstatement  */
#line 228 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1656 "parser.tab.c"
    break;

  case 44: /* statementEnd: compoundstatement  */
#line 229 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1662 "parser.tab.c"
    break;

  case 45: /* statementEnd: breakstatement  */
#line 230 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1668 "parser.tab.c"
    break;

  case 46: /* statementEnd: returnstatement  */
#line 231 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1674 "parser.tab.c"
    break;

  case 47: /* compoundstatement: BEGN localdeclaration statementList FINISH  */
#line 236 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(CompoundK, (yyvsp[-3].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[-1].tree);
                                                                 }
#line 1683 "parser.tab.c"
    break;

  case 48: /* localdeclaration: localdeclaration scopedtypespecificer  */
#line 243 "parser.y"
                                                              { (yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1689 "parser.tab.c"
    break;

  case 49: /* localdeclaration: %empty  */
#line 244 "parser.y"
                                                                 { (yyval.tree) = NULL; }
#line 1695 "parser.tab.c"
    break;

  case 50: /* statementList: statementList statement  */
#line 247 "parser.y"
                                                                 { (yyval.tree) = addSibling((yyvsp[-1].tree), (yyvsp[0].tree)); }
#line 1701 "parser.tab.c"
    break;

  case 51: /* statementList: %empty  */
#line 248 "parser.y"
                                                                 { (yyval.tree) = NULL; }
#line 1707 "parser.tab.c"
    break;

  case 52: /* iterRange: simpleExp TO simpleExp  */
#line 251 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-1].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                 }
#line 1716 "parser.tab.c"
    break;

  case 53: /* iterRange: simpleExp TO simpleExp BY simpleExp  */
#line 255 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(RangeK, (yyvsp[-3].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-4].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[2] = (yyvsp[0].tree);
                                                                 }
#line 1726 "parser.tab.c"
    break;

  case 54: /* returnstatement: RETURN SEMICOLON  */
#line 263 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-1].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;
                                                                 }
#line 1734 "parser.tab.c"
    break;

  case 55: /* returnstatement: RETURN exp SEMICOLON  */
#line 266 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-2].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-1].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = (yyvsp[-1].tree)->expType;
                                                                 }
#line 1744 "parser.tab.c"
    break;

  case 56: /* breakstatement: BREAK SEMICOLON  */
#line 274 "parser.y"
                                                                 { (yyval.tree) = newStmtNode(BreakK, (yyvsp[-1].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;
                                                                 }
#line 1752 "parser.tab.c"
    break;

  case 57: /* asgnop: ASGN  */
#line 279 "parser.y"
                                                                 { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   //$$->expType = Integer;
                                                                 }
#line 1761 "parser.tab.c"
    break;

  case 58: /* asgnop: ADDASGN  */
#line 283 "parser.y"
                                                                 { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   //$$->expType = Integer;
                                                                 }
#line 1770 "parser.tab.c"
    break;

  case 59: /* asgnop: SUBASS  */
#line 287 "parser.y"
                                                                 { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   //$$->expType = Integer;
                                                                 }
#line 1779 "parser.tab.c"
    break;

  case 60: /* asgnop: MULASS  */
#line 291 "parser.y"
                                                                 { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   //$$->expType = Integer;
                                                                 }
#line 1788 "parser.tab.c"
    break;

  case 61: /* asgnop: DIVASS  */
#line 295 "parser.y"
                                                                 { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   //$$->expType = Integer;
                                                                 }
#line 1797 "parser.tab.c"
    break;

  case 62: /* exp: mutable asgnop exp  */
#line 301 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[-1].tree); 
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                 }
#line 1806 "parser.tab.c"
    break;

  case 63: /* exp: simpleExp  */
#line 306 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1812 "parser.tab.c"
    break;

  case 64: /* exp: mutable INC  */
#line 308 "parser.y"
                                                                 { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-1].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 1822 "parser.tab.c"
    break;

  case 65: /* exp: mutable DEC  */
#line 313 "parser.y"
                                                                 { (yyval.tree) = newExpNode(AssignK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-1].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 1832 "parser.tab.c"
    break;

  case 66: /* simpleExp: simpleExp OR andExp  */
#line 321 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1843 "parser.tab.c"
    break;

  case 67: /* simpleExp: andExp  */
#line 327 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1849 "parser.tab.c"
    break;

  case 68: /* andExp: andExp AND unaryRelExp  */
#line 331 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1860 "parser.tab.c"
    break;

  case 69: /* andExp: unaryRelExp  */
#line 337 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1866 "parser.tab.c"
    break;

  case 70: /* relExp: sumExp operator sumExp  */
#line 340 "parser.y"
                                                                    { (yyval.tree) = (yyvsp[-1].tree); 
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                 }
#line 1875 "parser.tab.c"
    break;

  case 71: /* relExp: sumExp  */
#line 344 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1881 "parser.tab.c"
    break;

  case 72: /* unaryRelExp: NOT unaryRelExp  */
#line 347 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[0].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[-1].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1891 "parser.tab.c"
    break;

  case 73: /* unaryRelExp: relExp  */
#line 352 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1897 "parser.tab.c"
    break;

  case 74: /* operator: GREAT  */
#line 355 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1906 "parser.tab.c"
    break;

  case 75: /* operator: GEQ  */
#line 359 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1915 "parser.tab.c"
    break;

  case 76: /* operator: LESS  */
#line 364 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1924 "parser.tab.c"
    break;

  case 77: /* operator: LEQ  */
#line 368 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1933 "parser.tab.c"
    break;

  case 78: /* operator: EQUAL  */
#line 373 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1942 "parser.tab.c"
    break;

  case 79: /* operator: NEQ  */
#line 377 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Boolean;
                                                                 }
#line 1951 "parser.tab.c"
    break;

  case 80: /* sumExp: sumExp sumop mulExp  */
#line 383 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[-1].tree); 
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                 }
#line 1960 "parser.tab.c"
    break;

  case 81: /* sumExp: mulExp  */
#line 387 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1966 "parser.tab.c"
    break;

  case 82: /* sumop: PLUS  */
#line 390 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 1975 "parser.tab.c"
    break;

  case 83: /* sumop: MINUS  */
#line 394 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 1984 "parser.tab.c"
    break;

  case 84: /* mulExp: mulExp mulop unaryExp  */
#line 400 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[-1].tree); 
                                                                   (yyval.tree)->child[0] = (yyvsp[-2].tree);
                                                                   (yyval.tree)->child[1] = (yyvsp[0].tree);
                                                                 }
#line 1993 "parser.tab.c"
    break;

  case 85: /* mulExp: unaryExp  */
#line 404 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 1999 "parser.tab.c"
    break;

  case 86: /* mulop: MULT  */
#line 407 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 2008 "parser.tab.c"
    break;

  case 87: /* mulop: DIV  */
#line 411 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 2017 "parser.tab.c"
    break;

  case 88: /* mulop: MOD  */
#line 415 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 2026 "parser.tab.c"
    break;

  case 89: /* unaryExp: unaryop unaryExp  */
#line 421 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[-1].tree); 
                                                                   (yyval.tree)->child[0] = (yyvsp[0].tree);
                                                                 }
#line 2034 "parser.tab.c"
    break;

  case 90: /* unaryExp: factor  */
#line 424 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 2040 "parser.tab.c"
    break;

  case 91: /* unaryop: MINUS  */
#line 427 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 2049 "parser.tab.c"
    break;

  case 92: /* unaryop: MULT  */
#line 431 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 2058 "parser.tab.c"
    break;

  case 93: /* unaryop: QUESTION  */
#line 435 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 2067 "parser.tab.c"
    break;

  case 94: /* mutable: ID  */
#line 441 "parser.y"
                                                                 { (yyval.tree) = newExpNode(IdK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;    
                                                                 }
#line 2075 "parser.tab.c"
    break;

  case 95: /* mutable: ID OBRACKET exp CBRACKET  */
#line 444 "parser.y"
                                                                 { (yyval.tree) = newExpNode(OpK, (yyvsp[-2].tokenData));  
                                                                  (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData));
                                                                  (yyval.tree)->child[0]->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                  (yyval.tree)->child[0]->isArray = true;
                                                                  (yyval.tree)->child[1] = (yyvsp[-1].tree); 
                                                                  (yyval.tree)->attr.name = (yyvsp[-2].tokenData)->tokenstr;
                                                                 }
#line 2087 "parser.tab.c"
    break;

  case 96: /* immutable: OPAREN exp CPAREN  */
#line 453 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[-1].tree); }
#line 2093 "parser.tab.c"
    break;

  case 97: /* immutable: call  */
#line 454 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 2099 "parser.tab.c"
    break;

  case 98: /* immutable: constant  */
#line 455 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 2105 "parser.tab.c"
    break;

  case 99: /* factor: mutable  */
#line 458 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 2111 "parser.tab.c"
    break;

  case 100: /* factor: immutable  */
#line 459 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 2117 "parser.tab.c"
    break;

  case 101: /* call: ID OPAREN args CPAREN  */
#line 463 "parser.y"
                                                                 { (yyval.tree) = newExpNode(CallK, (yyvsp[-3].tokenData));
                                                                   (yyval.tree)->child[0] = (yyvsp[-1].tree);
                                                                   (yyval.tree)->attr.name = (yyvsp[-3].tokenData)->tokenstr;
                                                                 }
#line 2126 "parser.tab.c"
    break;

  case 102: /* args: argList  */
#line 469 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 2132 "parser.tab.c"
    break;

  case 103: /* args: %empty  */
#line 470 "parser.y"
                                                                 { (yyval.tree) = NULL; }
#line 2138 "parser.tab.c"
    break;

  case 104: /* argList: argList COMMA exp  */
#line 473 "parser.y"
                                                                 { (yyval.tree) = addSibling((yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 2144 "parser.tab.c"
    break;

  case 105: /* argList: exp  */
#line 474 "parser.y"
                                                                 { (yyval.tree) = (yyvsp[0].tree); }
#line 2150 "parser.tab.c"
    break;

  case 106: /* constant: NUMCONST  */
#line 476 "parser.y"
                                                                 { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue; 
                                                                   (yyval.tree)->expType = Integer;
                                                                 }
#line 2159 "parser.tab.c"
    break;

  case 107: /* constant: CHARCONST  */
#line 480 "parser.y"
                                                                 { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   (yyval.tree)->thisTokenData = (yyvsp[0].tokenData); 
                                                                   (yyval.tree)->expType = Char;
                                                                 }
#line 2169 "parser.tab.c"
    break;

  case 108: /* constant: BOOLCONST  */
#line 485 "parser.y"
                                                                 { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.value = (yyvsp[0].tokenData)->nvalue; 
                                                                   (yyval.tree)->expType = Boolean;
                                                                   (yyval.tree)->attr.name = (yyvsp[0].tokenData)->tokenstr;
                                                                   
                                                                 }
#line 2180 "parser.tab.c"
    break;

  case 109: /* constant: STRINGCONST  */
#line 491 "parser.y"
                                                                 { (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData));
                                                                   (yyval.tree)->attr.string = (yyvsp[0].tokenData)->stringvalue;
                                                                   (yyval.tree)->isArray = true;
                                                                   (yyval.tree)->expType = CharInt;
                                                                 }
#line 2190 "parser.tab.c"
    break;


#line 2194 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 497 "parser.y"


extern int yydebug;
int main(int argc, char *argv[])
{

    int selOption = 0;
    bool printAST = 0;
    numErrors = 0;
    numWarnings = 0;

    while((selOption = getopt(argc, argv, "dDpPh")) != -1){

        switch(selOption){

            case 'p':
                printAST = true;
                ALLTYPE = false;
                break;
       
            case 'P':
                printAST = true;
                ALLTYPE = true;
                break;

            case 'd':
                yydebug = 1;
                break;           
           
            case 'D':
                symbolTable.debug(1);
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

    yyparse();

    if(printAST && !ALLTYPE){
        printTree(ROOT, 0, ALLTYPE);
    }
    else if(printAST && ALLTYPE){
        InitializeIO();
        semanticAnalysis(ROOT, numErrors, numWarnings);

        if(numErrors < 1)
        {  
            printTree(ROOT, 0, ALLTYPE);
        }
    }

    printf("Number of warnings: %d\n", numWarnings);
    printf("Number of errors: %d\n", numErrors);

    return 0;
}
