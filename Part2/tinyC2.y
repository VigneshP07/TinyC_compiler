%{
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

%}

%union{
    struct Tree_Node* tnode;
    char *str;
    float fconst;
    int iconst;
}

%token <str> IDENTIFIER
%token <iconst> INTCONST
%token <fconst> FLOATCONST
%token <str> CHARCONST
%token <str> STR_LITERAL

%token EXTERN STATIC AUTO VOID CHAR REGISTER SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED BOOL COMPLEX IMAGINARY CONST RESTRICT VOLATILE
%token INLINE SO_ON CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token IMPLIES INCRE DECRE SIZEOF LSHIFT RSHIFT GEQ LEQ EQEQ NEQ AND OR MULEQ DIVEQ MODEQ ADDEQ SUBEQ LSHEQ RSHEQ ANDEQ XOREQ OREQ
%token SINGCOMM MULTCOMM
%token OP_SQUARE CL_SQUARE OP_ROUND CL_ROUND OP_CURLY CL_CURLY DOT BIT_AND PLUS MIN MUL BIT_NOT NOT DIV MOD LT GT
%token BIT_XOR BIT_OR Q_MARK COLON SEMICOLON EQ COMMA
%type <tnode> constant primary_expression postfix_expression argument_expression_list argument_expression_list_opt unary_expression
%type <tnode> unary_operator cast_expression multiplicative_expression additive_expression shift_expression relational_expression 
%type <tnode> equality_expression AND_expression exclusive_OR_expression inclusive_OR_expression logical_AND_expression logical_OR_expression
%type <tnode> conditional_expression assignment_expression assignment_expression_opt assignment_operator expression constant_expression
%type <tnode> declaration declaration_specifiers declaration_specifiers_opt init_declarator init_declarator_list init_declarator_list_opt
%type <tnode> storage_class_specifier type_specifier specifier_qualifier_list specifier_qualifier_list_opt type_qualifier function_specifier
%type <tnode> declarator direct_declarator pointer pointer_opt type_qualifier_list type_qualifier_list_opt
%type <tnode> parameter_type_list parameter_list parameter_declaration identifier_list identifier_list_opt type_name
%type <tnode> initializer initializer_list designation designation_opt designator_list designator
%type <tnode> statement labeled_statement compound_statement block_item_list block_item_list_opt block_item
%type <tnode> expression_statement expression_opt selection_statement iteration_statement jump_statement
%type <tnode> translation_unit external_declaration function_definition declaration_list declaration_list_opt identifier program
%start program

%%

identifier
        : IDENTIFIER    {TreeNode* temp[15];$$=createNode("Identifier","",0,temp);}

constant
        : INTCONST   {TreeNode* temp[15];TreeNode* icon=createNode("Integer constant","",0,temp);temp[0]=icon;
            $$=createNode("Constant","",1,temp);
            printf("constant -> integer_constant\n");}
        | FLOATCONST    {TreeNode* temp[15];TreeNode* fcon=createNode("Floating constant","",0,temp);temp[0]=fcon;
            $$=createNode("Constant","",1,temp);
            printf("constant -> floating_constant\n");}
        | CHARCONST     {TreeNode* temp[15];TreeNode* ccon=createNode("Character constant","",0,temp);temp[0]=ccon;
            $$=createNode("Constant","",1,temp);
            printf("constant -> character_constant\n");}
        ;

primary_expression
        : identifier    {TreeNode* temp[15];temp[0]=$1;
            $$=createNode("Primary Expression","",1,temp);
            printf("primary_expression -> identifier\n");}
        | constant      {TreeNode* temp[15];temp[0]=$1;
            $$=createNode("Primary Expression","",1,temp);
            printf("primary_expression -> constant\n");}
        | STR_LITERAL   {TreeNode* temp[15];TreeNode* strlt=createNode("String Literal","",0,temp);temp[0]=strlt;
            $$=createNode("Primary Expression","",1,temp);
            printf("primary_expression -> string_literal\n");}
        | OP_ROUND expression CL_ROUND    {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;$$=createNode("Primary Expression","",3,temp);
            printf("primary_expression -> ( expression ) \n");}
        ;

