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
#line 1 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"
#include "quad.h"
extern int ligne;
extern int colonne;
extern char* yytext; 
extern int qc;

int temp = 1;
char tmp[20];
char currentType[10];
char* newTemp()
{
    sprintf(tmp, "T%d", temp++);
    return strdup(tmp);
}
void yyerror(char *s);
int yylex();

#line 94 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_DECL = 4,                       /* DECL  */
  YYSYMBOL_ENDDECL = 5,                    /* ENDDECL  */
  YYSYMBOL_BEGIN_ = 6,                     /* BEGIN_  */
  YYSYMBOL_END_ = 7,                       /* END_  */
  YYSYMBOL_INTEGER = 8,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_CONST = 10,                     /* CONST  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_WRITE = 15,                     /* WRITE  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MOINS = 17,                     /* MOINS  */
  YYSYMBOL_MUL = 18,                       /* MUL  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_GE = 25,                        /* GE  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_EQ = 27,                        /* EQ  */
  YYSYMBOL_NE = 28,                        /* NE  */
  YYSYMBOL_AFF = 29,                       /* AFF  */
  YYSYMBOL_PV = 30,                        /* PV  */
  YYSYMBOL_VIRG = 31,                      /* VIRG  */
  YYSYMBOL_DP = 32,                        /* DP  */
  YYSYMBOL_PO = 33,                        /* PO  */
  YYSYMBOL_PF = 34,                        /* PF  */
  YYSYMBOL_AO = 35,                        /* AO  */
  YYSYMBOL_AF = 36,                        /* AF  */
  YYSYMBOL_CO = 37,                        /* CO  */
  YYSYMBOL_CF = 38,                        /* CF  */
  YYSYMBOL_ENTIER = 39,                    /* ENTIER  */
  YYSYMBOL_REEL = 40,                      /* REEL  */
  YYSYMBOL_IDF = 41,                       /* IDF  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programme = 43,                 /* programme  */
  YYSYMBOL_declarations = 44,              /* declarations  */
  YYSYMBOL_declaration = 45,               /* declaration  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_type = 47,                      /* type  */
  YYSYMBOL_liste_idf = 48,                 /* liste_idf  */
  YYSYMBOL_valeur = 49,                    /* valeur  */
  YYSYMBOL_instructions = 50,              /* instructions  */
  YYSYMBOL_instruction = 51,               /* instruction  */
  YYSYMBOL_affectation = 52,               /* affectation  */
  YYSYMBOL_condition = 53,                 /* condition  */
  YYSYMBOL_54_2 = 54,                      /* @2  */
  YYSYMBOL_55_3 = 55,                      /* @3  */
  YYSYMBOL_boucle_for = 56,                /* boucle_for  */
  YYSYMBOL_57_4 = 57,                      /* @4  */
  YYSYMBOL_boucle_while = 58,              /* boucle_while  */
  YYSYMBOL_59_5 = 59,                      /* @5  */
  YYSYMBOL_60_6 = 60,                      /* @6  */
  YYSYMBOL_ecriture = 61,                  /* ecriture  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_condition_logique = 63          /* condition_logique  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    70,    71,    75,    74,    79,    92,    93,
      96,   105,   122,   131,   150,   151,   155,   156,   160,   161,
     162,   163,   164,   169,   192,   224,   232,   223,   255,   254,
     295,   299,   294,   319,   329,   341,   353,   365,   387,   393,
     404,   415,   427,   439,   450,   461,   472,   483
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "DECL",
  "ENDDECL", "BEGIN_", "END_", "INTEGER", "FLOAT", "CONST", "IF", "ELSE",
  "FOR", "WHILE", "WRITE", "PLUS", "MOINS", "MUL", "DIV", "AND", "OR",
  "NOT", "GT", "LT", "GE", "LE", "EQ", "NE", "AFF", "PV", "VIRG", "DP",
  "PO", "PF", "AO", "AF", "CO", "CF", "ENTIER", "REEL", "IDF", "$accept",
  "programme", "declarations", "declaration", "$@1", "type", "liste_idf",
  "valeur", "instructions", "instruction", "affectation", "condition",
  "@2", "@3", "boucle_for", "@4", "boucle_while", "@5", "@6", "ecriture",
  "expression", "condition_logique", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -10,    39,    41,   -49,   -49,    84,    55,   -49,   -49,
      21,   -49,    31,   -49,    37,   -49,    -6,   -37,    27,   -49,
      36,    42,    57,    67,   -25,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,    43,    64,     7,   -23,    68,   -49,    70,
     -23,    63,   -49,    71,   -49,    72,   -23,   -49,   -49,   -49,
      80,    38,    82,   -23,    78,    61,    77,    79,    81,    40,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -49,    83,    85,    86,   -49,    91,   -49,    87,   -49,    33,
      33,   -49,   -49,    69,    69,    69,    69,    69,    69,    88,
      89,   -49,   -49,   -23,    90,   -49,    92,    94,    65,   -49,
       0,    93,   -49,   -49,   -49,    95,    19,   112,    96,   -49,
      97,   -49,   -49,    98,    29,   -49,   -49,    35,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     8,     9,
       0,     3,     0,    17,     0,     5,     0,     0,     0,     2,
       0,     0,     0,     0,     0,    16,    18,    19,    20,    21,
      22,    14,    15,     0,    10,     0,     0,     0,    30,     0,
       0,     0,     7,     0,     6,     0,     0,    40,    41,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,    23,     0,    11,     0,    38,    34,
      35,    36,    37,    42,    43,    44,    45,    46,    47,     0,
       0,    31,    33,     0,     0,    17,     0,     0,     0,    13,
       0,     0,    17,    24,    26,     0,     0,     0,     0,    32,
       0,    28,    17,     0,     0,    17,    27,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -48,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -40,    74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,    11,    18,    12,    35,    33,    16,    25,
      26,    27,    89,   107,    28,   113,    29,    53,    97,    30,
      50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    19,    31,    32,    40,    20,    59,    21,    22,    23,
      46,    20,    41,    21,    22,    23,    47,    48,    49,     1,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      20,     3,    21,    22,    23,    24,   104,    44,    45,     4,
      20,    24,    21,    22,    23,     5,    20,   100,    21,    22,
      23,    62,    63,    98,   106,   109,    60,    61,    62,    63,
      24,    13,    14,    15,   114,   116,    17,   117,    34,    36,
      24,   118,    70,    42,    78,    37,    24,    60,    61,    62,
      63,    60,    61,    62,    63,    60,    61,    62,    63,     7,
      38,    74,     8,     9,    10,   103,    60,    61,    62,    63,
      39,    43,    56,    64,    65,    66,    67,    68,    69,    52,
      57,    54,    73,    58,    71,    75,    92,    76,    77,    91,
      93,    96,    90,    95,   110,   105,    94,    72,    99,   102,
     111,   101,   112,   115,   108
};

static const yytype_int8 yycheck[] =
{
      40,     7,    39,    40,    29,    11,    46,    13,    14,    15,
      33,    11,    37,    13,    14,    15,    39,    40,    41,     3,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      11,    41,    13,    14,    15,    41,    36,    30,    31,     0,
      11,    41,    13,    14,    15,     4,    11,    95,    13,    14,
      15,    18,    19,    93,   102,    36,    16,    17,    18,    19,
      41,     6,    41,    32,   112,    36,    29,   115,    41,    33,
      41,    36,    34,    30,    34,    33,    41,    16,    17,    18,
      19,    16,    17,    18,    19,    16,    17,    18,    19,     5,
      33,    30,     8,     9,    10,    30,    16,    17,    18,    19,
      33,    37,    39,    23,    24,    25,    26,    27,    28,    41,
      39,    41,    34,    41,    32,    38,    30,    38,    37,    34,
      29,    32,    39,    35,    12,    32,    39,    53,    38,    35,
      34,    39,    35,    35,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,    41,     0,     4,    44,     5,     8,     9,
      10,    45,    47,     6,    41,    32,    50,    29,    46,     7,
      11,    13,    14,    15,    41,    51,    52,    53,    56,    58,
      61,    39,    40,    49,    41,    48,    33,    33,    33,    33,
      29,    37,    30,    37,    30,    31,    33,    39,    40,    41,
      62,    63,    41,    59,    41,    62,    39,    39,    41,    62,
      16,    17,    18,    19,    23,    24,    25,    26,    27,    28,
      34,    32,    63,    34,    30,    38,    38,    37,    34,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    54,
      39,    34,    30,    29,    39,    35,    32,    60,    62,    38,
      50,    39,    35,    30,    36,    32,    50,    55,    39,    36,
      12,    34,    35,    57,    50,    35,    36,    50,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    46,    45,    45,    47,    47,
      48,    48,    48,    48,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    54,    55,    53,    57,    56,
      59,    60,    58,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    63,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     0,     5,     5,     1,     1,
       1,     4,     3,     6,     1,     1,     2,     0,     1,     1,
       1,     1,     1,     4,     7,     0,     0,    13,     0,    14,
       0,     0,     9,     5,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3
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
  case 5: /* $@1: %empty  */
