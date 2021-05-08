#include<bits/stdc++.h>
using namespace std;

struct Object{
    float weight; //To consider even decimal weight
    int value;
};

struct Node{
    int level;
    int profit;
    int cost;
    float weight;
};

//Comparator to sort the array on the basis of value/weight
bool compare(Object a, Object b) 
{ 
    double i = (double)a.value / a.weight; 
    double j = (double)b.value / b.weight; 
    return i > j; 
} 

//Greedy Way it finds the cost by considering fraction weight to get maxProfit
int getCost(Node u,int n,int W,Object arr[]){
    
    //KnapSack Weight is less than current weight
    if (u.weight >= W) 
        return 0;
        
    //Current cost
    int cost = u.profit;
    
    //Start including the next item
    int j = u.level + 1; 
    int totweight = u.weight;     
    
    //Adding the value of item in cost considering the index and KnapSack condition
    while ((j < n) && (totweight + arr[j].weight <= W)) 
    { 
        totweight    += arr[j].weight; 
        cost += arr[j].value; 
        j++; 
    }
    
    //To obtain fractional cost to fill the Sack Completely
    if (j < n) 
        cost += (W - totweight) * arr[j].value / 
                                         arr[j].weight; 
  
}


//Main Function 
int KnapSack(Object arr[],int n,int W){

    sort(arr,arr+n,compare);
    
    //LIFO branch and bound  
    queue<Node> Que; 
    Node u, v;
    
    //Push a node
    u.level = -1; 
    u.profit = u.weight = 0; 
    Que.push(u);
    
    int maxProfit = 0;
    
    while(!Que.empty())
    {
        u = Que.front();
        Que.pop();
        
        //Reached the end of array
        if (u.level == n-1){ 
            continue; 
        }
        
        //Increment the index by 1
        v.level = u.level + 1; 
        
        //Current Level Weight is included.
        
                //Include the current index weight and profit
                v.weight = u.weight + arr[v.level].weight; 
                v.profit = u.profit + arr[v.level].value;
                
                
                if (v.weight <= W && v.profit > maxProfit){ 
                    maxProfit = v.profit;
                }
                
                //Get the cost
                v.cost = getCost(v, n, W, arr);
                
                //If cost is less than profit,then the node isnt useful. Kill it. 
                //Dont include the node and if cost is greater push that node
                if (v.cost > maxProfit) 
                    Que.push(v);
            
        //Current Level weight isnt included
                
                //Exclude the Current weight and profit
                v.weight = u.weight; 
                v.profit = u.profit; 
                
                //Get the cost
                v.cost = getCost(v, n, W, arr);
                
                //If cost is less than profit,then the node isnt useful. Kill it. 
                //Dont include the node and if cost is greater push that node
                if (v.cost > maxProfit) 
                    Que.push(v);
        
    }
    return maxProfit;
}


int main()
{
   int W = 10;   // Weight of knapsack 
    Object arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, 
                  {5, 95}, {3, 30}}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Maximum possible profit = "
         << KnapSack(arr, n,W); 
  
    return 0; 
}