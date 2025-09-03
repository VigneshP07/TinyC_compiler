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
#line 1 "tinyC3.y"

    #include <iostream>
    #include "translator.h"
    #include <cstring>
    using namespace std;

    extern int yylex();
    extern char* yytext;
    extern int lineno;

    //Function to print the error message and its position
    void yyerror(const char *s){
        printf("In line no-%d, unable to parse: %s",lineno,yytext);
        printf("Error : %s\n",s);
        return;
    }

    extern string var_type;
    extern string id;

#line 92 "tinyC3.tab.c"

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

#include "tinyC3.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTCONST = 4,                   /* INTCONST  */
  YYSYMBOL_FLOATCONST = 5,                 /* FLOATCONST  */
  YYSYMBOL_CHARCONST = 6,                  /* CHARCONST  */
  YYSYMBOL_STR_LITERAL = 7,                /* STR_LITERAL  */
  YYSYMBOL_EXTERN = 8,                     /* EXTERN  */
  YYSYMBOL_STATIC = 9,                     /* STATIC  */
  YYSYMBOL_AUTO = 10,                      /* AUTO  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_REGISTER = 13,                  /* REGISTER  */
  YYSYMBOL_SHORT = 14,                     /* SHORT  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_LONG = 16,                      /* LONG  */
  YYSYMBOL_FLOAT = 17,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 18,                    /* DOUBLE  */
  YYSYMBOL_SIGNED = 19,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 20,                  /* UNSIGNED  */
  YYSYMBOL_BOOL = 21,                      /* BOOL  */
  YYSYMBOL_COMPLEX = 22,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 23,                 /* IMAGINARY  */
  YYSYMBOL_CONST = 24,                     /* CONST  */
  YYSYMBOL_RESTRICT = 25,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 26,                  /* VOLATILE  */
  YYSYMBOL_INLINE = 27,                    /* INLINE  */
  YYSYMBOL_SO_ON = 28,                     /* SO_ON  */
  YYSYMBOL_CASE = 29,                      /* CASE  */
  YYSYMBOL_DEFAULT = 30,                   /* DEFAULT  */
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_SWITCH = 33,                    /* SWITCH  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_DO = 35,                        /* DO  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_GOTO = 37,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 38,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 39,                     /* BREAK  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_ENUM = 41,                      /* ENUM  */
  YYSYMBOL_ERROR = 42,                     /* ERROR  */
  YYSYMBOL_IMPLIES = 43,                   /* IMPLIES  */
  YYSYMBOL_INCRE = 44,                     /* INCRE  */
  YYSYMBOL_DECRE = 45,                     /* DECRE  */
  YYSYMBOL_SIZEOF = 46,                    /* SIZEOF  */
  YYSYMBOL_LSHIFT = 47,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 48,                    /* RSHIFT  */
  YYSYMBOL_GEQ = 49,                       /* GEQ  */
  YYSYMBOL_LEQ = 50,                       /* LEQ  */
  YYSYMBOL_EQEQ = 51,                      /* EQEQ  */
  YYSYMBOL_NEQ = 52,                       /* NEQ  */
  YYSYMBOL_AND = 53,                       /* AND  */
  YYSYMBOL_OR = 54,                        /* OR  */
  YYSYMBOL_MULEQ = 55,                     /* MULEQ  */
  YYSYMBOL_DIVEQ = 56,                     /* DIVEQ  */
  YYSYMBOL_MODEQ = 57,                     /* MODEQ  */
  YYSYMBOL_ADDEQ = 58,                     /* ADDEQ  */
  YYSYMBOL_SUBEQ = 59,                     /* SUBEQ  */
  YYSYMBOL_LSHEQ = 60,                     /* LSHEQ  */
  YYSYMBOL_RSHEQ = 61,                     /* RSHEQ  */
  YYSYMBOL_ANDEQ = 62,                     /* ANDEQ  */
  YYSYMBOL_XOREQ = 63,                     /* XOREQ  */
  YYSYMBOL_OREQ = 64,                      /* OREQ  */
  YYSYMBOL_OP_SQUARE = 65,                 /* OP_SQUARE  */
  YYSYMBOL_CL_SQUARE = 66,                 /* CL_SQUARE  */
  YYSYMBOL_OP_ROUND = 67,                  /* OP_ROUND  */
  YYSYMBOL_CL_ROUND = 68,                  /* CL_ROUND  */
  YYSYMBOL_OP_CURLY = 69,                  /* OP_CURLY  */
  YYSYMBOL_CL_CURLY = 70,                  /* CL_CURLY  */
  YYSYMBOL_DOT = 71,                       /* DOT  */
  YYSYMBOL_BIT_AND = 72,                   /* BIT_AND  */
  YYSYMBOL_PLUS = 73,                      /* PLUS  */
  YYSYMBOL_MIN = 74,                       /* MIN  */
  YYSYMBOL_MUL = 75,                       /* MUL  */
  YYSYMBOL_BIT_NOT = 76,                   /* BIT_NOT  */
  YYSYMBOL_NOT = 77,                       /* NOT  */
  YYSYMBOL_DIV = 78,                       /* DIV  */
  YYSYMBOL_MOD = 79,                       /* MOD  */
  YYSYMBOL_LT = 80,                        /* LT  */
  YYSYMBOL_GT = 81,                        /* GT  */
  YYSYMBOL_BIT_XOR = 82,                   /* BIT_XOR  */
  YYSYMBOL_BIT_OR = 83,                    /* BIT_OR  */
  YYSYMBOL_Q_MARK = 84,                    /* Q_MARK  */
  YYSYMBOL_COLON = 85,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 86,                 /* SEMICOLON  */
  YYSYMBOL_EQ = 87,                        /* EQ  */
  YYSYMBOL_COMMA = 88,                     /* COMMA  */
  YYSYMBOL_LOWER_THAN_ELSE = 89,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 90,                  /* $accept  */
  YYSYMBOL_primary_expression = 91,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 92,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 93,  /* argument_expression_list  */
  YYSYMBOL_argument_expression_list_opt = 94, /* argument_expression_list_opt  */
  YYSYMBOL_unary_expression = 95,          /* unary_expression  */
  YYSYMBOL_unary_operator = 96,            /* unary_operator  */
  YYSYMBOL_cast_expression = 97,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 98, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 99,       /* additive_expression  */
  YYSYMBOL_shift_expression = 100,         /* shift_expression  */
  YYSYMBOL_relational_expression = 101,    /* relational_expression  */
  YYSYMBOL_equality_expression = 102,      /* equality_expression  */
  YYSYMBOL_AND_expression = 103,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 104,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 105,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 106,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 107,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 108,   /* conditional_expression  */
  YYSYMBOL_next_instr = 109,               /* next_instr  */
  YYSYMBOL_next_list = 110,                /* next_list  */
  YYSYMBOL_assignment_expression = 111,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 112,      /* assignment_operator  */
  YYSYMBOL_expression = 113,               /* expression  */
  YYSYMBOL_constant_expression = 114,      /* constant_expression  */
  YYSYMBOL_declaration = 115,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 116,   /* declaration_specifiers  */
  YYSYMBOL_type_qualifier = 117,           /* type_qualifier  */
  YYSYMBOL_init_declarator_list = 118,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 119,          /* init_declarator  */
  YYSYMBOL_type_specifier = 120,           /* type_specifier  */
  YYSYMBOL_storage_class_specifier = 121,  /* storage_class_specifier  */
  YYSYMBOL_specifier_qualifier_list = 122, /* specifier_qualifier_list  */
  YYSYMBOL_specifier_qualifier_list_opt = 123, /* specifier_qualifier_list_opt  */
  YYSYMBOL_enum_specifier = 124,           /* enum_specifier  */
  YYSYMBOL_identifier_opt = 125,           /* identifier_opt  */
  YYSYMBOL_enumerator_list = 126,          /* enumerator_list  */
  YYSYMBOL_enumerator = 127,               /* enumerator  */
  YYSYMBOL_function_specifier = 128,       /* function_specifier  */
  YYSYMBOL_declarator = 129,               /* declarator  */
  YYSYMBOL_direct_declarator = 130,        /* direct_declarator  */
  YYSYMBOL_type_qualifier_list_opt = 131,  /* type_qualifier_list_opt  */
  YYSYMBOL_pointer = 132,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 133,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 134,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 135,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 136,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 137,          /* identifier_list  */
  YYSYMBOL_type_name = 138,                /* type_name  */
  YYSYMBOL_initializer = 139,              /* initializer  */
  YYSYMBOL_initializer_list = 140,         /* initializer_list  */
  YYSYMBOL_designation_opt = 141,          /* designation_opt  */
  YYSYMBOL_designation = 142,              /* designation  */
  YYSYMBOL_designator_list = 143,          /* designator_list  */
  YYSYMBOL_designator = 144,               /* designator  */
  YYSYMBOL_statement = 145,                /* statement  */
  YYSYMBOL_loop_statement = 146,           /* loop_statement  */
  YYSYMBOL_labeled_statement = 147,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 148,       /* compound_statement  */
  YYSYMBOL_new_table = 149,                /* new_table  */
  YYSYMBOL_change_table = 150,             /* change_table  */
  YYSYMBOL_block_item_list_opt = 151,      /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 152,          /* block_item_list  */
  YYSYMBOL_block_item = 153,               /* block_item  */
  YYSYMBOL_expression_statement = 154,     /* expression_statement  */
  YYSYMBOL_selection_statement = 155,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 156,      /* iteration_statement  */
  YYSYMBOL_while_block = 157,              /* while_block  */
  YYSYMBOL_dowhile_block = 158,            /* dowhile_block  */
  YYSYMBOL_for_block = 159,                /* for_block  */
  YYSYMBOL_jump_statement = 160,           /* jump_statement  */
  YYSYMBOL_translation_unit = 161,         /* translation_unit  */
  YYSYMBOL_external_declaration = 162,     /* external_declaration  */
  YYSYMBOL_function_definition = 163,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 164,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 165,         /* declaration_list  */
  YYSYMBOL_program = 166                   /* program  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1053

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  403

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   344


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    94,   100,   106,   112,   118,   122,   129,
     146,   151,   152,   153,   159,   165,   166,   170,   174,   181,
     182,   186,   187,   191,   195,   226,   227,   231,   232,   233,
     234,   235,   236,   240,   241,   248,   261,   272,   283,   297,
     298,   309,   323,   324,   335,   349,   350,   363,   376,   389,
     405,   406,   421,   439,   440,   457,   458,   475,   476,   493,
     494,   506,   507,   519,   520,   541,   545,   553,   554,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     585,   586,   590,   594,   595,   599,   600,   601,   602,   603,
     604,   605,   606,   610,   611,   612,   616,   617,   621,   622,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   642,   643,   644,   645,   649,   650,   654,
     655,   659,   660,   661,   665,   666,   670,   671,   675,   676,
     680,   684,   692,   696,   702,   703,   704,   705,   730,   747,
     748,   749,   750,   751,   752,   753,   764,   778,   779,   783,
     784,   788,   789,   793,   794,   798,   799,   803,   804,   808,
     809,   813,   817,   818,   819,   823,   824,   828,   829,   833,
     837,   838,   842,   843,   847,   848,   849,   850,   851,   852,
     856,   857,   858,   859,   860,   864,   865,   866,   870,   874,
     886,   898,   899,   903,   904,   908,   909,   913,   914,   918,
     926,   935,   939,   949,   959,   967,   975,   986,   997,  1008,
    1022,  1026,  1030,  1033,  1034,  1035,  1036,  1037,  1041,  1042,
    1046,  1047,  1051,  1055,  1056,  1060,  1061,  1065
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTCONST", "FLOATCONST", "CHARCONST", "STR_LITERAL", "EXTERN", "STATIC",
  "AUTO", "VOID", "CHAR", "REGISTER", "SHORT", "INT", "LONG", "FLOAT",
  "DOUBLE", "SIGNED", "UNSIGNED", "BOOL", "COMPLEX", "IMAGINARY", "CONST",
  "RESTRICT", "VOLATILE", "INLINE", "SO_ON", "CASE", "DEFAULT", "IF",
  "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK",
  "RETURN", "ENUM", "ERROR", "IMPLIES", "INCRE", "DECRE", "SIZEOF",
  "LSHIFT", "RSHIFT", "GEQ", "LEQ", "EQEQ", "NEQ", "AND", "OR", "MULEQ",
  "DIVEQ", "MODEQ", "ADDEQ", "SUBEQ", "LSHEQ", "RSHEQ", "ANDEQ", "XOREQ",
  "OREQ", "OP_SQUARE", "CL_SQUARE", "OP_ROUND", "CL_ROUND", "OP_CURLY",
  "CL_CURLY", "DOT", "BIT_AND", "PLUS", "MIN", "MUL", "BIT_NOT", "NOT",
  "DIV", "MOD", "LT", "GT", "BIT_XOR", "BIT_OR", "Q_MARK", "COLON",
  "SEMICOLON", "EQ", "COMMA", "LOWER_THAN_ELSE", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "argument_expression_list_opt", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "next_instr", "next_list",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "type_qualifier", "init_declarator_list", "init_declarator",
  "type_specifier", "storage_class_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "enum_specifier", "identifier_opt",
  "enumerator_list", "enumerator", "function_specifier", "declarator",
  "direct_declarator", "type_qualifier_list_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation_opt", "designation", "designator_list",
  "designator", "statement", "loop_statement", "labeled_statement",
  "compound_statement", "new_table", "change_table", "block_item_list_opt",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "while_block",
  "dowhile_block", "for_block", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list_opt",
  "declaration_list", "program", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-317)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-225)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1012,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,
    -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,
    -317,    12,  -317,    45,  1012,  1012,  1012,  -317,  1012,  1012,
    -317,  -317,    27,   -35,   -18,  -317,    51,   116,  -317,   101,
    -317,   670,   139,    14,  -317,  -317,  -317,  -317,  -317,  -317,
     126,    39,  -317,    76,   116,  -317,    51,   217,  -317,    45,
    -317,  1012,   725,   175,   139,    69,   -44,  -317,  -317,  -317,
    -317,  -317,   111,  -317,  -317,  -317,  -317,  -317,   827,   827,
     861,   701,   -46,  -317,  -317,  -317,  -317,  -317,  -317,  -317,
     166,   294,   905,  -317,   124,    40,    26,   -10,   112,   122,
     123,   131,   165,   -32,  -317,  -317,  -317,   157,  -317,   803,
    -317,   170,   192,   779,  -317,    82,   944,   905,  -317,    10,
     701,  -317,  -317,   701,  -317,  -317,    84,   630,   630,  -317,
     196,   905,   257,   -23,   217,  -317,   -41,  -317,   267,  -317,
    -317,   905,   905,   270,  -317,  -317,  -317,  -317,  -317,  -317,
    -317,  -317,  -317,  -317,  -317,   905,  -317,  -317,   905,   905,
     905,   905,   905,   905,   905,   905,   905,   905,   905,   905,
     905,   905,   905,   905,  -317,  -317,   191,   296,   212,   803,
    -317,  -317,   905,  -317,   216,   219,  -317,   284,  -317,    51,
     220,   208,  -317,  -317,  -317,  -317,  -317,   256,   260,  -317,
     905,  -317,  -317,  -317,   814,   272,  -317,  -317,   -12,  -317,
    -317,  -317,  -317,    -6,   251,   275,  -317,  -317,  -317,  -317,
    -317,  -317,   124,   124,    40,    40,    26,    26,    26,    26,
     -10,   -10,   112,   122,   123,   905,   905,  -317,   259,   905,
     261,   278,   280,  -317,  -317,  -317,   356,   274,   276,   557,
    -317,  -317,   163,  -317,  -317,  -317,  -317,   291,   297,  -317,
    -317,  -317,  -317,  -317,  -317,   298,   300,  -317,  -317,  -317,
    -317,  -317,   978,   305,   305,  -317,   -46,  -317,  -317,  -317,
     217,  -317,   905,  -317,   131,   165,   905,   405,   290,   405,
     905,   905,   309,   308,   311,   293,  -317,  -317,  -317,   171,
    -317,  -317,  -317,   296,  -317,  -317,  -317,  -317,   -20,  -317,
    -317,   292,  -317,   405,  -317,   292,    85,  -317,  -317,   540,
    -317,  -317,  -317,   296,  -317,  -317,   120,   328,  -317,   346,
     405,  -317,   296,  -317,  -317,  -317,  -317,  -317,  -317,  -317,
     345,  -317,  -317,  -317,  -317,  -317,   347,   382,   380,  -317,
     905,   405,   905,  -317,   351,  -317,  -317,  -317,  -317,   100,
     385,   905,   591,   591,   388,   353,   360,   107,  -317,  -317,
    -317,  -317,   540,   905,   337,   905,   905,   405,   296,  -317,
     109,  -317,   292,   292,  -317,   358,   343,   362,   363,  -317,
    -317,  -317,  -317,   464,   482,   296,  -317,   296,  -317,   367,
     376,  -317,  -317
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   116,   115,   113,   100,   101,   114,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    93,    94,    95,
     130,   125,   221,     0,    90,    88,    86,   112,    92,   227,
     218,   220,     0,   122,     0,   133,     0,   148,    84,     0,
      96,    98,   132,     0,    89,    87,    85,    91,   219,     1,
       0,     0,   151,   149,   147,    83,     0,     0,   225,     0,
     190,   223,     0,   190,   131,   128,     0,   126,   134,   150,
     152,    97,    98,     2,     3,     4,     5,     6,     0,     0,
       0,     0,   168,    27,    29,    30,    28,    31,    32,     8,
      21,    33,     0,    35,    39,    42,    45,    50,    53,    55,
      57,    59,    61,    63,    67,   162,    99,     0,   226,     0,
     138,    28,     0,     0,   159,     0,     0,     0,   121,     0,
       0,    22,    23,     0,    25,    80,     0,   120,   120,   161,
       0,     0,     0,     0,     0,   167,     0,   170,     0,    13,
      14,     0,    20,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    69,     0,    33,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    65,     0,   192,     0,     0,
     143,   137,     0,   135,    28,     0,   144,     0,   146,   158,
       0,   153,   155,    82,   129,   123,   127,     0,     0,     7,
       0,   119,   118,   117,     0,     0,   173,   163,   168,   165,
     169,   171,    12,     0,    19,     0,    17,    11,    68,    36,
      37,    38,    40,    41,    43,    44,    49,    48,    46,    47,
      51,    52,    54,    56,    58,     0,     0,    65,     2,     0,
       0,     0,     0,   210,   211,   212,     0,     0,     0,     0,
     189,   198,     0,   195,   196,   174,   175,     0,    65,   193,
     176,   177,   178,   179,   140,     0,     0,   142,   136,   160,
     157,   145,     0,     0,    26,    81,   168,    34,   172,   164,
       0,     9,     0,    10,    60,    62,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,   214,   215,   217,     0,
     190,   197,   222,     0,   139,   141,   154,   156,     0,   166,
      18,    66,   185,     0,   187,    66,     0,   189,    65,     0,
     189,   213,   216,   192,   194,    15,   168,     0,   186,     0,
       0,   190,   192,    65,   180,   181,   182,   183,   184,   190,
       0,    16,    65,    65,   201,    65,     0,     0,     0,   188,
       0,     0,     0,    65,     0,    65,    65,    64,    66,     0,
       0,     0,     0,     0,   199,    65,     0,     0,    65,    65,
      65,    65,     0,     0,     0,     0,     0,     0,   192,   202,
       0,   204,    66,    66,   200,     0,     0,     0,     0,   203,
     205,    65,    65,     0,     0,   192,   206,   192,   207,     0,
       0,   208,   209
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -317,  -317,  -317,  -317,  -317,   -74,  -317,   -55,    79,   104,
      88,   102,   262,   286,   287,   197,   223,  -317,  -115,  -126,
    -249,   -34,  -317,   -78,  -120,     0,     7,    73,  -317,   392,
      56,  -317,   153,   333,  -317,  -317,  -317,   344,  -317,   -15,
     419,  -317,   411,   -42,  -317,  -317,   193,  -317,   105,  -125,
     199,  -198,  -317,  -317,   340,  -275,  -316,  -255,  -317,   -70,
     -62,  -163,  -317,   180,  -247,  -250,  -236,  -317,  -317,  -317,
    -213,  -317,   444,  -317,  -317,  -317,  -317
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    89,    90,   214,   215,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   235,
     176,   125,   155,   252,   194,   253,    59,    24,    39,    40,
      25,    26,   129,   202,    27,    34,    66,    67,    28,    72,
      42,    53,    43,    54,   190,   191,   192,   115,   130,   106,
     133,   134,   135,   136,   137,   254,   333,   255,   256,   300,
     107,   257,   258,   259,   260,   261,   262,   292,   293,   294,
     263,    29,    30,    31,    60,    61,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,   116,   193,   126,   121,   122,   124,    23,    41,   209,
     280,   205,   312,    65,   314,    33,   193,    35,   156,   131,
     113,    51,   175,   105,   131,   132,   118,    49,   112,    22,
     132,    44,    45,    46,  -124,    47,    23,   157,   328,   165,
     166,    58,   126,   156,   119,   126,   210,   207,    35,   236,
     325,    50,   -66,   131,    35,   344,   379,   156,   279,   132,
     281,   108,   327,   213,   334,   208,   329,   179,   326,   336,
     167,   168,   335,   163,   164,   178,   358,   396,   398,   185,
     195,    36,   200,   337,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     105,   356,   384,   219,   220,   221,   338,    68,   216,   364,
      52,   286,    36,   161,   162,   368,   369,   334,    36,   288,
      37,   218,   336,   189,   193,   335,    37,    70,   280,    65,
     156,    38,   303,   387,   388,    52,   337,   128,   334,   334,
      17,    18,    19,   336,   336,   265,   335,   335,   266,   277,
     186,    37,   199,   330,   127,   309,   117,   337,   337,   338,
     340,   156,   156,   169,   170,   156,   275,   319,   365,   346,
     187,   299,   200,   200,   270,   374,   128,   386,   114,   128,
     338,   338,    52,   128,   128,   131,    70,    55,   200,    56,
     341,   132,   332,   127,   171,   200,   127,   200,    57,   158,
     127,   127,   159,   160,    62,   172,    63,   347,   311,   138,
     139,   140,   315,   316,   173,   385,   350,   351,   174,   352,
      73,    74,    75,    76,    77,   197,   177,   360,   198,   362,
     363,   141,   399,   142,   400,   357,   180,   143,   323,   372,
     222,   223,   375,   376,   377,   378,   105,   331,   310,   301,
     339,   200,    70,   226,   227,   228,   229,   322,   181,   200,
     206,    78,    79,    80,   204,   393,   394,   224,   225,   345,
     212,   230,   231,   217,   359,   237,   156,   348,   264,   189,
     201,   201,   267,   367,    81,   268,    82,   269,   271,    83,
      84,    85,    86,    87,    88,   380,   272,   382,   383,   238,
      74,    75,    76,    77,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   273,   239,   240,   241,   274,   242,
     243,   244,   245,   246,   247,   248,   249,    21,   278,   282,
      78,    79,    80,   283,   287,   290,   289,   291,   355,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   295,
     296,   302,   297,    81,   304,   250,   305,  -191,    83,    84,
      85,    86,    87,    88,   276,   313,   317,   318,   320,   321,
     200,   154,   251,    73,    74,    75,    76,    77,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   238,    74,
      75,    76,    77,   342,   343,   349,   354,   353,   361,   366,
     370,    21,   371,   381,    78,    79,    80,   373,   389,   390,
     391,   392,   284,   232,   239,   240,   241,   401,   242,   243,
     244,   245,   246,   247,   248,   249,   402,    81,    71,    78,
      79,    80,    83,    84,    85,    86,    87,    88,   233,   285,
     234,   203,    64,   196,    69,   307,   251,   238,    74,    75,
      76,    77,    81,    48,   250,   308,   211,    83,    84,    85,
      86,    87,    88,   324,     0,   238,    74,    75,    76,    77,
       0,   251,     0,   239,   240,   241,     0,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,    78,    79,
      80,   239,   240,   241,     0,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,    78,    79,    80,     0,
       0,    81,     0,   395,     0,     0,    83,    84,    85,    86,
      87,    88,     0,   238,    74,    75,    76,    77,     0,    81,
     251,   397,     0,     0,    83,    84,    85,    86,    87,    88,
      73,    74,    75,    76,    77,     0,     0,     0,   251,   239,
     240,   241,     0,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,    78,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,     0,
       0,    78,    79,    80,     0,     0,     0,    81,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,    81,     0,   251,     0,     0,    83,
      84,    85,    86,    87,    88,    78,    79,    80,     0,     0,
       0,     4,     5,   298,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    81,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,     0,
       0,    21,     0,     0,     0,     0,     0,   251,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,     0,
       0,    21,     4,     5,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    73,    74,
      75,    76,    77,     0,   109,     0,     0,     0,     0,  -224,
       0,     0,    21,     0,     0,    78,    79,    80,     0,    17,
      18,    19,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    78,
      79,    80,     0,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    73,    74,    75,    76,    77,     0,   182,     0,
       0,   110,    81,     0,     0,     0,     0,    83,    84,    85,
     111,    87,    88,    17,    18,    19,    73,    74,    75,    76,
      77,     0,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,     0,    78,    79,    80,     0,    17,    18,    19,
      73,    74,    75,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,    81,    78,    79,    80,
       0,    83,    84,    85,   184,    87,    88,     0,    78,    79,
      80,     0,     0,     0,    73,    74,    75,    76,    77,     0,
      81,    78,    79,    80,     0,    83,    84,    85,    86,    87,
      88,    81,     0,   276,     0,     0,    83,    84,    85,    86,
      87,    88,     0,     0,   120,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    78,    79,    80,    73,    74,
      75,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,    80,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    81,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,     0,     0,    21,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   306,     0,     0,     0,
       0,     0,   188,     0,     0,     0,     0,     0,     0,    21,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21
};

static const yytype_int16 yycheck[] =
{
       0,    63,   117,    81,    78,    79,    80,     0,    23,   134,
     208,   131,   287,     3,   289,     3,   131,     3,    92,    65,
      62,    36,    54,    57,    65,    71,    70,     0,    62,    29,
      71,    24,    25,    26,    69,    28,    29,    92,   313,    49,
      50,    41,   120,   117,    88,   123,    87,    70,     3,   175,
      70,    69,    84,    65,     3,   330,   372,   131,    70,    71,
      66,    61,   311,   141,   319,    88,   315,   109,    88,   319,
      80,    81,   319,    47,    48,   109,   351,   393,   394,   113,
      70,    67,    88,   319,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     134,   348,   377,   158,   159,   160,   319,    68,   142,   358,
      37,   237,    67,    73,    74,   362,   363,   372,    67,   239,
      75,   155,   372,   116,   239,   372,    75,    54,   326,     3,
     204,    86,   258,   382,   383,    62,   372,    81,   393,   394,
      24,    25,    26,   393,   394,   179,   393,   394,   182,   204,
      68,    75,    68,    68,    81,   280,    87,   393,   394,   372,
     323,   235,   236,    51,    52,   239,   200,   293,    68,   332,
      88,   249,    88,    88,   189,    68,   120,    68,     3,   123,
     393,   394,   109,   127,   128,    65,   113,    86,    88,    88,
      70,    71,   318,   120,    72,    88,   123,    88,    87,    75,
     127,   128,    78,    79,    65,    82,    67,   333,   286,    43,
      44,    45,   290,   291,    83,   378,   342,   343,    53,   345,
       3,     4,     5,     6,     7,   120,    69,   353,   123,   355,
     356,    65,   395,    67,   397,   350,    66,    71,   300,   365,
     161,   162,   368,   369,   370,   371,   280,   317,   282,    86,
     320,    88,   179,   165,   166,   167,   168,    86,    66,    88,
       3,    44,    45,    46,    68,   391,   392,   163,   164,   331,
       3,   169,   170,     3,   352,    84,   350,   339,    66,   272,
     127,   128,    66,   361,    67,    66,    69,     3,    68,    72,
      73,    74,    75,    76,    77,   373,    88,   375,   376,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    68,    29,    30,    31,    68,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    66,    88,
      44,    45,    46,    68,    85,    67,    85,    67,   348,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     3,
      86,    70,    86,    67,    66,    69,    66,    70,    72,    73,
      74,    75,    76,    77,    69,    85,    67,    69,    67,    86,
      88,    87,    86,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     3,     4,
       5,     6,     7,    85,    68,    70,    34,    70,    67,    34,
      32,    41,    69,    86,    44,    45,    46,    67,    70,    86,
      68,    68,   235,   171,    29,    30,    31,    70,    33,    34,
      35,    36,    37,    38,    39,    40,    70,    67,    56,    44,
      45,    46,    72,    73,    74,    75,    76,    77,   172,   236,
     173,   128,    43,   119,    53,   272,    86,     3,     4,     5,
       6,     7,    67,    29,    69,   276,   136,    72,    73,    74,
      75,    76,    77,   303,    -1,     3,     4,     5,     6,     7,
      -1,    86,    -1,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    67,    -1,    69,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,     3,     4,     5,     6,     7,    -1,    67,
      86,    69,    -1,    -1,    72,    73,    74,    75,    76,    77,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    86,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    86,    -1,    -1,    72,
      73,    74,    75,    76,    77,    44,    45,    46,    -1,    -1,
      -1,    11,    12,    86,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    67,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    86,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    41,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    41,    -1,    -1,    44,    45,    46,    -1,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    44,
      45,    46,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,     9,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    24,    25,    26,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    44,    45,    46,    -1,    24,    25,    26,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    44,    45,    46,
      -1,    72,    73,    74,    75,    76,    77,    -1,    44,    45,
      46,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      67,    44,    45,    46,    -1,    72,    73,    74,    75,    76,
      77,    67,    -1,    69,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    67,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    44,    45,    46,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    67,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    41,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    41,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    41,   115,   116,   117,   120,   121,   124,   128,   161,
     162,   163,   166,     3,   125,     3,    67,    75,    86,   118,
     119,   129,   130,   132,   116,   116,   116,   116,   162,     0,
      69,   129,   117,   131,   133,    86,    88,    87,   115,   116,
     164,   165,    65,    67,   130,     3,   126,   127,    68,   132,
     117,   119,   129,     3,     4,     5,     6,     7,    44,    45,
      46,    67,    69,    72,    73,    74,    75,    76,    77,    91,
      92,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   111,   139,   150,   115,     9,
      66,    75,   111,   133,     3,   137,   150,    87,    70,    88,
      67,    95,    95,    67,    95,   111,   113,   117,   120,   122,
     138,    65,    71,   140,   141,   142,   143,   144,    43,    44,
      45,    65,    67,    71,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    87,   112,    95,    97,    75,    78,
      79,    73,    74,    47,    48,    49,    50,    80,    81,    51,
      52,    72,    82,    83,    53,    54,   110,    69,   111,   133,
      66,    66,     9,    66,    75,   111,    68,    88,    68,   116,
     134,   135,   136,   108,   114,    70,   127,   138,   138,    68,
      88,   122,   123,   123,    68,   114,     3,    70,    88,   139,
      87,   144,     3,   113,    93,    94,   111,     3,   111,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   100,   100,
     101,   101,   102,   103,   104,   109,   109,    84,     3,    29,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      69,    86,   113,   115,   145,   147,   148,   151,   152,   153,
     154,   155,   156,   160,    66,   111,   111,    66,    66,     3,
     129,    68,    88,    68,    68,   111,    69,    97,    66,    70,
     141,    66,    88,    68,   105,   106,   109,    85,   114,    85,
      67,    67,   157,   158,   159,     3,    86,    86,    86,   113,
     149,    86,    70,   109,    66,    66,    28,   136,   140,   139,
     111,   113,   145,    85,   145,   113,   113,    67,    69,   109,
      67,    86,    86,   150,   153,    70,    88,   110,   145,   110,
      68,   149,   109,   146,   147,   154,   155,   156,   160,   149,
     151,    70,    85,    68,   145,   150,   151,   109,   150,    70,
     109,   109,   109,    70,    34,   115,   154,   108,   145,   113,
     109,    67,   109,   109,   110,    68,    34,   113,   154,   154,
      32,    69,   109,    67,    68,   109,   109,   109,   109,   146,
     113,    86,   113,   113,   145,   151,    68,   110,   110,    70,
      86,    68,    68,   109,   109,    69,   146,    69,   146,   151,
     151,    70,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    97,    97,    98,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   101,   101,   101,   101,   101,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   114,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   122,   122,   123,
     123,   124,   124,   124,   125,   125,   126,   126,   127,   127,
     128,   129,   129,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   139,   139,   139,   140,   140,   141,   141,   142,
     143,   143,   144,   144,   145,   145,   145,   145,   145,   145,
     146,   146,   146,   146,   146,   147,   147,   147,   148,   149,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   155,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   158,   159,   160,   160,   160,   160,   160,   161,   161,
     162,   162,   163,   164,   164,   165,   165,   166
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       4,     3,     3,     2,     2,     6,     7,     1,     3,     1,
       0,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       4,     1,     4,     1,     9,     0,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     2,     2,     1,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       0,     5,     2,     6,     1,     0,     1,     3,     1,     3,
       1,     2,     1,     1,     3,     4,     5,     4,     3,     6,
       5,     6,     5,     4,     4,     5,     4,     1,     0,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     1,     1,
       3,     1,     1,     3,     4,     2,     4,     1,     0,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     5,     0,
       0,     1,     0,     1,     3,     1,     1,     2,     1,     8,
      11,     5,    10,    12,    10,    12,    14,    14,    16,    16,
       0,     0,     0,     3,     2,     2,     3,     2,     1,     2,
       1,     1,     7,     1,     0,     1,     2,     1
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
  case 2: /* primary_expression: IDENTIFIER  */
