#include<iostream>
using namespace std;
#define min(a,b)a<b?a:b
int main(){
	int m,tot=0;
	cin >> m;
	if(m>0)--m;
	tot += m/1440*240;
	tot += min(m%1440/30*20+20,240); 
	if(m<30)
		tot=0;//first 30 min is free
	cout << tot << endl;

	return 0;
}
