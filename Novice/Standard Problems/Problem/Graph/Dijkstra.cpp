#include<bits/stdc++.h>
using namespace std;

const int N = 3000;
const int W = 1e5;
const int INF = 1e9;
vector<pair<int, int>> g[N];
int dist[N];
bool visited[N];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i) g[i].clear();
        //Insert Edge in Undirected Graph
        for(int i = 0; i < m; i++){
            int v, u, w;
            scanf("%d %d %d", &v, &u, &w);
            --v; --u;
            g[v].push_back({u, w});
            g[u].push_back({v, w});
        }
        //Source Vertex
        int s;
        scanf("%d", &s);
        --s;
        
        //To fill the dist to inifinity and visited to false
        fill(dist, dist + n, INF);
        fill(visited, visited + n, 0);
        dist[s] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        //Push the source vertex
        q.push({0, s});
        while(!q.empty())
        {
            //Get the source node
            int u = q.top().second;
            
            //Get the distance
            int d = q.top().first;
            
            //Pop the node
            q.pop();
            
            //If the node is already visited
            if(visited[u]) continue;
            
            //Mark the node visited
            visited[u] = 1;
            
            for(auto it: g[u])
            {
                //destination vertex
                int v = it.first;
                //destination distance
                int w = it.second;
                
                if(dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(i == s) continue;
            printf("%d ", (dist[i] != INF ? dist[i] : -1));
        }
        printf("\n");
    }
    return 0;
}