#line 88 "tinyC3.y"
                        {
            symbol* sym=pres_table->lookup(id);
            (yyval.expr)=new expression();
            (yyval.expr)->type="non_bool";
            (yyval.expr)->loc=sym;
        }
#line 1690 "tinyC3.tab.c"
    break;

  case 3: /* primary_expression: INTCONST  */
#line 94 "tinyC3.y"
                        {
            (yyval.expr)=new expression();
            data_type* a=new data_type("int");
            (yyval.expr)->loc=symbolTbl::gentemp(a,to_string((yyvsp[0].intconst)));
            emit("=",(yyval.expr)->loc->name,(yyvsp[0].intconst));
        }
#line 1701 "tinyC3.tab.c"
    break;

  case 4: /* primary_expression: FLOATCONST  */
#line 100 "tinyC3.y"
                        {
            (yyval.expr)=new expression();
            data_type* a=new data_type("float");
            (yyval.expr)->loc=symbolTbl::gentemp(a,to_string((yyvsp[0].floatconst)));
            emit("=",(yyval.expr)->loc->name,(yyvsp[0].floatconst));
        }
#line 1712 "tinyC3.tab.c"
    break;

  case 5: /* primary_expression: CHARCONST  */
#line 106 "tinyC3.y"
                        {
            (yyval.expr)=new expression();
            data_type* a=new data_type("char");
            (yyval.expr)->loc=symbolTbl::gentemp(a,string((yyvsp[0].strconst)));
            emit("=",(yyval.expr)->loc->name,string((yyvsp[0].strconst)));
        }
