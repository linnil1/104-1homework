#include<iostream>
#include<cmath>
using namespace std;

int main(){
	for(int i=1;i<=10;++i){
		double sum=1,now=1;
		for(int j=1;j<=20;++j)
			sum += now*=(double)i/j;
		cout << "e^" << i << "=" << sum << endl;
	}
	return 0;
}
