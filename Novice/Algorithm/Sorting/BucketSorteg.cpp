//Bucket Sort 
#include<iostream>
#include<vector>
using namespace std;

class Student{
 public:
    int marks;
    string name;
};

//Bucket Sort to sort an array of students 
//We make an array of 0-100 and put the number with particulat number in particular index
//Each array element will be a vector

void bucket_sort(Student s[],int n){
    //Assuming marks are in range 0-100
    vector<Student>v[101];
    //O(N) time
    for(int i=0;i<n;i++){
        int m=s[i].marks;
        v[m].push_back(s[i]);
    }
    
    //Iterate over the vector and print the students 
    for(int i=100;i>=0;i--){
        for(vector<Student>::iterator it=v[i].begin(); it != v[i].end();it++){
            cout << (*it).marks<<(*it).name<<endl;
        }
    }
    
}

int main()
{
    Student s[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].marks>>s[i].name;
    }
    bucket_sort(s,n);
}