#include<bits/stdc++.h>
using namespace std;
map<int,list<pair<int,int>>>adjList;

int findMinVertex(vector<bool>&visited,vector<int>&weight){
	int minVertex=-1;
	for(int i=1;i<=weight.size();i++){
		if(!visited[i]&& (minVertex==-1 || (weight[i]<weight[minVertex])) ){
			minVertex=i;
		}
	}
	return minVertex;
}

void addEdge(int u,int v,int w){
	adjList[u].push_back(make_pair(v,w));
	adjList[v].push_back(make_pair(u,w));
}
void minSpantree(int n){
	vector<bool>visited(n+1);
	vector<int>weight(n+1);
	vector<int>parent(n+1);
	for(int i=1;i<=n;i++){
		weight[i]=INT_MAX;
		visited[i]=false;
	}
	parent[1]=-1;
	weight[1]=0;
	for(int i=1;i<=n;i++){
		int minVertex= findMinVertex(visited,weight);
		visited[minVertex]=true;
		for(auto obj:adjList[minVertex]){
			if(!visited[obj.first]){
				if(weight[obj.first]>obj.second){
					parent[obj.first]=minVertex;
					weight[obj.first]=obj.second;
				}
			}
		}
	}
	int total=0;
	for(int i=1;i<=n;i++){
		total+=weight[i];
	}
	cout<<total<<endl;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	minSpantree(n);
}