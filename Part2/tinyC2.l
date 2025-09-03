%{
    #include "y.tab.h"
    void yyerror(char* s);
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
"("                         {return OP_ROUND;}
")"                         {return CL_ROUND;}
"{"                         {return OP_CURLY;}
"}"                         {return CL_CURLY;}
"["                         {return OP_SQUARE;}
"]"                         {return CL_SQUARE;}
"."                         {return DOT;}
"&"                         {return BIT_AND;}
"*"                         {return MUL;}
"+"                         {return PLUS;}
"-"                         {return MIN;}
"~"                         {return BIT_NOT;}
"!"                         {return NOT;}
"/"                         {return DIV;}
"%"                         {return MOD;}
"<"                         {return LT;}
">"                         {return GT;}
"^"                         {return BIT_XOR;}
"|"                         {return BIT_OR;}
"?"                         {return Q_MARK;}
":"                         {return COLON;}
";"                         {return SEMICOLON;}
"="                         {return EQ;}
","                         {return COMMA;}
"->"                        {return IMPLIES;}
"++"                        {return INCRE;}
"--"                        {return DECRE;}
"sizeof"                    {return SIZEOF;}
"<<"                        {return LSHIFT;}
">>"                        {return RSHIFT;}
"<="                        {return LEQ;}
">="                        {return GEQ;}
"=="                        {return EQEQ;}
"!="                        {return NEQ;}
"&&"                        {return AND;}
"||"                        {return OR;}
"*="                        {return MULEQ;}
"/="                        {return DIVEQ;}
"%="                        {return MODEQ;}
"+="                        {return ADDEQ;}
"-="                        {return SUBEQ;}
"<<="                       {return LSHEQ;}
">>="                       {return RSHEQ;}
"&="                        {return ANDEQ;}
"^="                        {return XOREQ;}
"|="                        {return OREQ;}
"extern"                    {return EXTERN;}
"static"                    {return STATIC;}
"auto"                      {return AUTO;}
"register"                  {return REGISTER;}
"void"                      {return VOID;}
"char"                      {return CHAR;}
"short"                     {return SHORT;}
"int"                       {return INT;}
"long"                      {return LONG;}
"float"                     {return FLOAT;}
"double"                    {return DOUBLE;}
"signed"                    {return SIGNED;}
"unsigned"                  {return UNSIGNED;}
"_Bool"                     {return BOOL;}
"_Complex"                  {return COMPLEX;}
"_Imaginary"                {return IMAGINARY;}
"const"                     {return CONST;}
"volatile"                  {return VOLATILE;}
"restrict"                  {return RESTRICT;}
"inline"                    {return INLINE;}
"..."                       {return SO_ON;}
"case"                      {return CASE;}
"default"                   {return DEFAULT;}
"if"                        {return IF;}
"else"                      {return ELSE;}
"switch"                    {return SWITCH;}
"while"                     {return WHILE;}
"for"                       {return FOR;}
"do"                        {return DO;}
"goto"                      {return GOTO;}
"continue"                  {return CONTINUE;}
"break"                     {return BREAK;}
"return"                    {return RETURN;}
{identifier}                {return IDENTIFIER;}
{integer_constant}          {return INTCONST;}
{floating_constant}         {return FLOATCONST;}
{character_constant}        {return CHARCONST;}
{string_literal}            {return STR_LITERAL;}
{space}                     { }

%%
