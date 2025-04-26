#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row1,col1,row2,col2;
    printf("enter rows and column for first matrix");
    scanf("%d%d",&row1,&col1);
    printf("enter rows and column for second matrix");
    scanf("%d%d",&row2,&col2);
    if(col1!=row2)
    {
        printf("matrix multiplication not possible");
        return 1;
    }
    int** mat1= (int*)malloc(row1*sizeof(int));
    int** mat2= (int*)malloc(row2*sizeof(int));
    int** res= (int*)malloc(row1*sizeof(int));
    for(int i=0;i<row2;i++)
        mat2[i]=((int*)malloc(col2*sizeof(int)));
    printf("enter elements of first matrix:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
   printf("enter elements of second matrix:\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }


        for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            res[i][j]=0;
            for(int k=0;k<col2;k++)
                res[i][j]+=mat1[i][k]*mat2[k][j];
        }
        }
    printf("Resultant matrix:\n");
     for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++)
            printf("%d",res[i][j]);
        printf("\n");
     }



}