#include<stdio.h>
#include<math.h>
#include<string.h>
#define INT_MAX 100005

int reset[INT_MAX];

//Function to compute reset table
void KMPpreProcess(char ptr[],int n){
 int i=0,j=-1;
 reset[0]=-1;
    while(i<n){
        while(j>=0 && ptr[i]!=ptr[j]){
            j = reset[j];
        }
        i++;
        j++;
        reset[i]=j;
    }
}

//KMP Pattern Search Function
void KMPSearch(char str[],int n1,char pat[],int n2){
    int i=0,j=0;
    KMPpreProcess(pat,n2);
    while(i<n1){
        while(j>=0 && str[i]!=pat[j] ){
            j=reset[j];
        }
        i++;
        j++;
        if(j==n2){
            printf("Pattern found at index %d\n",(i-j));
            j = reset[j];
        }
    }
}

int main()
{
    for(int i=0;i<=INT_MAX;i++){
        reset[i]=-1;
    }    
    char str[]={"ababab"};
    char pat[]={"ab"};
    int n1=strlen(str);
    int n2=strlen(pat);
    KMPSearch(str,n1,pat,n2);
}