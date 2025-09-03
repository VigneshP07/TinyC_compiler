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

#ifndef YY_YY_TINYC3_TAB_H_INCLUDED
# define YY_YY_TINYC3_TAB_H_INCLUDED
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
    ENUM = 296,                    /* ENUM  */
    ERROR = 297,                   /* ERROR  */
    IMPLIES = 298,                 /* IMPLIES  */
    INCRE = 299,                   /* INCRE  */
    DECRE = 300,                   /* DECRE  */
    SIZEOF = 301,                  /* SIZEOF  */
    LSHIFT = 302,                  /* LSHIFT  */
    RSHIFT = 303,                  /* RSHIFT  */
    GEQ = 304,                     /* GEQ  */
    LEQ = 305,                     /* LEQ  */
    EQEQ = 306,                    /* EQEQ  */
    NEQ = 307,                     /* NEQ  */
    AND = 308,                     /* AND  */
    OR = 309,                      /* OR  */
    MULEQ = 310,                   /* MULEQ  */
    DIVEQ = 311,                   /* DIVEQ  */
    MODEQ = 312,                   /* MODEQ  */
    ADDEQ = 313,                   /* ADDEQ  */
    SUBEQ = 314,                   /* SUBEQ  */
    LSHEQ = 315,                   /* LSHEQ  */
    RSHEQ = 316,                   /* RSHEQ  */
    ANDEQ = 317,                   /* ANDEQ  */
    XOREQ = 318,                   /* XOREQ  */
    OREQ = 319,                    /* OREQ  */
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
    COMMA = 343,                   /* COMMA  */
    LOWER_THAN_ELSE = 344          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "tinyC3.y"

    symbol* pointer;    //for identifiers
    int intconst;   //for integer constants
    float floatconst;   //for float constants
    char* strconst;     //for char and string constants

    expression* expr;   //for expressions
    array_type* Array;  //for arrays
    int numParams;  //for functions
    char unaryOp;   //for unary operations
    data_type* ptr; //for datatypes
    int instr;  //for instrction type non terminals
    statement* stmt;    //for statement type non terminals

#line 168 "tinyC3.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TINYC3_TAB_H_INCLUDED  */
