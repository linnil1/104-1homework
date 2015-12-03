#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){
	srand(time(NULL));
	int arr[6];
	for(int i=0;i<6;++i)arr[i]=0;
	for(int t=0;t<10000;++t)
		++arr[rand()%6];
	for(int i=0;i<6;++i)
		cout << i+1 <<":"<<arr[i]<<endl;
	return 0;
}
