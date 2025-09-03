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
#line 1 "tinyC2.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(char *s);
int yywrap(){
    return 1;
}

typedef struct Tree_Node{
    char* name;
    char* val;
    int n_child;
    struct Tree_Node** child_nodes;
}TreeNode;

TreeNode* createNode(char *name,char* val,int n,TreeNode** child);
void printTree(TreeNode* root,int h);

TreeNode *root; 


#line 96 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTCONST = 259,                /* INTCONST  */
    FLOATCONST = 260,              /* FLOATCONST  */
    CHARCONST = 261,               /* CHARCONST  */
    STR_LITERAL = 262,             /* STR_LITERAL  */
    EXTERN = 263,                  /* EXTERN  */
    STATIC = 264,                  /* STATIC  */
    AUTO = 265,                    /* AUTO  */
    VOID = 266,                    /* VOID  */
    CHAR = 267,                    /* CHAR  */
    REGISTER = 268,                /* REGISTER  */
    SHORT = 269,                   /* SHORT  */
    INT = 270,                     /* INT  */
    LONG = 271,                    /* LONG  */
    FLOAT = 272,                   /* FLOAT  */
    DOUBLE = 273,                  /* DOUBLE  */
    SIGNED = 274,                  /* SIGNED  */
    UNSIGNED = 275,                /* UNSIGNED  */
    BOOL = 276,                    /* BOOL  */
    COMPLEX = 277,                 /* COMPLEX  */
    IMAGINARY = 278,               /* IMAGINARY  */
    CONST = 279,                   /* CONST  */
    RESTRICT = 280,                /* RESTRICT  */
    VOLATILE = 281,                /* VOLATILE  */
    INLINE = 282,                  /* INLINE  */
    SO_ON = 283,                   /* SO_ON  */
    CASE = 284,                    /* CASE  */
    DEFAULT = 285,                 /* DEFAULT  */
    IF = 286,                      /* IF  */
    ELSE = 287,                    /* ELSE  */
    SWITCH = 288,                  /* SWITCH  */
    WHILE = 289,                   /* WHILE  */
    DO = 290,                      /* DO  */
    FOR = 291,                     /* FOR  */
    GOTO = 292,                    /* GOTO  */
    CONTINUE = 293,                /* CONTINUE  */
    BREAK = 294,                   /* BREAK  */
    RETURN = 295,                  /* RETURN  */
    IMPLIES = 296,                 /* IMPLIES  */
    INCRE = 297,                   /* INCRE  */
    DECRE = 298,                   /* DECRE  */
    SIZEOF = 299,                  /* SIZEOF  */
    LSHIFT = 300,                  /* LSHIFT  */
    RSHIFT = 301,                  /* RSHIFT  */
    GEQ = 302,                     /* GEQ  */
    LEQ = 303,                     /* LEQ  */
    EQEQ = 304,                    /* EQEQ  */
    NEQ = 305,                     /* NEQ  */
    AND = 306,                     /* AND  */
    OR = 307,                      /* OR  */
    MULEQ = 308,                   /* MULEQ  */
    DIVEQ = 309,                   /* DIVEQ  */
    MODEQ = 310,                   /* MODEQ  */
    ADDEQ = 311,                   /* ADDEQ  */
    SUBEQ = 312,                   /* SUBEQ  */
    LSHEQ = 313,                   /* LSHEQ  */
    RSHEQ = 314,                   /* RSHEQ  */
    ANDEQ = 315,                   /* ANDEQ  */
    XOREQ = 316,                   /* XOREQ  */
    OREQ = 317,                    /* OREQ  */
    SINGCOMM = 318,                /* SINGCOMM  */
    MULTCOMM = 319,                /* MULTCOMM  */
    OP_SQUARE = 320,               /* OP_SQUARE  */
    CL_SQUARE = 321,               /* CL_SQUARE  */
    OP_ROUND = 322,                /* OP_ROUND  */
    CL_ROUND = 323,                /* CL_ROUND  */
    OP_CURLY = 324,                /* OP_CURLY  */
    CL_CURLY = 325,                /* CL_CURLY  */
    DOT = 326,                     /* DOT  */
    BIT_AND = 327,                 /* BIT_AND  */
    PLUS = 328,                    /* PLUS  */
    MIN = 329,                     /* MIN  */
    MUL = 330,                     /* MUL  */
    BIT_NOT = 331,                 /* BIT_NOT  */
    NOT = 332,                     /* NOT  */
    DIV = 333,                     /* DIV  */
    MOD = 334,                     /* MOD  */
    LT = 335,                      /* LT  */
    GT = 336,                      /* GT  */
    BIT_XOR = 337,                 /* BIT_XOR  */
    BIT_OR = 338,                  /* BIT_OR  */
    Q_MARK = 339,                  /* Q_MARK  */
    COLON = 340,                   /* COLON  */
    SEMICOLON = 341,               /* SEMICOLON  */
    EQ = 342,                      /* EQ  */
    COMMA = 343                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INTCONST 259
#define FLOATCONST 260
#define CHARCONST 261
#define STR_LITERAL 262
#define EXTERN 263
#define STATIC 264
#define AUTO 265
#define VOID 266
#define CHAR 267
#define REGISTER 268
#define SHORT 269
#define INT 270
#define LONG 271
#define FLOAT 272
#define DOUBLE 273
#define SIGNED 274
#define UNSIGNED 275
#define BOOL 276
#define COMPLEX 277
#define IMAGINARY 278
#define CONST 279
#define RESTRICT 280
#define VOLATILE 281
#define INLINE 282
#define SO_ON 283
#define CASE 284
#define DEFAULT 285
#define IF 286
#define ELSE 287
#define SWITCH 288
#define WHILE 289
#define DO 290
#define FOR 291
#define GOTO 292
#define CONTINUE 293
#define BREAK 294
#define RETURN 295
#define IMPLIES 296
#define INCRE 297
#define DECRE 298
#define SIZEOF 299
#define LSHIFT 300
#define RSHIFT 301
#define GEQ 302
#define LEQ 303
#define EQEQ 304
#define NEQ 305
#define AND 306
#define OR 307
#define MULEQ 308
#define DIVEQ 309
#define MODEQ 310
#define ADDEQ 311
#define SUBEQ 312
#define LSHEQ 313
#define RSHEQ 314
#define ANDEQ 315
#define XOREQ 316
#define OREQ 317
#define SINGCOMM 318
#define MULTCOMM 319
#define OP_SQUARE 320
#define CL_SQUARE 321
#define OP_ROUND 322
#define CL_ROUND 323
#define OP_CURLY 324
#define CL_CURLY 325
#define DOT 326
#define BIT_AND 327
#define PLUS 328
#define MIN 329
#define MUL 330
#define BIT_NOT 331
#define NOT 332
#define DIV 333
#define MOD 334
#define LT 335
#define GT 336
#define BIT_XOR 337
#define BIT_OR 338
#define Q_MARK 339
#define COLON 340
#define SEMICOLON 341
#define EQ 342
#define COMMA 343

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "tinyC2.y"

    struct Tree_Node* tnode;
    char *str;
    float fconst;
    int iconst;

