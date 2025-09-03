extern int global_value;
static float pi=3.14;
int array[3]={2,6,9};
static int static_var = 50;
short var1 = 5;
_Bool is_valid =1;
volatile int vol_var=0;
int multiply(int,int);
int main(){
    global_value=multiply(array[0],array[1]);
    global_value++;
    for(int i=0;i<3;i++){
        global_value+=array[i];
    }
    int counter = (int)0;
    while (counter < 3) {
        global_value += counter;
        counter++;
        continue;
    }
    do {
        global_value--;
    } while (global_value > 10);
    
    global_value += static_var;

    switch (global_value) {
        case 10:
            global_value = multiply(global_value, 2);
            break;
        case 20:
            global_value = multiply(global_value, 3);
            break;
        default:
            global_value = multiply(global_value, 1);
            break;
    }
    global_value = global_value & var1;
    
    if (global_value < 100) {
        goto end_program;
    }
    else{
        global_value = (global_value<var1?counter&&2:var1%5);
    }
    printf("global value is %d",&global_value);
    return 0;
    end_program:
        return 0;
}

int multiply(int a,int b,...){
    return a*b;
}