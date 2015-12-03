#include<iostream>
#include<cmath>
using namespace std;

bool isprim(int a){
	int lim = (int)sqrt(a);
	for(int i=2;i<=lim;++i)
		if(a%i==0)
			return 0;
	return 1;
}

int main(){
	int n;
	cin >> n;
	for(int i=2;i<n;++i)
		if(isprim(i))
			cout << i << " ";
	cout << endl;

	return 0;
}
