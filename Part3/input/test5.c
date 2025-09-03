//If else statements and function with recursive calls

int factorial(int n){
    if(n==0){
        return 1;
    }
    else {
        return n*factorial(n-1);
    }
}

int main()
{
    int n=5;
    int result=factorial(n);
    if(result<=50){
        if(result>25){
            return result;
        }
        else return result+result;
    }
    return 0;
}