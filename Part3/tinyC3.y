%{
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
%}

%union{
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
}

//Basic terminals like numbers and variables
%token <pointer> IDENTIFIER
%token <intconst> INTCONST
%token <floatconst> FLOATCONST
%token <strconst> CHARCONST 
%token <strconst> STR_LITERAL

//Predefined words, parantheses and operators
%token EXTERN STATIC AUTO VOID CHAR REGISTER SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED BOOL COMPLEX IMAGINARY CONST RESTRICT VOLATILE
%token INLINE SO_ON CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN ENUM ERROR
%token IMPLIES INCRE DECRE SIZEOF LSHIFT RSHIFT GEQ LEQ EQEQ NEQ AND OR MULEQ DIVEQ MODEQ ADDEQ SUBEQ LSHEQ RSHEQ ANDEQ XOREQ OREQ
%token OP_SQUARE CL_SQUARE OP_ROUND CL_ROUND OP_CURLY CL_CURLY DOT BIT_AND PLUS MIN MUL BIT_NOT NOT DIV MOD LT GT
%token BIT_XOR BIT_OR Q_MARK COLON SEMICOLON EQ COMMA

//setting precedence for else and similar types
%precedence LOWER_THAN_ELSE
%precedence ELSE

//Expression type non terminals
%type<expr> expression primary_expression multiplicative_expression additive_expression shift_expression relational_expression
%type<expr> equality_expression AND_expression exclusive_OR_expression inclusive_OR_expression logical_AND_expression 
%type<expr> logical_OR_expression conditional_expression assignment_expression expression_statement

//Array types non terminals
%type<Array> postfix_expression unary_expression cast_expression

//Function parameters list non terminals
%type<numParams> argument_expression_list_opt argument_expression_list

//unary operators
%type<unaryOp> unary_operator

//Pointer to symbol type non terminals
%type<pointer> declarator init_declarator direct_declarator initializer

//pointer to data type stroing non terminals 
%type<ptr> pointer

//Instruction number type non terminals
%type<instr> next_instr

//Statement type non terminals
%type<stmt> next_list statement loop_statement jump_statement selection_statement iteration_statement labeled_statement compound_statement
%type<stmt> block_item block_item_list block_item_list_opt

//Starting non terminal
%start program

%%

primary_expression
        : IDENTIFIER    {
            symbol* sym=pres_table->lookup(id);
            $$=new expression();
            $$->type="non_bool";
            $$->loc=sym;
        }
        | INTCONST      {
            $$=new expression();
            data_type* a=new data_type("int");
            $$->loc=symbolTbl::gentemp(a,to_string($1));
            emit("=",$$->loc->name,$1);
        }
        | FLOATCONST    {
            $$=new expression();
            data_type* a=new data_type("float");
            $$->loc=symbolTbl::gentemp(a,to_string($1));
            emit("=",$$->loc->name,$1);
        }
        | CHARCONST     {
            $$=new expression();
            data_type* a=new data_type("char");
            $$->loc=symbolTbl::gentemp(a,string($1));
            emit("=",$$->loc->name,string($1));
        }
        | STR_LITERAL   {
            $$=new expression();
            data_type* a=new data_type("ptr");
            $$->loc=symbolTbl::gentemp(a,string($1));
            $$->loc->type->arrtype=new data_type("char");
        }
        | OP_ROUND expression CL_ROUND  {$$=$2;}
        ;

