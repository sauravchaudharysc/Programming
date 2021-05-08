#include<bits/stdc++.h>
#define MAX_N 100005
using namespace std;

int reset[MAX_N];

//Function To Make Reset Table
void KMPpreProcess(string pat){
    int i=0,j=-1;
    reset[0] = -1;
    while(i < pat.size()){
        //To reset j value
        //Reset it till unmatch occurs and j>=0 
        while(j >=0 and pat[i]!=pat[j]){
            j=reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}

//Function to Implement KMP Search 
void KMPSearch(string str,string pat){
    KMPpreProcess(pat);
    int i=0,j=0;
    while(i < str.size()){
        while(j>=0 and str[i]!=pat[j]){
            j = reset[j];
        }
        i++;
        j++;
        if(j==pat.size()){
            cout<<"Pattern Found at index "<<i -j <<endl;
            j=reset[j];
        }
    }
    
}

int main()
{
    //Initialise the reset table
    for(int i=0;i<MAX_N;i++){
        reset[i]=-1;
    }
    
    string str="abaababbaba";
    string pat="ab";
    KMPSearch(str,pat);
}