#line 332 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
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
  YYSYMBOL_IMPLIES = 41,                   /* IMPLIES  */
  YYSYMBOL_INCRE = 42,                     /* INCRE  */
  YYSYMBOL_DECRE = 43,                     /* DECRE  */
  YYSYMBOL_SIZEOF = 44,                    /* SIZEOF  */
  YYSYMBOL_LSHIFT = 45,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 46,                    /* RSHIFT  */
  YYSYMBOL_GEQ = 47,                       /* GEQ  */
  YYSYMBOL_LEQ = 48,                       /* LEQ  */
  YYSYMBOL_EQEQ = 49,                      /* EQEQ  */
  YYSYMBOL_NEQ = 50,                       /* NEQ  */
  YYSYMBOL_AND = 51,                       /* AND  */
  YYSYMBOL_OR = 52,                        /* OR  */
  YYSYMBOL_MULEQ = 53,                     /* MULEQ  */
  YYSYMBOL_DIVEQ = 54,                     /* DIVEQ  */
  YYSYMBOL_MODEQ = 55,                     /* MODEQ  */
  YYSYMBOL_ADDEQ = 56,                     /* ADDEQ  */
  YYSYMBOL_SUBEQ = 57,                     /* SUBEQ  */
  YYSYMBOL_LSHEQ = 58,                     /* LSHEQ  */
  YYSYMBOL_RSHEQ = 59,                     /* RSHEQ  */
  YYSYMBOL_ANDEQ = 60,                     /* ANDEQ  */
  YYSYMBOL_XOREQ = 61,                     /* XOREQ  */
  YYSYMBOL_OREQ = 62,                      /* OREQ  */
  YYSYMBOL_SINGCOMM = 63,                  /* SINGCOMM  */
  YYSYMBOL_MULTCOMM = 64,                  /* MULTCOMM  */
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
  YYSYMBOL_YYACCEPT = 89,                  /* $accept  */
  YYSYMBOL_identifier = 90,                /* identifier  */
  YYSYMBOL_constant = 91,                  /* constant  */
  YYSYMBOL_primary_expression = 92,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 93,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 94,  /* argument_expression_list  */
  YYSYMBOL_argument_expression_list_opt = 95, /* argument_expression_list_opt  */
  YYSYMBOL_unary_expression = 96,          /* unary_expression  */
  YYSYMBOL_unary_operator = 97,            /* unary_operator  */
  YYSYMBOL_cast_expression = 98,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 99, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 100,      /* additive_expression  */
  YYSYMBOL_shift_expression = 101,         /* shift_expression  */
  YYSYMBOL_relational_expression = 102,    /* relational_expression  */
  YYSYMBOL_equality_expression = 103,      /* equality_expression  */
  YYSYMBOL_AND_expression = 104,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 105,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 106,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 107,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 108,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 109,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 110,    /* assignment_expression  */
  YYSYMBOL_assignment_expression_opt = 111, /* assignment_expression_opt  */
  YYSYMBOL_assignment_operator = 112,      /* assignment_operator  */
  YYSYMBOL_expression = 113,               /* expression  */
  YYSYMBOL_constant_expression = 114,      /* constant_expression  */
  YYSYMBOL_declaration = 115,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 116,   /* declaration_specifiers  */
  YYSYMBOL_declaration_specifiers_opt = 117, /* declaration_specifiers_opt  */
  YYSYMBOL_init_declarator_list = 118,     /* init_declarator_list  */
  YYSYMBOL_init_declarator_list_opt = 119, /* init_declarator_list_opt  */
  YYSYMBOL_init_declarator = 120,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 121,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 122,           /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 123, /* specifier_qualifier_list  */
  YYSYMBOL_specifier_qualifier_list_opt = 124, /* specifier_qualifier_list_opt  */
  YYSYMBOL_type_qualifier = 125,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 126,       /* function_specifier  */
  YYSYMBOL_declarator = 127,               /* declarator  */
  YYSYMBOL_direct_declarator = 128,        /* direct_declarator  */
  YYSYMBOL_pointer = 129,                  /* pointer  */
  YYSYMBOL_pointer_opt = 130,              /* pointer_opt  */
  YYSYMBOL_type_qualifier_list = 131,      /* type_qualifier_list  */
  YYSYMBOL_type_qualifier_list_opt = 132,  /* type_qualifier_list_opt  */
  YYSYMBOL_parameter_type_list = 133,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 134,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 135,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 136,          /* identifier_list  */
  YYSYMBOL_identifier_list_opt = 137,      /* identifier_list_opt  */
  YYSYMBOL_type_name = 138,                /* type_name  */
  YYSYMBOL_initializer = 139,              /* initializer  */
  YYSYMBOL_initializer_list = 140,         /* initializer_list  */
  YYSYMBOL_designation = 141,              /* designation  */
  YYSYMBOL_designation_opt = 142,          /* designation_opt  */
  YYSYMBOL_designator_list = 143,          /* designator_list  */
  YYSYMBOL_designator = 144,               /* designator  */
  YYSYMBOL_statement = 145,                /* statement  */
  YYSYMBOL_labeled_statement = 146,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 147,       /* compound_statement  */
  YYSYMBOL_block_item_list = 148,          /* block_item_list  */
  YYSYMBOL_block_item_list_opt = 149,      /* block_item_list_opt  */
  YYSYMBOL_block_item = 150,               /* block_item  */
  YYSYMBOL_expression_statement = 151,     /* expression_statement  */
  YYSYMBOL_expression_opt = 152,           /* expression_opt  */
  YYSYMBOL_selection_statement = 153,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 154,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 155,           /* jump_statement  */
  YYSYMBOL_translation_unit = 156,         /* translation_unit  */
  YYSYMBOL_external_declaration = 157,     /* external_declaration  */
  YYSYMBOL_function_definition = 158,      /* function_definition  */
  YYSYMBOL_declaration_list = 159,         /* declaration_list  */
  YYSYMBOL_declaration_list_opt = 160,     /* declaration_list_opt  */
  YYSYMBOL_program = 161                   /* program  */
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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   773

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  327

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   343


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
      85,    86,    87,    88
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    65,    68,    71,    77,    80,    83,    86,
      92,    95,    98,   101,   104,   107,   110,   113,   117,   124,
     127,   133,   136,   142,   145,   148,   151,   154,   157,   163,
     164,   165,   166,   167,   168,   172,   174,   180,   182,   185,
     188,   194,   196,   199,   205,   207,   210,   216,   218,   221,
     224,   227,   233,   235,   238,   244,   246,   252,   254,   260,
     262,   268,   270,   276,   278,   284,   286,   293,   295,   301,
     303,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   323,   325,   331,   337,   343,   346,   349,   352,
     358,   360,   366,   368,   374,   376,   382,   384,   390,   391,
     392,   393,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   412,   415,   421,   423,   429,   430,
     431,   435,   439,   445,   448,   451,   455,   459,   463,   467,
     471,   478,   481,   487,   489,   495,   497,   502,   504,   511,
     513,   519,   521,   527,   529,   534,   536,   542,   544,   550,
     555,   557,   560,   566,   568,   574,   580,   582,   588,   590,
     595,   598,   605,   607,   609,   611,   613,   615,   620,   623,
     626,   632,   638,   640,   645,   647,   653,   655,   660,   666,
     668,   674,   678,   683,   690,   694,   699,   705,   714,   717,
     720,   723,   730,   732,   737,   739,   744,   750,   752,   757,
     759,   765
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
  "RETURN", "IMPLIES", "INCRE", "DECRE", "SIZEOF", "LSHIFT", "RSHIFT",
  "GEQ", "LEQ", "EQEQ", "NEQ", "AND", "OR", "MULEQ", "DIVEQ", "MODEQ",
  "ADDEQ", "SUBEQ", "LSHEQ", "RSHEQ", "ANDEQ", "XOREQ", "OREQ", "SINGCOMM",
  "MULTCOMM", "OP_SQUARE", "CL_SQUARE", "OP_ROUND", "CL_ROUND", "OP_CURLY",
  "CL_CURLY", "DOT", "BIT_AND", "PLUS", "MIN", "MUL", "BIT_NOT", "NOT",
  "DIV", "MOD", "LT", "GT", "BIT_XOR", "BIT_OR", "Q_MARK", "COLON",
  "SEMICOLON", "EQ", "COMMA", "$accept", "identifier", "constant",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "argument_expression_list_opt", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression",
  "assignment_expression_opt", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list",
  "init_declarator_list_opt", "init_declarator", "storage_class_specifier",
  "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "pointer", "pointer_opt",
  "type_qualifier_list", "type_qualifier_list_opt", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "identifier_list_opt", "type_name", "initializer", "initializer_list",
  "designation", "designation_opt", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item_list_opt", "block_item",
  "expression_statement", "expression_opt", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list",
  "declaration_list_opt", "program", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-201)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     746,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,   -53,   746,   746,   746,   746,   746,  -203,  -203,
      77,    39,   -49,     6,  -203,   343,  -203,     8,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,    39,    48,    48,  -203,
     414,  -203,   -53,   746,    35,  -203,    48,  -203,   128,  -203,
    -203,  -203,   112,  -203,  -203,  -203,  -203,    92,    92,   587,
     503,    11,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,   -25,   193,   604,  -203,    75,    45,   111,   -28,   148,
      60,    69,    44,   151,   -39,  -203,  -203,  -203,  -203,   306,
    -203,    94,   113,   705,   503,  -203,  -203,   503,  -203,  -203,
     -10,   275,  -203,   275,   140,   604,   219,   -38,  -203,   414,
     -50,  -203,   219,  -203,  -203,   604,   604,   219,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,   604,
    -203,  -203,   604,   604,   604,   604,   604,   604,   604,   604,
     604,   604,   604,   604,   604,   604,   604,   604,   604,   604,
     604,   604,   138,   157,   160,   162,   529,   163,   219,   145,
     146,   604,   149,   147,  -203,  -203,  -203,  -203,   306,   168,
    -203,  -203,   154,  -203,  -203,  -203,  -203,    39,   121,   630,
    -203,   -34,   173,   155,  -203,   156,   188,   189,   190,  -203,
     604,  -203,  -203,  -203,   545,  -203,   194,  -203,  -203,    38,
    -203,  -203,  -203,  -203,   -41,   171,   198,  -203,  -203,  -203,
    -203,  -203,  -203,    75,    75,    45,    45,   111,   111,   111,
     111,   -28,   -28,   148,    60,    69,    44,   151,   -62,   176,
     529,   604,   604,   604,   233,   428,   182,  -203,  -203,   183,
     529,  -203,  -203,  -203,   604,   604,   204,  -203,   205,  -203,
    -203,   725,   219,  -203,   203,   203,  -203,    11,  -203,  -203,
    -203,   414,  -203,   604,  -203,   604,   529,  -203,    -8,    -1,
       0,   206,   604,   191,  -203,  -203,  -203,   208,   209,  -203,
    -203,  -203,  -203,  -203,   -27,  -203,  -203,  -203,  -203,   529,
     529,   529,   604,   192,   604,  -203,  -203,  -203,    40,   244,
    -203,  -203,     1,   604,   195,  -203,   529,   196,   215,   604,
    -203,  -203,   529,   216,  -203,   529,  -203
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,    99,   100,   102,   103,   101,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   118,   119,   120,
     121,   195,   134,    91,    91,    91,    91,   201,   192,   194,
       0,   138,    94,     0,    92,    96,   133,     0,    90,    86,
      87,    88,    89,   193,     1,   135,   137,   131,   134,    85,
       0,   197,   134,   199,     0,     2,   134,   123,   122,   136,
     132,    93,    96,     3,     4,     5,     8,     0,     0,     0,
       0,   157,    29,    31,    32,    30,    33,    34,     6,     7,
      10,    23,    35,     0,    37,    41,    44,    47,    52,    55,
      57,    59,    61,    63,    65,    67,   150,    97,   198,   175,
     196,     0,   138,   148,     0,    24,    25,     0,    27,    82,
       0,   117,   149,   117,     0,     0,     0,     0,   156,     0,
       0,   158,     0,    15,    16,     0,    22,     0,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    71,     0,
      35,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,   180,     6,   179,   176,   177,   162,   163,   174,     0,
     172,   164,     0,   165,   166,   167,   124,   138,   137,    70,
     145,   134,     0,   139,   141,   147,     0,     0,     0,     9,
       0,   116,   114,   115,     0,    84,     0,   161,   151,   157,
     153,   155,   159,    14,     0,    21,     0,    19,    13,    68,
      38,    39,    40,    42,    43,    45,    46,    51,    50,    48,
      49,    53,    54,    56,    58,    60,    62,    64,     0,     0,
     180,     0,     0,     0,     0,   180,     0,   189,   190,     0,
     180,   173,   171,   178,     0,     0,    30,    69,     0,   143,
     129,     0,     0,   130,     0,    28,    83,   157,    36,   160,
     152,     0,    11,     0,    12,     0,   180,   170,     0,     0,
       0,     0,   180,     0,   188,   191,   168,     0,     0,   128,
     125,   140,   142,   146,     0,   154,    20,    66,   169,   180,
     180,   180,     0,     0,   180,   126,   127,    17,   157,   181,
     183,   184,     0,   180,     0,    18,   180,     0,     0,   180,
     182,   185,   180,     0,   187,   180,   186
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,   -37,  -203,  -203,  -203,  -203,  -203,    33,  -203,   -71,
      66,    67,    55,    64,   150,   178,   181,   144,   212,  -203,
    -112,   -45,  -203,  -203,   -69,   142,   -29,     4,    88,  -203,
    -203,   256,  -203,   -56,    29,   234,    13,  -203,   -20,  -203,
     259,  -203,   270,   -94,  -203,  -203,    46,  -203,  -203,    21,
    -110,   107,  -203,  -202,  -203,   257,   -80,  -203,   322,  -203,
    -203,   207,  -203,  -161,  -203,  -203,  -203,  -203,   357,  -203,
    -203,  -203,  -203
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    78,    79,    80,    81,   215,   216,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,   109,   258,   139,   173,   206,    21,    52,    39,    32,
      33,    34,    23,    24,   112,   202,    25,    26,    62,    58,
      36,    37,    46,    47,   192,   193,   194,   195,   196,   114,
      97,   117,   118,   119,   120,   121,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    27,    28,    29,
      53,    54,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   110,    35,   205,    22,    96,    51,   271,   189,   210,
     249,    55,   141,   159,   111,   115,   122,   123,   124,   149,
     150,   116,    31,   275,    98,   272,   200,    38,    38,    38,
      38,    22,   208,   -95,  -144,   110,   101,   211,   110,    48,
     125,    31,   126,   307,    45,   160,   127,   200,   111,   205,
     209,   111,   151,   152,  -144,   111,   214,   111,   199,    59,
     299,   308,   172,    17,    18,    19,   190,   300,   301,   317,
     174,   220,   221,   222,    96,    56,   115,    44,   200,   207,
     200,   217,   116,   113,   283,   213,   244,   200,   200,   200,
     218,   238,    49,   254,   219,    55,    63,    64,    65,    66,
     105,   106,   108,   115,    99,   115,   271,   191,   270,   116,
     315,   116,    40,    41,    42,    45,   140,   113,   145,   146,
     113,   303,   187,    31,   113,   197,   113,   157,   198,   172,
     255,   246,   155,   268,    67,    68,    69,    17,    18,    19,
     201,   172,   201,   314,   257,    17,    18,    19,   140,   174,
     142,   156,   318,   143,   144,   266,   147,   148,   323,   104,
     277,   295,   186,   297,    72,    73,    74,    75,    76,    77,
     286,   259,   278,   279,   280,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   102,   140,   103,   298,   153,   154,    50,
      45,    59,   158,   172,   227,   228,   229,   230,   204,   287,
     288,   223,   224,   172,   225,   226,   282,   231,   232,   309,
     310,   311,    55,   240,   241,   293,    96,   242,   296,   243,
     245,   247,   248,   312,   250,   200,   320,   140,   252,   172,
     253,   260,   324,   261,   262,   326,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   263,   264,   265,   273,
     269,   276,   172,   172,   172,   191,   274,   281,   284,   285,
     289,   290,   267,   302,   305,   306,   316,   304,   313,   172,
     138,   319,   321,   322,   325,   172,     4,     5,   172,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   236,   239,    61,   233,    60,   292,   140,    55,
      63,    64,    65,    66,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   234,   161,   162,   163,   235,   164,
     165,   166,   167,   168,   169,   170,   171,   203,    67,    68,
      69,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   237,   188,    70,   294,    99,   100,   212,    72,    73,
      74,    75,    76,    77,    43,   251,     0,     0,     0,     0,
       0,     0,  -180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -200,     0,     0,     0,     0,    55,    63,    64,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    55,    63,    64,    65,    66,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,    71,     0,     0,    72,    73,    74,    75,
      76,    77,     0,     0,     0,    70,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    55,    63,    64,    65,
      66,     0,     0,     0,     4,     5,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,    55,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    68,    69,    55,    63,
      64,    65,    66,     0,     0,     0,     0,     0,   161,   162,
     163,     0,   164,   165,   166,   167,   168,   169,   170,   171,
      70,    67,    68,    69,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,     0,     0,     0,    67,    68,    69,
      55,    63,    64,    65,    66,     0,    70,     0,    99,     0,
       0,    72,    73,    74,    75,    76,    77,    55,    63,    64,
      65,    66,    70,     0,   267,     0,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,    55,    63,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,     0,     0,     0,     0,     0,
       0,    70,    67,    68,    69,     0,    72,    73,    74,    75,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,     0,    72,    73,    74,   256,    76,    77,    55,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   291,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
      37,    70,    22,   115,     0,    50,    35,   209,   102,   119,
     171,     3,    83,    52,    70,    65,    41,    42,    43,    47,
      48,    71,    75,    85,    53,    66,    88,    23,    24,    25,
      26,    27,    70,    86,    68,   104,    56,    87,   107,    88,
      65,    75,    67,    70,    31,    84,    71,    88,   104,   161,
      88,   107,    80,    81,    88,   111,   125,   113,    68,    46,
      68,    88,    99,    24,    25,    26,   103,    68,    68,    68,
      99,   142,   143,   144,   119,    67,    65,     0,    88,   116,
      88,   126,    71,    70,   245,   122,   166,    88,    88,    88,
     127,   160,    86,   187,   139,     3,     4,     5,     6,     7,
      67,    68,    69,    65,    69,    65,   308,   103,    70,    71,
      70,    71,    24,    25,    26,   102,    83,   104,    73,    74,
     107,   282,     9,    75,   111,   104,   113,    83,   107,   166,
       9,   168,    72,   204,    42,    43,    44,    24,    25,    26,
     111,   178,   113,   304,   189,    24,    25,    26,   115,   178,
      75,    82,   313,    78,    79,   200,    45,    46,   319,    67,
     240,   271,    68,   275,    72,    73,    74,    75,    76,    77,
     250,   191,   241,   242,   243,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    65,   161,    67,   276,    49,    50,    87,
     187,   188,    51,   240,   149,   150,   151,   152,    68,   254,
     255,   145,   146,   250,   147,   148,   245,   153,   154,   299,
     300,   301,     3,    85,    67,   262,   271,    67,   273,    67,
      67,    86,    86,   302,    85,    88,   316,   204,    70,   276,
      86,    68,   322,    88,    88,   325,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    68,    68,    68,    88,
      66,    85,   299,   300,   301,   261,    68,    34,    86,    86,
      66,    66,    69,    67,    66,    66,    32,    86,    86,   316,
      87,    86,    86,    68,    68,   322,    11,    12,   325,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   158,   161,    48,   155,    47,   261,   275,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   156,    29,    30,    31,   157,    33,
      34,    35,    36,    37,    38,    39,    40,   113,    42,    43,
      44,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   159,   102,    67,   267,    69,    54,   120,    72,    73,
      74,    75,    76,    77,    27,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      67,    42,    43,    44,    -1,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
       3,     4,     5,     6,     7,    -1,    67,    -1,    69,    -1,
      -1,    72,    73,    74,    75,    76,    77,     3,     4,     5,
       6,     7,    67,    -1,    69,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    42,    43,    44,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,     3,    -1,
      -1,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   115,   116,   121,   122,   125,   126,   156,   157,   158,
     161,    75,   118,   119,   120,   127,   129,   130,   116,   117,
     117,   117,   117,   157,     0,   125,   131,   132,    88,    86,
      87,   115,   116,   159,   160,     3,    67,    90,   128,   125,
     129,   120,   127,     4,     5,     6,     7,    42,    43,    44,
      67,    69,    72,    73,    74,    75,    76,    77,    90,    91,
      92,    93,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   139,   115,    69,
     147,   127,    65,    67,    67,    96,    96,    67,    96,   110,
     113,   122,   123,   125,   138,    65,    71,   140,   141,   142,
     143,   144,    41,    42,    43,    65,    67,    71,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    87,   112,
      96,    98,    75,    78,    79,    73,    74,    45,    46,    47,
      48,    80,    81,    49,    50,    72,    82,    83,    51,    52,
      84,    29,    30,    31,    33,    34,    35,    36,    37,    38,
      39,    40,    90,   113,   115,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    68,     9,   131,   132,
      90,   116,   133,   134,   135,   136,   137,   138,   138,    68,
      88,   123,   124,   124,    68,   109,   114,    90,    70,    88,
     139,    87,   144,    90,   113,    94,    95,   110,    90,   110,
      98,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     101,   102,   102,   103,   104,   105,   106,   107,   113,   114,
      85,    67,    67,    67,   145,    67,    90,    86,    86,   152,
      85,   150,    70,    86,   132,     9,    75,   110,   111,   127,
      68,    88,    88,    68,    68,    68,   110,    69,    98,    66,
      70,   142,    66,    88,    68,    85,    85,   145,   113,   113,
     113,    34,   115,   152,    86,    86,   145,   110,   110,    66,
      66,    28,   135,    90,   140,   139,   110,   109,   145,    68,
      68,    68,    67,   152,    86,    66,    66,    70,    88,   145,
     145,   145,   113,    86,   152,    70,    32,    68,   152,    86,
     145,    86,    68,   152,   145,    68,   145
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    91,    92,    92,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    98,    98,    99,    99,    99,
      99,   100,   100,   100,   101,   101,   101,   102,   102,   102,
     102,   102,   103,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   114,   115,   116,   116,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     125,   126,   127,   128,   128,   128,   128,   128,   128,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     139,   139,   139,   140,   140,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   145,   145,   145,   145,   146,   146,
     146,   147,   148,   148,   149,   149,   150,   150,   151,   152,
     152,   153,   153,   153,   154,   154,   154,   154,   155,   155,
     155,   155,   156,   156,   157,   157,   158,   159,   159,   160,
     160,   161
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     4,     3,     3,     2,     2,     6,     7,     1,
       3,     1,     0,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     2,     2,     2,     2,
       1,     0,     1,     3,     1,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     0,     1,     1,
       1,     1,     2,     1,     3,     5,     6,     6,     5,     4,
       4,     2,     3,     1,     0,     1,     2,     1,     0,     1,
       3,     1,     3,     2,     1,     1,     3,     1,     0,     1,
       1,     3,     4,     2,     4,     2,     1,     0,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     3,     1,     2,     1,     0,     1,     1,     2,     1,
       0,     5,     7,     5,     5,     7,     9,     8,     3,     2,
       2,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       0,     1
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
  case 2: /* identifier: IDENTIFIER  */