postfix_expression
        : primary_expression    {TreeNode* temp[15];temp[0]=$1;
            $$=createNode("Postfix Expression","",1,temp);
            printf("postfix_expression -> primary_expression\n");}
        | postfix_expression OP_SQUARE expression CL_SQUARE     {TreeNode* temp[15];TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=a2;$$=createNode("Postfix Expression","",4,temp);
            printf("postfix_expression -> postfix_expression [ expression ]\n");}
        | postfix_expression OP_ROUND argument_expression_list_opt CL_ROUND   {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=a2;$$=createNode("Postfix Expression","",4,temp);
            printf("postfix_expression -> postfix_expression ( argument_expression_list_opt ) \n");}   
        | postfix_expression DOT identifier     {TreeNode* temp[15];TreeNode* a1=createNode(".","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Postfix Expression","",3,temp);
            printf("postfix_expression -> postfix_expression . identifier\n");}
        | postfix_expression IMPLIES identifier    {TreeNode* temp[15];TreeNode* a1=createNode("->","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Postfix Expression","",3,temp);
            printf("postfix_expression -> postfix_expression -> identifier\n");}
        | postfix_expression INCRE   {TreeNode* temp[15];TreeNode* a1=createNode("++","",0,temp);
            temp[0]=$1;temp[1]=a1;$$=createNode("Postfix Expression","",2,temp);
            printf("postfix_expression -> postfix_expression ++\n");}
        | postfix_expression DECRE   {TreeNode* temp[15];TreeNode* a1=createNode("--","",0,temp);
            temp[0]=$1;temp[1]=a1;$$=createNode("Postfix Expression","",2,temp);
            printf("postfix_expression -> postfix_expression --\n");}
        | OP_ROUND type_name CL_ROUND OP_CURLY initializer_list CL_CURLY    {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            TreeNode* a3=createNode("{","",0,temp);TreeNode* a4=createNode("}","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;temp[3]=a3;temp[4]=$5;temp[5]=a4;$$=createNode("Postfix Expression","",6,temp);
            printf("postfix_expression -> ( type_name ) { initializer_list }\n");}
        | OP_ROUND type_name CL_ROUND OP_CURLY initializer_list COMMA CL_CURLY  {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            TreeNode* a3=createNode("{","",0,temp);TreeNode* a4=createNode("}","",0,temp);TreeNode* a5=createNode(",","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;temp[3]=a3;temp[4]=$5;temp[5]=a5;temp[6]=a4;$$=createNode("Postfix Expression","",7,temp);
            printf("postfix_expression -> ( type_name ) { initializer_list , }\n");}
        ;

argument_expression_list
        : assignment_expression     {TreeNode* temp[15];temp[0]=$1;
            $$=createNode("Argument Expression List","",1,temp);
            printf("argument_expression_list -> assignment_expression\n");}
        | argument_expression_list COMMA assignment_expression    {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Argument Expression List","",3,temp);
            printf("argument_expression_list -> argument_expression_list , assignment_expression\n");}
        ;

argument_expression_list_opt
        : argument_expression_list  {TreeNode* temp[15];temp[0]=$1;
            $$=createNode("Argument Expression List(opt)","",1,temp);
            printf("argument_expression_list_opt -> argument_expression_list\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Argument Expression List(opt)","",1,temp);
            printf("argument_expression_list_opt -> epsilon\n");}
        ;

unary_expression
        : postfix_expression    {TreeNode* temp[15];temp[0]=$1;
            $$=createNode("Unary Expression","",1,temp);
            printf("unary_expression -> postfix_expression\n");}
        | INCRE unary_expression     {TreeNode* temp[15];TreeNode* a1=createNode("++","",0,temp);
            temp[0]=a1;temp[1]=$2;$$=createNode("Unary Expression","",2,temp);
            printf("unary_expression -> ++ unary_expression\n");}
        | DECRE unary_expression     {TreeNode* temp[15];TreeNode* a1=createNode("--","",0,temp);
            temp[0]=a1;temp[1]=$2;$$=createNode("Unary Expression","",2,temp);
            printf("unary_expression -> -- unary_expression\n");}
        | unary_operator cast_expression    {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;
            $$=createNode("Unary Expression","",2,temp);
            printf("unary_expression -> unary_operator cast_expression\n");}
        | SIZEOF unary_expression     {TreeNode* temp[15];TreeNode* a1=createNode("sizeof","",0,temp);
            temp[0]=a1;temp[1]=$2;$$=createNode("Unary Expression","",2,temp);
            printf("unary_expression -> sizeof unary_expression\n");}
        | SIZEOF OP_ROUND type_name CL_ROUND    {TreeNode* temp[15];TreeNode* a1=createNode("sizeof","",0,temp);TreeNode* a2=createNode("(","",0,temp);TreeNode* a3=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=$3;temp[3]=a3;$$=createNode("Unary Expression","",4,temp);
            printf("unary_expression -> sizeof ( type_name )\n");}
        ;

unary_operator
        : BIT_AND   {TreeNode* temp[15];$$=createNode("Unary operator(&)","&",0,temp);printf("unary_opearator -> &\n");}
        | MUL   {TreeNode* temp[15];$$=createNode("Unary operator(*)","*",0,temp);printf("unary_operator -> *\n");}
        | PLUS   {TreeNode* temp[15];$$=createNode("Unary operator(+)","+",0,temp);printf("unary_operator -> +\n");}
        | MIN   {TreeNode* temp[15];$$=createNode("Unary operator(-)","-",0,temp);printf("unary_operator -> -\n");}
        | BIT_NOT   {TreeNode* temp[15];$$=createNode("Unary operator(~)","~",0,temp);printf("unary_operator -> ~\n");}
        | NOT   {TreeNode* temp[15];$$=createNode("Unary operator(!)","!",0,temp);printf("unary_operator -> !\n");}
        ;

cast_expression
        : unary_expression      {TreeNode* temp[15];temp[0]=$1;$$=createNode("Cast Expression","",1,temp);
            printf("cast_expression -> unary_expression\n");}
        | OP_ROUND type_name CL_ROUND cast_expression     {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;temp[3]=$4;$$=createNode("Cast Expression","",4,temp);
            printf("cast_expression -> ( type_name ) cast_expression\n");}
        ;

multiplicative_expression
        : cast_expression   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Multiplicative Expression","",1,temp);
            printf("multiplicative_expression -> cast_expression\n");}
        | multiplicative_expression MUL cast_expression {TreeNode* temp[15];TreeNode* a1=createNode("*","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Multiplicative Expression","",3,temp);
            printf("multiplicative_expression -> multiplicative_expression * cast_expression\n");}
        | multiplicative_expression DIV cast_expression {TreeNode* temp[15];TreeNode* a1=createNode("/","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Multiplicative Expression","",3,temp);
            printf("multiplicative_expression -> multiplicative_expression / cast_expression\n");}
        | multiplicative_expression MOD cast_expression {TreeNode* temp[15];TreeNode* a1=createNode("%","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Multiplicative Expression","",3,temp);
            printf("multiplicative_expression -> multiplicative_expression %% cast_expression\n");}
        ;

additive_expression
        : multiplicative_expression     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Additive Expression","",1,temp);
            printf("additive_expression -> multiplicative_expression\n");}
        | additive_expression PLUS multiplicative_expression     {TreeNode* temp[15];TreeNode* a1=createNode("+","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Additive Expression","",3,temp);
            printf("additive_expression -> additive_expression + multiplicative_expression\n");}
        | additive_expression MIN multiplicative_expression     {TreeNode* temp[15];TreeNode* a1=createNode("-","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Additive Expression","",3,temp);
            printf("additive_expression -> additive_expression - multiplicative_expression\n");}
        ;

