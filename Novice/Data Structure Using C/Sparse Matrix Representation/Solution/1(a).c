#include<stdio.h> 
int main() 
{ 
    
    int rows,col,val;
    printf("Enter the no of rows :- ");
    scanf("%d",&rows);
    printf("Enter the no of columns :- ");
    scanf("%d",&col);
    int sparseMatrix[rows][col]; 
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
        printf("Enter the Value at [%d][%d]",i,j);    
        scanf("%d",&val);
        sparseMatrix[i][j]=val;
        }
        
    }
    int size = 0; 
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < col; j++) 
            if (sparseMatrix[i][j] != 0) 
                size++; 
  
    
    int compactMatrix[size][3]; 
  int k = 0; 
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < col; j++) 
            if (sparseMatrix[i][j] != 0) 
            { 
                compactMatrix[k][0] = i; 
                compactMatrix[k][1] = j; 
                compactMatrix[k][2] = sparseMatrix[i][j]; 
                k++; 
            } 
    printf("ROW   Col  Val\n");
    for (int i=0; i<size; i++) 
    { 
        for (int j=0; j<3; j++) 
            printf("%d     ", compactMatrix[i][j]); 
  
        printf("\n"); 
    } 
    return 0; 
} 