#line 62 "tinyC2.y"
                        {TreeNode* temp[15];(yyval.tnode)=createNode("Identifier","",0,temp);}
#line 1826 "y.tab.c"
    break;

  case 3: /* constant: INTCONST  */
#line 65 "tinyC2.y"
                     {TreeNode* temp[15];TreeNode* icon=createNode("Integer constant","",0,temp);temp[0]=icon;
            (yyval.tnode)=createNode("Constant","",1,temp);
            printf("constant -> integer_constant\n");}
#line 1834 "y.tab.c"
    break;

  case 4: /* constant: FLOATCONST  */
#line 68 "tinyC2.y"
                        {TreeNode* temp[15];TreeNode* fcon=createNode("Floating constant","",0,temp);temp[0]=fcon;
            (yyval.tnode)=createNode("Constant","",1,temp);
            printf("constant -> floating_constant\n");}
#line 1842 "y.tab.c"
    break;

  case 5: /* constant: CHARCONST  */
#line 71 "tinyC2.y"
                        {TreeNode* temp[15];TreeNode* ccon=createNode("Character constant","",0,temp);temp[0]=ccon;
            (yyval.tnode)=createNode("Constant","",1,temp);
            printf("constant -> character_constant\n");}
#line 1850 "y.tab.c"
    break;

  case 6: /* primary_expression: identifier  */
#line 77 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Primary Expression","",1,temp);
            printf("primary_expression -> identifier\n");}
#line 1858 "y.tab.c"
    break;

  case 7: /* primary_expression: constant  */
#line 80 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Primary Expression","",1,temp);
            printf("primary_expression -> constant\n");}
#line 1866 "y.tab.c"
    break;

  case 8: /* primary_expression: STR_LITERAL  */
#line 83 "tinyC2.y"
                        {TreeNode* temp[15];TreeNode* strlt=createNode("String Literal","",0,temp);temp[0]=strlt;
            (yyval.tnode)=createNode("Primary Expression","",1,temp);
            printf("primary_expression -> string_literal\n");}
#line 1874 "y.tab.c"
    break;

  case 9: /* primary_expression: OP_ROUND expression CL_ROUND  */
#line 86 "tinyC2.y"
                                          {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-1].tnode);temp[2]=a2;(yyval.tnode)=createNode("Primary Expression","",3,temp);
            printf("primary_expression -> ( expression ) \n");}
#line 1882 "y.tab.c"
    break;

  case 10: /* postfix_expression: primary_expression  */
#line 92 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Postfix Expression","",1,temp);
            printf("postfix_expression -> primary_expression\n");}
#line 1890 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression OP_SQUARE expression CL_SQUARE  */
#line 95 "tinyC2.y"
                                                                {TreeNode* temp[15];TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);
            temp[0]=(yyvsp[-3].tnode);temp[1]=a1;temp[2]=(yyvsp[-1].tnode);temp[3]=a2;(yyval.tnode)=createNode("Postfix Expression","",4,temp);
            printf("postfix_expression -> postfix_expression [ expression ]\n");}
#line 1898 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression OP_ROUND argument_expression_list_opt CL_ROUND  */
#line 98 "tinyC2.y"
                                                                              {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=(yyvsp[-3].tnode);temp[1]=a1;temp[2]=(yyvsp[-1].tnode);temp[3]=a2;(yyval.tnode)=createNode("Postfix Expression","",4,temp);
            printf("postfix_expression -> postfix_expression ( argument_expression_list_opt ) \n");}
#line 1906 "y.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression DOT identifier  */
#line 101 "tinyC2.y"
                                                {TreeNode* temp[15];TreeNode* a1=createNode(".","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Postfix Expression","",3,temp);
            printf("postfix_expression -> postfix_expression . identifier\n");}
