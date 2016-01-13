#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	fstream f("PROGRAMMING.TXT");
	string s="aeiouAEIOU";
	char c;
	int sum=0;
	while(f>>c)
		sum+= ((string)&c).find_first_of(s) != string::npos;
	cout << sum ;
	return 0;
}