#line 1723 "tinyC3.tab.c"
    break;

  case 6: /* primary_expression: STR_LITERAL  */
#line 112 "tinyC3.y"
                        {
            (yyval.expr)=new expression();
            data_type* a=new data_type("ptr");
            (yyval.expr)->loc=symbolTbl::gentemp(a,string((yyvsp[0].strconst)));
            (yyval.expr)->loc->type->arrtype=new data_type("char");
        }
#line 1734 "tinyC3.tab.c"
    break;

  case 7: /* primary_expression: OP_ROUND expression CL_ROUND  */
#line 118 "tinyC3.y"
                                        {(yyval.expr)=(yyvsp[-1].expr);}
#line 1740 "tinyC3.tab.c"
    break;

  case 8: /* postfix_expression: primary_expression  */
#line 122 "tinyC3.y"
                                {
            //Creating a new array type variable and storing pointer of primary expression in the array type
            (yyval.Array)=new array_type();
            (yyval.Array)->loc=(yyvsp[0].expr)->loc;
            (yyval.Array)->type=(yyvsp[0].expr)->loc->type;//setting the type
            (yyval.Array)->Array=(yyvsp[0].expr)->loc;
        }
#line 1752 "tinyC3.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression OP_SQUARE expression CL_SQUARE  */
#line 129 "tinyC3.y"
                                                                {//Handling array indexing
            (yyval.Array)=new array_type();
            (yyval.Array)->loc=symbolTbl::gentemp("int");
            (yyval.Array)->struc_type="arr";
            (yyval.Array)->Array=(yyvsp[-3].Array)->Array;
            (yyval.Array)->type=(yyvsp[-3].Array)->type->arrtype;
            if((yyvsp[-3].Array)->struc_type=="arr"){
                symbol* temp=symbolTbl::gentemp("int");
                int size=size_of_type((yyval.Array)->type);
                emit("*",temp->name,(yyvsp[-1].expr)->loc->name,to_string(size));
                emit("+",(yyval.Array)->loc->name,(yyvsp[-3].Array)->loc->name,temp->name);
            }
            else{
                int size=size_of_type((yyval.Array)->type);
                emit("*",(yyval.Array)->loc->name,(yyvsp[-1].expr)->loc->name,to_string(size));
            }
        }
