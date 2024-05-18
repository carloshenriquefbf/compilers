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
#line 1 "cmdif.y"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int linha = 1, coluna = 0;

struct Atributos {
  vector<string> c; // Código

  int linha = 0, coluna = 0;

  void clear() {
    c.clear();
    linha = 0;
    coluna = 0;
  }
};

enum TipoDecl { Let = 1, Const, Var };

struct Simbolo {
  TipoDecl tipo;
  int linha;
  int coluna;
};

map< string, Simbolo > ts; // Tabela de símbolos

vector<string> declara_var( TipoDecl tipo, string nome, int linha, int coluna );
void checa_simbolo( string nome, bool modificavel );

#define YYSTYPE Atributos

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

vector<string> concatena( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

vector<string> operator+( string a, vector<string> b ) {
  return vector<string>{ a } + b;
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ )
    if( entrada[i][0] == ':' )
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );

  for( int i = 0; i < saida.size(); i++ )
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);

  return saida;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

void print( vector<string> codigo ) {
  for( string s : codigo )
    cout << s << " ";

  cout << endl;
}

#line 159 "y.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    LET = 261,                     /* LET  */
    CONST = 262,                   /* CONST  */
    VAR = 263,                     /* VAR  */
    PRINT = 264,                   /* PRINT  */
    FOR = 265,                     /* FOR  */
    WHILE = 266,                   /* WHILE  */
    CDOUBLE = 267,                 /* CDOUBLE  */
    CSTRING = 268,                 /* CSTRING  */
    CINT = 269,                    /* CINT  */
    AND = 270,                     /* AND  */
    OR = 271,                      /* OR  */
    ME_IG = 272,                   /* ME_IG  */
    MA_IG = 273,                   /* MA_IG  */
    DIF = 274,                     /* DIF  */
    IGUAL = 275,                   /* IGUAL  */
    MAIS_IGUAL = 276,              /* MAIS_IGUAL  */
    MAIS_MAIS = 277                /* MAIS_MAIS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define IF 259
#define ELSE 260
#define LET 261
#define CONST 262
#define VAR 263
#define PRINT 264
#define FOR 265
#define WHILE 266
#define CDOUBLE 267
#define CSTRING 268
#define CINT 269
#define AND 270
#define OR 271
#define ME_IG 272
#define MA_IG 273
#define DIF 274
#define IGUAL 275
#define MAIS_IGUAL 276
#define MAIS_MAIS 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_LET = 6,                        /* LET  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_PRINT = 9,                      /* PRINT  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_CDOUBLE = 12,                   /* CDOUBLE  */
  YYSYMBOL_CSTRING = 13,                   /* CSTRING  */
  YYSYMBOL_CINT = 14,                      /* CINT  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_ME_IG = 17,                     /* ME_IG  */
  YYSYMBOL_MA_IG = 18,                     /* MA_IG  */
  YYSYMBOL_DIF = 19,                       /* DIF  */
  YYSYMBOL_IGUAL = 20,                     /* IGUAL  */
  YYSYMBOL_MAIS_IGUAL = 21,                /* MAIS_IGUAL  */
  YYSYMBOL_MAIS_MAIS = 22,                 /* MAIS_MAIS  */
  YYSYMBOL_23_ = 23,                       /* '='  */
  YYSYMBOL_24_ = 24,                       /* '<'  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '/'  */
  YYSYMBOL_30_ = 30,                       /* '%'  */
  YYSYMBOL_31_ = 31,                       /* '['  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '.'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_S = 41,                         /* S  */
  YYSYMBOL_CMDs = 42,                      /* CMDs  */
  YYSYMBOL_CMD = 43,                       /* CMD  */
  YYSYMBOL_CMD_WHILE = 44,                 /* CMD_WHILE  */
  YYSYMBOL_CMD_FOR = 45,                   /* CMD_FOR  */
  YYSYMBOL_PRIM_E = 46,                    /* PRIM_E  */
  YYSYMBOL_CMD_LET = 47,                   /* CMD_LET  */
  YYSYMBOL_LET_VARs = 48,                  /* LET_VARs  */
  YYSYMBOL_LET_VAR = 49,                   /* LET_VAR  */
  YYSYMBOL_CMD_VAR = 50,                   /* CMD_VAR  */
  YYSYMBOL_VAR_VARs = 51,                  /* VAR_VARs  */
  YYSYMBOL_VAR_VAR = 52,                   /* VAR_VAR  */
  YYSYMBOL_CMD_CONST = 53,                 /* CMD_CONST  */
  YYSYMBOL_CONST_VARs = 54,                /* CONST_VARs  */
  YYSYMBOL_CONST_VAR = 55,                 /* CONST_VAR  */
  YYSYMBOL_CMD_IF = 56,                    /* CMD_IF  */
  YYSYMBOL_LVALUE = 57,                    /* LVALUE  */
  YYSYMBOL_E = 58                          /* E  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,     2,     2,     2,     2,    30,     2,     2,
      36,    37,    28,    26,    38,    27,    33,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      24,    23,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   109,   110,   113,   114,   115,   116,   117,
     119,   120,   121,   122,   123,   125,   127,   131,   143,   159,
     160,   161,   162,   166,   169,   170,   173,   175,   179,   184,
     189,   196,   199,   200,   203,   205,   208,   213,   218,   225,
     228,   229,   232,   235,   240,   245,   252,   269,   284,   288,
     290,   292,   294,   296,   298,   300,   302,   304,   306,   308,
     310,   312,   314,   316,   318,   320,   322,   324,   326,   328,
     330,   331,   332,   333,   335,   337,   339,   341,   344
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "IF", "ELSE",
  "LET", "CONST", "VAR", "PRINT", "FOR", "WHILE", "CDOUBLE", "CSTRING",
  "CINT", "AND", "OR", "ME_IG", "MA_IG", "DIF", "IGUAL", "MAIS_IGUAL",
  "MAIS_MAIS", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'['", "'{'", "'.'", "';'", "'}'", "'('", "')'", "','", "']'", "$accept",
  "S", "CMDs", "CMD", "CMD_WHILE", "CMD_FOR", "PRIM_E", "CMD_LET",
  "LET_VARs", "LET_VAR", "CMD_VAR", "VAR_VARs", "VAR_VAR", "CMD_CONST",
  "CONST_VARs", "CONST_VAR", "CMD_IF", "LVALUE", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -91,     3,   120,   -91,   -91,   -29,    17,    18,    24,    19,
       2,     4,   -91,   -91,   -91,   -91,   -91,    74,   -91,    23,
      26,    32,    44,    45,   -91,    -8,    87,    19,    30,   -91,
      52,    59,   -91,    53,    60,   -91,    54,   302,    -2,    19,
      61,    63,   246,   -91,   -91,   -91,   -91,   -91,    19,   -91,
     185,    19,    97,    19,    19,    19,    19,    19,    19,    19,
      19,   -91,   260,    49,    17,   132,    18,   148,    24,   -91,
      67,   -91,   -91,   -91,   324,   274,   -91,    65,   -91,   324,
      68,   324,   198,   -14,   335,   335,   335,     7,     7,   -91,
     -91,   -91,   120,    19,    69,    85,   324,   -91,    19,    70,
     101,   324,   -91,    19,    83,   102,   324,   -91,    19,   120,
     -91,   -91,    -7,   164,    19,   135,   324,   -91,   -91,   324,
     -91,   -91,   324,   -91,   -91,   313,   -91,   178,    19,   103,
     108,   324,   214,   120,    19,   109,   112,   324,   230,   -91,
     -91,     5,   -91,   288,   -91,   -91,   126,    19,    19,   120,
      19,   324,   324,   -91,   324
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    48,     0,     0,     0,     0,     0,
       0,     0,    70,    71,    72,     4,    15,     0,     3,    12,
      10,     0,     0,     0,     8,    73,     0,     0,    26,    23,
      25,     0,    39,    41,    34,    31,    33,     0,     0,     0,
       0,     0,     0,    13,    11,     5,     6,     7,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     9,
       0,    19,    20,    21,    22,     0,    16,     0,    77,    51,
       0,    50,     0,    74,    69,    62,    63,    64,    65,    66,
      67,    68,     0,     0,     0,     0,    27,    24,     0,     0,
       0,    42,    40,     0,     0,     0,    35,    32,     0,     0,
      78,    49,    75,     0,     0,    47,    30,    29,    28,    45,
      43,    44,    38,    36,    37,     0,    17,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,    58,     0,    55,
      54,     0,    46,     0,    60,    59,    76,     0,     0,     0,
       0,    57,    56,    18,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   138,   -90,   -91,   -91,   -91,   117,    86,   -91,
     119,    90,   -91,   127,   100,   -91,   -91,   -91,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    18,    19,    20,    70,    21,    29,    30,
      22,    35,    36,    23,    32,    33,    24,    25,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,     4,   115,     3,     6,     7,     8,    27,    42,   113,
      12,    13,    14,    48,    49,    50,   127,   114,    62,   126,
      28,    31,     4,    51,   128,    52,   147,    34,   148,    74,
      75,    12,    13,    14,    17,    58,    59,    60,    38,    79,
      39,    81,    82,   142,    84,    85,    86,    87,    88,    89,
      90,    91,     4,    63,    96,    17,   101,    43,   106,   153,
      44,    12,    13,    14,     4,     5,    45,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    93,     4,    46,    47,
      94,    95,    65,    67,   116,    17,    12,    13,    14,   119,
      64,    66,    68,    15,   122,    16,    76,    17,    77,   125,
      83,   108,   110,   111,   131,   132,    41,    53,   117,   120,
      17,    54,    55,    56,    57,    58,    59,    60,   137,   138,
     118,    61,   123,     4,     5,   143,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     4,   121,   124,   151,   152,
     133,   154,   139,   140,    12,    13,    14,   145,   144,   150,
      97,     4,    15,    40,    16,    71,    17,    72,   107,    98,
      12,    13,    14,    99,   100,    73,   102,     4,    17,     0,
       0,     0,     0,     0,     0,   103,    12,    13,    14,   104,
     105,     4,     0,     0,    17,     0,     0,     0,     4,     0,
      12,    13,    14,     0,     0,   129,   130,    12,    13,    14,
      17,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     136,     0,     0,     0,    17,     0,     0,    80,    53,     0,
       0,    17,    54,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,    53,     0,     0,   112,    54,    55,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
      53,     0,     0,   141,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,    53,     0,     0,   146,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
      53,     0,     0,    78,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,    53,     0,     0,    92,    54,    55,
      56,    57,    58,    59,    60,     0,     0,     0,    53,     0,
       0,   109,    54,    55,    56,    57,    58,    59,    60,     0,
       0,     0,    53,     0,     0,   149,    54,    55,    56,    57,
      58,    59,    60,    53,     0,     0,    69,    54,    55,    56,
      57,    58,    59,    60,    53,     0,     0,   134,    54,    55,
      56,    57,    58,    59,    60,    -1,     0,     0,     0,    -1,
      -1,    56,    57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
       9,     3,    92,     0,     6,     7,     8,    36,    17,    23,
      12,    13,    14,    21,    22,    23,    23,    31,    27,   109,
       3,     3,     3,    31,    31,    33,    21,     3,    23,    38,
      39,    12,    13,    14,    36,    28,    29,    30,    36,    48,
      36,    50,    51,   133,    53,    54,    55,    56,    57,    58,
      59,    60,     3,    23,    63,    36,    65,    34,    67,   149,
      34,    12,    13,    14,     3,     4,    34,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    27,     3,    34,    34,
      31,    32,    23,    23,    93,    36,    12,    13,    14,    98,
      38,    38,    38,    32,   103,    34,    35,    36,    35,   108,
       3,    34,    37,    35,   113,   114,    32,    20,    39,    39,
      36,    24,    25,    26,    27,    28,    29,    30,   127,   128,
      35,    34,    39,     3,     4,   134,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     3,    35,    35,   147,   148,
       5,   150,    39,    35,    12,    13,    14,    35,    39,    23,
      64,     3,    32,    15,    34,    38,    36,    38,    68,    27,
      12,    13,    14,    31,    32,    38,    66,     3,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    12,    13,    14,    31,
      32,     3,    -1,    -1,    36,    -1,    -1,    -1,     3,    -1,
      12,    13,    14,    -1,    -1,    31,    32,    12,    13,    14,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    32,    20,    -1,
      -1,    36,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    39,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    39,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    39,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      20,    -1,    -1,    37,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    20,    -1,    -1,    37,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    20,    -1,
      -1,    37,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    20,    -1,    -1,    37,    24,    25,    26,    27,
      28,    29,    30,    20,    -1,    -1,    34,    24,    25,    26,
      27,    28,    29,    30,    20,    -1,    -1,    34,    24,    25,
      26,    27,    28,    29,    30,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    42,     0,     3,     4,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    32,    34,    36,    43,    44,
      45,    47,    50,    53,    56,    57,    58,    36,     3,    48,
      49,     3,    54,    55,     3,    51,    52,    58,    36,    36,
      42,    32,    58,    34,    34,    34,    34,    34,    21,    22,
      23,    31,    33,    20,    24,    25,    26,    27,    28,    29,
      30,    34,    58,    23,    38,    23,    38,    23,    38,    34,
      46,    47,    50,    53,    58,    58,    35,    35,    37,    58,
      32,    58,    58,     3,    58,    58,    58,    58,    58,    58,
      58,    58,    37,    27,    31,    32,    58,    48,    27,    31,
      32,    58,    54,    27,    31,    32,    58,    51,    34,    37,
      37,    35,    39,    23,    31,    43,    58,    39,    35,    58,
      39,    35,    58,    39,    35,    58,    43,    23,    31,    31,
      32,    58,    58,     5,    34,    31,    32,    58,    58,    39,
      35,    39,    43,    58,    39,    35,    39,    21,    23,    37,
      23,    58,    58,    43,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    44,    45,    46,
      46,    46,    46,    47,    48,    48,    49,    49,    49,    49,
      49,    50,    51,    51,    52,    52,    52,    52,    52,    53,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     1,     3,
       1,     2,     1,     2,     2,     1,     3,     5,     9,     1,
       1,     1,     1,     2,     3,     1,     1,     3,     4,     4,
       4,     2,     3,     1,     1,     3,     4,     4,     4,     2,
       3,     1,     3,     4,     4,     4,     7,     5,     1,     4,
       3,     3,     2,     5,     6,     6,     8,     8,     6,     7,
       7,     9,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     4,     7,     3,     4
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
  case 2: /* S: CMDs  */
