%{
    #define KEYWORD     1
    #define IDENTIFIER  2
    #define INTCONST    3
    #define FLOATCONST  4
    #define CHARCONST   5
    #define STR_LITERAL 6
    #define PUNCT       7
    #define SINGCOMM    8
    #define MULTCOMM    9
%}

space                   [ \t\n]
keyword                 "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"
digit                   [0-9]
identifier_nondigit     [a-zA-Z_]
identifier              {identifier_nondigit}({identifier_nondigit}|{digit})*
integer_constant        {digit}+
sign                    [+-]
digit_sequence          {digit}+
exponent_part           [Ee]{sign}?{digit_sequence}
fractional_constant     ({digit_sequence}?\.{digit_sequence})|({digit_sequence}\.)
floating_constant       ({fractional_constant}{exponent_part}?)|({digit_sequence}{exponent_part})
escape_sequence         "\'"|"\""|"\?"|"\\"|"\a"|"\b"|"\f"|"\n"|"\r"|"\t"|"\v"
c_char                  [^("\'"|"\\"|"\n")]|{escape_sequence}
character_constant      "\'"{c_char}"\'"
constant                {integer_constant}|{floating_constant}|{character_constant}
s_char                  [^("\""|"\\"|"\n")]|{escape_sequence}
s_char_sequence         {s_char}+
string_literal          "\""{s_char_sequence}?"\""
punctuator              "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"
multi_line_comment      [/][*]([^*]|[*][^/])*[*][/]
single_line_comment     [/][/][^\n]*

%%

{single_line_comment}       {return SINGCOMM;}
{multi_line_comment}        {return MULTCOMM;}
{keyword}                   {return KEYWORD;}
{identifier}                {return IDENTIFIER;}
{integer_constant}          {return INTCONST;}
{floating_constant}         {return FLOATCONST;}
{character_constant}        {return CHARCONST;}
{string_literal}            {return STR_LITERAL;}
{punctuator}                {return PUNCT;}
{space}                     { }


%%