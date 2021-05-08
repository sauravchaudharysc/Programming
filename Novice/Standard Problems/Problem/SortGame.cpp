/*Suman needs your help! He gets a list of employees with their salary. The maximum salary is 100.

Suman is supposed to arrange the list in such a manner that the list is sorted in decreasing order of salary. And if two employees have the same salary, they should be arranged in lexicographical manner such that the list contains only names of those employees having salary greater than or equal to a given number x.

Help Suman prepare the same!

Input Format
On the first line of the standard input, there is an integer x. The next line contans integer N, denoting the number of employees. N lines follow, which contain a string and an integer, denoting the name of the employee and his salary.

Constraints
1 <= N <= 10^5 1 <= | Length of the name | <= 100 1 <= x, salary <= 100

Output Format
You must print the required list.

Sample Input
79
4
Eve 78
Bob 99
Suzy 86
Alice 86

Sample Output
Bob 99
Alice 86
Suzy 86 */
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<string,int> a,pair<string,int> b){
   if( a.second > b.second )
    {
        return true;
    }
    else
    if( a.second < b.second )
    {
        return false;
    }

    return b.first > a.first ;
    
}
int main()
{
    int min;
    cin>>min;
    vector<pair<string,int>>s1;
    int n;
    cin>>n;
    string x;
    int y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(y>=min){
        s1.push_back(make_pair(x,y));}
    }
    sort(s1.begin(),s1.end(),compare);
    
    for(auto a:s1){
        cout<<a.first<<" "<<a.second<<endl;
    }
}