shift_expression
        : additive_expression       {TreeNode* temp[15];temp[0]=$1;$$=createNode("Shift Expression","",1,temp);
            printf("shift_expression -> additive_expression\n");}
        | shift_expression LSHIFT additive_expression     {TreeNode* temp[15];TreeNode* a1=createNode("<<","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Shift Expression","",3,temp);
            printf("shift_expression -> shift_expression << additive_expression\n");}
        | shift_expression RSHIFT additive_expression     {TreeNode* temp[15];TreeNode* a1=createNode(">>","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Shift Expression","",3,temp);
            printf("shift_expression -> shift_expression >> additive_expression\n");}
        ;

relational_expression
        : shift_expression      {TreeNode* temp[15];temp[0]=$1;$$=createNode("Relational Expression","",1,temp);
            printf("relational_expression -> shift_expression\n");}
        | relational_expression LT shift_expression    {TreeNode* temp[15];TreeNode* a1=createNode("<","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Relational Expression","",3,temp);
            printf("relational_expression -> relational_expression < shift_expression\n");}
        | relational_expression GT shift_expression    {TreeNode* temp[15];TreeNode* a1=createNode(">","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Relational Expression","",3,temp);
            printf("relational_expression -> relational_expression > shift_expression\n");}
        | relational_expression LEQ shift_expression   {TreeNode* temp[15];TreeNode* a1=createNode("<=","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Relational Expression","",3,temp);
            printf("relational_expression -> relational_expression <= shift_expression\n");}
        | relational_expression GEQ shift_expression   {TreeNode* temp[15];TreeNode* a1=createNode(">=","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Relational Expression","",3,temp);
            printf("relational_expression -> relational_expression >= shift_expression\n");}
        ;

equality_expression
        : relational_expression     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Equality Expression","",1,temp);
            printf("equality_expression -> realtional_expression\n");}
        | equality_expression EQEQ relational_expression    {TreeNode* temp[15];TreeNode* a1=createNode("==","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Equality Expression","",3,temp);
            printf("equality_expression -> equality_expression == relational_expression\n");}
        | equality_expression NEQ relational_expression    {TreeNode* temp[15];TreeNode* a1=createNode("!=","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Equality Expression","",3,temp);
            printf("equality_expression -> equality_expression != relational_expression\n");}
        ;

AND_expression
        : equality_expression       {TreeNode* temp[15];temp[0]=$1;$$=createNode("AND Expression","",1,temp);
            printf("AND_expression -> equality_expression\n");}
        | AND_expression BIT_AND equality_expression    {TreeNode* temp[15];TreeNode* a1=createNode("&","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("AND Expression","",3,temp);
            printf("AND_expression -> AND_expression & equality_expression\n");}
        ;

exclusive_OR_expression
        : AND_expression    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Exclusive OR Expression","",1,temp);
            printf("exclusive_OR_expression -> AND_expression\n");}
        | exclusive_OR_expression BIT_XOR AND_expression    {TreeNode* temp[15];TreeNode* a1=createNode("^","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Exclusive OR Expression","",3,temp);
            printf("exclusive_OR_expression -> exclusive_OR_expression ^ AND_expression\n");}
        ;

inclusive_OR_expression
        : exclusive_OR_expression       {TreeNode* temp[15];temp[0]=$1;$$=createNode("Inclusive OR Expression","",1,temp);
            printf("inclusive_OR_expression -> exclusive_OR_expression\n");}
        | inclusive_OR_expression BIT_OR exclusive_OR_expression   {TreeNode* temp[15];TreeNode* a1=createNode("|","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Inclusive OR Expression","",3,temp);
            printf("inclusive_OR_expression -> inclusive_OR_expression | exclusive_OR_expression\n");}
        ;

logical_AND_expression
        : inclusive_OR_expression       {TreeNode* temp[15];temp[0]=$1;$$=createNode("Logical AND Expression","",1,temp);
            printf("logical_AND_expression -> inclusive_OR_expression\n");}
        | logical_AND_expression AND inclusive_OR_expression   {TreeNode* temp[15];TreeNode* a1=createNode("&&","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Logical AND Expression","",3,temp);
            printf("logical_AND_expression -> logial_AND_expression && inclusive_OR_expression\n");}
        ;

logical_OR_expression
        : logical_AND_expression        {TreeNode* temp[15];temp[0]=$1;$$=createNode("Logical OR Expression","",1,temp);
            printf("logical_OR_expression -> logical_AND_expression\n");}
        | logical_OR_expression OR logical_AND_expression     {TreeNode* temp[15];TreeNode* a1=createNode("||","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Logical OR Expression","",3,temp);
            printf("logical_OR_expression -> logial_OR_expression || logical_AND_expression\n");}
        ;

conditional_expression
        : logical_OR_expression     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Conditional Expression","",1,temp);
            printf("conditional_expression -> logical_OR_expression\n");}
        | logical_OR_expression Q_MARK expression COLON conditional_expression   {TreeNode* temp[15];TreeNode* a1=createNode("?","",0,temp);
            TreeNode* a2=createNode(":","",0,temp);temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=a2;temp[4]=$5;
            $$=createNode("Conditional Expression","",5,temp);
            printf("conditional_expression -> logical_OR_expression ? expression : conditional_expression\n");}
        ;

