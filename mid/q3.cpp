#include<iostream>
using namespace std;

int main(){
	string s;
	while( getline(cin,s)){
		for(int i=s.size();i>=0;--i)
			cout << s[i] ;
		cout << endl;
	}
	return 0;
}
