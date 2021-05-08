#include<bits/stdc++.h>
using namespace std;
int maxDivide(int a,int b)
{
    while(a%b == 0)
        a = a/b;
        
        return a;
 
}
//We Check does the ugly number gives one after getting divided from these.
int isUgly(int no)
{
    no = maxDivide(no, 2); 
  no = maxDivide(no, 3); 
  no = maxDivide(no, 5); 
  return (no == 1)? 1 : 0; //If yes then we return this number is ugly and count increases
}
//In this iteration we start finding the ugly number fron start.
int getNthUglyNo(int n)
{
    int i=1;
    int count=1;
    while(n > count){ //when count becomes equal to user n. return i.
        i++;
        if(isUgly(i)){
            count++;
        }
    }
    return i;
}
int ggetNthUglyNo(int n)
{
    int ugly[n];
    ugly[0]=1;
    int i2,i3,i5;
    i2=i3=i5=0;
    int next_uglyNo2 = 2;
    int next_uglyNo3 = 3;
    int next_uglyNo5 = 5;
    for(int i=1;i<n;i++){
        int next_ugly=min(next_uglyNo2,min(next_uglyNo3,next_uglyNo5));
        ugly[i]=next_ugly;
        if(next_ugly==next_uglyNo2){
            i2=i2+1;
            next_uglyNo2=ugly[i2]*2;
        }
        
        if(next_ugly==next_uglyNo3){
            i3=i3+1;
            next_uglyNo3=ugly[i3]*3;
        }
        
        if(next_ugly==next_uglyNo5){
            i5=i5+1;
            next_uglyNo5=ugly[i5]*5;
        }
    }
    return ugly[n-1];
}
int main()
{
    cout<<getNthUglyNo(150)<<endl;
    
    cout<<ggetNthUglyNo(150);
}