#line 1914 "y.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression IMPLIES identifier  */
#line 104 "tinyC2.y"
                                                   {TreeNode* temp[15];TreeNode* a1=createNode("->","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Postfix Expression","",3,temp);
            printf("postfix_expression -> postfix_expression -> identifier\n");}
#line 1922 "y.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression INCRE  */
#line 107 "tinyC2.y"
                                     {TreeNode* temp[15];TreeNode* a1=createNode("++","",0,temp);
            temp[0]=(yyvsp[-1].tnode);temp[1]=a1;(yyval.tnode)=createNode("Postfix Expression","",2,temp);
            printf("postfix_expression -> postfix_expression ++\n");}
#line 1930 "y.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression DECRE  */
#line 110 "tinyC2.y"
                                     {TreeNode* temp[15];TreeNode* a1=createNode("--","",0,temp);
            temp[0]=(yyvsp[-1].tnode);temp[1]=a1;(yyval.tnode)=createNode("Postfix Expression","",2,temp);
            printf("postfix_expression -> postfix_expression --\n");}
#line 1938 "y.tab.c"
    break;

  case 17: /* postfix_expression: OP_ROUND type_name CL_ROUND OP_CURLY initializer_list CL_CURLY  */
#line 113 "tinyC2.y"
                                                                            {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            TreeNode* a3=createNode("{","",0,temp);TreeNode* a4=createNode("}","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-4].tnode);temp[2]=a2;temp[3]=a3;temp[4]=(yyvsp[-1].tnode);temp[5]=a4;(yyval.tnode)=createNode("Postfix Expression","",6,temp);
            printf("postfix_expression -> ( type_name ) { initializer_list }\n");}
#line 1947 "y.tab.c"
    break;

  case 18: /* postfix_expression: OP_ROUND type_name CL_ROUND OP_CURLY initializer_list COMMA CL_CURLY  */
#line 117 "tinyC2.y"
                                                                                {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            TreeNode* a3=createNode("{","",0,temp);TreeNode* a4=createNode("}","",0,temp);TreeNode* a5=createNode(",","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-5].tnode);temp[2]=a2;temp[3]=a3;temp[4]=(yyvsp[-2].tnode);temp[5]=a5;temp[6]=a4;(yyval.tnode)=createNode("Postfix Expression","",7,temp);
            printf("postfix_expression -> ( type_name ) { initializer_list , }\n");}
#line 1956 "y.tab.c"
    break;

  case 19: /* argument_expression_list: assignment_expression  */
#line 124 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Argument Expression List","",1,temp);
            printf("argument_expression_list -> assignment_expression\n");}
#line 1964 "y.tab.c"
    break;

  case 20: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 127 "tinyC2.y"
                                                                  {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Argument Expression List","",3,temp);
            printf("argument_expression_list -> argument_expression_list , assignment_expression\n");}
#line 1972 "y.tab.c"
    break;

  case 21: /* argument_expression_list_opt: argument_expression_list  */
#line 133 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Argument Expression List(opt)","",1,temp);
            printf("argument_expression_list_opt -> argument_expression_list\n");}
#line 1980 "y.tab.c"
    break;

  case 22: /* argument_expression_list_opt: %empty  */
#line 136 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Argument Expression List(opt)","",1,temp);
            printf("argument_expression_list_opt -> epsilon\n");}
#line 1988 "y.tab.c"
    break;

  case 23: /* unary_expression: postfix_expression  */
#line 142 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Unary Expression","",1,temp);
            printf("unary_expression -> postfix_expression\n");}
#line 1996 "y.tab.c"
    break;

  case 24: /* unary_expression: INCRE unary_expression  */
#line 145 "tinyC2.y"
                                     {TreeNode* temp[15];TreeNode* a1=createNode("++","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Unary Expression","",2,temp);
            printf("unary_expression -> ++ unary_expression\n");}
#line 2004 "y.tab.c"
    break;

  case 25: /* unary_expression: DECRE unary_expression  */
#line 148 "tinyC2.y"
                                     {TreeNode* temp[15];TreeNode* a1=createNode("--","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Unary Expression","",2,temp);
            printf("unary_expression -> -- unary_expression\n");}
#line 2012 "y.tab.c"
    break;

  case 26: /* unary_expression: unary_operator cast_expression  */
#line 151 "tinyC2.y"
                                            {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode);temp[1]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Unary Expression","",2,temp);
            printf("unary_expression -> unary_operator cast_expression\n");}
#line 2020 "y.tab.c"
    break;

  case 27: /* unary_expression: SIZEOF unary_expression  */
#line 154 "tinyC2.y"
                                      {TreeNode* temp[15];TreeNode* a1=createNode("sizeof","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Unary Expression","",2,temp);
            printf("unary_expression -> sizeof unary_expression\n");}
#line 2028 "y.tab.c"
    break;

  case 28: /* unary_expression: SIZEOF OP_ROUND type_name CL_ROUND  */
#line 157 "tinyC2.y"
                                                {TreeNode* temp[15];TreeNode* a1=createNode("sizeof","",0,temp);TreeNode* a2=createNode("(","",0,temp);TreeNode* a3=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=(yyvsp[-1].tnode);temp[3]=a3;(yyval.tnode)=createNode("Unary Expression","",4,temp);
            printf("unary_expression -> sizeof ( type_name )\n");}
#line 2036 "y.tab.c"
    break;

  case 29: /* unary_operator: BIT_AND  */
#line 163 "tinyC2.y"
                    {TreeNode* temp[15];(yyval.tnode)=createNode("Unary operator(&)","&",0,temp);printf("unary_opearator -> &\n");}
#line 2042 "y.tab.c"
    break;

  case 30: /* unary_operator: MUL  */
#line 164 "tinyC2.y"
                {TreeNode* temp[15];(yyval.tnode)=createNode("Unary operator(*)","*",0,temp);printf("unary_operator -> *\n");}
#line 2048 "y.tab.c"
    break;

  case 31: /* unary_operator: PLUS  */
#line 165 "tinyC2.y"
                 {TreeNode* temp[15];(yyval.tnode)=createNode("Unary operator(+)","+",0,temp);printf("unary_operator -> +\n");}
#line 2054 "y.tab.c"
    break;

  case 32: /* unary_operator: MIN  */
#line 166 "tinyC2.y"
                {TreeNode* temp[15];(yyval.tnode)=createNode("Unary operator(-)","-",0,temp);printf("unary_operator -> -\n");}
#line 2060 "y.tab.c"
    break;

  case 33: /* unary_operator: BIT_NOT  */
#line 167 "tinyC2.y"
                    {TreeNode* temp[15];(yyval.tnode)=createNode("Unary operator(~)","~",0,temp);printf("unary_operator -> ~\n");}
#line 2066 "y.tab.c"
    break;

  case 34: /* unary_operator: NOT  */
#line 168 "tinyC2.y"
                {TreeNode* temp[15];(yyval.tnode)=createNode("Unary operator(!)","!",0,temp);printf("unary_operator -> !\n");}
#line 2072 "y.tab.c"
    break;

  case 35: /* cast_expression: unary_expression  */
#line 172 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Cast Expression","",1,temp);
            printf("cast_expression -> unary_expression\n");}
#line 2079 "y.tab.c"
    break;

  case 36: /* cast_expression: OP_ROUND type_name CL_ROUND cast_expression  */
#line 174 "tinyC2.y"
                                                          {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-2].tnode);temp[2]=a2;temp[3]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Cast Expression","",4,temp);
            printf("cast_expression -> ( type_name ) cast_expression\n");}
#line 2087 "y.tab.c"
    break;

  case 37: /* multiplicative_expression: cast_expression  */
#line 180 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Multiplicative Expression","",1,temp);
            printf("multiplicative_expression -> cast_expression\n");}
#line 2094 "y.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression MUL cast_expression  */
#line 182 "tinyC2.y"
                                                        {TreeNode* temp[15];TreeNode* a1=createNode("*","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Multiplicative Expression","",3,temp);
            printf("multiplicative_expression -> multiplicative_expression * cast_expression\n");}
#line 2102 "y.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression DIV cast_expression  */
#line 185 "tinyC2.y"
                                                        {TreeNode* temp[15];TreeNode* a1=createNode("/","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Multiplicative Expression","",3,temp);
            printf("multiplicative_expression -> multiplicative_expression / cast_expression\n");}
#line 2110 "y.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression MOD cast_expression  */
#line 188 "tinyC2.y"
                                                        {TreeNode* temp[15];TreeNode* a1=createNode("%","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Multiplicative Expression","",3,temp);
            printf("multiplicative_expression -> multiplicative_expression %% cast_expression\n");}
#line 2118 "y.tab.c"
    break;

  case 41: /* additive_expression: multiplicative_expression  */
#line 194 "tinyC2.y"
                                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Additive Expression","",1,temp);
            printf("additive_expression -> multiplicative_expression\n");}
#line 2125 "y.tab.c"
    break;

  case 42: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 196 "tinyC2.y"
                                                                 {TreeNode* temp[15];TreeNode* a1=createNode("+","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Additive Expression","",3,temp);
            printf("additive_expression -> additive_expression + multiplicative_expression\n");}
#line 2133 "y.tab.c"
    break;

  case 43: /* additive_expression: additive_expression MIN multiplicative_expression  */
#line 199 "tinyC2.y"
                                                                {TreeNode* temp[15];TreeNode* a1=createNode("-","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Additive Expression","",3,temp);
            printf("additive_expression -> additive_expression - multiplicative_expression\n");}
#line 2141 "y.tab.c"
    break;

  case 44: /* shift_expression: additive_expression  */
#line 205 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Shift Expression","",1,temp);
            printf("shift_expression -> additive_expression\n");}
#line 2148 "y.tab.c"
    break;

  case 45: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 207 "tinyC2.y"
                                                          {TreeNode* temp[15];TreeNode* a1=createNode("<<","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Shift Expression","",3,temp);
            printf("shift_expression -> shift_expression << additive_expression\n");}
#line 2156 "y.tab.c"
    break;

  case 46: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 210 "tinyC2.y"
                                                          {TreeNode* temp[15];TreeNode* a1=createNode(">>","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Shift Expression","",3,temp);
            printf("shift_expression -> shift_expression >> additive_expression\n");}
#line 2164 "y.tab.c"
    break;

  case 47: /* relational_expression: shift_expression  */
#line 216 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Relational Expression","",1,temp);
            printf("relational_expression -> shift_expression\n");}
#line 2171 "y.tab.c"
    break;

  case 48: /* relational_expression: relational_expression LT shift_expression  */
#line 218 "tinyC2.y"
                                                       {TreeNode* temp[15];TreeNode* a1=createNode("<","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Relational Expression","",3,temp);
            printf("relational_expression -> relational_expression < shift_expression\n");}
#line 2179 "y.tab.c"
    break;

  case 49: /* relational_expression: relational_expression GT shift_expression  */
#line 221 "tinyC2.y"
                                                       {TreeNode* temp[15];TreeNode* a1=createNode(">","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Relational Expression","",3,temp);
            printf("relational_expression -> relational_expression > shift_expression\n");}
#line 2187 "y.tab.c"
    break;

  case 50: /* relational_expression: relational_expression LEQ shift_expression  */
#line 224 "tinyC2.y"
                                                       {TreeNode* temp[15];TreeNode* a1=createNode("<=","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Relational Expression","",3,temp);
            printf("relational_expression -> relational_expression <= shift_expression\n");}
