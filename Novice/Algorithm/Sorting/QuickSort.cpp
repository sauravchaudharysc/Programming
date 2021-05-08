#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void swap(ll *x,ll *y){
	ll temp=*x;
	      *x=*y;
	      *y=temp;
}

ll partition(ll a[],ll lb,ll ub){
	ll i=lb,j=ub+1,pivot=a[lb];
	do{	
	    //Increase the count of i until we get greater element than pivot
		do{
		   i++;
		}while(i<=j && a[i]<=pivot);
		//Decrease the count of j until we get smaller element than pivot
		do{
		   j--;
		}while(a[j]>pivot);
		//If both get stucked then we reach here.If i<j then swap i j elements.
	    if(i<j)
	    {	
	     swap(&a[i],&a[j]);
	    } 
 	  }while(i<j);
	//Swap the pivot element and  j. J contains the index of smaller element than pivot
	swap(&a[lb],&a[j]);
	return j;
}

ll r_partition(ll a[],ll lb,ll ub){
	ll t= lb+(rand()%(ub-lb));
	swap(&a[lb],&a[t]);
	return partition(a,lb,ub);
}

void quick_Sort(ll a[],ll lb,ll ub){
	ll pivot;
	if(lb<ub)
	{
	 pivot=r_partition(a,lb,ub);
	 quick_Sort(a,lb,pivot-1);
	 quick_Sort(a,pivot+1,ub);	
	}
}

int main(){
	ll n;
	cin>>n;
	ll *a=new ll[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];	
	}
	quick_Sort(a,0,n-1);	
	for(ll i=0;i<n;i++){
		cout<<a[i]<<" ";	
	}
	cout<<endl;
}
