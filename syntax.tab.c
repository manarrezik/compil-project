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

#line 96 "syntax.tab.c"

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
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

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
       0,    69,    69,    73,    74,    79,    78,    84,   103,   104,
     118,   132,   156,   177,   191,   214,   237,   238,   242,   243,
     247,   248,   249,   250,   251,   255,   271,   299,   306,   298,
     326,   325,   356,   360,   355,   378,   390,   400,   410,   420,
     438,   443,   456,   466,   476,   485,   494,   503,   512,   521
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

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      11,   -20,    39,    43,   -46,   -46,    93,    54,   -46,   -46,
       8,   -46,    21,   -46,    33,   -46,    -5,   -35,    29,   -46,
      42,    46,    49,    50,   -26,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,    69,     3,    38,   -21,    35,   -46,    36,
     -21,    45,   -46,   -35,    71,   -46,    68,   -21,   -46,   -46,
     -46,    89,    77,    86,   -21,    85,    70,    82,   -46,    83,
       4,    47,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -46,    84,    88,    94,   -46,    96,   -46,   -35,
      87,   -46,    16,    16,   -46,   -46,    78,    78,    78,    78,
      78,    78,    92,    97,   -46,   -46,   -21,   -46,    90,   -46,
      91,    98,    74,   -46,     2,    99,   -46,   -46,   -46,    95,
      31,   120,   101,   -46,   102,   -46,   -46,   103,    37,   -46,
     -46,    44,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     8,     9,
       0,     3,     0,    19,     0,     5,     0,     0,     0,     2,
       0,     0,     0,     0,     0,    18,    20,    21,    22,    23,
      24,    16,    17,     0,    10,     0,     0,     0,    32,     0,
       0,     0,     7,     0,     0,     6,     0,     0,    42,    43,
      41,     0,     0,     0,     0,     0,     0,     0,    11,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,    25,     0,    12,     0,
       0,    40,    36,    37,    38,    39,    44,    45,    46,    47,
      48,    49,     0,     0,    33,    35,     0,    14,     0,    19,
       0,     0,     0,    15,     0,     0,    19,    26,    28,     0,
       0,     0,     0,    34,     0,    30,    19,     0,     0,    19,
      29,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -42,   -45,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -40,   100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,    11,    18,    12,    35,    33,    16,    25,
      26,    27,    92,   111,    28,   117,    29,    54,   101,    30,
      51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    58,    19,    40,    31,    32,    20,    61,    21,    22,
      23,    41,    47,    20,     1,    21,    22,    23,    48,    49,
      50,     3,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    43,    79,    64,    65,    24,    97,   108,     4,
      44,    80,    20,    24,    21,    22,    23,     5,    20,    14,
      21,    22,    23,    15,   104,    20,   102,    21,    22,    23,
      13,   110,    17,    62,    63,    64,    65,   113,    45,    46,
      34,   118,    24,   120,   121,    36,    53,    55,    24,    37,
     122,    81,    38,    39,    57,    24,    62,    63,    64,    65,
      62,    63,    64,    65,    62,    63,    64,    65,     7,    42,
      76,     8,     9,    10,   107,    62,    63,    64,    65,    60,
      59,    72,    66,    67,    68,    69,    70,    71,    73,    75,
      77,    78,    94,    93,    95,    96,    98,    99,   103,   100,
     105,   109,   114,   106,   112,   115,     0,   116,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74
};

