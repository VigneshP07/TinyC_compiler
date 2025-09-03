
// Test single-line comment

/*
  Multi-line comment:
  Test for multi-line comment.
*/


// Identifiers
int main() {

    // Keywords and identifiers
    const Var = 105;
    static int static_var = 120;
    void func(void);
    volatile int volatile_var;
    extern float externVar;

    // Constants
    int abcd = 100;
    float efgh = 10.5e-2;
    char ijkl_ = 'a';
    const char* str_Literal = "This is a string literal";

    // Punctuators
    int a = 324, b = 190;
    int z = a + b;
    z%=2;
    z++;
    if(a == b){
        a = b;
    }
    else {
        b = a;
    }

    for(int i = 0; i < 5; i++) {
        continue;
    }

    while(a<=0){
        a+=2;
    }

    if(a != b){
        return 1;
    }
    else{
        return 0;
    }
}

void func(void){
    long long int mynum = 1234567890;
    const char* strl = "Another string literal";

    enum colors { RED, GREEN, BLUE };
    enum colors color = RED;

    int* pointerVar = &mynum;
    *pointerVar = 42;
    /* Comment testing
    Another multi-line comment.
    */
    // More single-line comments 

    printf("Color: %d, String: %s\n", color, strl);
}
