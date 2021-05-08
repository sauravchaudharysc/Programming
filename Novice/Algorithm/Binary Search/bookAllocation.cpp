/*You are given number of pages in n different books and m students.
The books are arranged in ascending order of number of pages. Every student
is assigned to read some consecutive books.The task is to assign books in 
such a way that the maximum number of pages assigned to a student is minimum.*/
/*1
4 2
10 20 30 40
output 60
*/
#include<bits/stdc++.h>
using namespace std;
bool isPossible(int arr[],int n,int students,int pages)
{
    int studentsUsed=1;
    int canRead=0;
    for(int i=0;i<n;i++){
        if(arr[i]+canRead > pages){
            studentsUsed++;
            canRead=arr[i];
            if(studentsUsed>students){
                return false;
            }
        }else{
            canRead+=arr[i];
        }    
    }
    return true;
    
}
void findPages(int arr[],int books,int students)
{
    //Minimum pages a student will read
    int start=arr[books-1];
    //Maximum page a student will read
    int end=0;
    for(int i=0;i<books;i++){
        end+=arr[i];
    }
    int ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        bool canRead=isPossible(arr,books,students,mid);
        if(canRead){
            //If answer is found decrease the no of pages
            end=mid-1;
            ans=min(ans,mid);
        }else{
            //Increase the no of pages student can read.
            start=mid+1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int books,students;
        cin>>books>>students;
        //Creating the array to store no of pages of books.
        //The book pages are given in sorted way.
        int *arr=new int[books];
        for(int i=0;i<books;i++){
            cin>>arr[i];
        }
        findPages(arr,books,students);
    }
}