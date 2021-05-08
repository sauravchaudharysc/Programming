#include<stdio.h>
#include<stdbool.h>

struct Job{
    char name;
    int deadline;
    int profit;
};

typedef struct Job JOB;

//Helper Function
//To sort the given array according to the profit
void sort(JOB arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            /*A struct Data type do three swaps 
            JOB {aka struct Job}*/
            if(arr[j].profit<arr[j+1].profit){
                arr[j].profit^=arr[j+1].profit^=arr[j].profit^=arr[j+1].profit;
                arr[j].deadline^=arr[j+1].deadline^=arr[j].deadline^=arr[j+1].deadline;
                arr[j].name^=arr[j+1].name^=arr[j].name^=arr[j+1].name;
            }
        }
    }
}


//Main Function
void JobScheduling(JOB arr[],int n){
    int result[n];
    bool slot[n];
    
    //Initialise all slots to be free
    for(int i=0;i<n;i++){
        slot[i]=false;
    }
    
    //Iterate through all the given jobs
    for(int i=0;i<n;i++){
        /*To check a free slot and assign it to the last possible slot
        according to its deadline so we can have more slot vacant in before
        time so that we dont miss a work which should be done before*/
        for(int j=arr[i].deadline-1;j>=0;j--){
            //is the slot vacant
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
  
    //Print the array to know the JobScheduling
    //Result[i] store the index of job scheduled
    for (int i=0; i<n; i++) {
        if(slot[i]){
            printf("%c ",arr[result[i]].name);
        }
    }
	
}



int main()
{
    JOB arr[]={ {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
				{'d', 1, 25}, {'e', 3, 15}};

	sort(arr,5);
    JobScheduling(arr,5);
}