#include<bits/stdc++.h>
using namespace std;
int longestPalindromicSubsequence(char str[]) //Or write char *str
{
    int n=strlen(str);
    int L[n][n];
    /*String of length 1 are palindrome of length 1.
    Diagonal elements are single character so thier length is marked 1*/
    for(int i=0;i<n;i++){
        L[i][i]=1;
    }
    /*We move Diagonally and difference between diagonal+1 gives the 
    no of character between them.*/
    /*If characters are same we check the first and second last elements
    subsequence count and add 2 to it*/
    /*If characters arent same then we take the maximum subsequence of excluding 
    last characters or excluding first character*/
    for (int diagonal=1; diagonal<n; diagonal++) 
    { 
        for (int row=0; row<=n-diagonal; row++) 
        { 
            int col = row+diagonal; 
            if (str[row] == str[col] && diagonal == 1){
                /*For two characters the diogonal is 1 and if they are same then
                longestPalindromicSubsequence is 2.So mark them 2.*/
                   L[row][col] = 2; 
            }
            else if (str[row] == str[col]) 
               L[row][col] = L[row+1][col-1] + 2; 
            else
               L[row][col] = max(L[row][col-1], L[row+1][col]); 
        } 
    } 
    return L[0][n-1]; 
}
int main() 
{ 
    char seq[] = "BABCBAB"; 
    int n = strlen(seq); 
    cout<<longestPalindromicSubsequence(seq); 
} 