assignment_expression
        : conditional_expression    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Assignment Expression","",1,temp);
            printf("assignment_expression -> conditional_expression\n");}
        | unary_expression assignment_operator assignment_expression    {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;temp[2]=$3;
            $$=createNode("Assignment Expression","",3,temp);
            printf("Assignment_expression -> unary_expression assignment_operator assignment_expression\n");}
        ;

assignment_expression_opt
        : assignment_expression     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Assignment Expression(opt)","",1,temp);
            printf("assignment_expression_opt -> assignment_expression\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Assignment Expression(opt)","",1,temp);
            printf("assignment_expression_opt -> epsilon\n");}
        ;

assignment_operator
        : EQ       {TreeNode* temp[15];$$=createNode("Assignment operator(=)","=",0,temp);printf("Assignment_operator -> =\n");}
        | MULEQ      {TreeNode* temp[15];$$=createNode("Assignment operator(*=)","*=",0,temp);printf("Assignment_operator -> *=\n");}
        | DIVEQ      {TreeNode* temp[15];$$=createNode("Assignment operator(/=)","/=",0,temp);printf("Assignment_operator -> /=\n");}
        | MODEQ      {TreeNode* temp[15];$$=createNode("Assignment operator(%=)","%=",0,temp);printf("Assignment_operator -> %%=\n");}
        | ADDEQ      {TreeNode* temp[15];$$=createNode("Assignment operator(+=)","+=",0,temp);printf("Assignment_operator -> +=\n");}
        | SUBEQ      {TreeNode* temp[15];$$=createNode("Assignment operator(-=)","-=",0,temp);printf("Assignment_operator -> -=\n");}
        | LSHEQ     {TreeNode* temp[15];$$=createNode("Assignment operator(<<=)","<<=",0,temp);printf("Assignment_operator -> <<=\n");}
        | RSHEQ     {TreeNode* temp[15];$$=createNode("Assignment operator(>>=)",">>=",0,temp);printf("Assignment_operator -> >>=\n");}
        | ANDEQ      {TreeNode* temp[15];$$=createNode("Assignment operator(&=)","&=",0,temp);printf("Assignment_operator -> &=\n");}
        | XOREQ      {TreeNode* temp[15];$$=createNode("Assignment operator(^=)","^=",0,temp);printf("Assignment_operator -> ^=\n");}
        | OREQ      {TreeNode* temp[15];$$=createNode("Assignment operator(|=)","|=",0,temp);printf("Assignment_operator -> |=\n");}
        ;

expression
        : assignment_expression     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Expression","",1,temp);
            printf("expression -> assignment_expression\n");}
        | expression COMMA assignment_expression      {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Expression","",3,temp);
            printf("expression -> expression , assignment_expression\n");}
        ;

constant_expression
        : conditional_expression    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Constant Expression","",1,temp);
            printf("constant_expression -> conditional_expression\n");}
        ;


declaration
        : declaration_specifiers init_declarator_list_opt SEMICOLON   {TreeNode* temp[15];TreeNode* a1=createNode(";","",0,temp);
            temp[0]=$1;temp[1]=$2;temp[2]=a1;$$=createNode("Declaration","",3,temp);
            printf("declaration -> declaration_specifiers init_declarator_list_opt ;\n");}
        ;

declaration_specifiers
        : storage_class_specifier declaration_specifiers_opt    {TreeNode* temp[15];temp[0]=$1,temp[1]=$2;
            $$=createNode("Declaration Specifiers","",2,temp);
            printf("declaration_specifiers -> storage_class_specifier declaration_specifiers_opt\n");}
        | type_specifier declaration_specifiers_opt     {TreeNode* temp[15];temp[0]=$1,temp[1]=$2;
            $$=createNode("Declaration Specifiers","",2,temp);
            printf("declaration_specifiers -> type_specifier declaration_specifiers_opt\n");}
        | type_qualifier declaration_specifiers_opt     {TreeNode* temp[15];temp[0]=$1,temp[1]=$2;
            $$=createNode("Declaration Specifiers","",2,temp);
            printf("declaration_specifiers -> type_qualifier declaration_specifiers_opt\n");}
        | function_specifier declaration_specifiers_opt {TreeNode* temp[15];temp[0]=$1,temp[1]=$2;
            $$=createNode("Declaration Specifiers","",2,temp);
            printf("declaration_specifiers -> function_specifier declaration_specifiers_opt\n");}
        ;

declaration_specifiers_opt
        : declaration_specifiers    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Declaration Specifiers(opt)","",1,temp);
            printf("declaration_specifiers_opt -> declaration_specifiers\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Declaration Specifiers(opt)","",1,temp);
            printf("declaration_specifiers_opt -> epsilon\n");}
        ;

init_declarator_list
        : init_declarator       {TreeNode* temp[15];temp[0]=$1;$$=createNode("Init_Declarator_List","",1,temp);
            printf("init_declarator_list -> init_declarator\n");}
        | init_declarator_list COMMA init_declarator  {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Init_Declarator_List","",3,temp);
            printf("init_declarator_list -> init_declarator_list , init_declarator\n");}
        ;

init_declarator_list_opt
        : init_declarator_list   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Init_Declarator_List(opt)","",1,temp);
            printf("init_declarator_list_opt -> init_declarator_list\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Init_Declarator_List(opt)","",1,temp);
            printf("init_declarator_list_opt -> epsilon\n");}
        ;

init_declarator
        : declarator        {TreeNode* temp[15];temp[0]=$1;$$=createNode("Init_Declarator","",1,temp);
            printf("init_declarator -> declarator\n");}
        | declarator EQ initializer    {TreeNode* temp[15];TreeNode* a1=createNode("=","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Init_Declarator","",3,temp);
            printf("init_declarator -> declarator = initializer\n");}
        ;

