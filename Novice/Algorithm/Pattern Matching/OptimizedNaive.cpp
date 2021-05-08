/*Optimized Naive Algorithm*/
//Consider a situation where all characters of pattern are different.
/*So in naive Algorithm we always slide the pattern by 1.Here if a mismatch
occurs we can slide by j since all the characters are different.Because if
mismatch occurs at j.Then the characters till j-1 are matching.And 
since the characters of pattern are unique there is no chance of match before
i+j.So we will initialise i=i+j*/

#include <bits/stdc++.h> 
using namespace std; 
void search(string pat, string str)  
{  
    int i;
    for(i=0;i<=str.size()-pat.size();)
    {
        int j;
        for(j=0;j<pat.size();j++){
            if(str[i+j] != pat[j]){
                break; //If unequal
            }
        }
        if(j==pat.size()){
                cout<<"Pattern is found at "<<i<<endl;
                i=i+pat.size();
            }
        else if(j==0){
            i=i+1;
        }
        else{
            i= i + j; //If mismatch occurs at any point
        }
    }
}

int main()  
{  
    string str = "ABCEABCDABCEABCD";  
    string pat = "ABCD";  
    search(pat, str);  
    return 0;  
}  