#line 2195 "y.tab.c"
    break;

  case 51: /* relational_expression: relational_expression GEQ shift_expression  */
#line 227 "tinyC2.y"
                                                       {TreeNode* temp[15];TreeNode* a1=createNode(">=","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Relational Expression","",3,temp);
            printf("relational_expression -> relational_expression >= shift_expression\n");}
#line 2203 "y.tab.c"
    break;

  case 52: /* equality_expression: relational_expression  */
#line 233 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Equality Expression","",1,temp);
            printf("equality_expression -> realtional_expression\n");}
#line 2210 "y.tab.c"
    break;

  case 53: /* equality_expression: equality_expression EQEQ relational_expression  */
#line 235 "tinyC2.y"
                                                            {TreeNode* temp[15];TreeNode* a1=createNode("==","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Equality Expression","",3,temp);
            printf("equality_expression -> equality_expression == relational_expression\n");}
#line 2218 "y.tab.c"
    break;

  case 54: /* equality_expression: equality_expression NEQ relational_expression  */
#line 238 "tinyC2.y"
                                                           {TreeNode* temp[15];TreeNode* a1=createNode("!=","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Equality Expression","",3,temp);
            printf("equality_expression -> equality_expression != relational_expression\n");}
#line 2226 "y.tab.c"
    break;

  case 55: /* AND_expression: equality_expression  */
#line 244 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("AND Expression","",1,temp);
            printf("AND_expression -> equality_expression\n");}
#line 2233 "y.tab.c"
    break;

  case 56: /* AND_expression: AND_expression BIT_AND equality_expression  */
#line 246 "tinyC2.y"
                                                        {TreeNode* temp[15];TreeNode* a1=createNode("&","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("AND Expression","",3,temp);
            printf("AND_expression -> AND_expression & equality_expression\n");}
#line 2241 "y.tab.c"
    break;

  case 57: /* exclusive_OR_expression: AND_expression  */
#line 252 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Exclusive OR Expression","",1,temp);
            printf("exclusive_OR_expression -> AND_expression\n");}
#line 2248 "y.tab.c"
    break;

  case 58: /* exclusive_OR_expression: exclusive_OR_expression BIT_XOR AND_expression  */
#line 254 "tinyC2.y"
                                                            {TreeNode* temp[15];TreeNode* a1=createNode("^","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Exclusive OR Expression","",3,temp);
            printf("exclusive_OR_expression -> exclusive_OR_expression ^ AND_expression\n");}
#line 2256 "y.tab.c"
    break;

  case 59: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 260 "tinyC2.y"
                                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Inclusive OR Expression","",1,temp);
            printf("inclusive_OR_expression -> exclusive_OR_expression\n");}
#line 2263 "y.tab.c"
    break;

  case 60: /* inclusive_OR_expression: inclusive_OR_expression BIT_OR exclusive_OR_expression  */
#line 262 "tinyC2.y"
                                                                   {TreeNode* temp[15];TreeNode* a1=createNode("|","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Inclusive OR Expression","",3,temp);
            printf("inclusive_OR_expression -> inclusive_OR_expression | exclusive_OR_expression\n");}
#line 2271 "y.tab.c"
    break;

  case 61: /* logical_AND_expression: inclusive_OR_expression  */
#line 268 "tinyC2.y"
                                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Logical AND Expression","",1,temp);
            printf("logical_AND_expression -> inclusive_OR_expression\n");}
#line 2278 "y.tab.c"
    break;

  case 62: /* logical_AND_expression: logical_AND_expression AND inclusive_OR_expression  */
#line 270 "tinyC2.y"
                                                               {TreeNode* temp[15];TreeNode* a1=createNode("&&","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Logical AND Expression","",3,temp);
            printf("logical_AND_expression -> logial_AND_expression && inclusive_OR_expression\n");}
#line 2286 "y.tab.c"
    break;

  case 63: /* logical_OR_expression: logical_AND_expression  */
#line 276 "tinyC2.y"
                                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Logical OR Expression","",1,temp);
            printf("logical_OR_expression -> logical_AND_expression\n");}
#line 2293 "y.tab.c"
    break;

  case 64: /* logical_OR_expression: logical_OR_expression OR logical_AND_expression  */
#line 278 "tinyC2.y"
                                                              {TreeNode* temp[15];TreeNode* a1=createNode("||","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Logical OR Expression","",3,temp);
            printf("logical_OR_expression -> logial_OR_expression || logical_AND_expression\n");}
#line 2301 "y.tab.c"
    break;

  case 65: /* conditional_expression: logical_OR_expression  */
#line 284 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Conditional Expression","",1,temp);
            printf("conditional_expression -> logical_OR_expression\n");}
#line 2308 "y.tab.c"
    break;

  case 66: /* conditional_expression: logical_OR_expression Q_MARK expression COLON conditional_expression  */
#line 286 "tinyC2.y"
                                                                                 {TreeNode* temp[15];TreeNode* a1=createNode("?","",0,temp);
            TreeNode* a2=createNode(":","",0,temp);temp[0]=(yyvsp[-4].tnode);temp[1]=a1;temp[2]=(yyvsp[-2].tnode);temp[3]=a2;temp[4]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Conditional Expression","",5,temp);
            printf("conditional_expression -> logical_OR_expression ? expression : conditional_expression\n");}
#line 2317 "y.tab.c"
    break;

  case 67: /* assignment_expression: conditional_expression  */
#line 293 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Assignment Expression","",1,temp);
            printf("assignment_expression -> conditional_expression\n");}
#line 2324 "y.tab.c"
    break;

  case 68: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 295 "tinyC2.y"
                                                                        {TreeNode* temp[15];temp[0]=(yyvsp[-2].tnode);temp[1]=(yyvsp[-1].tnode);temp[2]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Assignment Expression","",3,temp);
            printf("Assignment_expression -> unary_expression assignment_operator assignment_expression\n");}
#line 2332 "y.tab.c"
    break;

  case 69: /* assignment_expression_opt: assignment_expression  */
#line 301 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Assignment Expression(opt)","",1,temp);
            printf("assignment_expression_opt -> assignment_expression\n");}
#line 2339 "y.tab.c"
    break;

  case 70: /* assignment_expression_opt: %empty  */
#line 303 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Assignment Expression(opt)","",1,temp);
            printf("assignment_expression_opt -> epsilon\n");}
#line 2347 "y.tab.c"
    break;

  case 71: /* assignment_operator: EQ  */
#line 309 "tinyC2.y"
                   {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(=)","=",0,temp);printf("Assignment_operator -> =\n");}
#line 2353 "y.tab.c"
    break;

  case 72: /* assignment_operator: MULEQ  */
#line 310 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(*=)","*=",0,temp);printf("Assignment_operator -> *=\n");}
#line 2359 "y.tab.c"
    break;

  case 73: /* assignment_operator: DIVEQ  */
#line 311 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(/=)","/=",0,temp);printf("Assignment_operator -> /=\n");}
#line 2365 "y.tab.c"
    break;

  case 74: /* assignment_operator: MODEQ  */
#line 312 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(%=)","%=",0,temp);printf("Assignment_operator -> %%=\n");}
#line 2371 "y.tab.c"
    break;

  case 75: /* assignment_operator: ADDEQ  */
#line 313 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(+=)","+=",0,temp);printf("Assignment_operator -> +=\n");}
#line 2377 "y.tab.c"
    break;

  case 76: /* assignment_operator: SUBEQ  */
#line 314 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(-=)","-=",0,temp);printf("Assignment_operator -> -=\n");}
#line 2383 "y.tab.c"
    break;

  case 77: /* assignment_operator: LSHEQ  */
#line 315 "tinyC2.y"
                    {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(<<=)","<<=",0,temp);printf("Assignment_operator -> <<=\n");}
#line 2389 "y.tab.c"
    break;

  case 78: /* assignment_operator: RSHEQ  */
#line 316 "tinyC2.y"
                    {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(>>=)",">>=",0,temp);printf("Assignment_operator -> >>=\n");}
#line 2395 "y.tab.c"
    break;

  case 79: /* assignment_operator: ANDEQ  */
#line 317 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(&=)","&=",0,temp);printf("Assignment_operator -> &=\n");}
#line 2401 "y.tab.c"
    break;

  case 80: /* assignment_operator: XOREQ  */
#line 318 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(^=)","^=",0,temp);printf("Assignment_operator -> ^=\n");}
#line 2407 "y.tab.c"
    break;

  case 81: /* assignment_operator: OREQ  */
#line 319 "tinyC2.y"
                    {TreeNode* temp[15];(yyval.tnode)=createNode("Assignment operator(|=)","|=",0,temp);printf("Assignment_operator -> |=\n");}
#line 2413 "y.tab.c"
    break;

  case 82: /* expression: assignment_expression  */
#line 323 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Expression","",1,temp);
            printf("expression -> assignment_expression\n");}
#line 2420 "y.tab.c"
    break;

  case 83: /* expression: expression COMMA assignment_expression  */
#line 325 "tinyC2.y"
                                                      {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Expression","",3,temp);
            printf("expression -> expression , assignment_expression\n");}
#line 2428 "y.tab.c"
    break;

  case 84: /* constant_expression: conditional_expression  */
#line 331 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Constant Expression","",1,temp);
            printf("constant_expression -> conditional_expression\n");}
#line 2435 "y.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list_opt SEMICOLON  */
#line 337 "tinyC2.y"
                                                                      {TreeNode* temp[15];TreeNode* a1=createNode(";","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=(yyvsp[-1].tnode);temp[2]=a1;(yyval.tnode)=createNode("Declaration","",3,temp);
            printf("declaration -> declaration_specifiers init_declarator_list_opt ;\n");}
#line 2443 "y.tab.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier declaration_specifiers_opt  */
#line 343 "tinyC2.y"
                                                                {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode),temp[1]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Declaration Specifiers","",2,temp);
            printf("declaration_specifiers -> storage_class_specifier declaration_specifiers_opt\n");}
#line 2451 "y.tab.c"
    break;

  case 87: /* declaration_specifiers: type_specifier declaration_specifiers_opt  */
#line 346 "tinyC2.y"
                                                        {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode),temp[1]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Declaration Specifiers","",2,temp);
            printf("declaration_specifiers -> type_specifier declaration_specifiers_opt\n");}
#line 2459 "y.tab.c"
    break;

  case 88: /* declaration_specifiers: type_qualifier declaration_specifiers_opt  */
#line 349 "tinyC2.y"
                                                        {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode),temp[1]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Declaration Specifiers","",2,temp);
            printf("declaration_specifiers -> type_qualifier declaration_specifiers_opt\n");}
#line 2467 "y.tab.c"
    break;

  case 89: /* declaration_specifiers: function_specifier declaration_specifiers_opt  */
#line 352 "tinyC2.y"
                                                        {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode),temp[1]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Declaration Specifiers","",2,temp);
            printf("declaration_specifiers -> function_specifier declaration_specifiers_opt\n");}
#line 2475 "y.tab.c"
    break;

  case 90: /* declaration_specifiers_opt: declaration_specifiers  */
#line 358 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Declaration Specifiers(opt)","",1,temp);
            printf("declaration_specifiers_opt -> declaration_specifiers\n");}
#line 2482 "y.tab.c"
    break;

  case 91: /* declaration_specifiers_opt: %empty  */
#line 360 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Declaration Specifiers(opt)","",1,temp);
            printf("declaration_specifiers_opt -> epsilon\n");}
