#include<iostream>
#include<cstring>
using namespace std;
int strLength(char str[]){
	int len=-1;
	while(str[++len]);
//	return strlen(str);//This is not in the string class XD
	return len;
}
int main(){
	//without using string
	char c[10000];
	for(int i=0;i<5;++i){
		cin >> c;
		cout << strLength(c);
	}
	return 0;
}
