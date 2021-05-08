#include<bits/stdc++.h>
using namespace std;
#define N 4
#define INF INT_MAX

// State Space Tree nodes
struct Node
{
    // stores edges in state space tree.Keep a trace of it parent vertices
    vector<pair<int, int>> path;

    // stores the reduced matrix
    int reducedMatrix[N][N];

    // stores the reduced cost of current reduced matrix
    int cost;

    //stores current city number
    int vertex;

    // keep a track of number of cities visited so far
    int level;
};

// Function to reduce each row in such a way that
// there must be at least one zero in each row
int rowReduction(int reducedMatrix[N][N], int row[N])
{
    // initialize row array to INF
    //see http://www.cplusplus.com/reference/algorithm/fill_n/
    fill_n(row, N, INF);

    // row[i] contains minimum in row i
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (reducedMatrix[i][j] < row[i]){
                row[i] = reducedMatrix[i][j];
            }
        }
    }
    
    // reduce the minimum value from each element in each row
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (reducedMatrix[i][j] != INF && row[i] != INF){
                reducedMatrix[i][j] -= row[i];
            }
        }
    } 
}

// Function to reduce each column in such a way that
// there must be at least one zero in each column
int columnReduction(int reducedMatrix[N][N], int col[N])
{
    // initialize col array to INF
    fill_n(col, N, INF);

    // col[j] contains minimum in col j
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (reducedMatrix[i][j] < col[j]){
                col[j] = reducedMatrix[i][j];
            }
        }
    }
    
    // reduce the minimum value from each element in each column
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (reducedMatrix[i][j] != INF && col[j] != INF){
                reducedMatrix[i][j] -= col[j];
            }
        }
    }    
}

//To calculateCost of the reducedMatrix
int calculateCost(int reducedMatrix[N][N])
{
    // initialize cost to 0
    int cost = 0;

    // Row Reduction
    int row[N];
    rowReduction(reducedMatrix, row);

    // Column Reduction
    int col[N];
    columnReduction(reducedMatrix, col);

    // the total expected cost
    // is the sum of all reductions
    for (int i = 0; i < N; i++)
        cost += (row[i] != INT_MAX) ? row[i] : 0,
            cost += (col[i] != INT_MAX) ? col[i] : 0;
    return cost;
}


Node* newNode(int parentMatrix[N][N],vector<pair<int, int>> const &path,int level, int i, int j){
    
    Node* node = new Node;
    
    // stores ancestors edges of state space tree
    node->path = path;
    
    //Skip for root node
    if(level != 0){
       // add current edge to path
       node->path.push_back(make_pair(i, j));
    }
    
     // copy data from parent node to current node
     //See memcpy details on https://www.geeksforgeeks.org/memcpy-in-cc/
    memcpy(node->reducedMatrix, parentMatrix,sizeof(node->reducedMatrix));
    
    // Change all entries of row i and column j to infinity because from i we cant go other places
    // and we can't come from other places to j.
    // skip for root node
    for (int k = 0; level != 0 && k < N; k++)
    {
        // set outgoing edges for city i to infinity
        node->reducedMatrix[i][k] = INF;

        // set incoming edges to city j to infinity
        node->reducedMatrix[k][j] = INF;
    }
    
    //TSP , After travelling all the city it should return back to start city
    //So In Between current city to start city is set to INFINITY.
    node->reducedMatrix[j][0] = INF;

    // set number of cities visited so far
    node->level = level;

    // assign current city number
    node->vertex = j;

    // return node
    return node;
}

// print list of cities visited following least cost
void printPath(vector<pair<int, int>> const &list)
{
    for (int i = 0; i < list.size(); i++)
        cout << list[i].first + 1 << " -> "
             << list[i].second + 1 << endl;
}


// Comparator to order the priority queue in ascending order
//Comparator in priority-queue is reverse than normal cases
struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return lhs->cost > rhs->cost;
    }
};


//Function to solve TSP using Branch and Bound
int solve(int cost[N][N]){
    
    // Create a priority queue to store nodes 
    priority_queue<Node*,vector<Node*>, comp> pq;

    //Create a pair
    vector<pair<int, int>> v;

    // create a root node and calculate its cost
    // The TSP starts from first city i.e. node 0
    Node* root = newNode(cost, v, 0, -1, 0);
    
    // get the root node cost
    root->cost = calculateCost(root->reducedMatrix);
    
    //Push the root
    pq.push(root);

    while (!pq.empty())
    {
        // Node with least cost
        Node* min = pq.top();

        // The found node is deleted from the list of nodes present in queue
        pq.pop();
        
        //It gives the node vertex no which we just poped out
        int i = min->vertex;
        
        // if all cities are visited
        if (min->level == N - 1)
        {
            // return to starting city
            min->path.push_back(make_pair(i, 0));

            // print list of cities visited;
            printPath(min->path);

            // return the optimal cost
            return min->cost;
        }
        
        // do for each child of min
        // (i, j) forms an edge in space tree
        for (int j = 0; j < N; j++)
        {
            if (min->reducedMatrix[i][j] != INF)
            {
                // create a child node and calculate its cost
                Node* child = newNode(min->reducedMatrix, min->path,min->level + 1, i, j);

                /* Cost of the child =
                    cost of parent node +
                    cost of the edge(i, j) +
                    lower bound of the path starting at node j
                */
                child->cost = min->cost + min->reducedMatrix[i][j]+ calculateCost(child->reducedMatrix);

                // Add child to list of nodes
                pq.push(child);
            }
        }
        //Free the min node as the data of min node is completely placed
        delete min;
    }    
}

int main()
{
    int cost[N][N]= { {INF, 10, 15, 20}, 
                      {10, INF, 35, 25}, 
                      {15, 35, INF, 30}, 
                      {20, 25, 30, INF} 
                    };
    
     cout << "\n\nTotal Cost is "<<endl<< solve(cost);

    
}
