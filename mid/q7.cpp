#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double a,b,c;
	cin >>a>>b>>c;
	double d=b*b-4*a*c;
	if(d==0){
		double r = -b/2/a;
		cout << "one root:" << r << endl;
	}
	else if(d<0)
		cout << "no real root\n";
	else if(d>0){
		double r1 = (-b+sqrt(d))/2/a,
			   r2 = (-b-sqrt(d))/2/a;
		cout << "two roots:" << r1 <<','<<r2 << endl;
	}

		
	return 0;
}