static const yytype_int8 yycheck[] =
{
      40,    43,     7,    29,    39,    40,    11,    47,    13,    14,
      15,    37,    33,    11,     3,    13,    14,    15,    39,    40,
      41,    41,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    29,    29,    18,    19,    41,    79,    36,     0,
      37,    37,    11,    41,    13,    14,    15,     4,    11,    41,
      13,    14,    15,    32,    99,    11,    96,    13,    14,    15,
       6,   106,    29,    16,    17,    18,    19,    36,    30,    31,
      41,   116,    41,    36,   119,    33,    41,    41,    41,    33,
      36,    34,    33,    33,    39,    41,    16,    17,    18,    19,
      16,    17,    18,    19,    16,    17,    18,    19,     5,    30,
      30,     8,     9,    10,    30,    16,    17,    18,    19,    41,
      39,    34,    23,    24,    25,    26,    27,    28,    32,    34,
      38,    38,    34,    39,    30,    29,    39,    35,    38,    32,
      39,    32,    12,    35,    39,    34,    -1,    35,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,    41,     0,     4,    44,     5,     8,     9,
      10,    45,    47,     6,    41,    32,    50,    29,    46,     7,
      11,    13,    14,    15,    41,    51,    52,    53,    56,    58,
      61,    39,    40,    49,    41,    48,    33,    33,    33,    33,
      29,    37,    30,    29,    37,    30,    31,    33,    39,    40,
      41,    62,    63,    41,    59,    41,    62,    39,    49,    39,
      41,    62,    16,    17,    18,    19,    23,    24,    25,    26,
      27,    28,    34,    32,    63,    34,    30,    38,    38,    29,
      37,    34,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    54,    39,    34,    30,    29,    49,    39,    35,
      32,    60,    62,    38,    50,    39,    35,    30,    36,    32,
      50,    55,    39,    36,    12,    34,    35,    57,    50,    35,
      36,    50,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    46,    45,    45,    47,    47,
      48,    48,    48,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    52,    52,    54,    55,    53,
      57,    56,    59,    60,    58,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     0,     5,     5,     1,     1,
       1,     3,     4,     3,     5,     6,     1,     1,     2,     0,
       1,     1,     1,     1,     1,     4,     7,     0,     0,    13,
       0,    14,     0,     0,     9,     5,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3
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
#line 79 "syntax.y"
    {
        strcpy(currentType, (yyvsp[-1].str));
    }
#line 1227 "syntax.tab.c"
    break;

  case 7: /* declaration: CONST IDF AFF valeur PV  */
#line 85 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[-3].str));
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, (yyvsp[-3].str));
        else {
            if (s == NULL) inserer_idf((yyvsp[-3].str), "CONST");
            s = rechercher((yyvsp[-3].str));
            strcpy(s->code, "CONST");
            strcpy(s->type, "CONST");
            s->valeur   = (yyvsp[-1].reel);
            s->init     = 1;
            s->declared = 1;
        }
    }
#line 1247 "syntax.tab.c"
    break;

  case 8: /* type: INTEGER  */
#line 103 "syntax.y"
            { (yyval.str) = "INTEGER"; }
#line 1253 "syntax.tab.c"
    break;

  case 9: /* type: FLOAT  */
#line 104 "syntax.y"
            { (yyval.str) = "FLOAT";   }
#line 1259 "syntax.tab.c"
    break;

  case 10: /* liste_idf: IDF  */
#line 119 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[0].str));
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, (yyvsp[0].str));
        else {
            if (s == NULL) inserer_idf((yyvsp[0].str), "IDF");
            s = rechercher((yyvsp[0].str));
            strcpy(s->type, currentType);
            s->declared = 1;
        }
    }
#line 1276 "syntax.tab.c"
    break;

  case 11: /* liste_idf: IDF AFF valeur  */
#line 133 "syntax.y"
    {
        /* déclaration avec valeur initiale : INTEGER : a = 2 ; */
        symbole *s = rechercher((yyvsp[-2].str));
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, (yyvsp[-2].str));
        else {
            if (s == NULL) inserer_idf((yyvsp[-2].str), "IDF");
            s = rechercher((yyvsp[-2].str));
            strcpy(s->type, currentType);
            s->valeur   = (yyvsp[0].reel);
            s->init     = 1;
            s->declared = 1;
            /* quadruplet d'initialisation */
            char buf[20];
            if (strcmp(currentType, "FLOAT") == 0)
                sprintf(buf, "%f", (yyvsp[0].reel));
            else
                sprintf(buf, "%d", (int)(yyvsp[0].reel));
            ajouter_quad("=", buf, "", (yyvsp[-2].str));
        }
    }
#line 1303 "syntax.tab.c"
    break;

  case 12: /* liste_idf: IDF CO ENTIER CF  */
#line 157 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[-3].str));
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, (yyvsp[-3].str));
        else {
            if (s == NULL) inserer_idf((yyvsp[-3].str), "IDF");
            s = rechercher((yyvsp[-3].str));
            strcpy(s->type, currentType);
            s->declared = 1;
            if ((yyvsp[-1].entier) <= 0)
                printf("Erreur Semantique : ligne %d , colonne %d , element %s (taille tableau invalide)\n",
                       ligne, colonne, (yyvsp[-3].str));
            else {
                s->taille     = (yyvsp[-1].entier);
                s->tabValeurs = malloc(sizeof(float) * (yyvsp[-1].entier));
            }
        }
    }
