/*
1.Declare an array each index represent a number
2.Initialise an array with 0.
3.All even number are non-prime.So mark all odd number as 1 . 
4.Start iteration from 3.If current number is marked prime then it is prime.
  Unmark all the multiples of it to be non-prime.
5.Print all the array index with value 1.  
*/


#include<bits/stdc++.h>
using namespace std;

void prime_sieve(int p[],int n){
    
    //First mark all odd number's as prime
    for(int i = 3; i<=n ;i+=2){
        p[i] = 1;
    }
    
    //Sieve 
    for(int i = 3; i<=n;i+=2){
        //if the current number is marked(it is prime)
        if(p[i]==1){
            //mark all the multiples of i as not prime 
            for(int j = i*i; j<=n;j=j+i){
                p[j] = 0;
            }
        }
    }
    //Special Case 
    p[2]=1;
    p[1]=p[0]=0;
}

int main()
{
    int n;
    cin>>n;
    int *p = new int[n+1];
    memset(p,0,sizeof(p));
    prime_sieve(p,n+1);
    for(int i=0;i<=n;i++){
        if(p[i]==1){
            cout<<i<<" ";
        }
    }
}