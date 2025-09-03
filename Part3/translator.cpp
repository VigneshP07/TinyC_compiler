#include "translator.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Global Variables
quad_array quads;
symbol* prev_symbol;
symbolTbl* pres_table;
symbolTbl* global_table;
int ntables;
string block_type;
string var_type;

//Constructor for symbol class
symbol::symbol(string name_, string t_, data_type* arrtype_, int width_):name(name_),value("null"),offset(0),nested_table(NULL){
    this->type=new data_type(t_,arrtype_,width_);
    this->size=size_of_type(this->type);
}

//Method to update the type of the symbol and return its pointer
symbol* symbol::update(data_type* a1){
    this->type=a1;
    this->size=size_of_type(this->type);
    return this;
}

//Emits a quad to convert the symbol into the given type and returns pointer to the symbol
symbol* symbol::convert(string a1){
    symbol* sym=symbolTbl::gentemp(a1);
    if(this->type->type==a1){
        emit("=",sym->name,this->name);
    }
    else{//if type is not same, convertions takes place
        string newname=this->type->type + "_2_" + a1 + "(" + this->name + ")";
        emit("=",sym->name,newname);
    }
    return sym;
}

//Constructor for symbolTbl class
symbolTbl::symbolTbl(string name_, symbolTbl* parent):name(name_),tempcount(0){}

//Member function: Lookup function
symbol* symbolTbl::lookup(string name){
    for(list<symbol>::iterator i=table.begin();i!=table.end();i++){//searching the table
        if(i->name==name){
            return &(*i);
        }
    }

    symbol* s=NULL;
    if(this->parent != NULL){//searching parent tables recursively
        s=this->parent->lookup(name);
    }

    if(pres_table==this && s==NULL){//if not found it is added and returned
        return this->addsym(name);
    }
    else if(s!=NULL){//if found it is returned
        return s;
    }
    else{
        return NULL;
    }
}

//Member function to add a symbol to the symbol table and return its pointer
symbol* symbolTbl::addsym(string name){
    symbol* s=new symbol(name);
    table.push_back(*s);//adding at the end
    return &(table.back());
}

//Member function to generate a new temporary given the data type and initial value and return its pointer
symbol* symbolTbl::gentemp(data_type* type,string x){
    string name="t" + to_string(pres_table->tempcount);
    pres_table->tempcount+=1;
    symbol* s=new symbol(name);
    s->type=type;
    s->size=size_of_type(type);
    s->value=x;
    pres_table->table.push_back(*s);
    return &(pres_table->table.back());
}

//Member function to generate a new temporary given the data type (as a string) and initial value and return its pointer
symbol* symbolTbl::gentemp(string type,string x){
    string name="t"+to_string(pres_table->tempcount);
    pres_table->tempcount+=1;
    symbol* s=new symbol(name);
    data_type* symtype=new data_type(type);
    s->type=symtype;
    s->size=size_of_type(symtype);
    s->value=x;
    pres_table->table.push_back(*s);
    return &(pres_table->table.back());
}

//Member function to update the offsets of the entries in the symbol table
void symbolTbl::update(){
    list<symbolTbl*> A;
    int temp;
    for(list<symbol>::iterator i=this->table.begin();i!=this->table.end();i++){
        if(i==this->table.begin()){
            temp=i->size;
        }
        else{
            i->offset=temp;
            temp+=i->size;
        }
        if(i->nested_table!=NULL){
            A.push_back(i->nested_table);
        }
    }
    for(auto i=A.begin();i!=A.end();i++){//recursively doing it for nested tables
        (*i)->update();
    }
    return;
}

//Member function to print the symbol table
void symbolTbl::print(){
    for(int i=0;i<120;i++){
        cout << '-';
    }
    cout << endl;

    cout << "Symboltbl name: " << setfill(' ') << left << setw(50) << this->name;
    cout << "Parent table: " << setfill(' ') << left << setw(50) << ((this->parent != NULL) ? this->parent->name : "NULL") << endl;
    
    for(int i=0;i<120;i++){
        cout << '-';
    }
    cout << endl;
    
    cout << setfill(' ') << left << setw(25) <<  "Name";
    cout << left << setw(30) << "Type";
    cout << left << setw(20) << "Initial Value";
    cout << left << setw(15) << "Size";
    cout << left << setw(15) << "Offset";
    cout << left << "Nested" << endl;
    
    for(int i=0;i<120;i++){
        cout << '-';
    }
    cout << endl;
    
    list<symbolTbl*> A;
    for(auto i=this->table.begin();i!=this->table.end();i++){
        cout << left << setw(25) << i->name;
        cout << left << setw(30) << give_type(i->type);
        cout << left << setw(20) << (i->value!=""?i->value:"null");
        cout << left << setw(15) << i->size;
        cout << left << setw(15) << i->offset;
        cout << left;
        if(i->nested_table!=NULL){
            cout << i->nested_table->name << endl;
            A.push_back(i->nested_table);
        }
        else{
            cout << "NULL" << endl;
        }
    }

    for(int i=0;i<120;i++){
        cout << '-';
    }
    cout << endl << endl << endl;
    
    for(auto i=A.begin();i!=A.end();i++){
        (*i)->print();
    }
    return;
}

