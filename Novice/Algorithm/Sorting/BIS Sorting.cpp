
#include <bits/stdc++.h>
using namespace std;


class Sort{
    public:
      void selection_sort(int a[],int n)
        {
          int i,k,j,temp;
           for(i=0;i<n;i++)
            {     
               k=i;
              for(j=i+1;j<n;j++)
              {  
                if(a[j]<a[k])
                {
                    k=j;
                }
              }
              if(k!=i)
              {
                 temp=a[k];
                 a[k]=a[i];
                 a[i]=temp;
              }
            }  
        }
        
        void insertionSort(int a[],int n){
          for(int i=1;i<n;i++){
            int key=a[i];
            int j=i-1;
            while(j>=0 && a[j]>key){
              a[j+1]=a[j];    
              j--;
            }
            a[j+1]=key;
          }
        }
        
        void bubble_sort(int a[],int n)
        {
            int i,j,temp,flag=1;
            for(i=0;i<n-1&&flag==1;i++)
            {   
              flag=0;    
              for(j=0;j<n-1-i;j++)
              {  
                if(a[j+1]<a[j])
                {
                    flag=1;
                    temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
              }
            }  
        }

};

int main()
{
    Sort t;
    int i,j,a[50],n;
    cout<<"Enter the no of elements : - ";
        cin>>n;
        cout<<"Enter the elements :- ";
        for(i=0;i<n;i++)
            cin>>a[i];
        
        cout<<"***************Main Menu***************\n";
        cout<<"1.Insertion Sort\n";
        cout<<"2.Bubble Sort\n";
        cout<<"3.Selection Sort\n";
        int option;
        cin>>option;
        switch(option){
            
            case 1:
                 t.insertionSort(a,n);
                 for(i=0;i<n;i++)
                cout<<a[i]<<" ";
                cout<<endl;
            break;
            case 2:
                 t.bubble_sort(a,n);
                 for(i=0;i<n;i++)
                cout<<a[i]<<" ";
                cout<<endl;
            break;
            case 3:
                t.selection_sort(a,n);
                for(i=0;i<n;i++)
                cout<<a[i]<<" ";
                cout<<endl;
            break;
            default:
                cout<<"Check your option\n";
            break;    
        }
}