storage_class_specifier
        : EXTERN  {TreeNode* temp[15];$$=createNode("Storage Class Specifier(extern)","extern",0,temp);printf("storage_class_specifier -> extern\n");}
        | STATIC  {TreeNode* temp[15];$$=createNode("Storage Class Specifier(static)","static",0,temp);printf("storage_class_specifier -> static\n");}
        | AUTO    {TreeNode* temp[15];$$=createNode("Storage Class Specifier(auto)","auto",0,temp);printf("storage_class_specifier -> auto\n");}
        | REGISTER    {TreeNode* temp[15];$$=createNode("Storage Class Specifier(register)","register",0,temp);printf("storage_class_specifier -> register\n");}
        ;

type_specifier
        : VOID    {TreeNode* temp[15];$$=createNode("Type Specifier(void)","void",0,temp);printf("type_specifier -> void\n");}
        | CHAR    {TreeNode* temp[15];$$=createNode("Type Specifier(char)","char",0,temp);printf("type_specifier -> char\n");}
        | SHORT   {TreeNode* temp[15];$$=createNode("Type Specifier(short)","short",0,temp);printf("type_specifier -> short\n");}
        | INT     {TreeNode* temp[15];$$=createNode("Type Specifier(int)","int",0,temp);printf("type_specifier -> int\n");}
        | LONG    {TreeNode* temp[15];$$=createNode("Type Specifier(long)","long",0,temp);printf("type_specifier -> long\n");}
        | FLOAT   {TreeNode* temp[15];$$=createNode("Type Specifier(float)","float",0,temp);printf("type_specifier -> float\n");}
        | DOUBLE  {TreeNode* temp[15];$$=createNode("Type Specifier(double)","double",0,temp);printf("type_specifier -> double\n");}
        | SIGNED  {TreeNode* temp[15];$$=createNode("Type Specifier(signed)","signed",0,temp);printf("type_specifier -> signed\n");}
        | UNSIGNED    {TreeNode* temp[15];$$=createNode("Type Specifier(unsigned)","unsigned",0,temp);printf("type_specifier -> unsigned\n");}
        | BOOL   {TreeNode* temp[15];$$=createNode("Type Specifier(bool)","bool",0,temp);printf("type_specifier -> _Bool\n");}
        | COMPLEX    {TreeNode* temp[15];$$=createNode("Type Specifier(complex)","complex",0,temp);printf("type_specifier -> _Complex\n");}
        | IMAGINARY  {TreeNode* temp[15];$$=createNode("Type Specifier(imaginary)","imaginary",0,temp);printf("type_specifier -> _Imaginary\n");}
        ;

specifier_qualifier_list
        : type_specifier specifier_qualifier_list_opt   {TreeNode* temp[15];temp[0]=$1,temp[1]=$2;
            $$=createNode("Specifier Qualifier List","",2,temp);
            printf("specifier_qualifier_list -> type_specifier specifier_qualifier_list_opt\n");}
        | type_qualifier specifier_qualifier_list_opt   {TreeNode* temp[15];temp[0]=$1,temp[1]=$2;
            $$=createNode("Specifier Qualifier List","",2,temp);
            printf("specifier_qualifier_list -> type_qualifier specifier_qualifier_list_opt\n");}
        ;

specifier_qualifier_list_opt
        : specifier_qualifier_list  {TreeNode* temp[15];temp[0]=$1;$$=createNode("Specifier Qualifier List(opt)","",1,temp);
            printf("specifier_qualifier_list_opt -> specifier_qualifier_list\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Specifier Qualifier List(opt)","",1,temp);
            printf("specifier_qualifier_list_opt -> epsilon\n");}
        ;

type_qualifier
        : CONST       {TreeNode* temp[15];$$=createNode("Type Qualifier(const)","const",0,temp);printf("type_qualifier -> const\n");}
        | RESTRICT    {TreeNode* temp[15];$$=createNode("Type Qualifier(restrict)","restrict",0,temp);printf("type_qualifier -> restrict\n");}
        | VOLATILE    {TreeNode* temp[15];$$=createNode("Type Qualifier(volatile)","volatile",0,temp);printf("type_qualifier -> volatile\n");}
        ;

function_specifier
        : INLINE      {TreeNode* temp[15];$$=createNode("Function Specifier(inline)","inline",0,temp);printf("function_specifier -> inline\n");}
        ;

declarator
        : pointer_opt direct_declarator     {TreeNode* temp[15];temp[0]=$1,temp[1]=$2;
            $$=createNode("Declarator","",2,temp);
            printf("declarator -> pointer_opt direct_declarator\n");}
        ;

