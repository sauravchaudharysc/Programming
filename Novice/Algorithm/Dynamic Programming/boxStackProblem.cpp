#include<bits/stdc++.h>
using namespace std;
class BOX{
    public:
    int l,b,h;
};
/*This sorts the array in descending order.The box with highest area comes at top*/
bool compare(BOX first,BOX second){
    return first.l*first.b>second.l*second.b;
}
int boxStackProblem(BOX arr[],int n)
{
    BOX rot[3*n];
    int index=0;
    for(int i=0;i<n;i++){
        //1st Rotation
            rot[index].l=max(arr[i].l,arr[i].b);
            rot[index].b=min(arr[i].b,arr[i].l);
            rot[index].h=arr[i].h;
            index++;
        //2nd Rotation
            rot[index].l=max(arr[i].l,arr[i].h);
            rot[index].b=min(arr[i].h,arr[i].l);
            rot[index].h=arr[i].b;
            index++;
        //3rd Rotation
            rot[index].l=max(arr[i].h,arr[i].b);
            rot[index].b=min(arr[i].b,arr[i].h);
            rot[index].h=arr[i].l;
            index++;
    }
    int N=3*n;
    /*Remove the comment to get the patterns  
    for(int i=0;i<3*n;i++)
    {
        cout<<rot[i].l<<" "<<rot[i].b<<" "<<rot[i].h<<endl;
    }*/
    sort(rot,rot+N,compare);
    /*Remove the comment to get the patterns  
    for(int i=0;i<3*n;i++)
    {
        cout<<rot[i].l<<" "<<rot[i].b<<" "<<rot[i].h<<endl;
    }*/
    int result[N];
    int arrangement[N];
    for(int i=0;i<N;i++){
        result[i]=rot[i].h;
        arrangement[i]=i;
    }
    int best=1;
    int position;
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(rot[j].l>rot[i].l && rot[j].b>rot[i].b && 
            result[j]+rot[i].h>result[i]){
                result[i]=result[j]+rot[i].h;
                arrangement[i]=j;
            }
        }
        if(best<result[i]){
            position=i;
        }
        best=max(best,result[i]);
    }
    // for(int i=0;i<N;i++)
    // {
    //     cout<<result[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<N;i++)
    // {
    //     cout<<arrangement[i]<<" ";
    // }
    while(position!=0)
    {
        cout<<rot[position].l<<" "<<rot[position].b<<" "<<rot[position].h<<endl;
        position=arrangement[position];
    }
    return best;
}
int main()
{
    BOX arr[]={{1,2,4},{3,2,5}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<boxStackProblem(arr,n);
}
