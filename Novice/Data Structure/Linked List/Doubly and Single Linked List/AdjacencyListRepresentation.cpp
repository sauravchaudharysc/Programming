//List For Implementing Adjacency List Representation Of Graph
/*A Better way to reprsent graph because adjaceny list will be better implementation
in terms of space and time.*/
/*So we need to create a list array*/
#include<iostream>
#include<list>
using namespace std;
int main(){
    /*
    //This Represent Single List
    list<pair<int,int>>l;
    //Array of List
    list<pair<int,int>>l;*/
    
    //Dynamic list
    list<pair<int,int>> *l;
    //No Of Vertices
    int n;
    cin>>n;
    //new Array list depending upon no of Vertices
    //So here l is pointer to array of linked list
    //To insert in first linked list l1.push_back()
    l = new list<pair<int,int>>[n];
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        l[x].push_back(make_pair(y,wt));
        //Vice verse for v-u edge
        l[y].push_back(make_pair(x,wt));
    }
    
    //Print the linked list
    for(int i=0;i<n;i++){
        //Print Every Linked list
        for(auto xp:l[i]){
            cout<<"("<<xp.first<<" ,"<<xp.second<<"),";
        }
        cout<<endl;
    }
    
}