//Constructor for data_type class
data_type::data_type(string type_,data_type* arrtype_,int width_):type(type_),width(width_),arrtype(arrtype_){}

//Constructor for quad class(argument-1 is given as string)
quad::quad(string res,string a,string oper,string b):result(res),arg1(a),op(oper),arg2(b){}

//Constructor for quad class(argument-1 is given as integer)
quad::quad(string res, int a, string oper, string b):result(res),op(oper),arg2(b){
    arg1=to_string(a);
}

//Constructor for quad class(argument-1 is given as floating point value)
quad::quad(string res, float a, string oper, string b):result(res),op(oper),arg2(b){
    arg1=to_string(a);
}

//Member function to print the quad in desired format
void quad::print(){
    if(op=="="){
        cout << this->result << "=" << this->arg1;
    }
    else if(op=="goto" || op=="param" || op=="return"){
        cout << this->op << " " << this->result;
    }
    else if(op=="call"){
        cout << this->result << "=call " << this->arg1 << ", " << this->arg2;
    }
    else if(op=="label"){
        cout << this->result << ": ";
    }
    else if(op=="<<" || op==">>" || op=="|" || op=="&" || op=="+" || op=="-" || op=="*" || op=="/" || op=="%" || op=="^"){
        cout << this->result << "=" << this->arg1 << " " << this->op << " " << this->arg2;
    }
    else if(op=="==" || op=="!=" || op=="<" || op==">" || op=="<=" || op==">="){
        cout << "if " << this->arg1 << " " << this->op << " " << this->arg2 << " goto " << this->result;
    }
    else if(op=="*="){
        cout << "*" << this->result << "=" << this->arg1;
    }
    else if(op=="[]="){
        cout << this->result << "[" << this->arg1 << "]=" << this->arg2;
    }
    else if(op=="=[]"){
        cout << this->result << "=" << this->arg1 << "[" << this->arg2 << "]";
    }
    else if(op=="= &" || op=="= *" || op=="= -" || op=="= ~" || op=="= !"){
        cout << this->result << " " << this->op << this->arg1;
    }
    else{
        cout << "Invalid operator";
    }
    return;
}

//Member function to print the quads present in a quad array in desired format
void quad_array::print(){
    for(int i=0;i<120;i++){
        cout << '_';
    }
    cout << endl;

    cout << "TAC: " << endl;

    for(int i=0; i < 120; i++) {
        cout << '_';
    }
    cout<<endl;

    int cnt=0;
    for(vector<quad>::iterator i=array.begin();i!=array.end();i++){
        if(i->op!="label") {
            cout << left << setw(4) << cnt << ":    ";
            i->print();
        }
        else {
            cout << endl << left << setw(4) << cnt << ": ";
            i->print();
        }
        cnt+=1;
        cout << endl;
    }
    return;
}

//Function to create a list with only element i in it and return the list
list<int> makelist(int i){
    list<int> temp(1,i);
    return temp;
}

//Function to merge the given lists and return the merged list
list<int> merge(list<int> &a,list<int> &b){
    a.merge(b);
    return a;
}

//Backpatch function: Allocating the temporary variables as result to the quad array in required position
void backpatch(list<int> &a,int i){
    string temp=to_string(i);
    for(auto i=a.begin();i!=a.end();i++){
        quads.array[*i].result=temp;
    }
    return;
}

//Function to check and convert the type of two given symbols
bool typecheck(symbol* &E1, symbol* &E2){
    if(check_data_type(E1->type,E2->type)){
        return true;
    }
    else if(E1->type->type=="float" || E2->type->type=="float"){
        E1=E1->convert("float");
        E2=E2->convert("float");
        return true;
    }
    else if(E1->type->type=="int" || E2->type->type=="int"){
        E1=E1->convert("int");
        E2=E2->convert("int");
        return true;
    }
    else{
        return false;
    }
}

