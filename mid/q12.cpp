#include<iostream>
using namespace std;

void mat_in(int **&a,int m,int n){
	a = new int*[m];
	for(int i=0;i<m;++i){
		a[i] = new int [n];
		for(int j=0;j<n;++j)
			cin >> a[i][j];
	}
}

void mat_del(int **&a,int m){
	for(int i=0;i<m;++i)
		delete[] a[i];
	delete[] a;
}

int main(){
	cout << "input M L N\n";
	int m,l,n;
	cin >> m >> l >> n;
	cout << "input A(M*L)\n";
	int **a;
	mat_in(a,m,l);
	
	cout << "input B(L*N)\n";
	int **b;
	mat_in(b,l,n);
	cout << "output C(M*N)\n";
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			int sum=0;
			for(int k=0;k<l;++k)
				sum += a[i][k]*b[k][j];
			cout << sum<<' ' ;
		}
		cout << endl ;
	}
	mat_del(a,m);
	mat_del(b,l);
	return 0;
}