direct_declarator
        : identifier        {TreeNode* temp[15];temp[0]=$1;
            $$=createNode("Direct Declarator","",1,temp);
            printf("direct_declarator -> identifier\n");}
        | OP_ROUND declarator CL_ROUND    {TreeNode* temp[15];TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;$$=createNode("Direct Declarator","",3,temp);
            printf("direct_declarator -> ( declarator ) \n");}
        | direct_declarator OP_SQUARE type_qualifier_list_opt assignment_expression_opt CL_SQUARE   {TreeNode* temp[15];
            TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=$4;temp[4]=a2;$$=createNode("Direct Declarator","",5,temp);
            printf("direct_declarator -> direct_declarator [ type_qualifier_list_opt assignment_expression_opt ]\n");}
        | direct_declarator OP_SQUARE STATIC type_qualifier_list_opt assignment_expression CL_SQUARE  {TreeNode* temp[15];
            TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);TreeNode* a3=createNode("static","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=a3;temp[3]=$4;temp[4]=$5;temp[5]=a2;$$=createNode("Direct Declarator","",6,temp);
            printf("direct_declarator -> direct_declarator [ static type_qualifier_list_opt assignment_expression ]\n");}
        | direct_declarator OP_SQUARE type_qualifier_list STATIC assignment_expression CL_SQUARE   {TreeNode* temp[15];
            TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);TreeNode* a3=createNode("static","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=a3;temp[4]=$5;temp[5]=a2;$$=createNode("Direct Declarator","",6,temp);
            printf("direct_declarator -> direct_declarator [ type_qualifier_list static assignment_expression ]\n");}
        | direct_declarator OP_SQUARE type_qualifier_list_opt MUL CL_SQUARE     {TreeNode* temp[15];
            TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);TreeNode* a3=createNode("*","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=a3;temp[4]=a2;$$=createNode("Direct Declarator","",5,temp);
            printf("direct_declarator -> direct_declarator [ type_qualifier_list_opt * ]\n");}
        | direct_declarator OP_ROUND parameter_type_list CL_ROUND     {TreeNode* temp[15];
            TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=a2;$$=createNode("Direct Declarator","",4,temp);
            printf("direct_declarator -> direct_declarator ( parameter_type_list )\n");}
        | direct_declarator OP_ROUND identifier_list_opt CL_ROUND     {TreeNode* temp[15];
            TreeNode* a1=createNode("(","",0,temp);TreeNode* a2=createNode(")","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=a2;$$=createNode("Direct Declarator","",4,temp);
            printf("direct_declarator -> direct_declarator ( identifier_list_opt )\n");}
        ;

pointer
        : MUL type_qualifier_list_opt   {TreeNode* temp[15];TreeNode* a1=createNode("*","",0,temp);
            temp[0]=a1;temp[1]=$2;$$=createNode("Pointer","",2,temp);
            printf("pointer -> * type_qualifier_list_opt");}
        | MUL type_qualifier_list_opt pointer       {TreeNode* temp[15];TreeNode* a1=createNode("*","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=$3;$$=createNode("Pointer","",3,temp);
            printf("pointer -> * type_qualifier_list_opt pointer");}
        ;

pointer_opt
        : pointer   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Pointer(opt)","",1,temp);
            printf("pointer_opt -> pointer\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Pointer(opt)","",1,temp);
            printf("pointer_opt -> epsilon\n");}
        ;

type_qualifier_list
        : type_qualifier    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Type Qualifier List","",1,temp);
            printf("type_qualifier_list -> type_qualifier\n");}
        | type_qualifier_list type_qualifier    {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;$$=createNode("Type Qualifier List","",2,temp);
            printf("type_qualifier_list -> type_qualifier_list type_qualifier\n");}
        ;

type_qualifier_list_opt
        : type_qualifier_list   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Type Qualifier List(opt)","",1,temp);
            printf("type_qualifier_list_opt -> type_qualifier_list\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Type Qualifier List(opt)","",1,temp);
            printf("type_qualifier_list_opt -> epsilon\n");}

        ;

parameter_type_list
        : parameter_list    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Parameter Type List","",1,temp);
            printf("parameter_type_list -> parameter_list\n");}
        | parameter_list COMMA SO_ON      {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);TreeNode* a2=createNode("...","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=a2;$$=createNode("Parameter Type List","",3,temp);
            printf("parameter_type_list -> parameter_list , ...\n");}
        ;

parameter_list
        : parameter_declaration     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Parameter List","",1,temp);
            printf("parameter_list -> parameter_declaration\n");}
        | parameter_list COMMA parameter_declaration  {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Parameter List","",3,temp);
            printf("parameter_list -> parameter_list , parameter_declaration\n");}
        ;

parameter_declaration
        : declaration_specifiers declarator {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;$$=createNode("Parameter Declaration","",2,temp);
            printf("parameter_declaration -> declaration_specifiers declarator\n");}
        | declaration_specifiers    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Parameter Declaration","",1,temp);
            printf("parameter_declaration -> declaration_specifiers\n");}
        ;

identifier_list
        : identifier    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Identifier List","",1,temp);
            printf("identifier_list -> identifier\n");}
        | identifier_list COMMA identifier    {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Identifier List","",3,temp);
            printf("identifier_list -> identifier_list , identifier\n");}
        ;

identifier_list_opt
        : identifier_list   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Identifier List(opt)","",1,temp);
            printf("identifier_list_opt -> identifier_list\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Identifier List(opt)","",1,temp);
            printf("identifier_list_opt -> epsilon\n");}
        ;

type_name
        : specifier_qualifier_list  {TreeNode* temp[15];temp[0]=$1;$$=createNode("Type Name","",1,temp);
            printf("type_name -> specifier_qualifier_list\n");}
        ;

initializer
        : assignment_expression     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Initializer","",1,temp);
            printf("initializer -> assignment_expression\n");}
        | OP_CURLY initializer_list CL_CURLY  {TreeNode* temp[15];TreeNode* a1=createNode("{","",0,temp);TreeNode* a2=createNode("}","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;$$=createNode("Initializer","",3,temp);
            printf("initializer -> { initializer_list }\n");}
        | OP_CURLY initializer_list COMMA CL_CURLY  {TreeNode* temp[15];TreeNode* a1=createNode("{","",0,temp);TreeNode* a2=createNode("}","",0,temp);
            TreeNode* a3=createNode(",","",0,temp);temp[0]=a1;temp[1]=$2;temp[2]=a3;temp[3]=a2;$$=createNode("Initializer","",4,temp);
            printf("initializer -> { initializer_list , }\n");}
        ;

initializer_list
        : designation_opt initializer   {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;$$=createNode("Initializer List","",2,temp);
            printf("initializer_list -> designation_opt initializer\n");}
        | initializer_list COMMA designation_opt initializer  {TreeNode* temp[15];TreeNode* a1=createNode(",","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;temp[3]=$4;$$=createNode("Initializer List","",4,temp);
            printf("initializer_list -> initializer_list , designation_opt initializer\n");}
        ;

designation
        : designator_list EQ   {TreeNode* temp[15];TreeNode* a1=createNode("=","",0,temp);
            temp[0]=$1;temp[1]=a1;$$=createNode("Designation","",2,temp);
            printf("designation -> designator_list =\n");}
        ;

designation_opt
        : designation   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Designation(opt)","",1,temp);
            printf("designation_opt -> designation\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Designation(opt)","",1,temp);
            printf("designation_opt -> epsilon\n");}
        ;

designator_list
        : designator    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Designator List","",1,temp);
            printf("designator_list -> designator\n");}
        | designator_list designator    {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;$$=createNode("Designator List","",2,temp);
            printf("designator_list -> designator_list designator\n");}
        ;

