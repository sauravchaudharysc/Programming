#include<bits/stdc++.h>
using namespace std;
int getCount(char keypad[][3], int n) 
{ 
    if(keypad == NULL || n <= 0) 
        return 0; 
    if(n == 1) 
        return 10; 
  
    // left, up, right, down move from current location 
    int row[] = {0, 0, -1, 0, 1}; 
    int col[] = {0, -1, 0, 1, 0}; 
  
    int count[10][n+1]; 
    int num = 0; 
    int nextNum=0, totalCount = 0; 
  
    //Filling the first column and second column.
    //For length=0 output 0. For length 1 output 10
    for (int i=0; i<=9; i++) 
    { 
        count[i][0] = 0; 
        count[i][1] = 1; 
    } 
   
    for (int k=2; k<=n; k++) 
    { 
        for (int i=0; i<4; i++)  // Loop on keypad row 
        { 
            for (int j=0; j<3; j++)   // Loop on keypad column 
            { 
                // Process for 0 to 9 digits 
                if (keypad[i][j] != '*' && keypad[i][j] != '#') 
                { 
                    /* Here we are counting the numbers starting with 
                     digit keypad[i][j] and of length k keypad[i][j] 
                     will become 1st digit, and we need to look for 
                     (k-1) more digits*/ 
                    num = keypad[i][j] - '0'; 
                    count[num][k] = 0; 
                    /*This get called after selecting a key so we need to apply moves on them
                    and see the number of ways it can move and form the give length*/
                    /*same,left,top,right,bottom then get number count of length k-1
                     add in count found so far*/
                    for (int move=0; move<5; move++) 
                    { 
                        int ro = i + row[move]; 
                        int co = j + col[move]; 
                        if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 && 
                           keypad[ro][co] != '*' && keypad[ro][co] != '#') 
                        { 
                            nextNum = keypad[ro][co] - '0'; 
                            count[num][k] += count[nextNum][k-1]; 
                        } 
                    } 
                } 
            } 
        } 
    } 
    /*To get the total count of all possible number of length n starting
    with digit 0,1...9*/
    totalCount = 0; 
    for (int i=0; i<=9; i++) 
        totalCount += count[i][n]; 
    return totalCount; 
} 
  

int main() 
{ 
   char keypad[4][3] = {{'1','2','3'}, 
                        {'4','5','6'}, 
                        {'7','8','9'}, 
                        {'*','0','#'}}; 
   printf("Count for numbers of length 1. %d:\n", getCount(keypad, 1)); 
   printf("Count for numbers of length 2. %d:\n", getCount(keypad, 2)); 
   printf("Count for numbers of length 3. %d:\n", getCount(keypad, 3)); 
   printf("Count for numbers of length 4. %d:\n", getCount(keypad, 4)); 
   printf("Count for numbers of length 5. %d:\n", getCount(keypad, 5)); 
  
   return 0; 
} 