#include<bits/stdc++.h>
using namespace std;
void printSubstr( string str, int low, int high ) 
{ 
    for( int i = low; i < high; i++ ) 
        cout << str[i];
    cout<<endl;    
}

int longestPalindromeSubstr(string str)
{
    int n=str.size();
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
    int maxLength=1;
    //A string of length 1 is a palindrome so diagonal are set to true
    for(int i=0;i<n;i++){
        dp[i][i]=true;
    }

    int start=0; //We store the starting index of palindrome string.
    /*No of character is diagonal+1*/
    for(int diagonal=1;diagonal<n;diagonal++){
        for(int row=0;row<n-diagonal;row++){
            int col=row+diagonal;
            //For string of length 2
            if(str[row]==str[col] && diagonal ==1){
                start=row; 
                maxLength=2;
                dp[row][col]= true;
            }
            //For string of length greater than 2 if character
            // matched then check for characters between them are they palindrome or not.
            else if(str[row] == str[col] && dp[row+1][col-1]){
                dp[row][col]=true;
                if(diagonal > maxLength){
                    start=row;
                    maxLength=diagonal+1;
                }
            }
        }
    }
    printSubstr(str,start,start+maxLength);
    return maxLength;
}
int main()
{
    string str= "forgeeksskeegfor";
    int n=longestPalindromeSubstr(str);
    cout<<"Length is: "<<n;
}