postfix_expression
        : primary_expression    {
            //Creating a new array type variable and storing pointer of primary expression in the array type
            $$=new array_type();
            $$->loc=$1->loc;
            $$->type=$1->loc->type;//setting the type
            $$->Array=$1->loc;
        }
        | postfix_expression OP_SQUARE expression CL_SQUARE     {//Handling array indexing
            $$=new array_type();
            $$->loc=symbolTbl::gentemp("int");
            $$->struc_type="arr";
            $$->Array=$1->Array;
            $$->type=$1->type->arrtype;
            if($1->struc_type=="arr"){
                symbol* temp=symbolTbl::gentemp("int");
                int size=size_of_type($$->type);
                emit("*",temp->name,$3->loc->name,to_string(size));
                emit("+",$$->loc->name,$1->loc->name,temp->name);
            }
            else{
                int size=size_of_type($$->type);
                emit("*",$$->loc->name,$3->loc->name,to_string(size));
            }
        }
        | postfix_expression OP_ROUND argument_expression_list_opt CL_ROUND     {//Handling function call
            $$=new array_type();
            $$->Array=symbolTbl::gentemp($1->type);
            emit("call", $$->Array->name, $1->Array->name, to_string($3));
        }
        | postfix_expression DOT IDENTIFIER         {}
        | postfix_expression IMPLIES IDENTIFIER     {}
        | postfix_expression INCRE      {
            $$=new array_type();
            $$->Array=symbolTbl::gentemp($1->Array->type);
            emit("=", $$->Array->name, $1->Array->name);//Value of temporary=unchanged value of variable
            emit("+", $1->Array->name, $1->Array->name, "1"); //Value of variable increased by 1
        }
        | postfix_expression DECRE      {
            $$=new array_type();
            $$->Array=symbolTbl::gentemp($1->Array->type);
            emit("=", $$->Array->name, $1->Array->name); //Value of temporary=unchanged value of variable
            emit("-", $1->Array->name, $1->Array->name, "1");//Value of variable decreased by 1
        }
        | OP_ROUND type_name CL_ROUND OP_CURLY initializer_list CL_CURLY            {}
        | OP_ROUND type_name CL_ROUND OP_CURLY initializer_list COMMA CL_CURLY      {}
        ;

argument_expression_list
        : assignment_expression       {
            $$=1;
            emit("param",$1->loc->name);
        }
        | argument_expression_list COMMA assignment_expression      {
            $$=$1+1;//Changing parameter count
            emit("param",$3->loc->name);
        }
        ;

argument_expression_list_opt
        : argument_expression_list      {$$=$1;}
        | %empty                        {$$=0;}
        ;

unary_expression
        : postfix_expression            {$$=$1;}
        | INCRE unary_expression        {
            emit("+", $2->Array->name, $2->Array->name, "1"); //Increase value of variable
            $$=$2;//Value of expression=increased value of variable
        }
        | DECRE unary_expression        {
            emit("-", $2->Array->name, $2->Array->name, "1");//Decrease value of variable
            $$=$2;//Value of expression=decreased value of variable
        }
        | unary_operator cast_expression        {
            $$=new array_type();
            switch($1){
                case '&'://Handling adressing
                    $$->Array=symbolTbl::gentemp(new data_type("ptr"));
                    $$->Array->type->arrtype=$2->Array->type;
                    emit("= &",$$->Array->name,$2->Array->name);
                    break;
                case '*'://Handling derefernce
                    $$->Array=$2->Array;
                    $$->loc=symbolTbl::gentemp($2->Array->type->arrtype);
                    $$->struc_type="ptr";
                    emit("= *",$$->loc->name,$2->Array->name);  
                    break;
                case '+'://unary plus(no handling required)
                    $$=$2;
                    break;
                case '-'://Handling unary minus
                    $$->Array=symbolTbl::gentemp($2->Array->type->type);
                    emit("= -",$$->Array->name,$2->Array->name);   
                    break;
                case '~'://Handling bitwise complementation
                    $$->Array=symbolTbl::gentemp($2->Array->type->type);
                    emit("= ~",$$->Array->name,$2->Array->name);
                    break;
                case '!'://Handling logical complementation
                    $$->Array=symbolTbl::gentemp($2->Array->type->type);
                    emit("= !",$$->Array->name,$2->Array->name);
                    break;
            }
        }
        | SIZEOF unary_expression                   {}
        | SIZEOF OP_ROUND type_name CL_ROUND        {}
        ;

unary_operator
        : BIT_AND   {$$='&';}
        | MUL       {$$='*';}
        | PLUS      {$$='+';}
        | MIN       {$$='-';}
        | BIT_NOT   {$$='~';}
        | NOT       {$$='!';}
        ;

cast_expression
        : unary_expression                              {$$=$1;}
        | OP_ROUND type_name CL_ROUND cast_expression   {//Handling type cast
            $$=new array_type();
            $$->Array=convertType($4->Array,var_type);
        }
        ;

