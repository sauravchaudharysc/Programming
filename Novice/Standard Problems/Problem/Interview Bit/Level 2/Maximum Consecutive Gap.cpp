#include<bits/stdc++.h>
using namespace std;

int MaximumConsecutiveGap(vector<int>&A){
    if(A.size()<2){
       return 0;
    }

    int mini=A[0],maxi=A[0];
    for(int i=1;i<A.size();i++){
        mini=min(A[i],mini);
        maxi=max(maxi,A[i]);
    }

/*If we get the maximum and minimum value and 
divide it by no of Interval((A.size()-1))
we can get the Interval average gap*/
//Average Interval Gap
    int Interval= (int)ceil((maxi-mini+0.0)/(A.size()-1));

//Bucket will be one less than the element.    
    int bucketMin[A.size()-1];
    fill(bucketMin,bucketMin+A.size()-1,INT_MAX);
    int bucketMax[A.size()-1];
    fill(bucketMax,bucketMax+A.size()-1,-1);

//To decide bucket
    for(int i=0;i<A.size();i++){
        if(A[i]==mini || A[i]==maxi){
            continue;
        }
        //A[i]-mini gives the gap between the minimum number and current number
        int getBucket = (A[i]-mini)/Interval;
        bucketMin[getBucket]= min(bucketMin[getBucket],A[i]);
        bucketMax[getBucket]= max(bucketMax[getBucket],A[i]);
    }

    int prev=mini;
    int maxGap=0;
    for(int i=0;i<A.size()-1;i++){
        if(bucketMax[i]==-1){
            continue;
        }
        maxGap=max(bucketMin[i]-prev,maxGap);
        prev=bucketMax[i];
    }
    maxGap=max(maxi-prev,maxGap);
    return maxGap;
    
}

int main(){
    vector<int>v{1,3,6,9};
    cout<<MaximumConsecutiveGap(v);
}