#include<iostream>
using namespace std;

int cal(int a){
	int sum=0,now,len=0;
	for(int i=a;i;i/=10)
		++len;
	for(;a;a/=10){
		now=1;
		for(int i=0;i<len;++i)
			now*=(a%10);
		sum+=now;
	}
	return sum;
}
int main(){
	for(int i=100;i<99999;++i)
		if(cal(i)==i)
			cout << i <<" ";
	cout << endl;
	return 0;
}
