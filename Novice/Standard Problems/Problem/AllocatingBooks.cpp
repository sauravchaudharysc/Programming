/*You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90
Sample Output
113 
Explanation
1st students : 12 , 34, 67 (total = 113)
2nd students : 90 (total = 90)
Print max(113, 90)*/
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