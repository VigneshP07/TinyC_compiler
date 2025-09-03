#include <iostream>
#include <vector>
#include <list>
using namespace std;

//Size of data types
#define size_of_void 0
#define size_of_int 4
#define size_of_float 8
#define size_of_char 1
#define size_of_pointer 4
#define size_of_function 0

//Class declarations
class symbol;
class symbolTbl;
class expression;
class statement;
class data_type;
class quad;
class quad_array;
class array_type;

//Global Variables
extern symbol* prev_symbol;
extern symbolTbl* pres_table;
extern symbolTbl* global_table;
extern int ntables;
extern string block_type;
extern string var_type;
extern string id;

//Function and variable related to parsing
extern int yyparse();
extern char* yytext;

//Class for symbol
class symbol{
    public:
        //Data members
        string name;
        data_type* type;
        string value;//initial value
        int size;
        int offset;
        symbolTbl* nested_table;

        //Constructor of the class
        symbol(string name_, string t_="int",data_type* arrtype=NULL, int width_=0);

        //Member functions
        symbol* convert(string t);
        symbol* update(data_type* t);
};

//Class for symbol table
class symbolTbl{
    public:
        //Data Members
        string name;
        list<symbol> table;
        symbolTbl* parent;
        int tempcount;

        //Constructor
        symbolTbl(string name_, symbolTbl* parent_=NULL);

        //Member functions
        symbol* lookup(string name);
        symbol* addsym(string name);
        static symbol* gentemp(data_type* type, string x="");
        static symbol* gentemp(string type, string x="");
        void update();
        void print();
};

//Class for expressions
class expression{
    public:
        //Data members
        string type;
        symbol* loc;//Pointer to current expression result in symbol table
        list<int> truelist, falselist;//used for boolean expressions
        list<int> nextlist;//used for statements
};

//Class for Statements
class statement{
    public:
        list<int> nextlist;
};

//Class for the data type of the variables
class data_type{
    public:
        //Data members
        string type;
        int width;
        data_type* arrtype;//for pointers and arrays

        //Constrctor
        data_type(string type_, data_type* arrtype_=NULL, int width_=1);
};

//Class for represnting quads
class quad{
    public:
        //Data Members
        string result;
        string op;
        string arg1;
        string arg2;

        //Constrctors
        quad(string res, string a, string oper="=", string b="");
        quad(string res, int a, string oper="=", string b="");
        quad(string res, float a, string oper="=", string b="");

        //Member function
        void print();
};

//Class for array of quads
class quad_array{
    public:
        //Data member
        vector<quad> array;//array of quads

        //Member function
        void print();
};

//Class for array type
class array_type{
    public:
        //Data members
        string struc_type;//"arr" or "ptr"
        symbol* loc;//location in symbol table of the offset
        symbol* Array;//location in symbol table of the array
        data_type* type;
};

//Other functions
list<int> makelist(int i);
list<int> merge(list<int> &a, list<int> &b);
void backpatch(list<int> &a, int i);
bool typecheck(symbol* &E1, symbol* &E2);
bool check_data_type(data_type* t1, data_type* t2);
symbol* convertType(symbol* s1, string t);

expression* conv_int_2_bool(expression* E1);
expression* conv_bool_2_int(expression* E1);
void switchTable(symbolTbl* T);
int nextinstr();
int size_of_type(data_type* t);
string give_type(data_type* t);
void emit(string op, string result, int arg1, string arg2="");
void emit(string op, string result, float arg1, string arg2="");
void emit(string op, string result, string arg1="", string arg2="");