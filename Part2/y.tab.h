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

#line 250 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
