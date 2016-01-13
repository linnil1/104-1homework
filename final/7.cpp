#include<iostream>
#include<cstdlib>

using namespace std;
int main(){
	srand(time(NULL));
	int arr[12]={0};
	for(int i=0;i<100000;++i)
		++arr[rand()%6+rand()%6];
	for(int i=0;i<=10;++i)
		cout << i+2 <<" "<<arr[i]<<"\n";
	return 0;
}
