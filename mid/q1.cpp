#include<iostream>
using namespace std;

int main(){
	int m,tot=0;
	cin >> m;
	if(m<=30)
		tot=0;
	else 
		tot = (m-30)/30*20+(m%30>0)*20;//first 30 min is free
	if(tot>240)
		tot=240;
	cout << tot << endl;

	return 0;
}
