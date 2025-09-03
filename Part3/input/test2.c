//Function calls and returns with multi operators
int average_i(float a,float b, float c){
    float avg=a+b+c;
    avg=avg/3;
    int answer =(int)avg;
    return answer;
}

int minimum (int x, int y) {
    int ans;
    ans = x > y ? y:x;             
    return ans;
}


int main()
{
    int x=5;
    int n=10;

    float sum=1;
    float term=1;
    int temp;
    temp=term/sum;
    float result=average_i(x,n,sum);
    return 1;

}