#include<bits/stdc++.h>
using namespace std;


int getOnesBitwiseOnly(int arr[],int n){
    
    //Initialise both as zero
    int ones=0;
    int twos=0;
    int common_bit_Mask;
    for(int i=0 ; i<n;i++){
    
        twos= twos | (ones & arr[i]); //2nd Occurence
        
        ones = ones^arr[i]; //1st Occurence
        
        //Common bits occur in third occurance 
        common_bit_Mask = ~(ones&twos);
        
        //Remove the third occurence bit from twos and ones 
        
        ones&=common_bit_Mask;
        twos&=common_bit_Mask;
    }
    return ones;
}

int getOnes(int arr[],int n){
    int bit[32]={0};
    for(int i=0;i<n;i++){
        int num=arr[i];
        int j=0;
        while(num!=0){
            if(num&1){
                bit[j++]+=1;
            }else{
                bit[j++]+=0;
            }
            num=num>>1;
        }
    }
    
    for(int i=0;i<32;i++){
        bit[i]=bit[i]%3;
    }
    int sum=0;
    for(int i=0;i<32;i++){
        sum+=bit[i]*pow(2,i);
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<getOnes(arr,n)<<endl;
}