#line 1327 "syntax.tab.c"
    break;

  case 13: /* liste_idf: liste_idf VIRG IDF  */
#line 178 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[0].str));
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, (yyvsp[0].str));
        else {
            if (s == NULL) inserer_idf((yyvsp[0].str), "IDF");
            s = rechercher((yyvsp[0].str));
            strcpy(s->type, currentType);
            s->declared = 1;
        }
    }
#line 1344 "syntax.tab.c"
    break;

  case 14: /* liste_idf: liste_idf VIRG IDF AFF valeur  */
#line 192 "syntax.y"
    {
        /* INTEGER : a, b = 5 ; */
        symbole *s = rechercher((yyvsp[-2].str));
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, (yyvsp[-2].str));
        else {
            if (s == NULL) inserer_idf((yyvsp[-2].str), "IDF");
            s = rechercher((yyvsp[-2].str));
            strcpy(s->type, currentType);
            s->valeur   = (yyvsp[0].reel);
            s->init     = 1;
            s->declared = 1;
            char buf[20];
            if (strcmp(currentType, "FLOAT") == 0)
                sprintf(buf, "%f", (yyvsp[0].reel));
            else
                sprintf(buf, "%d", (int)(yyvsp[0].reel));
            ajouter_quad("=", buf, "", (yyvsp[-2].str));
        }
    }
#line 1370 "syntax.tab.c"
    break;

  case 15: /* liste_idf: liste_idf VIRG IDF CO ENTIER CF  */
#line 215 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[-3].str));
        if (s != NULL && s->declared == 1)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (double declaration)\n",
                   ligne, colonne, (yyvsp[-3].str));
        else {
            if (s == NULL) inserer_idf((yyvsp[-3].str), "IDF");
            s = rechercher((yyvsp[-3].str));
            strcpy(s->type, currentType);
            s->declared = 1;
            if ((yyvsp[-1].entier) <= 0)
                printf("Erreur Semantique : ligne %d , colonne %d , element %s (taille tableau invalide)\n",
                       ligne, colonne, (yyvsp[-3].str));
            else {
                s->taille     = (yyvsp[-1].entier);
                s->tabValeurs = malloc(sizeof(float) * (yyvsp[-1].entier));
            }
        }
    }
#line 1394 "syntax.tab.c"
    break;

  case 16: /* valeur: ENTIER  */
#line 237 "syntax.y"
           { (yyval.reel) = (yyvsp[0].entier); }
#line 1400 "syntax.tab.c"
    break;

  case 17: /* valeur: REEL  */
#line 238 "syntax.y"
           { (yyval.reel) = (yyvsp[0].reel); }
#line 1406 "syntax.tab.c"
    break;

  case 25: /* affectation: IDF AFF expression PV  */
