#include <stdio.h>

#define LENGTH 5


/**
    This function gets the following parameters:
    int matrix- holds binary matrix-
    matrix[i][j]=1 if worker i can do assignment j, otherwise 0
    int column- holds current column
    array int used- holds which rows were already used

    The function returns number of options from column
**/
int get_result(int matrix[][LENGTH],int column,int used[])
{
    int sum=0;
    for(int i=0;i<LENGTH;i++)
    {
        if(used[i]||!matrix[i][column]) continue;
        used[i]=1;
        if(column<LENGTH-1) sum+=get_result(matrix,column+1,used);
        else sum+=1;
        used[i]=0;
    }
    return sum;
}

int main()
{
    printf("Enter the matrix:\n");
    int matrix[LENGTH][LENGTH];
    int used[LENGTH]={0,0,0,0,0};
    for(int i=0;i<LENGTH;i++)
    {
        for(int k=0;k<LENGTH;k++) scanf("%d",&matrix[i][k]);
    }
    int result=get_result(matrix,0,used);
    printf("The result is %d",result);
}
