#include<bits/stdc++.h>
using namespace std;
void gcdIterative(int n1,int n2){
    int gcd=0;
    for(int i=1; i <= n1 && i <= n2; i++)
    {
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
    cout<<gcd<<" ";
}

int gcdEuclidRecursive(int a,int b){
    return (b==0) ? a : gcd(b,a%b);
}

void gcdEuclidIterative(int a,int b){
    while(b!=0){
        int rem = a%b;
        a=b;
        b=rem;
    }
    cout<<a<<" ";
}

int main(){
    int x,y;
    cin>>x>>y;
    gcdIterative(x,y);
    cout<<gcdEuclidRecursive(x,y)<<" ";
    gcdEuclidIterative(x,y);
}