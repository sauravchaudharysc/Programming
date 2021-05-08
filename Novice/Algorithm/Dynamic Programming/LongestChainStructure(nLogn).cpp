/*Here we first sort the given array then we increase the value of best as we observe
that the temp value is less than next pair first element.Then we update to temp to 
corresponding pair second element value.*/
#include<bits/stdc++.h>
using namespace std;
//Structure for a pair
struct Pair
{
    public:
    int a;
    int b;
};
bool comparator(struct Pair p1,struct Pair p2)
{
    return (p1.a<p2.a);
}
int maximumLengthChain(Pair arr[],int n)
{
    sort(arr,arr+n,comparator);
    int best=1;
    int temp=arr[0].b;
    for(int i=1;i<n;i++){
        if(temp<arr[i].a){
            best++;
            temp=arr[i].b;
        }
    }
    return best;
}
int main()
{
    Pair arr1[]={ {5,24}, {15,25}, {27,40}, {50,60}};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    Pair arr2[]={{6, 8}, {3, 4}};
    int n1 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<maximumLengthChain(arr1,n)<<endl;
    cout<<maximumLengthChain(arr2,n1);
}