#line 1774 "tinyC3.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression OP_ROUND argument_expression_list_opt CL_ROUND  */
#line 146 "tinyC3.y"
                                                                                {//Handling function call
            (yyval.Array)=new array_type();
            (yyval.Array)->Array=symbolTbl::gentemp((yyvsp[-3].Array)->type);
            emit("call", (yyval.Array)->Array->name, (yyvsp[-3].Array)->Array->name, to_string((yyvsp[-1].numParams)));
        }
#line 1784 "tinyC3.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression DOT IDENTIFIER  */
#line 151 "tinyC3.y"
                                                    {}
#line 1790 "tinyC3.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression IMPLIES IDENTIFIER  */
#line 152 "tinyC3.y"
                                                    {}
#line 1796 "tinyC3.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression INCRE  */
#line 153 "tinyC3.y"
                                        {
            (yyval.Array)=new array_type();
            (yyval.Array)->Array=symbolTbl::gentemp((yyvsp[-1].Array)->Array->type);
            emit("=", (yyval.Array)->Array->name, (yyvsp[-1].Array)->Array->name);//Value of temporary=unchanged value of variable
            emit("+", (yyvsp[-1].Array)->Array->name, (yyvsp[-1].Array)->Array->name, "1"); //Value of variable increased by 1
        }
#line 1807 "tinyC3.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression DECRE  */
#line 159 "tinyC3.y"
                                        {
            (yyval.Array)=new array_type();
            (yyval.Array)->Array=symbolTbl::gentemp((yyvsp[-1].Array)->Array->type);
            emit("=", (yyval.Array)->Array->name, (yyvsp[-1].Array)->Array->name); //Value of temporary=unchanged value of variable
            emit("-", (yyvsp[-1].Array)->Array->name, (yyvsp[-1].Array)->Array->name, "1");//Value of variable decreased by 1
        }
#line 1818 "tinyC3.tab.c"
    break;

  case 15: /* postfix_expression: OP_ROUND type_name CL_ROUND OP_CURLY initializer_list CL_CURLY  */
#line 165 "tinyC3.y"
                                                                                    {}
#line 1824 "tinyC3.tab.c"
    break;

  case 16: /* postfix_expression: OP_ROUND type_name CL_ROUND OP_CURLY initializer_list COMMA CL_CURLY  */
#line 166 "tinyC3.y"
                                                                                    {}
#line 1830 "tinyC3.tab.c"
    break;

  case 17: /* argument_expression_list: assignment_expression  */
#line 170 "tinyC3.y"
                                      {
            (yyval.numParams)=1;
            emit("param",(yyvsp[0].expr)->loc->name);
        }
#line 1839 "tinyC3.tab.c"
    break;

  case 18: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 174 "tinyC3.y"
                                                                    {
            (yyval.numParams)=(yyvsp[-2].numParams)+1;//Changing parameter count
            emit("param",(yyvsp[0].expr)->loc->name);
        }
#line 1848 "tinyC3.tab.c"
    break;

  case 19: /* argument_expression_list_opt: argument_expression_list  */
#line 181 "tinyC3.y"
                                        {(yyval.numParams)=(yyvsp[0].numParams);}
#line 1854 "tinyC3.tab.c"
    break;

  case 20: /* argument_expression_list_opt: %empty  */
#line 182 "tinyC3.y"
                                        {(yyval.numParams)=0;}
#line 1860 "tinyC3.tab.c"
    break;

  case 21: /* unary_expression: postfix_expression  */
#line 186 "tinyC3.y"
                                        {(yyval.Array)=(yyvsp[0].Array);}
#line 1866 "tinyC3.tab.c"
    break;

  case 22: /* unary_expression: INCRE unary_expression  */
#line 187 "tinyC3.y"
                                        {
            emit("+", (yyvsp[0].Array)->Array->name, (yyvsp[0].Array)->Array->name, "1"); //Increase value of variable
            (yyval.Array)=(yyvsp[0].Array);//Value of expression=increased value of variable
        }
#line 1875 "tinyC3.tab.c"
    break;

  case 23: /* unary_expression: DECRE unary_expression  */
#line 191 "tinyC3.y"
                                        {
            emit("-", (yyvsp[0].Array)->Array->name, (yyvsp[0].Array)->Array->name, "1");//Decrease value of variable
            (yyval.Array)=(yyvsp[0].Array);//Value of expression=decreased value of variable
        }
#line 1884 "tinyC3.tab.c"
    break;

  case 24: /* unary_expression: unary_operator cast_expression  */
#line 195 "tinyC3.y"
                                                {
            (yyval.Array)=new array_type();
            switch((yyvsp[-1].unaryOp)){
                case '&'://Handling adressing
                    (yyval.Array)->Array=symbolTbl::gentemp(new data_type("ptr"));
                    (yyval.Array)->Array->type->arrtype=(yyvsp[0].Array)->Array->type;
                    emit("= &",(yyval.Array)->Array->name,(yyvsp[0].Array)->Array->name);
                    break;
                case '*'://Handling derefernce
                    (yyval.Array)->Array=(yyvsp[0].Array)->Array;
                    (yyval.Array)->loc=symbolTbl::gentemp((yyvsp[0].Array)->Array->type->arrtype);
                    (yyval.Array)->struc_type="ptr";
                    emit("= *",(yyval.Array)->loc->name,(yyvsp[0].Array)->Array->name);  
                    break;
                case '+'://unary plus(no handling required)
                    (yyval.Array)=(yyvsp[0].Array);
                    break;
                case '-'://Handling unary minus
                    (yyval.Array)->Array=symbolTbl::gentemp((yyvsp[0].Array)->Array->type->type);
                    emit("= -",(yyval.Array)->Array->name,(yyvsp[0].Array)->Array->name);   
                    break;
                case '~'://Handling bitwise complementation
                    (yyval.Array)->Array=symbolTbl::gentemp((yyvsp[0].Array)->Array->type->type);
                    emit("= ~",(yyval.Array)->Array->name,(yyvsp[0].Array)->Array->name);
                    break;
                case '!'://Handling logical complementation
                    (yyval.Array)->Array=symbolTbl::gentemp((yyvsp[0].Array)->Array->type->type);
                    emit("= !",(yyval.Array)->Array->name,(yyvsp[0].Array)->Array->name);
                    break;
            }
        }
#line 1920 "tinyC3.tab.c"
    break;

  case 25: /* unary_expression: SIZEOF unary_expression  */
#line 226 "tinyC3.y"
                                                    {}
#line 1926 "tinyC3.tab.c"
    break;

  case 26: /* unary_expression: SIZEOF OP_ROUND type_name CL_ROUND  */
#line 227 "tinyC3.y"
                                                    {}
#line 1932 "tinyC3.tab.c"
    break;

  case 27: /* unary_operator: BIT_AND  */
#line 231 "tinyC3.y"
                    {(yyval.unaryOp)='&';}
#line 1938 "tinyC3.tab.c"
    break;

  case 28: /* unary_operator: MUL  */
#line 232 "tinyC3.y"
                    {(yyval.unaryOp)='*';}
#line 1944 "tinyC3.tab.c"
    break;

  case 29: /* unary_operator: PLUS  */
#line 233 "tinyC3.y"
                    {(yyval.unaryOp)='+';}
#line 1950 "tinyC3.tab.c"
    break;

  case 30: /* unary_operator: MIN  */
#line 234 "tinyC3.y"
                    {(yyval.unaryOp)='-';}
#line 1956 "tinyC3.tab.c"
    break;

  case 31: /* unary_operator: BIT_NOT  */
#line 235 "tinyC3.y"
                    {(yyval.unaryOp)='~';}
#line 1962 "tinyC3.tab.c"
    break;

  case 32: /* unary_operator: NOT  */
#line 236 "tinyC3.y"
                    {(yyval.unaryOp)='!';}
#line 1968 "tinyC3.tab.c"
    break;

  case 33: /* cast_expression: unary_expression  */
#line 240 "tinyC3.y"
                                                        {(yyval.Array)=(yyvsp[0].Array);}
#line 1974 "tinyC3.tab.c"
    break;

  case 34: /* cast_expression: OP_ROUND type_name CL_ROUND cast_expression  */
#line 241 "tinyC3.y"
                                                        {//Handling type cast
            (yyval.Array)=new array_type();
            (yyval.Array)->Array=convertType((yyvsp[0].Array)->Array,var_type);
        }
#line 1983 "tinyC3.tab.c"
    break;

  case 35: /* multiplicative_expression: cast_expression  */
#line 248 "tinyC3.y"
                                {
            (yyval.expr)=new expression();
            if((yyvsp[0].Array)->struc_type=="arr"){
                (yyval.expr)->loc=symbolTbl::gentemp((yyvsp[0].Array)->loc->type);
                emit("=[]",(yyval.expr)->loc->name,(yyvsp[0].Array)->Array->name,(yyvsp[0].Array)->loc->name);
            }
            else if((yyvsp[0].Array)->struc_type=="ptr"){
                (yyval.expr)->loc=(yyvsp[0].Array)->loc;
            }
            else{
                (yyval.expr)->loc=(yyvsp[0].Array)->Array;
            }
        }
#line 2001 "tinyC3.tab.c"
    break;

  case 36: /* multiplicative_expression: multiplicative_expression MUL cast_expression  */
#line 261 "tinyC3.y"
                                                            {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].Array)->Array)){
                (yyval.expr)=new expression();
                data_type* a=new data_type((yyvsp[-2].expr)->loc->type->type);
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("*", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].Array)->Array->name);    
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
#line 2017 "tinyC3.tab.c"
    break;

  case 37: /* multiplicative_expression: multiplicative_expression DIV cast_expression  */
#line 272 "tinyC3.y"
                                                            {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].Array)->Array)){
                (yyval.expr)=new expression();
                data_type* a=new data_type((yyvsp[-2].expr)->loc->type->type);
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("/", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].Array)->Array->name);
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
#line 2033 "tinyC3.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression MOD cast_expression  */
#line 283 "tinyC3.y"
                                                            {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].Array)->Array)){
                (yyval.expr)=new expression();
                data_type* a=new data_type((yyvsp[-2].expr)->loc->type->type);
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("%", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].Array)->Array->name);   
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
#line 2049 "tinyC3.tab.c"
    break;

  case 39: /* additive_expression: multiplicative_expression  */
#line 297 "tinyC3.y"
                                                                {(yyval.expr)=(yyvsp[0].expr);}
