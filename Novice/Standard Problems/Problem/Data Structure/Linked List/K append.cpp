/*Given a linked list of length N and an integer K , append the last K elements of a linked list to the front. Note that K can be greater than N.

Input Format
First line contains a single integer N denoting the size of the linked list.
Second line contains N space separated integers denoting the elements of the linked list.
Third line contains a single integer K denoting the number of elements that are to be appended.

Constraints
1 <= N <= 10^4
1 <= K <= 10^4

Output Format
Display all the elements in the modified linked list.

Sample Input
7
1 2 2 1 8 5 6
3
Sample Output
8 5 6 1 2 2 1
Explanation
Initially the linked list is
1→ 2→ 3 → 4 → 5 → 6→ null
and k = 2. After appending the last two elements to the front , the new linked list looks like
5→ 6→ 1→ 2→ 3 → 4 → null*/
#include<bits/stdc++.h>
using  namespace std;
int main()
{
    list<int>l1;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        l1.push_back(x);
    }
    int k;
    cin>>k;
    while(k--){
        int num=l1.back();
        l1.pop_back();
        l1.push_front(num);
    }
    for(auto i:l1){
        cout<<i<<" ";
    }cout<<endl;
}