#line 256 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[-3].str));
        if (s == NULL || s->declared == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (variable non declaree)\n",
                   ligne, colonne, (yyvsp[-3].str));
        else if (strcmp(s->type, "CONST") == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , modification d'une constante %s\n",
                   ligne, colonne, (yyvsp[-3].str));
        else if (strcmp(s->type, (yyvsp[-1].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (incompatibilite de type)\n",
                   ligne, colonne, (yyvsp[-3].str));
        else
            ajouter_quad("=", (yyvsp[-1].expr).nom, "", (yyvsp[-3].str));
    }
#line 1425 "syntax.tab.c"
    break;

  case 26: /* affectation: IDF CO ENTIER CF AFF expression PV  */
#line 272 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[-6].str));
        if (s == NULL || s->declared == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (tableau non declare)\n",
                   ligne, colonne, (yyvsp[-6].str));
        else if (s->taille == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (n'est pas un tableau)\n",
                   ligne, colonne, (yyvsp[-6].str));
        else if ((yyvsp[-4].entier) < 0 || (yyvsp[-4].entier) >= s->taille)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (depassement tableau)\n",
                   ligne, colonne, (yyvsp[-6].str));
        else if (strcmp(s->type, "CONST") == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , modification d'une constante %s\n",
                   ligne, colonne, (yyvsp[-6].str));
        else if (strcmp(s->type, (yyvsp[-1].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (type tableau invalide)\n",
                   ligne, colonne, (yyvsp[-6].str));
        else {
            char index[20];
            sprintf(index, "%d", (yyvsp[-4].entier));
            ajouter_quad("=[]", (yyvsp[-6].str), index, (yyvsp[-1].expr).nom);
        }
    }
#line 1453 "syntax.tab.c"
    break;

  case 27: /* @2: %empty  */
#line 299 "syntax.y"
    {
        char t[20];
        sprintf(t, "%d", -1);
        ajouter_quad("BZ", (yyvsp[-1].expr).nom, "", t);
        (yyval.entier) = qc - 1;
    }
#line 1464 "syntax.tab.c"
    break;

  case 28: /* @3: %empty  */
#line 306 "syntax.y"
    {
        char t[20];
        sprintf(t, "%d", -1);
        ajouter_quad("BR", "", "", t);
        int saut = qc - 1;
        char finif[20];
        sprintf(finif, "%d", qc);
        maj_quad((yyvsp[-3].entier), finif);
        (yyval.entier) = saut;
    }
#line 1479 "syntax.tab.c"
    break;

  case 29: /* condition: IF PO condition_logique PF @2 AO instructions AF @3 ELSE AO instructions AF  */
#line 317 "syntax.y"
    {
        char fin[20];
        sprintf(fin, "%d", qc);
        maj_quad((yyvsp[-4].entier), fin);
    }
#line 1489 "syntax.tab.c"
    break;

  case 30: /* @4: %empty  */
#line 326 "syntax.y"
    {
        int debut = qc;
        char finv[20];
        sprintf(finv, "%d", (yyvsp[-3].entier));
        char *t = newTemp();
        ajouter_quad("<=", (yyvsp[-7].str), finv, t);
        char tmp2[20];
        sprintf(tmp2, "%d", -1);
        ajouter_quad("BZ", t, "", tmp2);
        (yyval.entier)  = qc - 1;
        (yyvsp[-8].entier)  = debut;
    }
#line 1506 "syntax.tab.c"
    break;

  case 31: /* boucle_for: FOR PO IDF DP ENTIER DP ENTIER DP ENTIER PF @4 AO instructions AF  */
#line 339 "syntax.y"
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
#line 1524 "syntax.tab.c"
    break;

  case 32: /* @5: %empty  */
#line 356 "syntax.y"
    {
        (yyval.entier) = qc;
    }
#line 1532 "syntax.tab.c"
    break;

  case 33: /* @6: %empty  */
#line 360 "syntax.y"
    {
        char t[20];
        sprintf(t, "%d", -1);
        ajouter_quad("BZ", (yyvsp[-1].expr).nom, "", t);
        (yyval.entier) = qc - 1;
    }
#line 1543 "syntax.tab.c"
    break;

  case 34: /* boucle_while: WHILE PO @5 condition_logique PF @6 AO instructions AF  */
#line 367 "syntax.y"
    {
        char retour[20];
        sprintf(retour, "%d", (yyvsp[-6].entier));
        ajouter_quad("BR", "", "", retour);
        char fin[20];
        sprintf(fin, "%d", qc);
        maj_quad((yyvsp[-3].entier), fin);
    }
#line 1556 "syntax.tab.c"
    break;

  case 35: /* ecriture: WRITE PO IDF PF PV  */
#line 379 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[-2].str));
        if (s == NULL || s->declared == 0)
            printf("Erreur Semantique : ligne %d , colonne %d , variable non declaree\n",
                   ligne, colonne);
        else
            ajouter_quad("WRITE", (yyvsp[-2].str), "", "");
    }
#line 1569 "syntax.tab.c"
    break;

  case 36: /* expression: expression PLUS expression  */
#line 391 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , incompatibilite de type\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("+", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t);
        strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
    }
#line 1583 "syntax.tab.c"
    break;

  case 37: /* expression: expression MOINS expression  */
#line 401 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , incompatibilite de type\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("-", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t);
        strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
    }
#line 1597 "syntax.tab.c"
    break;

  case 38: /* expression: expression MUL expression  */
#line 411 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , incompatibilite de type\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("*", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t);
        strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
    }
#line 1611 "syntax.tab.c"
    break;

  case 39: /* expression: expression DIV expression  */
#line 421 "syntax.y"
    {
        if (strcmp((yyvsp[0].expr).nom, "0") == 0 || strcmp((yyvsp[0].expr).nom, "0.0") == 0) {
            printf("Erreur Semantique : ligne %d , colonne %d , division par zero\n",
                   ligne, colonne);
            strcpy((yyval.expr).nom, "0");
            strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
        } else if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0) {
            printf("Erreur Semantique : incompatibilite de type\n");
            strcpy((yyval.expr).nom, "0");
            strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
        } else {
            char *t = newTemp();
            ajouter_quad("/", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
            strcpy((yyval.expr).nom, t);
            strcpy((yyval.expr).type, (yyvsp[-2].expr).type);
        }
    }
