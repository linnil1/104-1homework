#include<iostream>
using namespace std;
int main(){
	double x,sum,now;
	int n;
	cin >> x>>n;
	sum=now=x;
	for(int i=1;i<n;++i)
		sum += now *= -x*x/(2*i+1)/(2*i+2);
	cout << sum ;
	return 0;
}