#line 2490 "y.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator  */
#line 366 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Init_Declarator_List","",1,temp);
            printf("init_declarator_list -> init_declarator\n");}
#line 2497 "y.tab.c"
    break;

  case 93: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 368 "tinyC2.y"
                                                      {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Init_Declarator_List","",3,temp);
            printf("init_declarator_list -> init_declarator_list , init_declarator\n");}
#line 2505 "y.tab.c"
    break;

  case 94: /* init_declarator_list_opt: init_declarator_list  */
#line 374 "tinyC2.y"
                                 {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Init_Declarator_List(opt)","",1,temp);
            printf("init_declarator_list_opt -> init_declarator_list\n");}
#line 2512 "y.tab.c"
    break;

  case 95: /* init_declarator_list_opt: %empty  */
#line 376 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Init_Declarator_List(opt)","",1,temp);
            printf("init_declarator_list_opt -> epsilon\n");}
#line 2520 "y.tab.c"
    break;

  case 96: /* init_declarator: declarator  */
#line 382 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Init_Declarator","",1,temp);
            printf("init_declarator -> declarator\n");}
#line 2527 "y.tab.c"
    break;

  case 97: /* init_declarator: declarator EQ initializer  */
#line 384 "tinyC2.y"
                                       {TreeNode* temp[15];TreeNode* a1=createNode("=","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Init_Declarator","",3,temp);
            printf("init_declarator -> declarator = initializer\n");}
#line 2535 "y.tab.c"
    break;

  case 98: /* storage_class_specifier: EXTERN  */
#line 390 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Storage Class Specifier(extern)","extern",0,temp);printf("storage_class_specifier -> extern\n");}
#line 2541 "y.tab.c"
    break;

  case 99: /* storage_class_specifier: STATIC  */
#line 391 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Storage Class Specifier(static)","static",0,temp);printf("storage_class_specifier -> static\n");}
#line 2547 "y.tab.c"
    break;

  case 100: /* storage_class_specifier: AUTO  */
#line 392 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Storage Class Specifier(auto)","auto",0,temp);printf("storage_class_specifier -> auto\n");}
#line 2553 "y.tab.c"
    break;

  case 101: /* storage_class_specifier: REGISTER  */
#line 393 "tinyC2.y"
                      {TreeNode* temp[15];(yyval.tnode)=createNode("Storage Class Specifier(register)","register",0,temp);printf("storage_class_specifier -> register\n");}
#line 2559 "y.tab.c"
    break;

  case 102: /* type_specifier: VOID  */
#line 397 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(void)","void",0,temp);printf("type_specifier -> void\n");}
#line 2565 "y.tab.c"
    break;

  case 103: /* type_specifier: CHAR  */
#line 398 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(char)","char",0,temp);printf("type_specifier -> char\n");}
#line 2571 "y.tab.c"
    break;

  case 104: /* type_specifier: SHORT  */
#line 399 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(short)","short",0,temp);printf("type_specifier -> short\n");}
#line 2577 "y.tab.c"
    break;

  case 105: /* type_specifier: INT  */
#line 400 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(int)","int",0,temp);printf("type_specifier -> int\n");}
#line 2583 "y.tab.c"
    break;

  case 106: /* type_specifier: LONG  */
#line 401 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(long)","long",0,temp);printf("type_specifier -> long\n");}
#line 2589 "y.tab.c"
    break;

  case 107: /* type_specifier: FLOAT  */
#line 402 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(float)","float",0,temp);printf("type_specifier -> float\n");}
#line 2595 "y.tab.c"
    break;

  case 108: /* type_specifier: DOUBLE  */
#line 403 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(double)","double",0,temp);printf("type_specifier -> double\n");}
#line 2601 "y.tab.c"
    break;

  case 109: /* type_specifier: SIGNED  */
#line 404 "tinyC2.y"
                  {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(signed)","signed",0,temp);printf("type_specifier -> signed\n");}
#line 2607 "y.tab.c"
    break;

  case 110: /* type_specifier: UNSIGNED  */
#line 405 "tinyC2.y"
                      {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(unsigned)","unsigned",0,temp);printf("type_specifier -> unsigned\n");}
#line 2613 "y.tab.c"
    break;

  case 111: /* type_specifier: BOOL  */
#line 406 "tinyC2.y"
                 {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(bool)","bool",0,temp);printf("type_specifier -> _Bool\n");}
#line 2619 "y.tab.c"
    break;

  case 112: /* type_specifier: COMPLEX  */
#line 407 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(complex)","complex",0,temp);printf("type_specifier -> _Complex\n");}
#line 2625 "y.tab.c"
    break;

  case 113: /* type_specifier: IMAGINARY  */
#line 408 "tinyC2.y"
                     {TreeNode* temp[15];(yyval.tnode)=createNode("Type Specifier(imaginary)","imaginary",0,temp);printf("type_specifier -> _Imaginary\n");}
#line 2631 "y.tab.c"
    break;

  case 114: /* specifier_qualifier_list: type_specifier specifier_qualifier_list_opt  */
#line 412 "tinyC2.y"
                                                        {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode),temp[1]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Specifier Qualifier List","",2,temp);
            printf("specifier_qualifier_list -> type_specifier specifier_qualifier_list_opt\n");}
#line 2639 "y.tab.c"
    break;

  case 115: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list_opt  */
#line 415 "tinyC2.y"
                                                        {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode),temp[1]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Specifier Qualifier List","",2,temp);
            printf("specifier_qualifier_list -> type_qualifier specifier_qualifier_list_opt\n");}
#line 2647 "y.tab.c"
    break;

  case 116: /* specifier_qualifier_list_opt: specifier_qualifier_list  */
#line 421 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Specifier Qualifier List(opt)","",1,temp);
            printf("specifier_qualifier_list_opt -> specifier_qualifier_list\n");}
#line 2654 "y.tab.c"
    break;

  case 117: /* specifier_qualifier_list_opt: %empty  */
#line 423 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Specifier Qualifier List(opt)","",1,temp);
            printf("specifier_qualifier_list_opt -> epsilon\n");}
#line 2662 "y.tab.c"
    break;

  case 118: /* type_qualifier: CONST  */
#line 429 "tinyC2.y"
                      {TreeNode* temp[15];(yyval.tnode)=createNode("Type Qualifier(const)","const",0,temp);printf("type_qualifier -> const\n");}
#line 2668 "y.tab.c"
    break;

  case 119: /* type_qualifier: RESTRICT  */
#line 430 "tinyC2.y"
                      {TreeNode* temp[15];(yyval.tnode)=createNode("Type Qualifier(restrict)","restrict",0,temp);printf("type_qualifier -> restrict\n");}
#line 2674 "y.tab.c"
    break;

  case 120: /* type_qualifier: VOLATILE  */
#line 431 "tinyC2.y"
                      {TreeNode* temp[15];(yyval.tnode)=createNode("Type Qualifier(volatile)","volatile",0,temp);printf("type_qualifier -> volatile\n");}
#line 2680 "y.tab.c"
    break;

  case 121: /* function_specifier: INLINE  */
#line 435 "tinyC2.y"
                      {TreeNode* temp[15];(yyval.tnode)=createNode("Function Specifier(inline)","inline",0,temp);printf("function_specifier -> inline\n");}
#line 2686 "y.tab.c"
    break;

  case 122: /* declarator: pointer_opt direct_declarator  */
#line 439 "tinyC2.y"
                                            {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode),temp[1]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Declarator","",2,temp);
            printf("declarator -> pointer_opt direct_declarator\n");}
#line 2694 "y.tab.c"
    break;

  case 123: /* direct_declarator: identifier  */
#line 445 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Direct Declarator","",1,temp);
            printf("direct_declarator -> identifier\n");}
#line 2702 "y.tab.c"
    break;

  case 124: /* direct_declarator: OP_ROUND declarator CL_ROUND  */
#line 448 "tinyC2.y"
                                          {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-1].tnode);temp[2]=a2;(yyval.tnode)=createNode("Direct Declarator","",3,temp);
            printf("direct_declarator -> ( declarator ) \n");}
#line 2710 "y.tab.c"
    break;

  case 125: /* direct_declarator: direct_declarator OP_SQUARE type_qualifier_list_opt assignment_expression_opt CL_SQUARE  */
#line 451 "tinyC2.y"
                                                                                                    {TreeNode* temp[15];
            TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);
            temp[0]=(yyvsp[-4].tnode);temp[1]=a1;temp[2]=(yyvsp[-2].tnode);temp[3]=(yyvsp[-1].tnode);temp[4]=a2;(yyval.tnode)=createNode("Direct Declarator","",5,temp);
            printf("direct_declarator -> direct_declarator [ type_qualifier_list_opt assignment_expression_opt ]\n");}
#line 2719 "y.tab.c"
    break;

  case 126: /* direct_declarator: direct_declarator OP_SQUARE STATIC type_qualifier_list_opt assignment_expression CL_SQUARE  */
#line 455 "tinyC2.y"
                                                                                                      {TreeNode* temp[15];
            TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);TreeNode* a3=createNode("static","",0,temp);
            temp[0]=(yyvsp[-5].tnode);temp[1]=a1;temp[2]=a3;temp[3]=(yyvsp[-2].tnode);temp[4]=(yyvsp[-1].tnode);temp[5]=a2;(yyval.tnode)=createNode("Direct Declarator","",6,temp);
            printf("direct_declarator -> direct_declarator [ static type_qualifier_list_opt assignment_expression ]\n");}
#line 2728 "y.tab.c"
    break;

  case 127: /* direct_declarator: direct_declarator OP_SQUARE type_qualifier_list STATIC assignment_expression CL_SQUARE  */
#line 459 "tinyC2.y"
                                                                                                   {TreeNode* temp[15];
            TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);TreeNode* a3=createNode("static","",0,temp);
            temp[0]=(yyvsp[-5].tnode);temp[1]=a1;temp[2]=(yyvsp[-3].tnode);temp[3]=a3;temp[4]=(yyvsp[-1].tnode);temp[5]=a2;(yyval.tnode)=createNode("Direct Declarator","",6,temp);
            printf("direct_declarator -> direct_declarator [ type_qualifier_list static assignment_expression ]\n");}
#line 2737 "y.tab.c"
    break;

  case 128: /* direct_declarator: direct_declarator OP_SQUARE type_qualifier_list_opt MUL CL_SQUARE  */
#line 463 "tinyC2.y"
                                                                                {TreeNode* temp[15];
            TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);TreeNode* a3=createNode("*","",0,temp);
            temp[0]=(yyvsp[-4].tnode);temp[1]=a1;temp[2]=(yyvsp[-2].tnode);temp[3]=a3;temp[4]=a2;(yyval.tnode)=createNode("Direct Declarator","",5,temp);
            printf("direct_declarator -> direct_declarator [ type_qualifier_list_opt * ]\n");}
#line 2746 "y.tab.c"
    break;

  case 129: /* direct_declarator: direct_declarator OP_ROUND parameter_type_list CL_ROUND  */
#line 467 "tinyC2.y"
                                                                      {TreeNode* temp[15];
            TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=(yyvsp[-3].tnode);temp[1]=a1;temp[2]=(yyvsp[-1].tnode);temp[3]=a2;(yyval.tnode)=createNode("Direct Declarator","",4,temp);
            printf("direct_declarator -> direct_declarator ( parameter_type_list )\n");}
