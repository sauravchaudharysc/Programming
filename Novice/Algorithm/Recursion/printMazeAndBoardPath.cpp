#include<bits/stdc++.h>
using namespace std;
void printMazePath(int sr,int sc,int er,int ec,string path){
	if(sr==er and sc==ec){
		cout<<path<<endl;
		return;
	}

	if(sr>er or sc>ec){
		return;
	}

	printMazePath(sr+1,sc,er,ec,path + "V");
	printMazePath(sr,sc+1,er,ec,path + "H");
}

void printBoardPath(int start,int end,string path){
	if(start==end){
		cout<<path<<endl;
		return;
	}

	if(start>end){
		return;
	}

	for(int dice = 1;dice<=6;dice++){
		char ch = dice + '0';
		printBoardPath(start+dice,end,path + ch);
	}
}
int main()
{
 printMazePath(0,0,2,2,"");
    cout<<endl;
 printBoardPath(0,3,"");
}