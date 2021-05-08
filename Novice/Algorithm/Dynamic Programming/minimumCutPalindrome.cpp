#include<bits/stdc++.h>
using namespace std;
int minimumCuts(string s){
    int n=s.length();
    bool palindrome[n][n];
    memset(palindrome,0,sizeof(palindrome));
    //Single Letters is always palindrome.
    for(int i=0;i<n;i++){
        palindrome[i][i]=true;
    }
    /*For two letters compare both letters if 
    both letters are same then they are palindrome.*/
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            palindrome[i][i+1]=true;
        }
    }
    /*Filling the rest palindrome table*/
    for(int diagonal=2;diagonal<n;diagonal++)
    {
        for(int row=0;row<=n-diagonal;row++){
            int col=row+diagonal;
            if(s[row] == s[col] && palindrome[row+1][col-1]){
                palindrome[row][col]=true;
            } 
        }
    }
    /*Now we decide the minimum amount of cuts using a 1d array
    where last index denotes the number of minimumCuts*/
    int *cuts=new int[n];
    /*Here i is gradually increased so we compare for each position of
    j the palindrome condition*/
    for(int i=0;i<n;i++){
        int temp = INT_MAX;
        if(palindrome[0][i]){
            cuts[i]=0;
        }else{
            for(int j=0;j<i;j++){
            /*Here temp assure that there is minimum cut.For better understanding take the example
            of BANANA and fill the 2d palindrome table then start filling the 1d minimum cuts table.*/    
                if(palindrome[j+1][i] && temp > cuts[j]+1){
                    temp = cuts[j] + 1; //Check the before cuts and this cut make it palindrome
                }
            }
            cuts[i]=temp; //Assign the minimumCuts
        }
    }
          return cuts[n-1];
}
int main()
{
    cout<<minimumCuts("AAB");
}