multiplicative_expression
        : cast_expression       {
            $$=new expression();
            if($1->struc_type=="arr"){
                $$->loc=symbolTbl::gentemp($1->loc->type);
                emit("=[]",$$->loc->name,$1->Array->name,$1->loc->name);
            }
            else if($1->struc_type=="ptr"){
                $$->loc=$1->loc;
            }
            else{
                $$->loc=$1->Array;
            }
        }
        | multiplicative_expression MUL cast_expression     {
            if(typecheck($1->loc,$3->Array)){
                $$=new expression();
                data_type* a=new data_type($1->loc->type->type);
                $$->loc=symbolTbl::gentemp(a);
                emit("*", $$->loc->name, $1->loc->name, $3->Array->name);    
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
        | multiplicative_expression DIV cast_expression     {
            if(typecheck($1->loc,$3->Array)){
                $$=new expression();
                data_type* a=new data_type($1->loc->type->type);
                $$->loc=symbolTbl::gentemp(a);
                emit("/", $$->loc->name, $1->loc->name, $3->Array->name);
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
        | multiplicative_expression MOD cast_expression     {
            if(typecheck($1->loc,$3->Array)){
                $$=new expression();
                data_type* a=new data_type($1->loc->type->type);
                $$->loc=symbolTbl::gentemp(a);
                emit("%", $$->loc->name, $1->loc->name, $3->Array->name);   
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
        ;

additive_expression
        : multiplicative_expression                             {$$=$1;}
        | additive_expression PLUS multiplicative_expression    {
            if(typecheck($1->loc,$3->loc)){
                $$=new expression();
                data_type* a=new data_type($1->loc->type->type);
                $$->loc=symbolTbl::gentemp(a);
                emit("+", $$->loc->name, $1->loc->name, $3->loc->name);    
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
        | additive_expression MIN multiplicative_expression     {
            if(typecheck($1->loc,$3->loc)){
                $$=new expression();
                data_type* a=new data_type($1->loc->type->type);
                $$->loc=symbolTbl::gentemp(a);
                emit("-", $$->loc->name, $1->loc->name, $3->loc->name);           
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
        ;

shift_expression
        : additive_expression                               {$$=$1;}
        | shift_expression LSHIFT additive_expression       {
            if($3->loc->type->type=="int"){
                $$=new expression();
                data_type* a=new data_type("int");
                $$->loc=symbolTbl::gentemp(a);
                emit("<<", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Shift expression is being applied with non integer shift values"));
            }
        }
        | shift_expression RSHIFT additive_expression       {
            if($3->loc->type->type=="int"){
                $$=new expression();
                data_type* a=new data_type("int");
                $$->loc=symbolTbl::gentemp(a);
                emit(">>", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Shift expression is being applied with non integer shift values"));
            }
        }
        ;

relational_expression
        : shift_expression                              {$$=$1;}
        | relational_expression LT shift_expression     {
            if(typecheck($1->loc,$3->loc)){
                $$=new expression();
                $$->type="bool";
                $$->truelist=makelist(nextinstr());//Handling true list and false list
                $$->falselist=makelist(nextinstr()+1);
                emit("<","",$1->loc->name,$3->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
        | relational_expression GT shift_expression     {
            if(typecheck($1->loc,$3->loc)){
                $$=new expression();
                $$->type="bool";
                $$->truelist=makelist(nextinstr());//Handling true list and false list
                $$->falselist=makelist(nextinstr()+1);
                emit(">","",$1->loc->name,$3->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
        | relational_expression LEQ shift_expression    {
            if(typecheck($1->loc,$3->loc)){
                $$=new expression();
                $$->type="bool";
                $$->truelist=makelist(nextinstr());
                $$->falselist=makelist(nextinstr()+1);
                emit("<=","",$1->loc->name,$3->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
        | relational_expression GEQ shift_expression    {
            if(typecheck($1->loc,$3->loc)){
                $$=new expression();
                $$->type="bool";
                $$->truelist=makelist(nextinstr());
                $$->falselist=makelist(nextinstr()+1);
                emit(">=","",$1->loc->name,$3->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
        ;

equality_expression
        : relational_expression                             {$$=$1;}
        | equality_expression EQEQ relational_expression    {
            if(typecheck($1->loc,$3->loc)){
                conv_bool_2_int($1);
                conv_bool_2_int($3);
                $$=new expression();
                $$->type="bool";
                $$->truelist=makelist(nextinstr());//Handling true list and false list
                $$->falselist=makelist(nextinstr()+1);
                emit("==","",$1->loc->name,$3->loc->name);
                emit("goto","_");
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
        | equality_expression NEQ relational_expression     {
            if(typecheck($1->loc,$3->loc)){
                conv_bool_2_int($1);
                conv_bool_2_int($3);
                $$=new expression();
                $$->type="bool";
                $$->truelist=makelist(nextinstr());//Handling true list and false list
                $$->falselist=makelist(nextinstr()+1);
                emit("!=","",$1->loc->name,$3->loc->name);
                emit("goto","_");
            }
            else{
                yyerror(strdup("Types of the operands to be compared does not match"));
            }
        }
        ;

AND_expression
        : equality_expression                           {$$=$1;}
        | AND_expression BIT_AND equality_expression    {
            if(typecheck($1->loc,$3->loc)){
                conv_bool_2_int($1);
                conv_bool_2_int($3);
                $$=new expression();
                $$->type="non_bool";
                data_type* a=new data_type("int");
                $$->loc=symbolTbl::gentemp(a);
                emit("&",$$->loc->name,$1->loc->name,$3->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
        ;

exclusive_OR_expression
        : AND_expression                                    {$$=$1;}
        | exclusive_OR_expression BIT_XOR AND_expression    {
            if(typecheck($1->loc,$3->loc)){
                conv_bool_2_int($1);
                conv_bool_2_int($3);
                $$=new expression();
                $$->type="non_bool";
                data_type* a=new data_type("int");
                $$->loc=symbolTbl::gentemp(a);
                emit("^", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
        ;

inclusive_OR_expression
        : exclusive_OR_expression                                   {$$=$1;}
        | inclusive_OR_expression BIT_OR exclusive_OR_expression    {
            if(typecheck($1->loc,$3->loc)){
                conv_bool_2_int($1);
                conv_bool_2_int($3);
                $$=new expression();
                $$->type="non_bool";
                data_type* a=new data_type("int");
                $$->loc=symbolTbl::gentemp(a);
                emit("|", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else{//Type mismatch
                yyerror(strdup("Types of the operands does not match"));
            }
        }
        ;

logical_AND_expression
        : inclusive_OR_expression                                           {$$=$1;}
        | logical_AND_expression AND next_instr inclusive_OR_expression     {//next_instr is added to augment grammer
            conv_int_2_bool($1);
            conv_int_2_bool($4);
            $$=new expression();
            $$->type="bool";
            backpatch($1->truelist,$3);//Backpatching truelist to the operand
            $$->truelist=$4->truelist;
            $$->falselist=merge($1->falselist,$4->falselist);
        }
        ;

logical_OR_expression
        : logical_AND_expression                                        {$$=$1;}
        | logical_OR_expression OR next_instr logical_AND_expression    {//next_instr is added to augment grammer
            conv_int_2_bool($1);
            conv_int_2_bool($4);
            $$=new expression();
            $$->type="bool";
            backpatch($1->falselist,$3);//Backpatching falselist to the operand
            $$->falselist=$4->falselist;
            $$->truelist=merge($1->truelist,$4->truelist);
        }
        ;

conditional_expression
        : logical_OR_expression     {$$=$1;}
        | logical_OR_expression next_list Q_MARK next_instr expression next_list COLON next_instr conditional_expression      {//next_list is added to jump to else part
            $$=new expression();
            $$->loc=symbolTbl::gentemp($5->loc->type);
            $$->loc->update($5->loc->type);
            emit("=",$$->loc->name,$9->loc->name);
            list<int> l1=makelist(nextinstr());
            emit("goto", "");
            backpatch($6->nextlist,nextinstr());
            emit("=",$$->loc->name,$5->loc->name);
            list<int> l2=makelist(nextinstr());
            l1=merge(l1,l2);
            emit("goto","");
            backpatch($2->nextlist,nextinstr());              
            conv_int_2_bool($1);                              
            backpatch($1->truelist,$4);//Backpatchings                
            backpatch($1->falselist,$8);                    
            backpatch(l1,nextinstr());
        }
        ;

next_instr
        : %empty    {$$=nextinstr();}
        ;

next_list
        : %empty    {//To prevent fallthrough
            $$=new statement();
            $$->nextlist=makelist(nextinstr());
            emit("goto","");
        }
        ;

assignment_expression
        : conditional_expression                                        {$$=$1;}
        | unary_expression assignment_operator assignment_expression    {
            if($1->struc_type=="arr"){
                $3->loc=convertType($3->loc,$1->type->type);
                emit("[]=",$1->Array->name,$1->loc->name,$3->loc->name);
            }
            else if($1->struc_type=="ptr"){
                emit("*=",$1->Array->name,$3->loc->name);
            }
            else{
                $3->loc=convertType($3->loc,$1->Array->type->type);
                emit("=",$1->Array->name,$3->loc->name);
            }
            $$=$3;
        }
        ;

assignment_operator
        : EQ        {}
        | MULEQ     {}
        | DIVEQ     {}
        | MODEQ     {}
        | ADDEQ     {}
        | SUBEQ     {}
        | LSHEQ     {}
        | RSHEQ     {}
        | ANDEQ     {}
        | XOREQ     {}
        | OREQ      {}
        ;

expression
        : assignment_expression                     {$$=$1;}
        | expression COMMA assignment_expression    {}
        ;

constant_expression:
        conditional_expression  {}
        ;

declaration
        : declaration_specifiers init_declarator_list SEMICOLON     {}
        | declaration_specifiers SEMICOLON                          {}
        ;

declaration_specifiers
        : storage_class_specifier declaration_specifiers    {}
        | storage_class_specifier                           {}
        | type_specifier declaration_specifiers             {}
        | type_specifier                                    {}
        | type_qualifier declaration_specifiers             {}
        | type_qualifier                                    {}
        | function_specifier declaration_specifiers         {}
        | function_specifier                                {}
        ;

type_qualifier
        : CONST     {}
        | RESTRICT  {}
        | VOLATILE  {}
        ;

init_declarator_list
        : init_declarator                               {}
        | init_declarator_list COMMA init_declarator    {}
        ;

init_declarator
        : declarator                    {$$=$1;}
        | declarator EQ initializer     {if($3->value !=""){$1->value=$3->value;}emit("=", $1->name, $3->name);}
        ;

type_specifier
        : VOID              {var_type="void";}
        | CHAR              {var_type="char";}
        | SHORT             {var_type="short";}
        | INT               {var_type="int";}
        | LONG              {var_type="long";}
        | FLOAT             {var_type="float";}
        | DOUBLE            {var_type="double";}
        | SIGNED            {var_type="signed";}
        | UNSIGNED          {var_type="unsigned";}
        | BOOL              {var_type="bool";}
        | COMPLEX           {var_type="complex";}
        | IMAGINARY         {var_type="imaginary";}
        | enum_specifier    {}
        ;

storage_class_specifier
        : AUTO      {}
        | REGISTER  {}
        | STATIC    {}
        | EXTERN    {}
        ;

specifier_qualifier_list
        : type_specifier specifier_qualifier_list_opt       {}
        | type_qualifier specifier_qualifier_list_opt       {}
        ;

specifier_qualifier_list_opt
        : specifier_qualifier_list      {}
        | %empty                        {}
        ;

enum_specifier
        : ENUM identifier_opt OP_CURLY enumerator_list CL_CURLY         {}
        | ENUM IDENTIFIER                                               {}
        | ENUM identifier_opt OP_CURLY enumerator_list COMMA CL_CURLY   {}
        ;

identifier_opt
        : IDENTIFIER        {}
        | %empty            {}
        ;

enumerator_list
        : enumerator                            {}
        | enumerator_list COMMA enumerator      {}
        ;

enumerator
        : IDENTIFIER                            {}
        | IDENTIFIER EQ constant_expression     {}
        ;

function_specifier
        : INLINE    {}
        ;

declarator
        : pointer direct_declarator     {
            data_type* temp=$1;
            while(temp->arrtype!=NULL){
                temp=temp->arrtype;
            }
            temp->arrtype=$2->type;
            $$=$2->update($1);
        }
        | direct_declarator             {}
        ;

direct_declarator
        : IDENTIFIER    {
            $$=pres_table->addsym(id);
            data_type* a=new data_type(var_type);
            $$->update(a);
            prev_symbol=$$;
        }
        | OP_ROUND declarator CL_ROUND      {$$=$2;}
        | direct_declarator OP_SQUARE type_qualifier_list CL_SQUARE                             {}
        | direct_declarator OP_SQUARE type_qualifier_list assignment_expression CL_SQUARE       {}
        | direct_declarator OP_SQUARE assignment_expression CL_SQUARE       {//array declaration
            data_type *t=$1->type;
            data_type* prev=NULL;
            while(t->type=="arr"){
                prev=t;
                t=t->arrtype;
            }
            if(prev==NULL){
                int temp=stoi($3->loc->value);
                if(temp<=0){
                    yyerror(strdup("Array size should be positive value"));
                }
                data_type* tp=new data_type("arr",$1->type,temp);
                $$=$1->update(tp);
            }
            else{
                int temp=stoi($3->loc->value);
                if(temp<=0){
                    yyerror(strdup("Array size should be positive value"));
                }
                data_type* a=new data_type("arr",t,temp);
                prev->arrtype=a;
                $$=$1->update($1->type);
            }
        }
        | direct_declarator OP_SQUARE CL_SQUARE     {//array declaration informal
            data_type* t=$1->type;
            data_type* prev=NULL;
            while(t->type=="arr"){
                prev=t;
                t=t->arrtype;
            }
            if(prev==NULL){
                data_type* a=new data_type("arr",$1->type,0);
                $$=$1->update(a);
            }
            else{
                data_type* a=new data_type("arr",t,0);
                prev->arrtype=a;
                $$=$1->update($1->type);
            }
        }
        | direct_declarator OP_SQUARE STATIC type_qualifier_list assignment_expression CL_SQUARE    {}
        | direct_declarator OP_SQUARE STATIC assignment_expression CL_SQUARE                        {}
        | direct_declarator OP_SQUARE type_qualifier_list STATIC assignment_expression CL_SQUARE    {}
        | direct_declarator OP_SQUARE type_qualifier_list MUL CL_SQUARE                             {}
        | direct_declarator OP_SQUARE MUL CL_SQUARE                                                 {}
        | direct_declarator OP_ROUND identifier_list CL_ROUND                                       {}
        | direct_declarator OP_ROUND change_table parameter_type_list CL_ROUND                      {//function declaration,change_table added to augment the grammar
            pres_table->name=$1->name;
            if($1->type->type!="void"){
                symbol* sym=pres_table->lookup("return");   
                sym->update($1->type);
            }
            $1->nested_table=pres_table;
            pres_table->parent=global_table; 
            switchTable(global_table);
            prev_symbol=$$;
        }
        | direct_declarator OP_ROUND change_table CL_ROUND          {
            pres_table->name=$1->name;
            if($1->type->type!="void"){
                symbol* sym=pres_table->lookup("return");   
                sym->update($1->type);
            }
            $1->nested_table=pres_table;
            pres_table->parent=global_table; 
            switchTable(global_table);        
            prev_symbol=$$;
        }
        ;

type_qualifier_list_opt
        : type_qualifier_list       {}
        | %empty                    {}
        ;

pointer
        : MUL type_qualifier_list_opt               {$$=new data_type("ptr");}
        | MUL type_qualifier_list_opt pointer       {$$=new data_type("ptr",$3);}
        ;

type_qualifier_list
        : type_qualifier                        {}
        | type_qualifier_list type_qualifier    {}
        ;

parameter_type_list
        : parameter_list                {}
        | parameter_list COMMA SO_ON    {}
        ;

parameter_list
        : parameter_declaration                         {}
        | parameter_list COMMA parameter_declaration    {}
        ;

parameter_declaration
        : declaration_specifiers declarator     {}
        | declaration_specifiers                {}
        ;

identifier_list
        : IDENTIFIER                            {}
        | identifier_list COMMA IDENTIFIER      {}
        ;

type_name
        : specifier_qualifier_list              {}
        ;

initializer
        : assignment_expression                         {$$=$1->loc;}
        | OP_CURLY initializer_list CL_CURLY            {}
        | OP_CURLY initializer_list COMMA CL_CURLY      {}
        ;

initializer_list
        : designation_opt initializer                           {}
        | initializer_list COMMA designation_opt initializer    {}
        ;

designation_opt
        : designation       {}
        | %empty            {}
        ;

designation
        : designator_list EQ    {}
        ;

designator_list
        : designator                    {}
        | designator_list designator    {}
        ;

designator
        : OP_SQUARE constant_expression CL_SQUARE       {}
        | DOT IDENTIFIER                                {}
        ;

statement
        : labeled_statement         {}
        | compound_statement        {$$=$1;}
        | expression_statement      {$$=new statement();$$->nextlist=$1->nextlist;}
        | selection_statement       {$$=$1;}
        | iteration_statement       {$$=$1;}
        | jump_statement            {$$=$1;}
        ;

loop_statement
        : labeled_statement         {}
        | expression_statement      {$$=new statement();$$->nextlist=$1->nextlist;}
        | selection_statement       {$$=$1;}
        | iteration_statement       {$$=$1;}
        | jump_statement            {$$=$1;}
        ;

labeled_statement
        : IDENTIFIER COLON statement                    {}
        | CASE constant_expression COLON statement      {}
        | DEFAULT COLON statement                       {}
        ;

compound_statement
        : OP_CURLY new_table change_table block_item_list_opt CL_CURLY      {$$=$4;switchTable(pres_table->parent);}
        ;

new_table
        : %empty    {//to add new table
            string new_name=pres_table->name + "_" + block_type + "_" + to_string(ntables++);
            symbol* sym=pres_table->lookup(new_name);
            sym->name=new_name;
            sym->type=new data_type("block");
            sym->nested_table=new symbolTbl(new_name);
            sym->nested_table->parent=pres_table;
            prev_symbol=sym;
        }
        ;

change_table
        : %empty    {//to change tables
            if(prev_symbol->nested_table != NULL){
                switchTable(prev_symbol->nested_table);
                emit("label",pres_table->name);
            }
            else{
                switchTable(new symbolTbl(""));
            }
        }
        ;

block_item_list_opt
        : block_item_list       {$$=$1;}
        | %empty                {$$=new statement();}
        ;

block_item_list
        : block_item                                {$$=$1;}
        | block_item_list next_instr block_item     {$$=$3;backpatch($1->nextlist, $2);}
        ;

block_item
        : declaration       {$$=new statement();}
        | statement         {$$=$1;}
        ;

expression_statement
        : expression SEMICOLON      {$$=$1;}
        | SEMICOLON                 {$$=new expression();}
        ;

selection_statement
        : IF OP_ROUND expression next_list CL_ROUND next_instr statement next_list %prec LOWER_THAN_ELSE        {
            conv_int_2_bool($3);
            backpatch($4->nextlist,nextinstr());
            backpatch($3->truelist,$6);
            list<int> temp=merge($3->falselist,$7->nextlist);
            $$=new statement();
            $$->nextlist=merge(temp,$8->nextlist);
        }
        | IF OP_ROUND expression next_list CL_ROUND  next_instr statement next_list ELSE next_instr statement   {
            conv_int_2_bool($3);
            backpatch($4->nextlist,nextinstr());
            backpatch($3->truelist,$6);
            backpatch($3->falselist,$10);
            list<int> temp=merge($7->nextlist,$8->nextlist);
            $$=new statement();
            $$->nextlist=merge(temp,$11->nextlist);
        }
        | SWITCH OP_ROUND expression CL_ROUND statement     {}
        ;

iteration_statement
        : WHILE while_block OP_ROUND new_table change_table next_instr expression CL_ROUND next_instr loop_statement    {
            conv_int_2_bool($7);
            backpatch($10->nextlist, $6);
            backpatch($7->truelist, $9);
            $$=new statement();
            $$->nextlist=$7->falselist;
            emit("goto",to_string($6));
            block_type="";
            switchTable(pres_table->parent);
        }
        | WHILE while_block OP_ROUND new_table change_table next_instr expression CL_ROUND OP_CURLY next_instr block_item_list_opt CL_CURLY     {
            conv_int_2_bool($7);
            backpatch($11->nextlist, $6);
            backpatch($7->truelist, $10);
            $$=new statement();
            $$->nextlist=$7->falselist;
            emit("goto",to_string($6));
            block_type="";
            switchTable(pres_table->parent);
        }
        | DO dowhile_block next_instr loop_statement next_instr WHILE OP_ROUND expression CL_ROUND SEMICOLON      {
            conv_int_2_bool($8);
            backpatch($8->truelist, $3);
            backpatch($4->nextlist, $5);
            $$=new statement();
            $$->nextlist=$8->falselist;
            block_type="";
        }
        | DO dowhile_block OP_CURLY next_instr block_item_list_opt CL_CURLY next_instr WHILE OP_ROUND expression CL_ROUND SEMICOLON       {
            conv_int_2_bool($10);
            backpatch($10->truelist, $4);
            backpatch($5->nextlist, $7);
            $$=new statement();
            $$->nextlist=$10->falselist;
            block_type="";
        }
        | FOR for_block OP_ROUND new_table change_table declaration next_instr expression_statement next_instr expression next_list CL_ROUND next_instr loop_statement     {
            conv_int_2_bool($8);
            backpatch($8->truelist, $13);
            backpatch($11->nextlist, $7);
            backpatch($14->nextlist, $9);
            emit("goto", to_string($9));
            $$=new statement();
            $$->nextlist=$8->falselist;
            block_type="";
            switchTable(pres_table->parent);
        }
        | FOR for_block OP_ROUND new_table change_table expression_statement next_instr expression_statement next_instr expression next_list CL_ROUND next_instr loop_statement    {
            conv_int_2_bool($8);
            backpatch($8->truelist, $13);
            backpatch($11->nextlist, $7);
            backpatch($14->nextlist, $9);
            emit("goto", to_string($9));
            $$=new statement();
            $$->nextlist=$8->falselist;
            block_type="";
            switchTable(pres_table->parent);
        }
        | FOR for_block OP_ROUND new_table change_table declaration next_instr expression_statement next_instr expression next_list CL_ROUND next_instr OP_CURLY block_item_list_opt CL_CURLY      {
            conv_int_2_bool($8);
            backpatch($8->truelist, $13);
            backpatch($11->nextlist, $7);
            backpatch($15->nextlist, $9);
            emit("goto", to_string($9));
            $$=new statement();
            $$->nextlist=$8->falselist;
            block_type="";
            switchTable(pres_table->parent);
        }
        | FOR for_block OP_ROUND new_table change_table expression_statement next_instr expression_statement next_instr expression next_list CL_ROUND next_instr OP_CURLY block_item_list_opt CL_CURLY     {
            conv_int_2_bool($8);                 
            backpatch($8->truelist, $13);          
            backpatch($11->nextlist, $7);          
            backpatch($15->nextlist, $9);          
            emit("goto", to_string($9)); 
            $$=new statement();
            $$->nextlist=$8->falselist;
            block_type="";
            switchTable(pres_table->parent);
        }
        ;

while_block
        : %empty        {block_type="WHILE";}
        ;

dowhile_block
        : %empty        {block_type="DO_WHILE";}
        ;

for_block
        : %empty        {block_type="for";}

jump_statement
        : GOTO IDENTIFIER SEMICOLON     {}
        | CONTINUE SEMICOLON            {$$=new statement();}
        | BREAK SEMICOLON               {$$=new statement();}
        | RETURN expression SEMICOLON   {$$=new statement();emit("return",$2->loc->name);}
        | RETURN SEMICOLON              {$$=new statement();emit("return","");}
        ;

translation_unit
        : external_declaration                      {}
        | translation_unit external_declaration     {}
        ;

external_declaration
        : function_definition       {}
        | declaration               {}
        ;

function_definition
        : declaration_specifiers declarator declaration_list_opt change_table OP_CURLY block_item_list_opt CL_CURLY      {pres_table->parent=global_table;ntables=0;switchTable(global_table);}
        ;

declaration_list_opt
        : declaration_list      {}
        | %empty                {}
        ;
        
declaration_list
        : declaration                       {}
        | declaration_list declaration      {}
        ;

program
        : translation_unit      {}
        ;

%%