#line 75 "syntax.y"
      {
          strcpy(currentType, (yyvsp[-1].str));
      }
#line 1218 "syntax.tab.c"
    break;

  case 7: /* declaration: CONST IDF AFF valeur PV  */
#line 80 "syntax.y"
{
    inserer((yyvsp[-3].str), "CONST");

    symbole *s = rechercher((yyvsp[-3].str));
    if(s != NULL)
    {
        s->valeur = (yyvsp[-1].reel); // ✔ correction finale
    }
}
#line 1232 "syntax.tab.c"
    break;

  case 8: /* type: INTEGER  */
#line 92 "syntax.y"
            {(yyval.str) = "INTEGER"; }
#line 1238 "syntax.tab.c"
    break;

  case 9: /* type: FLOAT  */
#line 93 "syntax.y"
            { (yyval.str) = "FLOAT"; }
#line 1244 "syntax.tab.c"
    break;

  case 10: /* liste_idf: IDF  */
#line 97 "syntax.y"
      {
          symbole *s = rechercher((yyvsp[0].str));
          if(s != NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (double declaration)\n", ligne, colonne, (yyvsp[0].str));
          else
              inserer((yyvsp[0].str), currentType);
      }
#line 1256 "syntax.tab.c"
    break;

  case 11: /* liste_idf: IDF CO ENTIER CF  */
#line 106 "syntax.y"
      {
          symbole *s = rechercher((yyvsp[-3].str));
          if(s != NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (double declaration)\n", ligne, colonne, (yyvsp[-3].str));
          else {
              inserer((yyvsp[-3].str), currentType);
              s = rechercher((yyvsp[-3].str));

              if((yyvsp[-1].entier) <= 0)
                  printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (taille tableau invalide)\n", ligne, colonne, (yyvsp[-3].str));
              else
                  s->taille = (yyvsp[-1].entier);
                  s->tabValeurs = malloc(sizeof(float) * (yyvsp[-1].entier));
          }
      }
#line 1276 "syntax.tab.c"
    break;

  case 12: /* liste_idf: liste_idf VIRG IDF  */
#line 123 "syntax.y"
      {
          symbole *s = rechercher((yyvsp[0].str));
          if(s != NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (double declaration)\n", ligne, colonne, (yyvsp[0].str));
          else
              inserer((yyvsp[0].str), currentType);
      }
#line 1288 "syntax.tab.c"
    break;

  case 13: /* liste_idf: liste_idf VIRG IDF CO ENTIER CF  */
#line 132 "syntax.y"
      {
          symbole *s = rechercher((yyvsp[-3].str));
          if(s != NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (double declaration)\n", ligne, colonne, (yyvsp[-3].str));
          else {
              inserer((yyvsp[-3].str), currentType);
              s = rechercher((yyvsp[-3].str));

              if((yyvsp[-1].entier) <= 0)
                  printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (taille tableau invalide)\n", ligne, colonne, (yyvsp[-3].str));
              else
                  s->taille = (yyvsp[-1].entier);
                  s->tabValeurs = malloc(sizeof(float) * (yyvsp[-1].entier));
          }
      }
#line 1308 "syntax.tab.c"
    break;

  case 14: /* valeur: ENTIER  */
#line 150 "syntax.y"
             { (yyval.reel) = (yyvsp[0].entier); }
#line 1314 "syntax.tab.c"
    break;

  case 15: /* valeur: REEL  */
#line 151 "syntax.y"
             { (yyval.reel) = (yyvsp[0].reel); }
#line 1320 "syntax.tab.c"
    break;

  case 23: /* affectation: IDF AFF expression PV  */
#line 170 "syntax.y"
      {
          symbole *s = rechercher((yyvsp[-3].str));

          if(s == NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (variable non declaree)\n", ligne, colonne, (yyvsp[-3].str));

          else if(strcmp(s->type, "CONST") == 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , modification d'une constante %s\n", ligne, colonne, (yyvsp[-3].str));

          else if(strcmp(s->type, (yyvsp[-1].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (incompatibilite de type)\n", ligne, colonne, (yyvsp[-3].str));

          else
          {
              ajouter_quad("=", (yyvsp[-1].expr).nom, "", (yyvsp[-3].str));
              if(strcmp((yyvsp[-1].expr).type, "INTEGER") == 0)
                  s->valeur = (yyvsp[-1].expr).val;
              else
                  s->valeur = (yyvsp[-1].expr).val;
          }
      }
#line 1346 "syntax.tab.c"
    break;

  case 24: /* affectation: IDF CO ENTIER CF AFF expression PV  */
#line 193 "syntax.y"
      {
          symbole *s = rechercher((yyvsp[-6].str));

          if(s == NULL)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (tableau non declare)\n", ligne, colonne, (yyvsp[-6].str));

          else if(s->taille == 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (n'est pas un tableau)\n", ligne, colonne, (yyvsp[-6].str));

          else if((yyvsp[-4].entier) < 0 || (yyvsp[-4].entier) >= s->taille)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (depassement tableau)\n", ligne, colonne, (yyvsp[-6].str));

          else if(strcmp(s->type, "CONST") == 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , modification d'une constante %s\n", ligne, colonne, (yyvsp[-6].str));

          else if(strcmp(s->type, (yyvsp[-1].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (type tableau invalide)\n", ligne, colonne, (yyvsp[-6].str));

          else
          {
              ajouter_quad("=[]", (yyvsp[-6].str), (yyvsp[-1].expr).nom, "TAB");

              if(strcmp((yyvsp[-1].expr).type, "INTEGER") == 0)
                  s->tabValeurs[(yyvsp[-4].entier)] = (yyvsp[-1].expr).val;
              else
                  s->tabValeurs[(yyvsp[-4].entier)] = atof((yyvsp[-1].expr).nom);
          }
      }
#line 1379 "syntax.tab.c"
    break;

  case 25: /* @2: %empty  */
#line 224 "syntax.y"
    {
        char tmp[20];
        sprintf(tmp, "%d", -1);
        ajouter_quad("BZ", (yyvsp[-1].expr).nom, "", tmp);

        (yyval.entier) = qc - 1; // position BZ
    }
#line 1391 "syntax.tab.c"
    break;

  case 26: /* @3: %empty  */
#line 232 "syntax.y"
    {
        char tmp2[20];
        sprintf(tmp2, "%d", -1);
        ajouter_quad("BR", "", "", tmp2);

        int saut = qc - 1;

        char finif[20];
        sprintf(finif, "%d", qc);
        maj_quad((yyvsp[-3].entier), finif);

        (yyval.entier) = saut;
    }
#line 1409 "syntax.tab.c"
    break;

  case 27: /* condition: IF PO condition_logique PF @2 AO instructions AF @3 ELSE AO instructions AF  */
#line 246 "syntax.y"
    {
        char fin[20];
        sprintf(fin, "%d", qc);
        maj_quad((yyvsp[-4].entier), fin);
    }
#line 1419 "syntax.tab.c"
    break;

  case 28: /* @4: %empty  */
#line 255 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[-7].str));
        if(s) s->valeur = (yyvsp[-5].entier);

        int debut = qc;

        char finv[20];
        sprintf(finv, "%d", (yyvsp[-3].entier));

        char *t = newTemp();
        ajouter_quad("<=", (yyvsp[-7].str), finv, t);

        char tmp[20];
        sprintf(tmp, "%d", -1);
        ajouter_quad("BZ", t, "", tmp);

        (yyval.entier) = qc - 1;
        (yyvsp[-8].entier) = debut;
    }
#line 1443 "syntax.tab.c"
    break;

  case 29: /* boucle_for: FOR PO IDF DP ENTIER DP ENTIER DP ENTIER PF @4 AO instructions AF  */
#line 275 "syntax.y"
    {
        char step[20];
        sprintf(step, "%d", (yyvsp[-5].entier));

        char *t = newTemp();
        ajouter_quad("+", (yyvsp[-11].str), step, t);
        ajouter_quad("=", t, "", (yyvsp[-11].str));

        char retour[20];
        sprintf(retour, "%d", (yyvsp[-12].entier));
        ajouter_quad("BR", "", "", retour);

        char fin[20];
        sprintf(fin, "%d", qc);
        maj_quad((yyvsp[-3].entier), fin);
    }
#line 1464 "syntax.tab.c"
    break;

  case 30: /* @5: %empty  */
#line 295 "syntax.y"
    {
        (yyval.entier) = qc;
    }
#line 1472 "syntax.tab.c"
    break;

  case 31: /* @6: %empty  */
#line 299 "syntax.y"
    {
        char tmp[20];
        sprintf(tmp, "%d", -1);
        ajouter_quad("BZ", (yyvsp[-1].expr).nom, "", tmp);

        (yyval.entier) = qc - 1;
    }
#line 1484 "syntax.tab.c"
    break;

  case 32: /* boucle_while: WHILE PO @5 condition_logique PF @6 AO instructions AF  */
#line 307 "syntax.y"
    {
        char retour[20];
        sprintf(retour, "%d", (yyvsp[-6].entier));
        ajouter_quad("BR", "", "", retour);

        char fin[20];
        sprintf(fin, "%d", qc);
        maj_quad((yyvsp[-3].entier), fin);
    }
#line 1498 "syntax.tab.c"
    break;

  case 33: /* ecriture: WRITE PO IDF PF PV  */
#line 320 "syntax.y"
    {
        if(rechercher((yyvsp[-2].str)) == NULL)
            printf("Erreur Sémantique : ligne %d , colonne %d , variable non declaree\n", ligne, colonne);
        else
            ajouter_quad("WRITE", (yyvsp[-2].str), "", "");
    }
#line 1509 "syntax.tab.c"
    break;

  case 34: /* expression: expression PLUS expression  */
#line 330 "syntax.y"
      {
          if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , incompatibilite de type\n", ligne, colonne);

          char *t = newTemp();
          ajouter_quad("+", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

          strcpy((yyval.expr).nom, t);
          strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
          (yyval.expr).val=(yyvsp[-2].expr).val + (yyvsp[0].expr).val;
      }
#line 1525 "syntax.tab.c"
    break;

  case 35: /* expression: expression MOINS expression  */
#line 342 "syntax.y"
      {
          if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , incompatibilite de type\n", ligne, colonne);

          char *t = newTemp();
          ajouter_quad("-", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

          strcpy((yyval.expr).nom, t);
          strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
          (yyval.expr).val=(yyvsp[-2].expr).val - (yyvsp[0].expr).val;
      }
#line 1541 "syntax.tab.c"
    break;

  case 36: /* expression: expression MUL expression  */
#line 354 "syntax.y"
      {
          if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , incompatibilite de type\n", ligne, colonne);

          char *t = newTemp();
          ajouter_quad("*", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

          strcpy((yyval.expr).nom, t);
          strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
          (yyval.expr).val=(yyvsp[-2].expr).val * (yyvsp[0].expr).val;
      }
#line 1557 "syntax.tab.c"
    break;

  case 37: /* expression: expression DIV expression  */
#line 366 "syntax.y"
{
    if((yyvsp[0].expr).val == 0)
    {
        printf("Erreur Sémantique : ligne %d , colonne %d , division par zero\n", ligne, colonne);

        strcpy((yyval.expr).nom, "0");   // IMPORTANT
        strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
        (yyval.expr).val = 0;
    }
    else if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
    {
        printf("Erreur Sémantique : incompatibilite de type\n");
    }
    else {
        char *t = newTemp();
        ajouter_quad("/", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t);
        strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
        (yyval.expr).val=(yyvsp[-2].expr).val / (yyvsp[0].expr).val;
    }
}
#line 1583 "syntax.tab.c"
    break;

  case 38: /* expression: PO expression PF  */
#line 388 "syntax.y"
{
    strcpy((yyval.expr).nom, (yyvsp[-1].expr).nom);
    strcpy((yyval.expr).type, (yyvsp[-1].expr).type);
    (yyval.expr).val=(yyvsp[-1].expr).val;
}
#line 1593 "syntax.tab.c"
    break;

  case 39: /* expression: IDF  */
#line 394 "syntax.y"
{
    symbole *s = rechercher((yyvsp[0].str));
    if(s == NULL)
        printf("Erreur Sémantique : ligne %d , colonne %d , élément %s (variable non declaree)\n", ligne, colonne, (yyvsp[0].str));
    else {
        strcpy((yyval.expr).nom, (yyvsp[0].str));
        strcpy((yyval.expr).type, s->type);
        (yyval.expr).val= s->valeur;
    }
}
#line 1608 "syntax.tab.c"
    break;

  case 40: /* expression: ENTIER  */
#line 405 "syntax.y"
{
    if((yyvsp[0].entier) < -32768 || (yyvsp[0].entier) > 32767)
        printf("Erreur Sémantique : ligne %d , colonne %d , entier hors intervalle\n", ligne, colonne);

    char buffer[20];
    sprintf(buffer, "%d", (yyvsp[0].entier));
    strcpy((yyval.expr).nom, buffer);
    strcpy((yyval.expr).type, "INTEGER");
    (yyval.expr).val=(yyvsp[0].entier);
}
#line 1623 "syntax.tab.c"
    break;

  case 41: /* expression: REEL  */
#line 416 "syntax.y"
      {
          char buffer[20];
          sprintf(buffer, "%f", (yyvsp[0].reel));

          strcpy((yyval.expr).nom, buffer);
          strcpy((yyval.expr).type, "FLOAT");
          (yyval.expr).val=(yyvsp[0].reel);
      }
#line 1636 "syntax.tab.c"
    break;

  case 42: /* condition_logique: expression GT expression  */
#line 428 "syntax.y"
{   if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);


    char *t = newTemp();
    ajouter_quad(">", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

    strcpy((yyval.expr).nom, t);
    strcpy((yyval.expr).type, "INTEGER");
    (yyval.expr).val = ((yyvsp[-2].expr).val > (yyvsp[0].expr).val);
}
#line 1652 "syntax.tab.c"
    break;

  case 43: /* condition_logique: expression LT expression  */
#line 440 "syntax.y"
{   if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);

    char *t = newTemp();
    ajouter_quad("<", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

    strcpy((yyval.expr).nom, t);
    strcpy((yyval.expr).type, "INTEGER");
    (yyval.expr).val = ((yyvsp[-2].expr).val < (yyvsp[0].expr).val);
}
#line 1667 "syntax.tab.c"
    break;

  case 44: /* condition_logique: expression GE expression  */
#line 451 "syntax.y"
{   if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);

    char *t = newTemp();
    ajouter_quad(">=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

    strcpy((yyval.expr).nom, t);
    strcpy((yyval.expr).type, "INTEGER");
    (yyval.expr).val = ((yyvsp[-2].expr).val >= (yyvsp[0].expr).val);
}
#line 1682 "syntax.tab.c"
    break;

  case 45: /* condition_logique: expression LE expression  */
#line 462 "syntax.y"
{   if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);

    char *t = newTemp();
    ajouter_quad("<=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

    strcpy((yyval.expr).nom, t);
    strcpy((yyval.expr).type, "INTEGER");
    (yyval.expr).val = ((yyvsp[-2].expr).val <= (yyvsp[0].expr).val);
}
#line 1697 "syntax.tab.c"
    break;

  case 46: /* condition_logique: expression EQ expression  */
#line 473 "syntax.y"
{   if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);

    char *t = newTemp();
    ajouter_quad("==", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

    strcpy((yyval.expr).nom, t);
    strcpy((yyval.expr).type, "INTEGER");
    (yyval.expr).val = ((yyvsp[-2].expr).val == (yyvsp[0].expr).val);
}
#line 1712 "syntax.tab.c"
    break;

  case 47: /* condition_logique: expression NE expression  */
#line 484 "syntax.y"
{   if(strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
              printf("Erreur Sémantique : ligne %d , colonne %d , comparaison entre types differents\n", ligne, colonne);

    char *t = newTemp();
    ajouter_quad("!=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);

    strcpy((yyval.expr).nom, t);
    strcpy((yyval.expr).type, "INTEGER");
    (yyval.expr).val = ((yyvsp[-2].expr).val != (yyvsp[0].expr).val);
}
#line 1727 "syntax.tab.c"
    break;


#line 1731 "syntax.tab.c"

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

#line 496 "syntax.y"


void yyerror(char *s)
{
    if(strcmp(yytext, ")") == 0)
        printf("Erreur Syntaxique : parenthese fermante sans ouvrante ligne %d colonne %d\n", ligne, colonne);
    else if(strcmp(yytext, "(") == 0)
        printf("Erreur Syntaxique : parenthese ouvrante sans fermante ligne %d colonne %d\n", ligne, colonne);
    else
        printf("Erreur Syntaxique : ligne %d , colonne %d , élément %s\n", ligne, colonne, yytext);
}

int main()
{
    yyparse();
    executer_quads();
    afficher_ts();
    afficher_quad();
    return 0;
}
