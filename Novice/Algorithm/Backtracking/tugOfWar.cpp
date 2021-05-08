#include<bits/stdc++.h>
using namespace std;

int min_diff=INT_MAX; //To Compare the subset difference
void tugOfWar(int arr[],int n,bool* curr_elements,int position,bool* solution,int sum,int selected_elements,int current_sum)
{
    //Base Case
    if(position ==n) //If Array is Traversed Completely
    {
        return;
    }
    
    if((n/2- selected_elements)>(n- position)) //Checks the number of element arent less than required 
    {
        return;
    }
    //When current element is not included in the solution
    tugOfWar(arr,n,curr_elements,position+1,solution,sum,selected_elements,current_sum);
    selected_elements++;
    current_sum=current_sum+arr[position];
    curr_elements[position]=true;
    
    if(selected_elements==n/2)
    {
        if(abs(sum/2- current_sum) < min_diff)
        {
            min_diff= abs(sum/2- current_sum);
            for(int i=0;i<n;i++)
            {
                solution[i]=curr_elements[i];
            }
        }
    }
    else
    {
        //When current element is included in the solution
        tugOfWar(arr,n,curr_elements,position+1,solution,sum,selected_elements,current_sum);
    }
    //Removes current element before returning
    curr_elements[position]=false;
}
int main()
{
    int arr[]={10,20,15,5,25};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool* curr_elements= new bool[n];
    bool* solution=new bool[n];
    curr_elements[n]=solution[n]={false};
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    tugOfWar(arr,n,curr_elements,0/*position*/,solution,sum,0,0);
    cout<<"The First Subset is :- ";
    for(int i=0;i<n;i++)
    {
        if(solution[i]==true)
        {
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl<<"The Second Subset is:- ";
    for(int i=0;i<n;i++)
    {
        if(solution[i]==false)
        {
            cout<<arr[i]<<" ";
        }
    }
}