#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define vi vector<double>
class poly{
	double a,b,c;
	public:
		poly(double _a=1,double _b=2,double _c=1):a(_a),b(_b),c(_c){};
		vi cal(){
			double d=b*b-4*a*c;
			int roots = -(d<0) + (d>0) +1 ;
			vi v;
			if(roots)
				v.push_back((-b+sqrt(d))/2/a);
			if(roots>1)
				v.push_back((-b-sqrt(d))/2/a);
			return v;

		}
};

int main(){
	double a,b,c;
	cin >> a >> b >> c;
	poly pol(a,b,c);
	vi v = pol.cal();
	cout << "roots : " << v.size() <<"\n";
	for(int i=0;i<v.size();++i)
		cout << v[i]<<" ";	
	return 0;
}
