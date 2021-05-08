#include<stdio.h>
int main()
{
    printf("Enter the no of matrices");
    int n;
    scanf("%d",&n);
    int dimension[n+1];
    for(int i=0;i<=n;i++){
        scanf("%d",&dimension[i]);
    }
    //Indexing starts from 1
    int cost[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cost[i][j]=0;
        }
    }
    //Diagonal Corresponds to no of matrices included
    for(int diagonal=1;diagonal<n;diagonal++){
        for(int row=1;row<=n-diagonal;row++){
            int col=row+diagonal;
            //Set the cost to an Max Value
            cost[row][col]=99999;
            for(int k=row;k<col;k++){
                printf("%d %d %d \n",row,k,col);
                int q=cost[row][k]+cost[k+1][col]+dimension[row-1]*dimension[k]*dimension[col];
            if(q<cost[row][col])
                {
                    printf("%d %d %d\n",dimension[row-1],dimension[k],dimension[col]);
                    cost[row][col]=q;
                }               
                
            }
            
        }
    }
    printf("%d\n",cost[1][n]);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }
}