#line 1633 "syntax.tab.c"
    break;

  case 40: /* expression: PO expression PF  */
#line 439 "syntax.y"
    {
        strcpy((yyval.expr).nom,  (yyvsp[-1].expr).nom);
        strcpy((yyval.expr).type, (yyvsp[-1].expr).type);
    }
#line 1642 "syntax.tab.c"
    break;

  case 41: /* expression: IDF  */
#line 444 "syntax.y"
    {
        symbole *s = rechercher((yyvsp[0].str));
        if (s == NULL || s->declared == 0) {
            printf("Erreur Semantique : ligne %d , colonne %d , element %s (variable non declaree)\n",
                   ligne, colonne, (yyvsp[0].str));
            strcpy((yyval.expr).nom,  (yyvsp[0].str));
            strcpy((yyval.expr).type, "INTEGER");
        } else {
            strcpy((yyval.expr).nom,  (yyvsp[0].str));
            strcpy((yyval.expr).type, s->type);
        }
    }
#line 1659 "syntax.tab.c"
    break;

  case 42: /* expression: ENTIER  */
#line 457 "syntax.y"
    {
        if ((yyvsp[0].entier) < -32768 || (yyvsp[0].entier) > 32767)
            printf("Erreur Semantique : ligne %d , colonne %d , entier hors intervalle\n",
                   ligne, colonne);
        char buffer[20];
        sprintf(buffer, "%d", (yyvsp[0].entier));
        strcpy((yyval.expr).nom,  buffer);
        strcpy((yyval.expr).type, "INTEGER");
    }
#line 1673 "syntax.tab.c"
    break;

  case 43: /* expression: REEL  */
#line 467 "syntax.y"
    {
        char buffer[20];
        sprintf(buffer, "%f", (yyvsp[0].reel));
        strcpy((yyval.expr).nom,  buffer);
        strcpy((yyval.expr).type, "FLOAT");
    }
#line 1684 "syntax.tab.c"
    break;

  case 44: /* condition_logique: expression GT expression  */
#line 477 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad(">", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t); strcpy((yyval.expr).type, "INTEGER");
    }
#line 1697 "syntax.tab.c"
    break;

  case 45: /* condition_logique: expression LT expression  */
#line 486 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("<", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t); strcpy((yyval.expr).type, "INTEGER");
    }
#line 1710 "syntax.tab.c"
    break;

  case 46: /* condition_logique: expression GE expression  */
#line 495 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad(">=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t); strcpy((yyval.expr).type, "INTEGER");
    }
#line 1723 "syntax.tab.c"
    break;

  case 47: /* condition_logique: expression LE expression  */
#line 504 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("<=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t); strcpy((yyval.expr).type, "INTEGER");
    }
#line 1736 "syntax.tab.c"
    break;

  case 48: /* condition_logique: expression EQ expression  */
#line 513 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("==", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t); strcpy((yyval.expr).type, "INTEGER");
    }
#line 1749 "syntax.tab.c"
    break;

  case 49: /* condition_logique: expression NE expression  */
#line 522 "syntax.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("Erreur Semantique : ligne %d , colonne %d , comparaison entre types differents\n",
                   ligne, colonne);
        char *t = newTemp();
        ajouter_quad("!=", (yyvsp[-2].expr).nom, (yyvsp[0].expr).nom, t);
        strcpy((yyval.expr).nom, t); strcpy((yyval.expr).type, "INTEGER");
    }
#line 1762 "syntax.tab.c"
    break;


#line 1766 "syntax.tab.c"

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

#line 532 "syntax.y"


void yyerror(char *s)
{
    if (strcmp(yytext, ")") == 0)
        printf("Erreur Syntaxique : parenthese fermante sans ouvrante ligne %d colonne %d\n",
               ligne, colonne);
    else if (strcmp(yytext, "(") == 0)
        printf("Erreur Syntaxique : parenthese ouvrante sans fermante ligne %d colonne %d\n",
               ligne, colonne);
    else
        printf("Erreur Syntaxique : ligne %d , colonne %d , element %s\n",
               ligne, colonne, yytext);
}

int main()
{
    yyparse();
    afficher_ts(1);
    afficher_quad();
    return 0;
}
