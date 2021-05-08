#include <stdio.h>
#include<string.h>

void NaiveSearch(char str[],int x,char pat[],int y){
    int flag=0;
    for(int i=0;i<x-y;i++){
        int j=0;
        for(;j<y;j++){
            if(str[i+j]!=pat[j]){
                break;
            }
        }
        if(j==y){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Pattern Found");
    }else{
        printf("Pattern not Found");
    }
}

int main()
{
   char str[10]="abbacdab";
   char pat[10]="ab";
   int x=strlen(str);
   int y=strlen(pat);
   NaiveSearch(str,x,pat,y);
}
