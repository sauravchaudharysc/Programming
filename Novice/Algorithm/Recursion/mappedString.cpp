#include<bits/stdc++.h>
using namespace std;
void mappedString(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch1 = str[0];
	string ros = str.substr(1);

	int ch1_int = ch1 - '0';

	ch1 = ch1 - '0' + 'A' - 1;

	mappedString(ros,ans + ch1);

	if(ros.length()>0){

		char ch2 = str[1];
		int ch2_int = ch2 - '0';

		int second_num = ch1_int*10 + ch2_int;

		if(second_num < 27){
			ch2 = second_num + 'A' - 1;
			string ros2 = str.substr(2);

			mappedString(ros2,ans+ch2);
		}
	}

}

int main()
{
   mappedString("123","");
} 