#include<bits/stdc++.h>
using namespace std;

//&* cancel each other
int main(){
    //Declaration
    int *p;
    //Initaliization
    int a=10;
    p=&a;
    //Meri address bata mujhe
    cout<<p<<endl;
    //Meri address ki value bata mujhe kyunki *& cancel karti h ek dusre ko
    cout<<*p<<endl;
    
    //Use of pointer
    //Swap of two values
    int n;
    cin>>n;
    //Dynamic created array
    int *arr=new int(n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //Static array
    int arrq[n];
    for(int i=0;i<n;i++){
        cout<<arrq[i]<<" ";
    }
}