#line 2055 "tinyC3.tab.c"
    break;

  case 40: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 298 "tinyC3.y"
                                                                {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                (yyval.expr)=new expression();
                data_type* a=new data_type((yyvsp[-2].expr)->loc->type->type);
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("+", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);    
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
#line 2071 "tinyC3.tab.c"
    break;

  case 41: /* additive_expression: additive_expression MIN multiplicative_expression  */
#line 309 "tinyC3.y"
                                                                {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                (yyval.expr)=new expression();
                data_type* a=new data_type((yyvsp[-2].expr)->loc->type->type);
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("-", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);           
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
#line 2087 "tinyC3.tab.c"
    break;

  case 42: /* shift_expression: additive_expression  */
#line 323 "tinyC3.y"
                                                            {(yyval.expr)=(yyvsp[0].expr);}
#line 2093 "tinyC3.tab.c"
    break;

  case 43: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 324 "tinyC3.y"
                                                            {
            if((yyvsp[0].expr)->loc->type->type=="int"){
                (yyval.expr)=new expression();
                data_type* a=new data_type("int");
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("<<", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Shift expression is being applied with non integer shift values"));
            }
        }
#line 2109 "tinyC3.tab.c"
    break;

  case 44: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 335 "tinyC3.y"
                                                            {
            if((yyvsp[0].expr)->loc->type->type=="int"){
                (yyval.expr)=new expression();
                data_type* a=new data_type("int");
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit(">>", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Shift expression is being applied with non integer shift values"));
            }
        }
#line 2125 "tinyC3.tab.c"
    break;

  case 45: /* relational_expression: shift_expression  */
#line 349 "tinyC3.y"
                                                        {(yyval.expr)=(yyvsp[0].expr);}
#line 2131 "tinyC3.tab.c"
    break;

  case 46: /* relational_expression: relational_expression LT shift_expression  */
#line 350 "tinyC3.y"
                                                        {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                (yyval.expr)=new expression();
                (yyval.expr)->type="bool";
                (yyval.expr)->truelist=makelist(nextinstr());//Handling true list and false list
                (yyval.expr)->falselist=makelist(nextinstr()+1);
                emit("<","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
#line 2149 "tinyC3.tab.c"
    break;

  case 47: /* relational_expression: relational_expression GT shift_expression  */
#line 363 "tinyC3.y"
                                                        {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                (yyval.expr)=new expression();
                (yyval.expr)->type="bool";
                (yyval.expr)->truelist=makelist(nextinstr());//Handling true list and false list
                (yyval.expr)->falselist=makelist(nextinstr()+1);
                emit(">","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
#line 2167 "tinyC3.tab.c"
    break;

  case 48: /* relational_expression: relational_expression LEQ shift_expression  */
#line 376 "tinyC3.y"
                                                        {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                (yyval.expr)=new expression();
                (yyval.expr)->type="bool";
                (yyval.expr)->truelist=makelist(nextinstr());
                (yyval.expr)->falselist=makelist(nextinstr()+1);
                emit("<=","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
#line 2185 "tinyC3.tab.c"
    break;

  case 49: /* relational_expression: relational_expression GEQ shift_expression  */
#line 389 "tinyC3.y"
                                                        {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                (yyval.expr)=new expression();
                (yyval.expr)->type="bool";
                (yyval.expr)->truelist=makelist(nextinstr());
                (yyval.expr)->falselist=makelist(nextinstr()+1);
                emit(">=","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
#line 2203 "tinyC3.tab.c"
    break;

  case 50: /* equality_expression: relational_expression  */
#line 405 "tinyC3.y"
                                                            {(yyval.expr)=(yyvsp[0].expr);}
#line 2209 "tinyC3.tab.c"
    break;

  case 51: /* equality_expression: equality_expression EQEQ relational_expression  */
#line 406 "tinyC3.y"
                                                            {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                conv_bool_2_int((yyvsp[-2].expr));
                conv_bool_2_int((yyvsp[0].expr));
                (yyval.expr)=new expression();
                (yyval.expr)->type="bool";
                (yyval.expr)->truelist=makelist(nextinstr());//Handling true list and false list
                (yyval.expr)->falselist=makelist(nextinstr()+1);
                emit("==","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
#line 2229 "tinyC3.tab.c"
    break;

  case 52: /* equality_expression: equality_expression NEQ relational_expression  */
#line 421 "tinyC3.y"
                                                            {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                conv_bool_2_int((yyvsp[-2].expr));
                conv_bool_2_int((yyvsp[0].expr));
                (yyval.expr)=new expression();
                (yyval.expr)->type="bool";
                (yyval.expr)->truelist=makelist(nextinstr());//Handling true list and false list
                (yyval.expr)->falselist=makelist(nextinstr()+1);
                emit("!=","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
                emit("goto","_");
            }
            else{
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
#line 2249 "tinyC3.tab.c"
    break;

  case 53: /* AND_expression: equality_expression  */
#line 439 "tinyC3.y"
                                                        {(yyval.expr)=(yyvsp[0].expr);}
#line 2255 "tinyC3.tab.c"
    break;

  case 54: /* AND_expression: AND_expression BIT_AND equality_expression  */
#line 440 "tinyC3.y"
                                                        {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                conv_bool_2_int((yyvsp[-2].expr));
                conv_bool_2_int((yyvsp[0].expr));
                (yyval.expr)=new expression();
                (yyval.expr)->type="non_bool";
                data_type* a=new data_type("int");
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("&",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
#line 2274 "tinyC3.tab.c"
    break;

  case 55: /* exclusive_OR_expression: AND_expression  */
#line 457 "tinyC3.y"
                                                            {(yyval.expr)=(yyvsp[0].expr);}
#line 2280 "tinyC3.tab.c"
    break;

  case 56: /* exclusive_OR_expression: exclusive_OR_expression BIT_XOR AND_expression  */
#line 458 "tinyC3.y"
                                                            {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                conv_bool_2_int((yyvsp[-2].expr));
                conv_bool_2_int((yyvsp[0].expr));
                (yyval.expr)=new expression();
                (yyval.expr)->type="non_bool";
                data_type* a=new data_type("int");
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("^", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
#line 2299 "tinyC3.tab.c"
    break;

  case 57: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 475 "tinyC3.y"
                                                                    {(yyval.expr)=(yyvsp[0].expr);}
#line 2305 "tinyC3.tab.c"
    break;

  case 58: /* inclusive_OR_expression: inclusive_OR_expression BIT_OR exclusive_OR_expression  */
#line 476 "tinyC3.y"
                                                                    {
            if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc)){
                conv_bool_2_int((yyvsp[-2].expr));
                conv_bool_2_int((yyvsp[0].expr));
                (yyval.expr)=new expression();
                (yyval.expr)->type="non_bool";
                data_type* a=new data_type("int");
                (yyval.expr)->loc=symbolTbl::gentemp(a);
                emit("|", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
#line 2324 "tinyC3.tab.c"
    break;

  case 59: /* logical_AND_expression: inclusive_OR_expression  */
#line 493 "tinyC3.y"
                                                                            {(yyval.expr)=(yyvsp[0].expr);}
#line 2330 "tinyC3.tab.c"
    break;

  case 60: /* logical_AND_expression: logical_AND_expression AND next_instr inclusive_OR_expression  */
#line 494 "tinyC3.y"
                                                                            {//next_instr is added to augment grammer
            conv_int_2_bool((yyvsp[-3].expr));
            conv_int_2_bool((yyvsp[0].expr));
            (yyval.expr)=new expression();
            (yyval.expr)->type="bool";
            backpatch((yyvsp[-3].expr)->truelist,(yyvsp[-1].instr));//Backpatching truelist to the operand
            (yyval.expr)->truelist=(yyvsp[0].expr)->truelist;
            (yyval.expr)->falselist=merge((yyvsp[-3].expr)->falselist,(yyvsp[0].expr)->falselist);
        }
#line 2344 "tinyC3.tab.c"
    break;

  case 61: /* logical_OR_expression: logical_AND_expression  */
#line 506 "tinyC3.y"
                                                                        {(yyval.expr)=(yyvsp[0].expr);}
#line 2350 "tinyC3.tab.c"
    break;

  case 62: /* logical_OR_expression: logical_OR_expression OR next_instr logical_AND_expression  */
#line 507 "tinyC3.y"
                                                                        {//next_instr is added to augment grammer
            conv_int_2_bool((yyvsp[-3].expr));
            conv_int_2_bool((yyvsp[0].expr));
            (yyval.expr)=new expression();
            (yyval.expr)->type="bool";
            backpatch((yyvsp[-3].expr)->falselist,(yyvsp[-1].instr));//Backpatching falselist to the operand
            (yyval.expr)->falselist=(yyvsp[0].expr)->falselist;
            (yyval.expr)->truelist=merge((yyvsp[-3].expr)->truelist,(yyvsp[0].expr)->truelist);
        }
#line 2364 "tinyC3.tab.c"
    break;

  case 63: /* conditional_expression: logical_OR_expression  */
#line 519 "tinyC3.y"
                                    {(yyval.expr)=(yyvsp[0].expr);}
#line 2370 "tinyC3.tab.c"
    break;

  case 64: /* conditional_expression: logical_OR_expression next_list Q_MARK next_instr expression next_list COLON next_instr conditional_expression  */
#line 520 "tinyC3.y"
                                                                                                                              {//next_list is added to jump to else part
            (yyval.expr)=new expression();
            (yyval.expr)->loc=symbolTbl::gentemp((yyvsp[-4].expr)->loc->type);
            (yyval.expr)->loc->update((yyvsp[-4].expr)->loc->type);
            emit("=",(yyval.expr)->loc->name,(yyvsp[0].expr)->loc->name);
            list<int> l1=makelist(nextinstr());
            emit("goto", "");
            backpatch((yyvsp[-3].stmt)->nextlist,nextinstr());
            emit("=",(yyval.expr)->loc->name,(yyvsp[-4].expr)->loc->name);
            list<int> l2=makelist(nextinstr());
            l1=merge(l1,l2);
            emit("goto","");
            backpatch((yyvsp[-7].stmt)->nextlist,nextinstr());              
            conv_int_2_bool((yyvsp[-8].expr));                              
            backpatch((yyvsp[-8].expr)->truelist,(yyvsp[-5].instr));//Backpatchings                
            backpatch((yyvsp[-8].expr)->falselist,(yyvsp[-1].instr));                    
            backpatch(l1,nextinstr());
        }
#line 2393 "tinyC3.tab.c"
    break;

  case 65: /* next_instr: %empty  */
#line 541 "tinyC3.y"
                    {(yyval.instr)=nextinstr();}
#line 2399 "tinyC3.tab.c"
    break;

  case 66: /* next_list: %empty  */
#line 545 "tinyC3.y"
                    {//To prevent fallthrough
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=makelist(nextinstr());
            emit("goto","");
        }
#line 2409 "tinyC3.tab.c"
    break;

  case 67: /* assignment_expression: conditional_expression  */
#line 553 "tinyC3.y"
                                                                        {(yyval.expr)=(yyvsp[0].expr);}
#line 2415 "tinyC3.tab.c"
    break;

  case 68: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 554 "tinyC3.y"
                                                                        {
            if((yyvsp[-2].Array)->struc_type=="arr"){
                (yyvsp[0].expr)->loc=convertType((yyvsp[0].expr)->loc,(yyvsp[-2].Array)->type->type);
                emit("[]=",(yyvsp[-2].Array)->Array->name,(yyvsp[-2].Array)->loc->name,(yyvsp[0].expr)->loc->name);
            }
            else if((yyvsp[-2].Array)->struc_type=="ptr"){
                emit("*=",(yyvsp[-2].Array)->Array->name,(yyvsp[0].expr)->loc->name);
            }
            else{
                (yyvsp[0].expr)->loc=convertType((yyvsp[0].expr)->loc,(yyvsp[-2].Array)->Array->type->type);
                emit("=",(yyvsp[-2].Array)->Array->name,(yyvsp[0].expr)->loc->name);
            }
            (yyval.expr)=(yyvsp[0].expr);
        }
#line 2434 "tinyC3.tab.c"
    break;

  case 69: /* assignment_operator: EQ  */
#line 571 "tinyC3.y"
                    {}
#line 2440 "tinyC3.tab.c"
    break;

  case 70: /* assignment_operator: MULEQ  */
#line 572 "tinyC3.y"
                    {}
#line 2446 "tinyC3.tab.c"
    break;

  case 71: /* assignment_operator: DIVEQ  */
#line 573 "tinyC3.y"
                    {}
#line 2452 "tinyC3.tab.c"
    break;

  case 72: /* assignment_operator: MODEQ  */
#line 574 "tinyC3.y"
                    {}
#line 2458 "tinyC3.tab.c"
    break;

  case 73: /* assignment_operator: ADDEQ  */
#line 575 "tinyC3.y"
                    {}
#line 2464 "tinyC3.tab.c"
    break;

  case 74: /* assignment_operator: SUBEQ  */
#line 576 "tinyC3.y"
                    {}
#line 2470 "tinyC3.tab.c"
    break;

  case 75: /* assignment_operator: LSHEQ  */
#line 577 "tinyC3.y"
                    {}
#line 2476 "tinyC3.tab.c"
    break;

  case 76: /* assignment_operator: RSHEQ  */
#line 578 "tinyC3.y"
                    {}
#line 2482 "tinyC3.tab.c"
    break;

  case 77: /* assignment_operator: ANDEQ  */
#line 579 "tinyC3.y"
                    {}
#line 2488 "tinyC3.tab.c"
    break;

  case 78: /* assignment_operator: XOREQ  */
#line 580 "tinyC3.y"
                    {}
#line 2494 "tinyC3.tab.c"
    break;

  case 79: /* assignment_operator: OREQ  */
#line 581 "tinyC3.y"
                    {}
#line 2500 "tinyC3.tab.c"
    break;

  case 80: /* expression: assignment_expression  */
#line 585 "tinyC3.y"
                                                    {(yyval.expr)=(yyvsp[0].expr);}
#line 2506 "tinyC3.tab.c"
    break;

  case 81: /* expression: expression COMMA assignment_expression  */
#line 586 "tinyC3.y"
                                                    {}
#line 2512 "tinyC3.tab.c"
    break;

  case 82: /* constant_expression: conditional_expression  */
#line 590 "tinyC3.y"
                                {}
#line 2518 "tinyC3.tab.c"
    break;

  case 83: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 594 "tinyC3.y"
                                                                    {}
#line 2524 "tinyC3.tab.c"
    break;

  case 84: /* declaration: declaration_specifiers SEMICOLON  */
#line 595 "tinyC3.y"
                                                                    {}
#line 2530 "tinyC3.tab.c"
    break;

  case 85: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 599 "tinyC3.y"
                                                            {}
#line 2536 "tinyC3.tab.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier  */
#line 600 "tinyC3.y"
                                                            {}
#line 2542 "tinyC3.tab.c"
    break;

  case 87: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 601 "tinyC3.y"
                                                            {}
#line 2548 "tinyC3.tab.c"
    break;

  case 88: /* declaration_specifiers: type_specifier  */
#line 602 "tinyC3.y"
                                                            {}
#line 2554 "tinyC3.tab.c"
    break;

  case 89: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 603 "tinyC3.y"
                                                            {}
#line 2560 "tinyC3.tab.c"
    break;

  case 90: /* declaration_specifiers: type_qualifier  */
#line 604 "tinyC3.y"
                                                            {}
#line 2566 "tinyC3.tab.c"
    break;

  case 91: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 605 "tinyC3.y"
                                                            {}
#line 2572 "tinyC3.tab.c"
    break;

  case 92: /* declaration_specifiers: function_specifier  */
#line 606 "tinyC3.y"
                                                            {}
#line 2578 "tinyC3.tab.c"
    break;

  case 93: /* type_qualifier: CONST  */
#line 610 "tinyC3.y"
                    {}
#line 2584 "tinyC3.tab.c"
    break;

  case 94: /* type_qualifier: RESTRICT  */
#line 611 "tinyC3.y"
                    {}
#line 2590 "tinyC3.tab.c"
    break;

  case 95: /* type_qualifier: VOLATILE  */
#line 612 "tinyC3.y"
                    {}
#line 2596 "tinyC3.tab.c"
    break;

  case 96: /* init_declarator_list: init_declarator  */
#line 616 "tinyC3.y"
                                                        {}
#line 2602 "tinyC3.tab.c"
    break;

  case 97: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 617 "tinyC3.y"
                                                        {}
#line 2608 "tinyC3.tab.c"
    break;

  case 98: /* init_declarator: declarator  */
#line 621 "tinyC3.y"
                                        {(yyval.pointer)=(yyvsp[0].pointer);}
#line 2614 "tinyC3.tab.c"
    break;

  case 99: /* init_declarator: declarator EQ initializer  */
#line 622 "tinyC3.y"
                                        {if((yyvsp[0].pointer)->value !=""){(yyvsp[-2].pointer)->value=(yyvsp[0].pointer)->value;}emit("=", (yyvsp[-2].pointer)->name, (yyvsp[0].pointer)->name);}
#line 2620 "tinyC3.tab.c"
    break;

  case 100: /* type_specifier: VOID  */
#line 626 "tinyC3.y"
                            {var_type="void";}
#line 2626 "tinyC3.tab.c"
    break;

  case 101: /* type_specifier: CHAR  */
#line 627 "tinyC3.y"
                            {var_type="char";}
#line 2632 "tinyC3.tab.c"
    break;

  case 102: /* type_specifier: SHORT  */
#line 628 "tinyC3.y"
                            {var_type="short";}
#line 2638 "tinyC3.tab.c"
    break;

  case 103: /* type_specifier: INT  */
#line 629 "tinyC3.y"
                            {var_type="int";}
#line 2644 "tinyC3.tab.c"
    break;

  case 104: /* type_specifier: LONG  */
#line 630 "tinyC3.y"
                            {var_type="long";}
#line 2650 "tinyC3.tab.c"
    break;

  case 105: /* type_specifier: FLOAT  */
#line 631 "tinyC3.y"
                            {var_type="float";}
#line 2656 "tinyC3.tab.c"
    break;

  case 106: /* type_specifier: DOUBLE  */
#line 632 "tinyC3.y"
                            {var_type="double";}
#line 2662 "tinyC3.tab.c"
    break;

  case 107: /* type_specifier: SIGNED  */
#line 633 "tinyC3.y"
                            {var_type="signed";}
#line 2668 "tinyC3.tab.c"
    break;

  case 108: /* type_specifier: UNSIGNED  */
#line 634 "tinyC3.y"
                            {var_type="unsigned";}
#line 2674 "tinyC3.tab.c"
    break;

  case 109: /* type_specifier: BOOL  */
#line 635 "tinyC3.y"
                            {var_type="bool";}
#line 2680 "tinyC3.tab.c"
    break;

  case 110: /* type_specifier: COMPLEX  */
#line 636 "tinyC3.y"
                            {var_type="complex";}
#line 2686 "tinyC3.tab.c"
    break;

  case 111: /* type_specifier: IMAGINARY  */
#line 637 "tinyC3.y"
                            {var_type="imaginary";}
#line 2692 "tinyC3.tab.c"
    break;

  case 112: /* type_specifier: enum_specifier  */
#line 638 "tinyC3.y"
                            {}
#line 2698 "tinyC3.tab.c"
    break;

  case 113: /* storage_class_specifier: AUTO  */
#line 642 "tinyC3.y"
                    {}
#line 2704 "tinyC3.tab.c"
    break;

  case 114: /* storage_class_specifier: REGISTER  */
#line 643 "tinyC3.y"
                    {}
#line 2710 "tinyC3.tab.c"
    break;

  case 115: /* storage_class_specifier: STATIC  */
#line 644 "tinyC3.y"
                    {}
#line 2716 "tinyC3.tab.c"
    break;

  case 116: /* storage_class_specifier: EXTERN  */
#line 645 "tinyC3.y"
                    {}
#line 2722 "tinyC3.tab.c"
    break;

  case 117: /* specifier_qualifier_list: type_specifier specifier_qualifier_list_opt  */
#line 649 "tinyC3.y"
                                                            {}
#line 2728 "tinyC3.tab.c"
    break;

  case 118: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list_opt  */
#line 650 "tinyC3.y"
                                                            {}
#line 2734 "tinyC3.tab.c"
    break;

  case 119: /* specifier_qualifier_list_opt: specifier_qualifier_list  */
#line 654 "tinyC3.y"
                                        {}
#line 2740 "tinyC3.tab.c"
    break;

  case 120: /* specifier_qualifier_list_opt: %empty  */
#line 655 "tinyC3.y"
                                        {}
#line 2746 "tinyC3.tab.c"
    break;

  case 121: /* enum_specifier: ENUM identifier_opt OP_CURLY enumerator_list CL_CURLY  */
#line 659 "tinyC3.y"
                                                                        {}
#line 2752 "tinyC3.tab.c"
    break;

  case 122: /* enum_specifier: ENUM IDENTIFIER  */
#line 660 "tinyC3.y"
                                                                        {}
#line 2758 "tinyC3.tab.c"
    break;

  case 123: /* enum_specifier: ENUM identifier_opt OP_CURLY enumerator_list COMMA CL_CURLY  */
#line 661 "tinyC3.y"
                                                                        {}
#line 2764 "tinyC3.tab.c"
    break;

  case 124: /* identifier_opt: IDENTIFIER  */
#line 665 "tinyC3.y"
                            {}
#line 2770 "tinyC3.tab.c"
    break;

  case 125: /* identifier_opt: %empty  */
#line 666 "tinyC3.y"
                            {}
#line 2776 "tinyC3.tab.c"
    break;

  case 126: /* enumerator_list: enumerator  */
#line 670 "tinyC3.y"
                                                {}
#line 2782 "tinyC3.tab.c"
    break;

  case 127: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 671 "tinyC3.y"
                                                {}
#line 2788 "tinyC3.tab.c"
    break;

  case 128: /* enumerator: IDENTIFIER  */
#line 675 "tinyC3.y"
                                                {}
#line 2794 "tinyC3.tab.c"
    break;

  case 129: /* enumerator: IDENTIFIER EQ constant_expression  */
#line 676 "tinyC3.y"
                                                {}
#line 2800 "tinyC3.tab.c"
    break;

  case 130: /* function_specifier: INLINE  */
#line 680 "tinyC3.y"
                    {}
#line 2806 "tinyC3.tab.c"
    break;

  case 131: /* declarator: pointer direct_declarator  */
#line 684 "tinyC3.y"
                                        {
            data_type* temp=(yyvsp[-1].ptr);
            while(temp->arrtype!=NULL){
                temp=temp->arrtype;
            }
            temp->arrtype=(yyvsp[0].pointer)->type;
            (yyval.pointer)=(yyvsp[0].pointer)->update((yyvsp[-1].ptr));
        }
#line 2819 "tinyC3.tab.c"
    break;

  case 132: /* declarator: direct_declarator  */
#line 692 "tinyC3.y"
                                        {}
#line 2825 "tinyC3.tab.c"
    break;

  case 133: /* direct_declarator: IDENTIFIER  */
#line 696 "tinyC3.y"
                        {
            (yyval.pointer)=pres_table->addsym(id);
            data_type* a=new data_type(var_type);
            (yyval.pointer)->update(a);
            prev_symbol=(yyval.pointer);
        }
#line 2836 "tinyC3.tab.c"
    break;

  case 134: /* direct_declarator: OP_ROUND declarator CL_ROUND  */
#line 702 "tinyC3.y"
                                            {(yyval.pointer)=(yyvsp[-1].pointer);}
#line 2842 "tinyC3.tab.c"
    break;

  case 135: /* direct_declarator: direct_declarator OP_SQUARE type_qualifier_list CL_SQUARE  */
#line 703 "tinyC3.y"
                                                                                                {}
#line 2848 "tinyC3.tab.c"
    break;

  case 136: /* direct_declarator: direct_declarator OP_SQUARE type_qualifier_list assignment_expression CL_SQUARE  */
#line 704 "tinyC3.y"
                                                                                                {}
#line 2854 "tinyC3.tab.c"
    break;

  case 137: /* direct_declarator: direct_declarator OP_SQUARE assignment_expression CL_SQUARE  */
#line 705 "tinyC3.y"
                                                                            {//array declaration
            data_type *t=(yyvsp[-3].pointer)->type;
            data_type* prev=NULL;
            while(t->type=="arr"){
                prev=t;
                t=t->arrtype;
            }
            if(prev==NULL){
                int temp=stoi((yyvsp[-1].expr)->loc->value);
                if(temp<=0){
                    yyerror(strdup("Array size should be positive value"));
                }
                data_type* tp=new data_type("arr",(yyvsp[-3].pointer)->type,temp);
                (yyval.pointer)=(yyvsp[-3].pointer)->update(tp);
            }
            else{
                int temp=stoi((yyvsp[-1].expr)->loc->value);
                if(temp<=0){
                    yyerror(strdup("Array size should be positive value"));
                }
                data_type* a=new data_type("arr",t,temp);
                prev->arrtype=a;
                (yyval.pointer)=(yyvsp[-3].pointer)->update((yyvsp[-3].pointer)->type);
            }
        }
#line 2884 "tinyC3.tab.c"
    break;

  case 138: /* direct_declarator: direct_declarator OP_SQUARE CL_SQUARE  */
#line 730 "tinyC3.y"
                                                    {//array declaration informal
            data_type* t=(yyvsp[-2].pointer)->type;
            data_type* prev=NULL;
            while(t->type=="arr"){
                prev=t;
                t=t->arrtype;
            }
            if(prev==NULL){
                data_type* a=new data_type("arr",(yyvsp[-2].pointer)->type,0);
                (yyval.pointer)=(yyvsp[-2].pointer)->update(a);
            }
            else{
                data_type* a=new data_type("arr",t,0);
                prev->arrtype=a;
                (yyval.pointer)=(yyvsp[-2].pointer)->update((yyvsp[-2].pointer)->type);
            }
        }
#line 2906 "tinyC3.tab.c"
    break;

  case 139: /* direct_declarator: direct_declarator OP_SQUARE STATIC type_qualifier_list assignment_expression CL_SQUARE  */
#line 747 "tinyC3.y"
                                                                                                    {}
#line 2912 "tinyC3.tab.c"
    break;

  case 140: /* direct_declarator: direct_declarator OP_SQUARE STATIC assignment_expression CL_SQUARE  */
#line 748 "tinyC3.y"
                                                                                                    {}
#line 2918 "tinyC3.tab.c"
    break;

  case 141: /* direct_declarator: direct_declarator OP_SQUARE type_qualifier_list STATIC assignment_expression CL_SQUARE  */
#line 749 "tinyC3.y"
                                                                                                    {}
#line 2924 "tinyC3.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator OP_SQUARE type_qualifier_list MUL CL_SQUARE  */
#line 750 "tinyC3.y"
                                                                                                    {}
#line 2930 "tinyC3.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator OP_SQUARE MUL CL_SQUARE  */
#line 751 "tinyC3.y"
                                                                                                    {}
#line 2936 "tinyC3.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator OP_ROUND identifier_list CL_ROUND  */
#line 752 "tinyC3.y"
                                                                                                    {}
#line 2942 "tinyC3.tab.c"
    break;

  case 145: /* direct_declarator: direct_declarator OP_ROUND change_table parameter_type_list CL_ROUND  */
#line 753 "tinyC3.y"
                                                                                                    {//function declaration,change_table added to augment the grammar
            pres_table->name=(yyvsp[-4].pointer)->name;
            if((yyvsp[-4].pointer)->type->type!="void"){
                symbol* sym=pres_table->lookup("return");   
                sym->update((yyvsp[-4].pointer)->type);
            }
            (yyvsp[-4].pointer)->nested_table=pres_table;
            pres_table->parent=global_table; 
            switchTable(global_table);
            prev_symbol=(yyval.pointer);
        }
#line 2958 "tinyC3.tab.c"
    break;

  case 146: /* direct_declarator: direct_declarator OP_ROUND change_table CL_ROUND  */
#line 764 "tinyC3.y"
                                                                    {
            pres_table->name=(yyvsp[-3].pointer)->name;
            if((yyvsp[-3].pointer)->type->type!="void"){
                symbol* sym=pres_table->lookup("return");   
                sym->update((yyvsp[-3].pointer)->type);
            }
            (yyvsp[-3].pointer)->nested_table=pres_table;
            pres_table->parent=global_table; 
            switchTable(global_table);        
            prev_symbol=(yyval.pointer);
        }
#line 2974 "tinyC3.tab.c"
    break;

  case 147: /* type_qualifier_list_opt: type_qualifier_list  */
#line 778 "tinyC3.y"
                                    {}
#line 2980 "tinyC3.tab.c"
    break;

  case 148: /* type_qualifier_list_opt: %empty  */
#line 779 "tinyC3.y"
                                    {}
#line 2986 "tinyC3.tab.c"
    break;

  case 149: /* pointer: MUL type_qualifier_list_opt  */
#line 783 "tinyC3.y"
                                                    {(yyval.ptr)=new data_type("ptr");}
#line 2992 "tinyC3.tab.c"
    break;

  case 150: /* pointer: MUL type_qualifier_list_opt pointer  */
#line 784 "tinyC3.y"
                                                    {(yyval.ptr)=new data_type("ptr",(yyvsp[0].ptr));}
#line 2998 "tinyC3.tab.c"
    break;

  case 151: /* type_qualifier_list: type_qualifier  */
#line 788 "tinyC3.y"
                                                {}
#line 3004 "tinyC3.tab.c"
    break;

  case 152: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 789 "tinyC3.y"
                                                {}
#line 3010 "tinyC3.tab.c"
    break;

  case 153: /* parameter_type_list: parameter_list  */
#line 793 "tinyC3.y"
                                        {}
#line 3016 "tinyC3.tab.c"
    break;

  case 154: /* parameter_type_list: parameter_list COMMA SO_ON  */
#line 794 "tinyC3.y"
                                        {}
#line 3022 "tinyC3.tab.c"
    break;

  case 155: /* parameter_list: parameter_declaration  */
#line 798 "tinyC3.y"
                                                        {}
#line 3028 "tinyC3.tab.c"
    break;

  case 156: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 799 "tinyC3.y"
                                                        {}
#line 3034 "tinyC3.tab.c"
    break;

  case 157: /* parameter_declaration: declaration_specifiers declarator  */
#line 803 "tinyC3.y"
                                                {}
#line 3040 "tinyC3.tab.c"
    break;

  case 158: /* parameter_declaration: declaration_specifiers  */
#line 804 "tinyC3.y"
                                                {}
#line 3046 "tinyC3.tab.c"
    break;

  case 159: /* identifier_list: IDENTIFIER  */
#line 808 "tinyC3.y"
                                                {}
#line 3052 "tinyC3.tab.c"
    break;

  case 160: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 809 "tinyC3.y"
                                                {}
#line 3058 "tinyC3.tab.c"
    break;

  case 161: /* type_name: specifier_qualifier_list  */
#line 813 "tinyC3.y"
                                                {}
#line 3064 "tinyC3.tab.c"
    break;

  case 162: /* initializer: assignment_expression  */
#line 817 "tinyC3.y"
                                                        {(yyval.pointer)=(yyvsp[0].expr)->loc;}
#line 3070 "tinyC3.tab.c"
    break;

  case 163: /* initializer: OP_CURLY initializer_list CL_CURLY  */
#line 818 "tinyC3.y"
                                                        {}
#line 3076 "tinyC3.tab.c"
    break;

  case 164: /* initializer: OP_CURLY initializer_list COMMA CL_CURLY  */
#line 819 "tinyC3.y"
                                                        {}
#line 3082 "tinyC3.tab.c"
    break;

  case 165: /* initializer_list: designation_opt initializer  */
#line 823 "tinyC3.y"
                                                                {}
#line 3088 "tinyC3.tab.c"
    break;

  case 166: /* initializer_list: initializer_list COMMA designation_opt initializer  */
#line 824 "tinyC3.y"
                                                                {}
#line 3094 "tinyC3.tab.c"
    break;

  case 167: /* designation_opt: designation  */
#line 828 "tinyC3.y"
                            {}
#line 3100 "tinyC3.tab.c"
    break;

  case 168: /* designation_opt: %empty  */
#line 829 "tinyC3.y"
                            {}
#line 3106 "tinyC3.tab.c"
    break;

  case 169: /* designation: designator_list EQ  */
#line 833 "tinyC3.y"
                                {}
#line 3112 "tinyC3.tab.c"
    break;

  case 170: /* designator_list: designator  */
#line 837 "tinyC3.y"
                                        {}
#line 3118 "tinyC3.tab.c"
    break;

  case 171: /* designator_list: designator_list designator  */
#line 838 "tinyC3.y"
                                        {}
#line 3124 "tinyC3.tab.c"
    break;

  case 172: /* designator: OP_SQUARE constant_expression CL_SQUARE  */
#line 842 "tinyC3.y"
                                                        {}
#line 3130 "tinyC3.tab.c"
    break;

  case 173: /* designator: DOT IDENTIFIER  */
#line 843 "tinyC3.y"
                                                        {}
#line 3136 "tinyC3.tab.c"
    break;

  case 174: /* statement: labeled_statement  */
#line 847 "tinyC3.y"
                                    {}
#line 3142 "tinyC3.tab.c"
    break;

  case 175: /* statement: compound_statement  */
#line 848 "tinyC3.y"
                                    {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3148 "tinyC3.tab.c"
    break;

  case 176: /* statement: expression_statement  */
#line 849 "tinyC3.y"
                                    {(yyval.stmt)=new statement();(yyval.stmt)->nextlist=(yyvsp[0].expr)->nextlist;}
#line 3154 "tinyC3.tab.c"
    break;

  case 177: /* statement: selection_statement  */
#line 850 "tinyC3.y"
                                    {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3160 "tinyC3.tab.c"
    break;

  case 178: /* statement: iteration_statement  */
#line 851 "tinyC3.y"
                                    {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3166 "tinyC3.tab.c"
    break;

  case 179: /* statement: jump_statement  */
#line 852 "tinyC3.y"
                                    {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3172 "tinyC3.tab.c"
    break;

  case 180: /* loop_statement: labeled_statement  */
#line 856 "tinyC3.y"
                                    {}
#line 3178 "tinyC3.tab.c"
    break;

  case 181: /* loop_statement: expression_statement  */
#line 857 "tinyC3.y"
                                    {(yyval.stmt)=new statement();(yyval.stmt)->nextlist=(yyvsp[0].expr)->nextlist;}
#line 3184 "tinyC3.tab.c"
    break;

  case 182: /* loop_statement: selection_statement  */
#line 858 "tinyC3.y"
                                    {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3190 "tinyC3.tab.c"
    break;

  case 183: /* loop_statement: iteration_statement  */
#line 859 "tinyC3.y"
                                    {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3196 "tinyC3.tab.c"
    break;

  case 184: /* loop_statement: jump_statement  */
#line 860 "tinyC3.y"
                                    {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3202 "tinyC3.tab.c"
    break;

  case 185: /* labeled_statement: IDENTIFIER COLON statement  */
#line 864 "tinyC3.y"
                                                        {}
#line 3208 "tinyC3.tab.c"
    break;

  case 186: /* labeled_statement: CASE constant_expression COLON statement  */
#line 865 "tinyC3.y"
                                                        {}
#line 3214 "tinyC3.tab.c"
    break;

  case 187: /* labeled_statement: DEFAULT COLON statement  */
#line 866 "tinyC3.y"
                                                        {}
#line 3220 "tinyC3.tab.c"
    break;

  case 188: /* compound_statement: OP_CURLY new_table change_table block_item_list_opt CL_CURLY  */
#line 870 "tinyC3.y"
                                                                            {(yyval.stmt)=(yyvsp[-1].stmt);switchTable(pres_table->parent);}
#line 3226 "tinyC3.tab.c"
    break;

  case 189: /* new_table: %empty  */
#line 874 "tinyC3.y"
                    {//to add new table
            string new_name=pres_table->name + "_" + block_type + "_" + to_string(ntables++);
            symbol* sym=pres_table->lookup(new_name);
            sym->name=new_name;
            sym->type=new data_type("block");
            sym->nested_table=new symbolTbl(new_name);
            sym->nested_table->parent=pres_table;
            prev_symbol=sym;
        }
#line 3240 "tinyC3.tab.c"
    break;

  case 190: /* change_table: %empty  */
#line 886 "tinyC3.y"
                    {//to change tables
            if(prev_symbol->nested_table != NULL){
                switchTable(prev_symbol->nested_table);
                emit("label",pres_table->name);
            }
            else{
                switchTable(new symbolTbl(""));
            }
        }
#line 3254 "tinyC3.tab.c"
    break;

  case 191: /* block_item_list_opt: block_item_list  */
#line 898 "tinyC3.y"
                                {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3260 "tinyC3.tab.c"
    break;

  case 192: /* block_item_list_opt: %empty  */
#line 899 "tinyC3.y"
                                {(yyval.stmt)=new statement();}
#line 3266 "tinyC3.tab.c"
    break;

  case 193: /* block_item_list: block_item  */
#line 903 "tinyC3.y"
                                                    {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3272 "tinyC3.tab.c"
    break;

  case 194: /* block_item_list: block_item_list next_instr block_item  */
#line 904 "tinyC3.y"
                                                    {(yyval.stmt)=(yyvsp[0].stmt);backpatch((yyvsp[-2].stmt)->nextlist, (yyvsp[-1].instr));}
#line 3278 "tinyC3.tab.c"
    break;

  case 195: /* block_item: declaration  */
#line 908 "tinyC3.y"
                            {(yyval.stmt)=new statement();}
#line 3284 "tinyC3.tab.c"
    break;

  case 196: /* block_item: statement  */
#line 909 "tinyC3.y"
                            {(yyval.stmt)=(yyvsp[0].stmt);}
#line 3290 "tinyC3.tab.c"
    break;

  case 197: /* expression_statement: expression SEMICOLON  */
#line 913 "tinyC3.y"
                                    {(yyval.expr)=(yyvsp[-1].expr);}
#line 3296 "tinyC3.tab.c"
    break;

  case 198: /* expression_statement: SEMICOLON  */
#line 914 "tinyC3.y"
                                    {(yyval.expr)=new expression();}
#line 3302 "tinyC3.tab.c"
    break;

  case 199: /* selection_statement: IF OP_ROUND expression next_list CL_ROUND next_instr statement next_list  */
#line 918 "tinyC3.y"
                                                                                                                {
            conv_int_2_bool((yyvsp[-5].expr));
            backpatch((yyvsp[-4].stmt)->nextlist,nextinstr());
            backpatch((yyvsp[-5].expr)->truelist,(yyvsp[-2].instr));
            list<int> temp=merge((yyvsp[-5].expr)->falselist,(yyvsp[-1].stmt)->nextlist);
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=merge(temp,(yyvsp[0].stmt)->nextlist);
        }
#line 3315 "tinyC3.tab.c"
    break;

  case 200: /* selection_statement: IF OP_ROUND expression next_list CL_ROUND next_instr statement next_list ELSE next_instr statement  */
#line 926 "tinyC3.y"
                                                                                                                {
            conv_int_2_bool((yyvsp[-8].expr));
            backpatch((yyvsp[-7].stmt)->nextlist,nextinstr());
            backpatch((yyvsp[-8].expr)->truelist,(yyvsp[-5].instr));
            backpatch((yyvsp[-8].expr)->falselist,(yyvsp[-1].instr));
            list<int> temp=merge((yyvsp[-4].stmt)->nextlist,(yyvsp[-3].stmt)->nextlist);
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=merge(temp,(yyvsp[0].stmt)->nextlist);
        }
#line 3329 "tinyC3.tab.c"
    break;

  case 201: /* selection_statement: SWITCH OP_ROUND expression CL_ROUND statement  */
#line 935 "tinyC3.y"
                                                            {}
#line 3335 "tinyC3.tab.c"
    break;

  case 202: /* iteration_statement: WHILE while_block OP_ROUND new_table change_table next_instr expression CL_ROUND next_instr loop_statement  */
#line 939 "tinyC3.y"
                                                                                                                        {
            conv_int_2_bool((yyvsp[-3].expr));
            backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-4].instr));
            backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].instr));
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=(yyvsp[-3].expr)->falselist;
            emit("goto",to_string((yyvsp[-4].instr)));
            block_type="";
            switchTable(pres_table->parent);
        }
#line 3350 "tinyC3.tab.c"
    break;

  case 203: /* iteration_statement: WHILE while_block OP_ROUND new_table change_table next_instr expression CL_ROUND OP_CURLY next_instr block_item_list_opt CL_CURLY  */
#line 949 "tinyC3.y"
                                                                                                                                                {
            conv_int_2_bool((yyvsp[-5].expr));
            backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-6].instr));
            backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].instr));
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=(yyvsp[-5].expr)->falselist;
            emit("goto",to_string((yyvsp[-6].instr)));
            block_type="";
            switchTable(pres_table->parent);
        }
#line 3365 "tinyC3.tab.c"
    break;

  case 204: /* iteration_statement: DO dowhile_block next_instr loop_statement next_instr WHILE OP_ROUND expression CL_ROUND SEMICOLON  */
#line 959 "tinyC3.y"
                                                                                                                  {
            conv_int_2_bool((yyvsp[-2].expr));
            backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-7].instr));
            backpatch((yyvsp[-6].stmt)->nextlist, (yyvsp[-5].instr));
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=(yyvsp[-2].expr)->falselist;
            block_type="";
        }
#line 3378 "tinyC3.tab.c"
    break;

  case 205: /* iteration_statement: DO dowhile_block OP_CURLY next_instr block_item_list_opt CL_CURLY next_instr WHILE OP_ROUND expression CL_ROUND SEMICOLON  */
#line 967 "tinyC3.y"
                                                                                                                                          {
            conv_int_2_bool((yyvsp[-2].expr));
            backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-8].instr));
            backpatch((yyvsp[-7].stmt)->nextlist, (yyvsp[-5].instr));
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=(yyvsp[-2].expr)->falselist;
            block_type="";
        }
#line 3391 "tinyC3.tab.c"
    break;

  case 206: /* iteration_statement: FOR for_block OP_ROUND new_table change_table declaration next_instr expression_statement next_instr expression next_list CL_ROUND next_instr loop_statement  */
#line 975 "tinyC3.y"
                                                                                                                                                                           {
            conv_int_2_bool((yyvsp[-6].expr));
            backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].instr));
            backpatch((yyvsp[-3].stmt)->nextlist, (yyvsp[-7].instr));
            backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-5].instr));
            emit("goto", to_string((yyvsp[-5].instr)));
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=(yyvsp[-6].expr)->falselist;
            block_type="";
            switchTable(pres_table->parent);
        }
#line 3407 "tinyC3.tab.c"
    break;

  case 207: /* iteration_statement: FOR for_block OP_ROUND new_table change_table expression_statement next_instr expression_statement next_instr expression next_list CL_ROUND next_instr loop_statement  */
#line 986 "tinyC3.y"
                                                                                                                                                                                   {
            conv_int_2_bool((yyvsp[-6].expr));
            backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].instr));
            backpatch((yyvsp[-3].stmt)->nextlist, (yyvsp[-7].instr));
            backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-5].instr));
            emit("goto", to_string((yyvsp[-5].instr)));
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=(yyvsp[-6].expr)->falselist;
            block_type="";
            switchTable(pres_table->parent);
        }
