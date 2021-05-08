#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define ll long long int
#define prime 119

ll createHashValue(char str[],int size){
    ll result=0;
    for(int i=0;i<size;i++){
        result += str[i]*pow(prime,i);
    }
    return result;
}

bool checkEqual(char str[],int i,int x,char pat[],int y){
    if(y>x-i){
        return false;
    }
    int k=0;
    while(k<y){
        if(str[i+k]!=pat[k]){
            return false;
        }
        k++;
    }
    return true;
}

ll reCalculateHashValue(char str[],ll strHashValue,int i,int y){
    ll result=strHashValue-str[i];
    result /=prime;
    result=str[i+y]*pow(prime,y-1);
    return result;
}

int main()
{
   char str[10]="abbacdab";
   char pat[10]="abba";
   int x=strlen(str);
   int y=strlen(pat);
   ll strHashValue = createHashValue(str,y);
   ll patHashValue = createHashValue(pat,y);
   int flag=0;
   for(int i=0;i<x-y;i++){
       if( strHashValue==patHashValue && checkEqual(str,i,x,pat,y)){
           flag=1;
       }
       
       if(x-i>y){
           strHashValue = reCalculateHashValue(str,strHashValue,i,y);
       }
   } 
   if(flag==1){
       printf("Pattern found");
   }else{
       printf("Not Found");
   }
}
