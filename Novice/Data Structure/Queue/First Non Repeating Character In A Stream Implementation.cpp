//First Non Repeating Character In A Stream
/*I will make a queue of char data type as sooon as i get a new character
i will enqueue it . I will check the front of queue and check it corresponding
frequency is 1 or not in frequency map.If frequency is 1 i will simply print the front
element and break out of the loop. If frequency is greater than 1. We keep on poping the 
corresponding element and as soon as we poped the element we will get the new element*/

#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main()
{
    queue<char>qu;
    unordered_map<char,int>mp;
    char ch;
    cin>>ch;
    while(ch!='.'){
        //Push the character in queue
        qu.push(ch);
        //Increase the frequency of character
        mp[ch]++;
        while(!qu.empty()){
            if(mp[qu.front()]>1){
                qu.pop();
            }else{
                cout<<qu.front()<<endl;
                break;
            }
        }
        if(qu.empty()){
            cout<<"-1"<<endl;
        }
        cin>>ch;
    }
    return 0;
}