#line 3423 "tinyC3.tab.c"
    break;

  case 208: /* iteration_statement: FOR for_block OP_ROUND new_table change_table declaration next_instr expression_statement next_instr expression next_list CL_ROUND next_instr OP_CURLY block_item_list_opt CL_CURLY  */
#line 997 "tinyC3.y"
                                                                                                                                                                                                   {
            conv_int_2_bool((yyvsp[-8].expr));
            backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-3].instr));
            backpatch((yyvsp[-5].stmt)->nextlist, (yyvsp[-9].instr));
            backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-7].instr));
            emit("goto", to_string((yyvsp[-7].instr)));
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=(yyvsp[-8].expr)->falselist;
            block_type="";
            switchTable(pres_table->parent);
        }
#line 3439 "tinyC3.tab.c"
    break;

  case 209: /* iteration_statement: FOR for_block OP_ROUND new_table change_table expression_statement next_instr expression_statement next_instr expression next_list CL_ROUND next_instr OP_CURLY block_item_list_opt CL_CURLY  */
#line 1008 "tinyC3.y"
                                                                                                                                                                                                           {
            conv_int_2_bool((yyvsp[-8].expr));                 
            backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-3].instr));          
            backpatch((yyvsp[-5].stmt)->nextlist, (yyvsp[-9].instr));          
            backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-7].instr));          
            emit("goto", to_string((yyvsp[-7].instr))); 
            (yyval.stmt)=new statement();
            (yyval.stmt)->nextlist=(yyvsp[-8].expr)->falselist;
            block_type="";
            switchTable(pres_table->parent);
        }
