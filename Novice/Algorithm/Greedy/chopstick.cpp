//TACHSTCK
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a[100000];
    while(t--){
        int n,d;
        int pair=0;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int i=0;
        while(i!=n-1){
            if(a[i+1]-a[i]<=d){
                pair++;
                i=i+2;
            }else{
                //If we cant pair a chopstick with the present one then this chopstick can pair with more greater than this.
                i++;
            }
        }
        cout<<pair<<endl;
    }
}