//Function to check if the given data_types are similar
bool check_data_type(data_type* t1, data_type* t2){
    if(t1==NULL){
        if(t2==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(t2==NULL){
            return false;
        }
        else if(t1->type != t2->type){
            return false;
        }
        else{
            return check_data_type(t1->arrtype,t2->arrtype);
        }
    }
}

//Function to convert the type of a symbol to the given type and store it in symbol table, return its pointer
symbol* convertType(symbol* s, string t) {
    symbol* temp=symbolTbl::gentemp(new data_type(t));
    if(s->type->type=="int"){
        if(t=="float"){
            string newname="int_2_float(" + s->name + ")";
            emit("=",temp->name,newname);
            return temp;
        }
        else if(t=="char"){
            string newname="int_2_char(" + s->name + ")";
            emit("=",temp->name,newname);
            return temp;
        }
        else{
            return s;
        }
    }
    else if(s->type->type=="float"){
        if(t=="int"){
            string newname="float_2_int(" + s->name + ")";
            emit("=",temp->name,newname);
            return temp;
        }
        else if(t=="char"){
            string newname="float_2_char(" + s->name + ")";
            emit("=",temp->name,newname);
            return temp;
        }
        else{
            return s;
        }
    }
    else if(s->type->type=="char"){
        if(t=="float"){
            string newname="char_2_float(" + s->name + ")";
            emit("=",temp->name,newname);
            return temp;
        }
        else if(t=="int"){
            string newname="char_2_int(" + s->name + ")";
            emit("=",temp->name,newname);
            return temp;
        }
        else{
            return s;
        }
    }
    else{
        return s;
    }
}

//Function to convert int type expression to bool type and return it
expression* conv_int_2_bool(expression* E1){
    if(E1->type!="bool"){
        E1->falselist=makelist(nextinstr());
        emit("==",E1->loc->name,"0");
        E1->truelist=makelist(nextinstr());
        emit("goto","");
    }
    return E1;
}

//Function to convert bool type expression to int type and return it
expression* conv_bool_2_int(expression* E1){
    if(E1->type=="bool"){
        E1->loc=symbolTbl::gentemp(new data_type("int"));
        backpatch(E1->truelist,nextinstr());
        emit("=",E1->loc->name,"true");
        emit("goto",to_string(nextinstr()+1));
        backpatch(E1->falselist,nextinstr());
        emit("=",E1->loc->name,"false");
    }
    return E1;
}

//Function to change the present table to the given table
void switchTable(symbolTbl* T){
    pres_table=T;
}

//Function to return the next instruction number
int nextinstr(){
    return quads.array.size();
}

//Function to find size of the given data type
int size_of_type(data_type* t){
    if(t->type=="void"){
        return size_of_void;
    }
    else if(t->type=="int"){
        return size_of_int;
    }
    else if(t->type=="float"){
        return size_of_float;
    }
    else if(t->type=="char"){
        return size_of_char;
    }
    else if(t->type=="ptr"){
        return size_of_pointer;
    }
    else if(t->type=="func"){
        return size_of_function;
    }
    else if(t->type=="arr"){
        return t->width * size_of_type(t->arrtype);
    }
    else{
        return -1;
    }
}

//Function that returns the complete description of the given data type
string give_type(data_type* t){
    if(t==NULL){
        return "null";
    }
    if(t->type=="void" || t->type=="char" || t->type=="int" || t->type=="float" || t->type=="block" || t->type=="func"){
        return t->type;
    }
    else if(t->type=="arr"){
        return t->type + "(" + give_type(t->arrtype) + "," + to_string(t->width) + ")";
    }
    else if(t->type=="ptr"){
        return t->type + "(" + give_type(t->arrtype) + ")";
    }
    else{
        return "unknown";
    }
}

//Function to add a new quad when argument-1 is given as integer
void emit(string op, string result, int arg1, string arg2){
    quad* temp=new quad(result,arg1,op,arg2);
    quads.array.push_back(*temp);
}

//Function to add a new quad when argument-1 is given as floating point value
void emit(string op, string result, float arg1, string arg2){
    quad* temp=new quad(result,arg1,op,arg2);
    quads.array.push_back(*temp);
}

//Function to add a new quad when argument-1 is given as string
void emit(string op, string result, string arg1, string arg2){
    quad* temp=new quad(result,arg1,op,arg2);
    quads.array.push_back(*temp);
}

int main(){
    //Initializing the global variables
    ntables=0;
    global_table=new symbolTbl("Global");
    pres_table=global_table;
    var_type="";
    block_type="";
    
    //Parsing
    yyparse();

    //Printing the symbol tables and three address code
    global_table->update();
    global_table->print();
    quads.print();
    return 0;
}