//Length of longest sub-string non repeating character
//Sliding window
/*
Maximum Length
Index of the character where it last occured(hashmap,array)*/
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[]="abbacdeb";
    int n=strlen(a);
    int curren_len =1;
    int max_len=1;
    int visited[256];
    for(int i=0;i<256;i++){
        visited[i]=-1;
    }
    
    visited[a[0]]=0;
    
    for(int i=1;i<n;i++){
        int last_occ = visited[a[i]];
        //Expansion
        if(last_occ==-1 || i-curren_len>last_occ){
            curren_len+=1;
            max_len=max(max_len,curren_len);
        }else{
            max_len=max(max_len,curren_len);
            curren_len = i- last_occ;
        }
        visited[a[i]]=i;
    }
    max_len=max(max_len,curren_len);
    cout<<max_len<<endl;
}