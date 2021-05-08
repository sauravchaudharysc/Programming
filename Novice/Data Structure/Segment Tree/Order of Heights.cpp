#include<bits/stdc++.h>
using namespace std;

//Traverse the segment tree
//Decrease the count till we dont get the required position
/*For each node visited decrease the node count as we are filling the 
array from min height to large height so after filling that space wont
contribute in other heights so we decrease the root each time.

We return the index after subtracting the no of internal nodes to make the 
leaf nodes to return the original index.
*/
int empty_pos(vector<int> &tree, int pos) {
    int n = tree.size()/2, i = 0;
    while (i < n) {
        --tree[i];
        if (tree[2*i+1] > pos) i = 2*i+1;
        else {
            pos -= tree[2*i+1];
            i = 2*i+2;
        }
    }
    --tree[i];
    return i-(n);
}

//Create a segment tree
vector<int> build_segment_tree(int len) {
    int n = pow(2, ceil(log2(len)));
    vector<int> tree((2*n)-1);
    for (int i = 0; i <= len-1; ++i) tree[n-1+i] = 1;
    for (int i = n-2; i >= 0; --i) tree[i] = tree[2*i+1] + tree[2*i+2];
    return tree;
}

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
    cout << endl;
}

vector<int> orderofHeights(vector<int> &heights, vector<int> &infronts) {
    vector<int> perm(heights.size());
    for (int i = 0; i < perm.size(); ++i) perm[i] = i;
    sort(perm.begin(), perm.end(), [&](const int& a, const int& b) { return (heights[a] < heights[b]); });
    vector<int> tree = build_segment_tree(heights.size());
    vector<int> res(heights.size(), -1);
    for (int i = 0; i < perm.size(); ++i) res[empty_pos(tree, infronts[perm[i]])] = heights[perm[i]];
    return res;
}

int main(){
    vector<int>heights{5, 3, 2, 6, 1, 4};
    vector<int>infronts{0, 1, 2, 0, 3, 2};
    vector<int>ans=orderofHeights(heights,infronts);
    print_vector(ans);
}