#line 3455 "tinyC3.tab.c"
    break;

  case 210: /* while_block: %empty  */
#line 1022 "tinyC3.y"
                        {block_type="WHILE";}
#line 3461 "tinyC3.tab.c"
    break;

  case 211: /* dowhile_block: %empty  */
#line 1026 "tinyC3.y"
                        {block_type="DO_WHILE";}
#line 3467 "tinyC3.tab.c"
    break;

  case 212: /* for_block: %empty  */
#line 1030 "tinyC3.y"
                        {block_type="for";}
#line 3473 "tinyC3.tab.c"
    break;

  case 213: /* jump_statement: GOTO IDENTIFIER SEMICOLON  */
#line 1033 "tinyC3.y"
                                        {}
#line 3479 "tinyC3.tab.c"
    break;

  case 214: /* jump_statement: CONTINUE SEMICOLON  */
#line 1034 "tinyC3.y"
                                        {(yyval.stmt)=new statement();}
#line 3485 "tinyC3.tab.c"
    break;

  case 215: /* jump_statement: BREAK SEMICOLON  */
#line 1035 "tinyC3.y"
                                        {(yyval.stmt)=new statement();}
#line 3491 "tinyC3.tab.c"
    break;

  case 216: /* jump_statement: RETURN expression SEMICOLON  */
