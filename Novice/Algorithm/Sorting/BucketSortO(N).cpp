//n base h to n2-1 ke bare 2 digit meh hi represent honge
//islie 2 baar countsort
//O(n) with O(n) space
#include<iostream>
using namespace std;
void countSort(int a[],int n,int exp)
{
   int output[n];
    int i,count[n]={0};
    
    for(i=0;i<n;i++)
        count[ (a[i]/exp)%n ]++;

    for(i=1;i<n;i++)
        count[i]+=count[i-1];
        
    for(i=n-1;i>=0;i--)
    {
        output[ count[ (a[i]/exp)%n ]-1 ]=a[i];
        count[ (a[i]/exp)%n ]--;
    }
        
    for(i=0;i<n;i++)
        a[i]=output[i]; 
        
}

void sort(int a[],int n)
{
    // Do counting sort for first digit in base n. Note that 
    // instead of passing digit number, exp (n^0 = 1) is passed. 
    countSort(a,n,1);
    
    // Do counting sort for second digit in base n. Note that 
    // instead of passing digit number, exp (n^1 = n) is passed.
    countSort(a,n,n);
}

void printArr(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
}

int main() 
{ 
    // Since array size is 7, elements should be from 0 to 48 
    int arr[] = {40, 12, 45, 32, 33, 1, 22}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Given array is n"; 
    printArr(arr, n); 
  
    sort(arr, n); 
  
    cout << "nSorted array is n"; 
    printArr(arr, n); 
    return 0; 
}