#line 2755 "y.tab.c"
    break;

  case 130: /* direct_declarator: direct_declarator OP_ROUND identifier_list_opt CL_ROUND  */
#line 471 "tinyC2.y"
                                                                      {TreeNode* temp[15];
            TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=(yyvsp[-3].tnode);temp[1]=a1;temp[2]=(yyvsp[-1].tnode);temp[3]=a2;(yyval.tnode)=createNode("Direct Declarator","",4,temp);
            printf("direct_declarator -> direct_declarator ( identifier_list_opt )\n");}
#line 2764 "y.tab.c"
    break;

  case 131: /* pointer: MUL type_qualifier_list_opt  */
#line 478 "tinyC2.y"
                                        {TreeNode* temp[15];TreeNode* a1=createNode("*","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Pointer","",2,temp);
            printf("pointer -> * type_qualifier_list_opt");}
#line 2772 "y.tab.c"
    break;

  case 132: /* pointer: MUL type_qualifier_list_opt pointer  */
#line 481 "tinyC2.y"
                                                    {TreeNode* temp[15];TreeNode* a1=createNode("*","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-1].tnode);temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Pointer","",3,temp);
            printf("pointer -> * type_qualifier_list_opt pointer");}
#line 2780 "y.tab.c"
    break;

  case 133: /* pointer_opt: pointer  */
#line 487 "tinyC2.y"
                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Pointer(opt)","",1,temp);
            printf("pointer_opt -> pointer\n");}
#line 2787 "y.tab.c"
    break;

  case 134: /* pointer_opt: %empty  */
#line 489 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Pointer(opt)","",1,temp);
            printf("pointer_opt -> epsilon\n");}
#line 2795 "y.tab.c"
    break;

  case 135: /* type_qualifier_list: type_qualifier  */
#line 495 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Type Qualifier List","",1,temp);
            printf("type_qualifier_list -> type_qualifier\n");}
#line 2802 "y.tab.c"
    break;

  case 136: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 497 "tinyC2.y"
                                                {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode);temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Type Qualifier List","",2,temp);
            printf("type_qualifier_list -> type_qualifier_list type_qualifier\n");}
#line 2809 "y.tab.c"
    break;

  case 137: /* type_qualifier_list_opt: type_qualifier_list  */
#line 502 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Type Qualifier List(opt)","",1,temp);
            printf("type_qualifier_list_opt -> type_qualifier_list\n");}
#line 2816 "y.tab.c"
    break;

  case 138: /* type_qualifier_list_opt: %empty  */
#line 504 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Type Qualifier List(opt)","",1,temp);
            printf("type_qualifier_list_opt -> epsilon\n");}
#line 2824 "y.tab.c"
    break;

  case 139: /* parameter_type_list: parameter_list  */
#line 511 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Parameter Type List","",1,temp);
            printf("parameter_type_list -> parameter_list\n");}
#line 2831 "y.tab.c"
    break;

  case 140: /* parameter_type_list: parameter_list COMMA SO_ON  */
#line 513 "tinyC2.y"
                                          {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);TreeNode* a2=createNode("...","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=a2;(yyval.tnode)=createNode("Parameter Type List","",3,temp);
            printf("parameter_type_list -> parameter_list , ...\n");}
#line 2839 "y.tab.c"
    break;

  case 141: /* parameter_list: parameter_declaration  */
#line 519 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Parameter List","",1,temp);
            printf("parameter_list -> parameter_declaration\n");}
#line 2846 "y.tab.c"
    break;

  case 142: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 521 "tinyC2.y"
                                                      {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Parameter List","",3,temp);
            printf("parameter_list -> parameter_list , parameter_declaration\n");}
#line 2854 "y.tab.c"
    break;

  case 143: /* parameter_declaration: declaration_specifiers declarator  */
#line 527 "tinyC2.y"
                                            {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode);temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Parameter Declaration","",2,temp);
            printf("parameter_declaration -> declaration_specifiers declarator\n");}
#line 2861 "y.tab.c"
    break;

  case 144: /* parameter_declaration: declaration_specifiers  */
#line 529 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Parameter Declaration","",1,temp);
            printf("parameter_declaration -> declaration_specifiers\n");}
#line 2868 "y.tab.c"
    break;

  case 145: /* identifier_list: identifier  */
#line 534 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Identifier List","",1,temp);
            printf("identifier_list -> identifier\n");}
#line 2875 "y.tab.c"
    break;

  case 146: /* identifier_list: identifier_list COMMA identifier  */
#line 536 "tinyC2.y"
                                              {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Identifier List","",3,temp);
            printf("identifier_list -> identifier_list , identifier\n");}
#line 2883 "y.tab.c"
    break;

  case 147: /* identifier_list_opt: identifier_list  */
#line 542 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Identifier List(opt)","",1,temp);
            printf("identifier_list_opt -> identifier_list\n");}
#line 2890 "y.tab.c"
    break;

  case 148: /* identifier_list_opt: %empty  */
#line 544 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Identifier List(opt)","",1,temp);
            printf("identifier_list_opt -> epsilon\n");}
#line 2898 "y.tab.c"
    break;

  case 149: /* type_name: specifier_qualifier_list  */
#line 550 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Type Name","",1,temp);
            printf("type_name -> specifier_qualifier_list\n");}
#line 2905 "y.tab.c"
    break;

  case 150: /* initializer: assignment_expression  */
#line 555 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Initializer","",1,temp);
            printf("initializer -> assignment_expression\n");}
#line 2912 "y.tab.c"
    break;

  case 151: /* initializer: OP_CURLY initializer_list CL_CURLY  */
#line 557 "tinyC2.y"
                                              {TreeNode* temp[15];TreeNode* a1=createNode("{","",0,temp);TreeNode* a2=createNode("}","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-1].tnode);temp[2]=a2;(yyval.tnode)=createNode("Initializer","",3,temp);
            printf("initializer -> { initializer_list }\n");}
#line 2920 "y.tab.c"
    break;

  case 152: /* initializer: OP_CURLY initializer_list COMMA CL_CURLY  */
#line 560 "tinyC2.y"
                                                    {TreeNode* temp[15];TreeNode* a1=createNode("{","",0,temp);TreeNode* a2=createNode("}","",0,temp);
            TreeNode* a3=createNode(",","",0,temp);temp[0]=a1;temp[1]=(yyvsp[-2].tnode);temp[2]=a3;temp[3]=a2;(yyval.tnode)=createNode("Initializer","",4,temp);
            printf("initializer -> { initializer_list , }\n");}
#line 2928 "y.tab.c"
    break;

  case 153: /* initializer_list: designation_opt initializer  */
#line 566 "tinyC2.y"
                                        {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode);temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Initializer List","",2,temp);
            printf("initializer_list -> designation_opt initializer\n");}
#line 2935 "y.tab.c"
    break;

  case 154: /* initializer_list: initializer_list COMMA designation_opt initializer  */
#line 568 "tinyC2.y"
                                                              {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=(yyvsp[-3].tnode);temp[1]=a1;temp[2]=(yyvsp[-1].tnode);temp[3]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Initializer List","",4,temp);
            printf("initializer_list -> initializer_list , designation_opt initializer\n");}
#line 2943 "y.tab.c"
    break;

  case 155: /* designation: designator_list EQ  */
#line 574 "tinyC2.y"
                               {TreeNode* temp[15];TreeNode* a1=createNode("=","",0,temp);
            temp[0]=(yyvsp[-1].tnode);temp[1]=a1;(yyval.tnode)=createNode("Designation","",2,temp);
            printf("designation -> designator_list =\n");}
#line 2951 "y.tab.c"
    break;

  case 156: /* designation_opt: designation  */
#line 580 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Designation(opt)","",1,temp);
            printf("designation_opt -> designation\n");}
#line 2958 "y.tab.c"
    break;

  case 157: /* designation_opt: %empty  */
#line 582 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Designation(opt)","",1,temp);
            printf("designation_opt -> epsilon\n");}
#line 2966 "y.tab.c"
    break;

  case 158: /* designator_list: designator  */
#line 588 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Designator List","",1,temp);
            printf("designator_list -> designator\n");}
#line 2973 "y.tab.c"
    break;

  case 159: /* designator_list: designator_list designator  */
#line 590 "tinyC2.y"
                                        {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode);temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Designator List","",2,temp);
            printf("designator_list -> designator_list designator\n");}
#line 2980 "y.tab.c"
    break;

  case 160: /* designator: OP_SQUARE constant_expression CL_SQUARE  */
#line 595 "tinyC2.y"
                                                    {TreeNode* temp[15];TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-1].tnode);temp[2]=a2;(yyval.tnode)=createNode("Designator","",3,temp);
            printf("designator -> [ constant_expression ]\n");}
#line 2988 "y.tab.c"
    break;

  case 161: /* designator: DOT identifier  */
#line 598 "tinyC2.y"
                            {TreeNode* temp[15];TreeNode* a1=createNode(".","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Designator","",1,temp);
            printf("designator -> . identifier\n");}
#line 2996 "y.tab.c"
    break;

  case 162: /* statement: labeled_statement  */
#line 605 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Statement","",1,temp);
            printf("statement -> labeled_statement\n");}
#line 3003 "y.tab.c"
    break;

  case 163: /* statement: compound_statement  */
#line 607 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Statement","",1,temp);
            printf("statement -> compound_statement\n");}
#line 3010 "y.tab.c"
    break;

  case 164: /* statement: expression_statement  */
#line 609 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Statement","",1,temp);
            printf("statement -> expression_statement\n");}
#line 3017 "y.tab.c"
    break;

  case 165: /* statement: selection_statement  */
#line 611 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Statement","",1,temp);
            printf("statement -> selection_statement\n");}
#line 3024 "y.tab.c"
    break;

  case 166: /* statement: iteration_statement  */
#line 613 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Statement","",1,temp);
            printf("statement -> iteration_statement\n");}
#line 3031 "y.tab.c"
    break;

  case 167: /* statement: jump_statement  */
#line 615 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Statement","",1,temp);
            printf("statement -> jump_statement\n");}
#line 3038 "y.tab.c"
    break;

  case 168: /* labeled_statement: identifier COLON statement  */
#line 620 "tinyC2.y"
                                          {TreeNode* temp[15];TreeNode* a1=createNode(":","",0,temp);
            temp[0]=(yyvsp[-2].tnode);temp[1]=a1;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Labeled Statement","",3,temp);
            printf("labeled_statement -> identifier : statement\n");}
#line 3046 "y.tab.c"
    break;

  case 169: /* labeled_statement: CASE constant_expression COLON statement  */
#line 623 "tinyC2.y"
                                                        {TreeNode* temp[15];TreeNode* a1=createNode("case","",0,temp);TreeNode* a2=createNode(":","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-2].tnode);temp[2]=a2;temp[3]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Labeled Statement","",4,temp);
            printf("labeled_statement -> case constant_expression : statement\n");}
#line 3054 "y.tab.c"
    break;

  case 170: /* labeled_statement: DEFAULT COLON statement  */
#line 626 "tinyC2.y"
                                    {TreeNode* temp[15];TreeNode* a1=createNode("default","",0,temp);TreeNode* a2=createNode(":","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Labeled Statement","",3,temp);
            printf("labeled_statement -> default : statement\n");}
#line 3062 "y.tab.c"
    break;

  case 171: /* compound_statement: OP_CURLY block_item_list_opt CL_CURLY  */