designator
        : OP_SQUARE constant_expression CL_SQUARE   {TreeNode* temp[15];TreeNode* a1=createNode("[","",0,temp);TreeNode* a2=createNode("]","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;$$=createNode("Designator","",3,temp);
            printf("designator -> [ constant_expression ]\n");}
        | DOT identifier    {TreeNode* temp[15];TreeNode* a1=createNode(".","",0,temp);
            temp[0]=a1;temp[1]=$2;$$=createNode("Designator","",1,temp);
            printf("designator -> . identifier\n");}
        ;


statement
        : labeled_statement     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Statement","",1,temp);
            printf("statement -> labeled_statement\n");}
        | compound_statement    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Statement","",1,temp);
            printf("statement -> compound_statement\n");}
        | expression_statement  {TreeNode* temp[15];temp[0]=$1;$$=createNode("Statement","",1,temp);
            printf("statement -> expression_statement\n");}
        | selection_statement   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Statement","",1,temp);
            printf("statement -> selection_statement\n");}
        | iteration_statement   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Statement","",1,temp);
            printf("statement -> iteration_statement\n");}
        | jump_statement    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Statement","",1,temp);
            printf("statement -> jump_statement\n");}
        ;

labeled_statement
        : identifier COLON statement      {TreeNode* temp[15];TreeNode* a1=createNode(":","",0,temp);
            temp[0]=$1;temp[1]=a1;temp[2]=$3;$$=createNode("Labeled Statement","",3,temp);
            printf("labeled_statement -> identifier : statement\n");}
        | CASE constant_expression COLON statement      {TreeNode* temp[15];TreeNode* a1=createNode("case","",0,temp);TreeNode* a2=createNode(":","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;temp[3]=$4;$$=createNode("Labeled Statement","",4,temp);
            printf("labeled_statement -> case constant_expression : statement\n");}
        | DEFAULT COLON statement   {TreeNode* temp[15];TreeNode* a1=createNode("default","",0,temp);TreeNode* a2=createNode(":","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=$3;$$=createNode("Labeled Statement","",3,temp);
            printf("labeled_statement -> default : statement\n");}
        ;

compound_statement
        : OP_CURLY block_item_list_opt CL_CURLY   {TreeNode* temp[15];TreeNode* a1=createNode("{","",0,temp);TreeNode* a2=createNode("}","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;$$=createNode("Compound Statement","",3,temp);
            printf("compound_statement -> { block_item_list_opt }\n");}
        ;

block_item_list
        : block_item    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Block Item List","",1,temp);
            printf("block_item_list -> block_item\n");}
        | block_item_list block_item    {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;$$=createNode("Block Item List","",2,temp);
            printf("block_item_list -> block_item_list block_item\n");}
        ;

block_item_list_opt
        : block_item_list   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Block Item List(opt)","",1,temp);
            printf("block_item_list_opt -> block_item_list\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Block Item List(opt)","",1,temp);
            printf("block_item_list_opt -> epsilon\n");}
        ;

block_item
        : declaration   {TreeNode* temp[15];temp[0]=$1;$$=createNode("Block Item","",1,temp);
            printf("block_item -> declaration\n");}
        | statement     {TreeNode* temp[15];temp[0]=$1;$$=createNode("Block Item","",1,temp);
            printf("block_item -> statement\n");}
        ;

expression_statement
        : expression_opt SEMICOLON    {TreeNode* temp[15];TreeNode* a1=createNode(";","",0,temp);
            temp[0]=$1;temp[1]=a1;$$=createNode("Expression Statement","",2,temp);
            printf("expression_statement -> expression_opt ;\n");}
        ;

expression_opt
        : expression    {TreeNode* temp[15];temp[0]=$1;$$=createNode("Expression(opt)","",1,temp);
            printf("expression_opt -> expression\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Expression(opt)","",1,temp);
            printf("expression_opt -> epsilon\n");}
        ;

selection_statement
        : IF OP_ROUND expression CL_ROUND statement     {TreeNode* temp[15];TreeNode* a1=createNode("if","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(")","",0,temp);temp[0]=a1;temp[1]=a2;temp[2]=$3;temp[3]=a3;temp[4]=$5;
            $$=createNode("Selection Statement","",5,temp);
            printf("selection_statement -> if ( expression ) statement\n");}
        | IF OP_ROUND expression CL_ROUND statement ELSE statement    {TreeNode* temp[15];TreeNode* a1=createNode("if","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(")","",0,temp);TreeNode* a4=createNode("else","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=$3;temp[3]=a3;temp[4]=$5;temp[5]=a4;temp[6]=$7;
            $$=createNode("Selection Statement","",7,temp);
            printf("selection_statement -> if ( expression ) statement else statement\n");}
        | SWITCH OP_ROUND expression CL_ROUND statement     {TreeNode* temp[15];TreeNode* a1=createNode("switch","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(")","",0,temp);temp[0]=a1;temp[1]=a2;temp[2]=$3;temp[3]=a3;temp[4]=$5;
            $$=createNode("Selection Statement","",5,temp);
            printf("selection_statement -> switch ( expression ) statement\n");}
        ;

iteration_statement
        : WHILE OP_ROUND expression CL_ROUND statement  {TreeNode* temp[15];TreeNode* a1=createNode("while","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(")","",0,temp);temp[0]=a1;temp[1]=a2;temp[2]=$3;temp[3]=a3;temp[4]=$5;
            $$=createNode("Iteration Statement","",5,temp);
            printf("iteration_statement -> while ( expression ) statement\n");}
        | DO statement WHILE OP_ROUND expression CL_ROUND SEMICOLON   {TreeNode* temp[15];TreeNode* a1=createNode("do","",0,temp);TreeNode* a2=createNode("while","",0,temp);
            TreeNode* a3=createNode("(","",0,temp);TreeNode* a4=createNode(")","",0,temp);TreeNode* a5=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;temp[3]=a3;temp[4]=$5;temp[5]=a4;temp[6]=a5;
            $$=createNode("Iteration Statement","",7,temp);
            printf("iteration_statement -> do statement while ( expression ) ;\n");}
        | FOR OP_ROUND expression_opt SEMICOLON expression_opt SEMICOLON expression_opt CL_ROUND statement  {TreeNode* temp[15];TreeNode* a1=createNode("for","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(";","",0,temp);TreeNode* a4=createNode(";","",0,temp);TreeNode* a5=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=$3;temp[3]=a3;temp[4]=$5;temp[5]=a4;temp[6]=$7;temp[7]=a5;temp[8]=$9;
            $$=createNode("Iteration Statement","",9,temp);
            printf("iteration_statement -> for ( expression_opt ; expression_opt ; expression_opt ) statement\n");
            }
        | FOR OP_ROUND declaration expression_opt SEMICOLON expression_opt CL_ROUND statement {TreeNode* temp[15];TreeNode* a1=createNode("for","",0,temp);TreeNode* a2=createNode("(","",0,temp);
            TreeNode* a3=createNode(";","",0,temp);TreeNode* a4=createNode(")","",0,temp);
            temp[0]=a1;temp[1]=a2;temp[2]=$3;temp[3]=$4;temp[4]=a3;temp[5]=$6;temp[6]=a4;temp[7]=$8;
            $$=createNode("Iteration Statement","",8,temp);
            printf("iteration_statement -> for ( declaration expression_opt ; expression_opt ) statement\n");
            }
        ;

jump_statement
        :   GOTO identifier SEMICOLON     {TreeNode* temp[15];TreeNode* a1=createNode("goto","",0,temp);TreeNode* a2=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;$$=createNode("Jump Statement","",3,temp);
            printf("jump_statement -> goto identifier ;\n");}
        | CONTINUE SEMICOLON     {TreeNode* temp[15];TreeNode* a1=createNode("continue","",0,temp);TreeNode* a2=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=a2;$$=createNode("Jump Statement","",2,temp);
            printf("jump_statement -> continue ;\n");}
        | BREAK SEMICOLON       {TreeNode* temp[15];TreeNode* a1=createNode("break","",0,temp);TreeNode* a2=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=a2;$$=createNode("Jump Statement","",2,temp);
            printf("jump_statement -> break ;\n");}
        | RETURN expression_opt SEMICOLON   {TreeNode* temp[15];TreeNode* a1=createNode("return","",0,temp);TreeNode* a2=createNode(";","",0,temp);
            temp[0]=a1;temp[1]=$2;temp[2]=a2;$$=createNode("Jump Statement","",3,temp);
            printf("jump_statement -> return expression_opt ;\n");}
        ;


translation_unit
        : external_declaration      {TreeNode* temp[15];temp[0]=$1;$$=createNode("Translation Unit","",1,temp);root=$$;
            printf("translation_unit -> external_declaration\n");}
        | translation_unit external_declaration     {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;$$=createNode("Translation Unit","",2,temp);root==$$;
            printf("translation_unit -> translation_unit external_declaration\n");}
        ;

external_declaration
        : function_definition   {TreeNode* temp[15];temp[0]=$1;$$=createNode("External Declaration","",1,temp);
            printf("external_declaration -> function_definition\n");}
        | declaration   {TreeNode* temp[15];temp[0]=$1;$$=createNode("External Declaration","",1,temp);
            printf("external_declaration -> declaration\n");}
        ;

function_definition
        : declaration_specifiers declarator declaration_list_opt compound_statement     {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;temp[2]=$3;temp[3]=$4;
            $$=createNode("Function Definition","",4,temp);
            printf("function_definition -> declaration_specifiers declarator declaration_list_opt compound_statement\n");}
        ;

declaration_list
        : declaration       {TreeNode* temp[15];temp[0]=$1;$$=createNode("Declaration List","",1,temp);
            printf("declaration_list -> declaration\n");}
        | declaration_list declaration      {TreeNode* temp[15];temp[0]=$1;temp[1]=$2;$$=createNode("Declaration List","",2,temp);
            printf("declaration_list -> declaration_list declaration\n");}
        ;

declaration_list_opt
        : declaration_list      {TreeNode* temp[15];temp[0]=$1;$$=createNode("Declaration List(opt)","",1,temp);
            printf("declaration_list_opt -> declaration_list\n");}
        | {TreeNode* temp[15];TreeNode* a1=createNode("Epsilon","",0,temp);temp[0]=a1;
            $$=createNode("Declaration List(opt)","",1,temp);
            printf("declaration_list_opt -> epsilon\n");}
        ;

program
        : translation_unit      {TreeNode* temp[15];temp[0]=$1;$$=createNode("Program","",1,temp);root=$$;
            printf("program -> translation_unit\n");}
%%


