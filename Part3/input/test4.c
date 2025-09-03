//Implicit and explicit typecasting and pointers
int main()
{

    int a;
    float b;
    a=4;
    b=9.9;
    b=(float)a;
    float x=b*a;
    int y=(int)x;
    int z=a*b;
    int *p;
    p = &a;
    *p=10;
    return 0;
}