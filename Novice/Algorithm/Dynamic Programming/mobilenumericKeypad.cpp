#include<bits/stdc++.h>
using namespace std;

/*This get called after selecting a key so we need to apply moves on them
and see the number of ways it can move and form the give length*/
//same,left,top,right,bottom
int row[] = {0, 0, -1, 0, 1}; 
int col[] = {0, -1, 0, 1, 0}; 
int getCountUtil(char keypad[][3], int i, int j, int n)
 {
    //Base case
    if(keypad==NULL || n<=0){
        return 0;
    }
    if(n==1){
        return 1;        
    }
    int totalCount=0;
    for (int move=0; move<5; move++) 
    { 
        int ro = i + row[move]; 
        int co = j + col[move]; 
        if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 && 
           keypad[ro][co] != '*' && keypad[ro][co] != '#') 
        { 
            totalCount += getCountUtil(keypad, ro, co, n-1); 
        } 
    } 
    return totalCount;   
 }
int getCount(char keypad[][3],int n)
{
    //Base case
    if(keypad==NULL || n<=0){
        return 0;
    }
    //The no of ways we can press the keys to get length 1
    if(n==1){
        return 10;        
    }
    int totalCount=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if (keypad[i][j] != '*' && keypad[i][j] != '#') 
            { 
                totalCount += getCountUtil(keypad, i, j, n); 
            } 
        }
    }
    return totalCount;
    
}
int main()
{
    char keypad[4][3] = {{'1','2','3'}, 
                        {'4','5','6'}, 
                        {'7','8','9'}, 
                        {'*','0','#'}}; 
   printf("Count for numbers of length 1: %d\n", getCount(keypad, 1)); 
   printf("Count for numbers of length 2: %d\n", getCount(keypad, 2)); 
   printf("Count for numbers of length 3: %d\n", getCount(keypad, 3)); 
   printf("Count for numbers of length 4: %d\n", getCount(keypad, 4)); 
   printf("Count for numbers of length 5: %d\n", getCount(keypad, 5));
}