//Nested loops and multidimension array usage
int main()
{
    int i,j;

    int a[6][6];
    int b[5][5];
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            a[i][j] = i+j;
            
        }
    }
    for(i=4;i>=0;i--){
        for(j=4;j>=0;j--){
            b[i][j]=i-j;
        }
    }


    for(i=0;i<6;i++)
    {
        for(j=0;j<i;j++)
        {
            if(i<3 && j<3){
                a[i][j]=b[i][j];
            }
            else
            a[i][j] = a[j][i];
        }
    }

    return 0;
    
}