#line 1036 "tinyC3.y"
                                        {(yyval.stmt)=new statement();emit("return",(yyvsp[-1].expr)->loc->name);}
#line 3497 "tinyC3.tab.c"
    break;

  case 217: /* jump_statement: RETURN SEMICOLON  */
#line 1037 "tinyC3.y"
                                        {(yyval.stmt)=new statement();emit("return","");}
#line 3503 "tinyC3.tab.c"
    break;

  case 218: /* translation_unit: external_declaration  */
#line 1041 "tinyC3.y"
                                                    {}
#line 3509 "tinyC3.tab.c"
    break;

  case 219: /* translation_unit: translation_unit external_declaration  */
#line 1042 "tinyC3.y"
                                                    {}
#line 3515 "tinyC3.tab.c"
    break;

  case 220: /* external_declaration: function_definition  */
#line 1046 "tinyC3.y"
                                    {}
#line 3521 "tinyC3.tab.c"
    break;

  case 221: /* external_declaration: declaration  */
#line 1047 "tinyC3.y"
                                    {}
#line 3527 "tinyC3.tab.c"
    break;

  case 222: /* function_definition: declaration_specifiers declarator declaration_list_opt change_table OP_CURLY block_item_list_opt CL_CURLY  */
#line 1051 "tinyC3.y"
                                                                                                                         {pres_table->parent=global_table;ntables=0;switchTable(global_table);}
#line 3533 "tinyC3.tab.c"
    break;

  case 223: /* declaration_list_opt: declaration_list  */
#line 1055 "tinyC3.y"
                                {}
#line 3539 "tinyC3.tab.c"
    break;

  case 224: /* declaration_list_opt: %empty  */
#line 1056 "tinyC3.y"
                                {}
#line 3545 "tinyC3.tab.c"
    break;

  case 225: /* declaration_list: declaration  */
#line 1060 "tinyC3.y"
                                            {}
#line 3551 "tinyC3.tab.c"
    break;

  case 226: /* declaration_list: declaration_list declaration  */
#line 1061 "tinyC3.y"
                                            {}
#line 3557 "tinyC3.tab.c"
    break;

  case 227: /* program: translation_unit  */
#line 1065 "tinyC3.y"
                                {}
#line 3563 "tinyC3.tab.c"
    break;


#line 3567 "tinyC3.tab.c"

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

#line 1068 "tinyC3.y"
