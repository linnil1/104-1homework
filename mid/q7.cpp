#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double a,b,c;
	cin >>a>>b>>c;
	if(b*b-4*a*c==0){
		double r = -b/2/a;
		cout << "one root:" << r << endl;
	}
	else if(b*b-4*a*c<0)
		cout << "no real root\n";
	else if(b*b-4*a*c>0){
		double r1 = (-b+sqrt(b*b-4*a*c))/2/a,
			   r2 = (-b-sqrt(b*b-4*a*c))/2/a;
		cout << "two roots:" << r1 <<','<<r2 << endl;
	}

		
	return 0;
}
