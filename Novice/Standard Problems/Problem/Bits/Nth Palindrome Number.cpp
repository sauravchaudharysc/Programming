#include<bits/stdc++.h>
using namespace std;

#define INT_SIZE 32 

int constructNthNumber(int group_no,int aux_num,int op){
    //All the 32 bit are market zero
    int a[INT_SIZE]={0};
    
    //Length of string
    int len_f;
    int i=0;
    //FOr even length
    if(op==2){
        len_f=2*group_no;
        a[len_f-1]=a[0]=1;
        while(aux_num){
            a[group_no-1-i]=a[group_no+i]=aux_num&1;
            aux_num=aux_num>>1;
            i++;
        }
    }else if(op==0){
        len_f=2*group_no+1;
        a[len_f-1]=a[0]=1;
        a[group_no]=0;
        while(aux_num){
            a[group_no-1-i]=a[group_no+i+1]=aux_num&1;
            aux_num=aux_num>>1;
            i++;
        }
    }else if(op==1){
        len_f=2*group_no+1;
        a[len_f-1]=a[0]=1;
        a[group_no]=1;
        while(aux_num){
            a[group_no-1-i]=a[group_no+i+1]=aux_num&1;
            aux_num=aux_num>>1;
            i++;
        }
    }
    //To store final number
    int num=0;
    for(i=0;i<len_f;i++){
        num+=(1<<i)*a[i];
    }
    return num;
}

int getNthNumber(int n){
    //If n==1 the first palindrome number return 1
    if(n==1){
        return 1;
    }
    int count_upto_group=0,count_temp=1,group_index;
    int group_no=0;
    int op,aux_num;
    //Get the count of all element just before the required group
    while(count_temp<n){
        group_no++;
        count_upto_group=count_temp;
        count_temp=count_temp+3*(1<<(group_no-1));
    }
    //Get the index of the element where it is present in required group
    group_index=n - count_upto_group -1;
    //Even length palindrome lies on top of the group
    //Check whether it belongs to the group
    //If yes mark it
    //And the group index is 1 less than original
    if((group_index+1)<=(1<<(group_no-1))){
        op=2;
        aux_num=group_index;
    }else{
        //Check the position of the odd length palindrome 
        //If odd then mark 0
        if(((group_index+1)-(1<<(group_no-1)))%2){
            op=0;
        }else{
            //If even then mark 1
            op=1;
        }
        //The aux_num is the rank of the odd length index and
    //divide by 2 to remove a bit from last as we have already placed it
        aux_num=((group_index)-(1<<(group_no-1)))/2;
    }
    return constructNthNumber(group_no,aux_num,op);
}

int main(){
    int n=9;
    cout<<getNthNumber(n);
}