#line 632 "tinyC2.y"
                                                  {TreeNode* temp[15];TreeNode* a1=createNode("{","",0,temp);TreeNode* a2=createNode("}","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-1].tnode);temp[2]=a2;(yyval.tnode)=createNode("Compound Statement","",3,temp);
            printf("compound_statement -> { block_item_list_opt }\n");}
#line 3070 "y.tab.c"
    break;

  case 172: /* block_item_list: block_item  */
#line 638 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Block Item List","",1,temp);
            printf("block_item_list -> block_item\n");}
#line 3077 "y.tab.c"
    break;

  case 173: /* block_item_list: block_item_list block_item  */
#line 640 "tinyC2.y"
                                        {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode);temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Block Item List","",2,temp);
            printf("block_item_list -> block_item_list block_item\n");}
#line 3084 "y.tab.c"
    break;

  case 174: /* block_item_list_opt: block_item_list  */
#line 645 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Block Item List(opt)","",1,temp);
            printf("block_item_list_opt -> block_item_list\n");}
#line 3091 "y.tab.c"
    break;

  case 175: /* block_item_list_opt: %empty  */
#line 647 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Block Item List(opt)","",1,temp);
            printf("block_item_list_opt -> epsilon\n");}
#line 3099 "y.tab.c"
    break;

  case 176: /* block_item: declaration  */
#line 653 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Block Item","",1,temp);
            printf("block_item -> declaration\n");}
#line 3106 "y.tab.c"
    break;

  case 177: /* block_item: statement  */
#line 655 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Block Item","",1,temp);
            printf("block_item -> statement\n");}
#line 3113 "y.tab.c"
    break;

  case 178: /* expression_statement: expression_opt SEMICOLON  */
#line 660 "tinyC2.y"
                                      {TreeNode* temp[15];TreeNode* a1=createNode(";","",0,temp);
            temp[0]=(yyvsp[-1].tnode);temp[1]=a1;(yyval.tnode)=createNode("Expression Statement","",2,temp);
            printf("expression_statement -> expression_opt ;\n");}
#line 3121 "y.tab.c"
    break;

  case 179: /* expression_opt: expression  */
#line 666 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Expression(opt)","",1,temp);
            printf("expression_opt -> expression\n");}
#line 3128 "y.tab.c"
    break;

  case 180: /* expression_opt: %empty  */
#line 668 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Expression(opt)","",1,temp);
            printf("expression_opt -> epsilon\n");}
#line 3136 "y.tab.c"
    break;

  case 181: /* selection_statement: IF OP_ROUND expression CL_ROUND statement  */
#line 674 "tinyC2.y"
                                                        {TreeNode* temp[15];TreeNode* a1=createNode("if","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(")","",0,temp);temp[0]=a1;temp[1]=a2;temp[2]=(yyvsp[-2].tnode);temp[3]=a3;temp[4]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Selection Statement","",5,temp);
            printf("selection_statement -> if ( expression ) statement\n");}
#line 3145 "y.tab.c"
    break;

  case 182: /* selection_statement: IF OP_ROUND expression CL_ROUND statement ELSE statement  */
#line 678 "tinyC2.y"
                                                                      {TreeNode* temp[15];TreeNode* a1=createNode("if","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(")","",0,temp);TreeNode* a4=createNode("else","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=(yyvsp[-4].tnode);temp[3]=a3;temp[4]=(yyvsp[-2].tnode);temp[5]=a4;temp[6]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Selection Statement","",7,temp);
            printf("selection_statement -> if ( expression ) statement else statement\n");}
#line 3155 "y.tab.c"
    break;

  case 183: /* selection_statement: SWITCH OP_ROUND expression CL_ROUND statement  */
#line 683 "tinyC2.y"
                                                            {TreeNode* temp[15];TreeNode* a1=createNode("switch","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(")","",0,temp);temp[0]=a1;temp[1]=a2;temp[2]=(yyvsp[-2].tnode);temp[3]=a3;temp[4]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Selection Statement","",5,temp);
            printf("selection_statement -> switch ( expression ) statement\n");}
#line 3164 "y.tab.c"
    break;

  case 184: /* iteration_statement: WHILE OP_ROUND expression CL_ROUND statement  */
#line 690 "tinyC2.y"
                                                        {TreeNode* temp[15];TreeNode* a1=createNode("while","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(")","",0,temp);temp[0]=a1;temp[1]=a2;temp[2]=(yyvsp[-2].tnode);temp[3]=a3;temp[4]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Iteration Statement","",5,temp);
            printf("iteration_statement -> while ( expression ) statement\n");}
#line 3173 "y.tab.c"
    break;

  case 185: /* iteration_statement: DO statement WHILE OP_ROUND expression CL_ROUND SEMICOLON  */
#line 694 "tinyC2.y"
                                                                      {TreeNode* temp[15];TreeNode* a1=createNode("do","",0,temp);TreeNode* a2=createNode("while","",0,temp);
            TreeNode* a3=createNode("(","",0,temp);TreeNode* a4=createNode(")","",0,temp);TreeNode* a5=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-5].tnode);temp[2]=a2;temp[3]=a3;temp[4]=(yyvsp[-2].tnode);temp[5]=a4;temp[6]=a5;
            (yyval.tnode)=createNode("Iteration Statement","",7,temp);
            printf("iteration_statement -> do statement while ( expression ) ;\n");}
#line 3183 "y.tab.c"
    break;

  case 186: /* iteration_statement: FOR OP_ROUND expression_opt SEMICOLON expression_opt SEMICOLON expression_opt CL_ROUND statement  */
#line 699 "tinyC2.y"
                                                                                                            {TreeNode* temp[15];TreeNode* a1=createNode("for","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(";","",0,temp);TreeNode* a4=createNode(";","",0,temp);TreeNode* a5=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=(yyvsp[-6].tnode);temp[3]=a3;temp[4]=(yyvsp[-4].tnode);temp[5]=a4;temp[6]=(yyvsp[-2].tnode);temp[7]=a5;temp[8]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Iteration Statement","",9,temp);
            printf("iteration_statement -> for ( expression_opt ; expression_opt ; expression_opt ) statement\n");
            }
#line 3194 "y.tab.c"
    break;

  case 187: /* iteration_statement: FOR OP_ROUND declaration expression_opt SEMICOLON expression_opt CL_ROUND statement  */
#line 705 "tinyC2.y"
                                                                                              {TreeNode* temp[15];TreeNode* a1=createNode("for","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(";","",0,temp);TreeNode* a4=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=(yyvsp[-5].tnode);temp[3]=(yyvsp[-4].tnode);temp[4]=a3;temp[5]=(yyvsp[-2].tnode);temp[6]=a4;temp[7]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Iteration Statement","",8,temp);
            printf("iteration_statement -> for ( declaration expression_opt ; expression_opt ) statement\n");
            }
#line 3205 "y.tab.c"
    break;

  case 188: /* jump_statement: GOTO identifier SEMICOLON  */
#line 714 "tinyC2.y"
                                          {TreeNode* temp[15];TreeNode* a1=createNode("goto","",0,temp);TreeNode* a2=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-1].tnode);temp[2]=a2;(yyval.tnode)=createNode("Jump Statement","",3,temp);
            printf("jump_statement -> goto identifier ;\n");}
#line 3213 "y.tab.c"
    break;

  case 189: /* jump_statement: CONTINUE SEMICOLON  */
#line 717 "tinyC2.y"
                                 {TreeNode* temp[15];TreeNode* a1=createNode("continue","",0,temp);TreeNode* a2=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=a2;(yyval.tnode)=createNode("Jump Statement","",2,temp);
            printf("jump_statement -> continue ;\n");}
#line 3221 "y.tab.c"
    break;

  case 190: /* jump_statement: BREAK SEMICOLON  */
#line 720 "tinyC2.y"
                                {TreeNode* temp[15];TreeNode* a1=createNode("break","",0,temp);TreeNode* a2=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=a2;(yyval.tnode)=createNode("Jump Statement","",2,temp);
            printf("jump_statement -> break ;\n");}
#line 3229 "y.tab.c"
    break;

  case 191: /* jump_statement: RETURN expression_opt SEMICOLON  */
#line 723 "tinyC2.y"
                                            {TreeNode* temp[15];TreeNode* a1=createNode("return","",0,temp);TreeNode* a2=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=(yyvsp[-1].tnode);temp[2]=a2;(yyval.tnode)=createNode("Jump Statement","",3,temp);
            printf("jump_statement -> return expression_opt ;\n");}
#line 3237 "y.tab.c"
    break;

  case 192: /* translation_unit: external_declaration  */
#line 730 "tinyC2.y"
                                    {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Translation Unit","",1,temp);root=(yyval.tnode);
            printf("translation_unit -> external_declaration\n");}
#line 3244 "y.tab.c"
    break;

  case 193: /* translation_unit: translation_unit external_declaration  */
#line 732 "tinyC2.y"
                                                    {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode);temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Translation Unit","",2,temp);root==(yyval.tnode);
            printf("translation_unit -> translation_unit external_declaration\n");}
#line 3251 "y.tab.c"
    break;

  case 194: /* external_declaration: function_definition  */
#line 737 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("External Declaration","",1,temp);
            printf("external_declaration -> function_definition\n");}
#line 3258 "y.tab.c"
    break;

  case 195: /* external_declaration: declaration  */
#line 739 "tinyC2.y"
                        {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("External Declaration","",1,temp);
            printf("external_declaration -> declaration\n");}
#line 3265 "y.tab.c"
    break;

  case 196: /* function_definition: declaration_specifiers declarator declaration_list_opt compound_statement  */
#line 744 "tinyC2.y"
                                                                                        {TreeNode* temp[15];temp[0]=(yyvsp[-3].tnode);temp[1]=(yyvsp[-2].tnode);temp[2]=(yyvsp[-1].tnode);temp[3]=(yyvsp[0].tnode);
            (yyval.tnode)=createNode("Function Definition","",4,temp);
            printf("function_definition -> declaration_specifiers declarator declaration_list_opt compound_statement\n");}
#line 3273 "y.tab.c"
    break;

  case 197: /* declaration_list: declaration  */
#line 750 "tinyC2.y"
                            {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Declaration List","",1,temp);
            printf("declaration_list -> declaration\n");}
#line 3280 "y.tab.c"
    break;

  case 198: /* declaration_list: declaration_list declaration  */
#line 752 "tinyC2.y"
                                            {TreeNode* temp[15];temp[0]=(yyvsp[-1].tnode);temp[1]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Declaration List","",2,temp);
            printf("declaration_list -> declaration_list declaration\n");}
#line 3287 "y.tab.c"
    break;

  case 199: /* declaration_list_opt: declaration_list  */
#line 757 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Declaration List(opt)","",1,temp);
            printf("declaration_list_opt -> declaration_list\n");}
#line 3294 "y.tab.c"
    break;

  case 200: /* declaration_list_opt: %empty  */
#line 759 "tinyC2.y"
          {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            (yyval.tnode)=createNode("Declaration List(opt)","",1,temp);
            printf("declaration_list_opt -> epsilon\n");}
#line 3302 "y.tab.c"
    break;

  case 201: /* program: translation_unit  */
#line 765 "tinyC2.y"
                                {TreeNode* temp[15];temp[0]=(yyvsp[0].tnode);(yyval.tnode)=createNode("Program","",1,temp);root=(yyval.tnode);
            printf("program -> translation_unit\n");}
#line 3309 "y.tab.c"
    break;


#line 3313 "y.tab.c"

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

#line 767 "tinyC2.y"



