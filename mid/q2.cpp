#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double sum=0;
	for(int i=1;i<=50;++i)
		sum += (double)1/i/i;
	cout << sqrt(sum*6)<<endl;
	return 0;
}