#line 106 "cmdif.y"
         { print( resolve_enderecos( yyvsp[0].c + "." ) ); }
#line 1419 "y.tab.c"
    break;

  case 3: /* CMDs: CMDs CMD  */
#line 109 "cmdif.y"
                 { yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1425 "y.tab.c"
    break;

  case 4: /* CMDs: %empty  */
#line 110 "cmdif.y"
                 { yyval.clear(); }
#line 1431 "y.tab.c"
    break;

  case 9: /* CMD: PRINT E ';'  */
#line 118 "cmdif.y"
      { yyval.c = yyvsp[-1].c + "println" + "#"; }
#line 1437 "y.tab.c"
    break;

  case 14: /* CMD: E ';'  */
#line 124 "cmdif.y"
      { yyval.c = yyvsp[-1].c + "^"; }
#line 1443 "y.tab.c"
    break;

  case 15: /* CMD: ';'  */
#line 126 "cmdif.y"
    {  yyval.c.clear(); }
#line 1449 "y.tab.c"
    break;

  case 16: /* CMD: '{' CMDs '}'  */
#line 128 "cmdif.y"
      { yyval.c = yyvsp[-1].c; }
#line 1455 "y.tab.c"
    break;

  case 17: /* CMD_WHILE: WHILE '(' E ')' CMD  */
#line 132 "cmdif.y"
           { string lbl_while = gera_label( "while" );
             string lbl_fim_while = gera_label( "fim_while" );
             string definicao_lbl_while = ":" + lbl_while;
             string definicao_lbl_fim_while = ":" + lbl_fim_while;

             yyval.c = yyvsp[-2].c + lbl_while + "?" + lbl_fim_while + "#" +
                    definicao_lbl_while + yyvsp[0].c + yyvsp[-2].c + lbl_while + "?" + lbl_fim_while + "#" +
                    definicao_lbl_fim_while;
           }
#line 1469 "y.tab.c"
    break;

  case 18: /* CMD_FOR: FOR '(' PRIM_E ';' E ';' E ')' CMD  */
#line 144 "cmdif.y"
        { string lbl_fim_for = gera_label( "fim_for" );
          string lbl_condicao_for = gera_label( "condicao_for" );
          string lbl_comando_for = gera_label( "comando_for" );
          string definicao_lbl_fim_for = ":" + lbl_fim_for;
          string definicao_lbl_condicao_for = ":" + lbl_condicao_for;
          string definicao_lbl_comando_for = ":" + lbl_comando_for;

          yyval.c = yyvsp[-6].c + definicao_lbl_condicao_for +
                 yyvsp[-4].c + lbl_comando_for + "?" + lbl_fim_for + "#" +
                 definicao_lbl_comando_for + yyvsp[0].c +
                 yyvsp[-2].c + "^" + lbl_condicao_for + "#" +
                 definicao_lbl_fim_for;
        }
#line 1487 "y.tab.c"
    break;

  case 22: /* PRIM_E: E  */
#line 163 "cmdif.y"
         { yyval.c = yyvsp[0].c + "^"; }
#line 1493 "y.tab.c"
    break;

  case 23: /* CMD_LET: LET LET_VARs  */
#line 166 "cmdif.y"
                       { yyval.c = yyvsp[0].c; }
#line 1499 "y.tab.c"
    break;

  case 24: /* LET_VARs: LET_VAR ',' LET_VARs  */
#line 169 "cmdif.y"
                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1505 "y.tab.c"
    break;

  case 26: /* LET_VAR: ID  */
#line 174 "cmdif.y"
          { yyval.c = declara_var( Let, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); }
#line 1511 "y.tab.c"
    break;

  case 27: /* LET_VAR: ID '=' E  */
#line 176 "cmdif.y"
          {
            yyval.c = declara_var( Let, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) +
                   yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1519 "y.tab.c"
    break;

  case 28: /* LET_VAR: ID '=' '{' '}'  */
#line 180 "cmdif.y"
          {
            yyval.c = declara_var( Let, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
                   yyvsp[-3].c + "{}" + "=" + "^";
          }
#line 1528 "y.tab.c"
    break;

  case 29: /* LET_VAR: ID '=' '[' ']'  */
#line 185 "cmdif.y"
          {
            yyval.c = declara_var( Let, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
                   yyvsp[-3].c + "[]" + "=" + "^";
          }
#line 1537 "y.tab.c"
    break;

  case 30: /* LET_VAR: ID '=' '-' E  */
#line 190 "cmdif.y"
          {
            yyval.c = declara_var( Let, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
              yyvsp[-3].c + "0" + yyvsp[0].c + "-" + "=" + "^";
          }
#line 1546 "y.tab.c"
    break;

  case 31: /* CMD_VAR: VAR VAR_VARs  */
#line 196 "cmdif.y"
                       { yyval.c = yyvsp[0].c; }
#line 1552 "y.tab.c"
    break;

  case 32: /* VAR_VARs: VAR_VAR ',' VAR_VARs  */
#line 199 "cmdif.y"
                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1558 "y.tab.c"
    break;

  case 34: /* VAR_VAR: ID  */
#line 204 "cmdif.y"
          { yyval.c = declara_var( Var, yyvsp[0].c[0], yyvsp[0].linha, yyvsp[0].coluna ); }
#line 1564 "y.tab.c"
    break;

  case 35: /* VAR_VAR: ID '=' E  */
#line 206 "cmdif.y"
          { yyval.c = declara_var( Var, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) +
                   yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1571 "y.tab.c"
    break;

  case 36: /* VAR_VAR: ID '=' '[' ']'  */
#line 209 "cmdif.y"
          {
            yyval.c = declara_var( Var, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
                   yyvsp[-3].c + "[]" + "=" + "^";
          }
#line 1580 "y.tab.c"
    break;

  case 37: /* VAR_VAR: ID '=' '{' '}'  */
#line 214 "cmdif.y"
          {
            yyval.c = declara_var( Var, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
                   yyvsp[-3].c + "{}" + "=" + "^";
          }
#line 1589 "y.tab.c"
    break;

  case 38: /* VAR_VAR: ID '=' '-' E  */
#line 219 "cmdif.y"
          {
            yyval.c = declara_var( Var, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
              yyvsp[-3].c + "0" + yyvsp[0].c + "-" + "=" + "^";
          }
#line 1598 "y.tab.c"
    break;

  case 39: /* CMD_CONST: CONST CONST_VARs  */
#line 225 "cmdif.y"
                            { yyval.c = yyvsp[0].c; }
#line 1604 "y.tab.c"
    break;

  case 40: /* CONST_VARs: CONST_VAR ',' CONST_VARs  */
#line 228 "cmdif.y"
                                      { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1610 "y.tab.c"
    break;

  case 42: /* CONST_VAR: ID '=' E  */
#line 233 "cmdif.y"
            { yyval.c = declara_var( Const, yyvsp[-2].c[0], yyvsp[-2].linha, yyvsp[-2].coluna ) +
                     yyvsp[-2].c + yyvsp[0].c + "=" + "^"; }
#line 1617 "y.tab.c"
    break;

  case 43: /* CONST_VAR: ID '=' '[' ']'  */
#line 236 "cmdif.y"
            {
              yyval.c = declara_var( Const, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
                     yyvsp[-3].c + "[]" + "=" + "^";
            }
#line 1626 "y.tab.c"
    break;

  case 44: /* CONST_VAR: ID '=' '{' '}'  */
#line 241 "cmdif.y"
            {
              yyval.c = declara_var( Const, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
                     yyvsp[-3].c + "{}" + "=" + "^";
            }
#line 1635 "y.tab.c"
    break;

  case 45: /* CONST_VAR: ID '=' '-' E  */
#line 246 "cmdif.y"
          {
            yyval.c = declara_var( Const, yyvsp[-3].c[0], yyvsp[-3].linha, yyvsp[-3].coluna ) +
              yyvsp[-3].c + "0" + yyvsp[0].c + "-" + "=" + "^";
          }
#line 1644 "y.tab.c"
    break;

  case 46: /* CMD_IF: IF '(' E ')' CMD ELSE CMD  */
#line 253 "cmdif.y"
         { string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string lbl_else = gera_label( "lbl_else" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;
           string definicao_lbl_else = ":" + lbl_else;

            yyval.c = yyvsp[-4].c +                        // Codigo da expressão
                    lbl_true + "?" +             // Código do IF
                    lbl_else + "#" +             // Código do False
                    definicao_lbl_true + yyvsp[-2].c +  // Código do True
                    lbl_fim_if + "#" +           // Código do Fim do IF
                    definicao_lbl_else + yyvsp[0].c +  // Código do Else
                    definicao_lbl_fim_if         // Fim do IF
                   ;
         }
#line 1665 "y.tab.c"
    break;

  case 47: /* CMD_IF: IF '(' E ')' CMD  */
#line 270 "cmdif.y"
          { string lbl_true = gera_label( "lbl_true" );
            string lbl_fim_if = gera_label( "lbl_fim_if" );
            string definicao_lbl_true = ":" + lbl_true;
            string definicao_lbl_fim_if = ":" + lbl_fim_if;

              yyval.c = yyvsp[-2].c +                      // Codigo da expressão
                    lbl_true + "?" +             // Código do IF
                    lbl_fim_if + "#" +           // Código do False
                    definicao_lbl_true + yyvsp[0].c +  // Código do True
                    definicao_lbl_fim_if         // Fim do IF
                    ;
          }
#line 1682 "y.tab.c"
    break;

  case 49: /* E: LVALUE '=' '{' '}'  */
#line 289 "cmdif.y"
    { checa_simbolo( yyvsp[-3].c[0], true ); yyval.c = yyvsp[-3].c + "{}" + "="; }
#line 1688 "y.tab.c"
    break;

  case 50: /* E: LVALUE '=' E  */
#line 291 "cmdif.y"
    { checa_simbolo( yyvsp[-2].c[0], true ); yyval.c = yyvsp[-2].c + yyvsp[0].c + "="; }
#line 1694 "y.tab.c"
    break;

  case 51: /* E: LVALUE MAIS_IGUAL E  */
#line 293 "cmdif.y"
    { checa_simbolo( yyvsp[-2].c[0], true ); yyval.c = yyvsp[-2].c + yyvsp[-2].c + "@" + yyvsp[0].c + "+" + "="; }
#line 1700 "y.tab.c"
    break;

  case 52: /* E: LVALUE MAIS_MAIS  */
#line 295 "cmdif.y"
    { checa_simbolo( yyvsp[-1].c[0], true ); yyval.c = yyvsp[-1].c + "@" + yyvsp[-1].c + yyvsp[-1].c + "@" + "1" + "+" + "=" + "^"; }
#line 1706 "y.tab.c"
    break;

  case 53: /* E: LVALUE '.' ID '=' E  */
#line 297 "cmdif.y"
    { checa_simbolo( yyvsp[-4].c[0], true ); yyval.c = yyvsp[-4].c + "@" + yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 1712 "y.tab.c"
    break;

  case 54: /* E: LVALUE '.' ID '=' '{' '}'  */
#line 299 "cmdif.y"
    { checa_simbolo( yyvsp[-5].c[0], true ); yyval.c = yyvsp[-5].c + "@" + yyvsp[-3].c + "{}" + "[=]"; }
#line 1718 "y.tab.c"
    break;

  case 55: /* E: LVALUE '.' ID '=' '[' ']'  */
#line 301 "cmdif.y"
    { checa_simbolo( yyvsp[-5].c[0], true ); yyval.c = yyvsp[-5].c + "@" + yyvsp[-3].c + "[]" + "[=]"; }
#line 1724 "y.tab.c"
    break;

  case 56: /* E: LVALUE '.' ID '[' E ']' '=' E  */
#line 303 "cmdif.y"
    { checa_simbolo( yyvsp[-7].c[0], true ); yyval.c = yyvsp[-7].c + "@" + yyvsp[-5].c + "[@]" + yyvsp[-3].c + yyvsp[0].c + "[=]"; }
#line 1730 "y.tab.c"
    break;

  case 57: /* E: LVALUE '.' ID '[' E ']' MAIS_IGUAL E  */
#line 305 "cmdif.y"
    { checa_simbolo( yyvsp[-7].c[0], true ); yyval.c = yyvsp[-7].c + "@" + yyvsp[-5].c + "[@]" + yyvsp[-3].c + yyvsp[-7].c + "@" + yyvsp[-5].c + "[@]" + yyvsp[-3].c + "[@]" + yyvsp[0].c + "+" + "[=]"; }
#line 1736 "y.tab.c"
    break;

  case 58: /* E: LVALUE '[' E ']' '=' E  */
#line 307 "cmdif.y"
    { checa_simbolo( yyvsp[-5].c[0], true ); yyval.c = yyvsp[-5].c + "@" + yyvsp[-3].c + yyvsp[0].c + "[=]"; }
#line 1742 "y.tab.c"
    break;

  case 59: /* E: LVALUE '[' E ']' '=' '{' '}'  */
#line 309 "cmdif.y"
    { checa_simbolo( yyvsp[-6].c[0], true ); yyval.c = yyvsp[-6].c + "@" + yyvsp[-4].c + "{}" + "[=]"; }
#line 1748 "y.tab.c"
    break;

  case 60: /* E: LVALUE '[' E ']' '=' '[' ']'  */
#line 311 "cmdif.y"
    { checa_simbolo( yyvsp[-6].c[0], true ); yyval.c = yyvsp[-6].c + "@" + yyvsp[-4].c + "[]" + "[=]"; }
#line 1754 "y.tab.c"
    break;

  case 61: /* E: LVALUE '[' E ']' '[' E ']' '=' E  */
#line 313 "cmdif.y"
    { checa_simbolo( yyvsp[-8].c[0], true ); yyval.c = yyvsp[-8].c + "@" + yyvsp[-6].c + "[@]" + yyvsp[-3].c + yyvsp[0].c + "[=]"; }
#line 1760 "y.tab.c"
    break;

  case 62: /* E: E '<' E  */
#line 315 "cmdif.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1766 "y.tab.c"
    break;

  case 63: /* E: E '>' E  */
#line 317 "cmdif.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1772 "y.tab.c"
    break;

  case 64: /* E: E '+' E  */
#line 319 "cmdif.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1778 "y.tab.c"
    break;

  case 65: /* E: E '-' E  */
#line 321 "cmdif.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1784 "y.tab.c"
    break;

  case 66: /* E: E '*' E  */
#line 323 "cmdif.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1790 "y.tab.c"
    break;

  case 67: /* E: E '/' E  */
#line 325 "cmdif.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1796 "y.tab.c"
    break;

  case 68: /* E: E '%' E  */
#line 327 "cmdif.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1802 "y.tab.c"
    break;

  case 69: /* E: E IGUAL E  */
#line 329 "cmdif.y"
    { yyval.c = yyvsp[-2].c + yyvsp[0].c + yyvsp[-1].c; }
#line 1808 "y.tab.c"
    break;

  case 73: /* E: LVALUE  */
#line 334 "cmdif.y"
    { checa_simbolo( yyvsp[0].c[0], false ); yyval.c = yyvsp[0].c + "@"; }
#line 1814 "y.tab.c"
    break;

  case 74: /* E: LVALUE '.' ID  */
#line 336 "cmdif.y"
    { checa_simbolo( yyvsp[-2].c[0], false ); yyval.c = yyvsp[-2].c + "@" + yyvsp[0].c + "[@]"; }
#line 1820 "y.tab.c"
    break;

  case 75: /* E: LVALUE '[' E ']'  */
#line 338 "cmdif.y"
    { checa_simbolo( yyvsp[-3].c[0], false ); yyval.c = yyvsp[-3].c + "@" + yyvsp[-1].c + "[@]"; }
#line 1826 "y.tab.c"
    break;

  case 76: /* E: LVALUE '[' E ']' '[' E ']'  */
#line 340 "cmdif.y"
    { checa_simbolo( yyvsp[-6].c[0], false ); yyval.c = yyvsp[-6].c + "@" + yyvsp[-4].c + "[@]" + yyvsp[-1].c + "[@]"; }
#line 1832 "y.tab.c"
    break;

  case 77: /* E: '(' E ')'  */
#line 342 "cmdif.y"
    { yyval.c = yyvsp[-1].c; }
#line 1838 "y.tab.c"
    break;

  case 78: /* E: '(' '{' '}' ')'  */
#line 345 "cmdif.y"
    { yyval.c = vector<string>{"{}"}; }
#line 1844 "y.tab.c"
    break;


#line 1848 "y.tab.c"

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

#line 349 "cmdif.y"


#include "lex.yy.c"

vector<string> declara_var( TipoDecl tipo, string nome, int linha, int coluna ) {
  // cerr << "insere_simbolo( " << tipo << ", " << nome
  //      << ", " << linha << ", " << coluna << ")" << endl;

  if( ts.count( nome ) == 0 ) {
    ts[nome] = Simbolo{ tipo, linha, coluna };
    return vector<string>{ nome, "&" };
  }
  else if( tipo == Var && ts[nome].tipo == Var ) {
    ts[nome] = Simbolo{ tipo, linha, coluna };
    return vector<string>{};
  }
  else {
    cerr << "Erro: a variável '" << nome << "' ja foi declarada na linha " << ts[nome].linha
         << "." << endl;
    exit( 1 );
  }
}

void checa_simbolo( string nome, bool modificavel ) {
  if( ts.count( nome ) > 0 ) {
    if( modificavel && ts[nome].tipo == Const ) {
      cerr << "Variavel '" << nome << "' não pode ser modificada." << endl;
      exit( 1 );
    }
  }
  else {
    cerr << "Erro: a variável '" << nome << "' não foi declarada." << endl;
    exit( 1 );
  }
}

void yyerror( const char* st ) {
   cerr << st << endl;
   cerr << "Proximo a: " << yytext << endl;
   exit( 1 );
}

int main( int argc, char* argv[] ) {
  yyparse();

  return 0;
}