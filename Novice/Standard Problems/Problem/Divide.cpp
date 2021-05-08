#include<bits/stdc++.h>
using namespace std;

int divide(int a,int b){
    if(b==0){
        return INT_MAX;
    }
    int flag1=1;
    int flag2=1;
    if(a<0){
        flag1=-1;
    }
    if(b<0){
        flag2=-1;
    }
    a=abs(a);
    b=abs(b);
    int res=0;
    while(a-b>=0){
        int x=0;
        while(a-(b<<1<<x)>=0){
            x++;
        }
        res+=1<<x;
        a=a-(b<<x);
    }
    return res*flag1*flag2;
}

int main(){
    int x;
    int y;
    cin>>x;
    cin>>y;
    cout<<divide(x,y);
}