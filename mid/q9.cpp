#include<iostream>
using namespace std;

void bubblesort(int *arr,int n){
	for(int i=0;i<n;++i)
		for(int j=1;j<n-i;++j)
			if(arr[j-1]>arr[j]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
}
int main(){
	int n=15;
	int arr[15]={3, 8, 10, 30, 2, 16, 27, 13, 22, 17, 42, 33, 38, 29, 14};
	cout << "unsort:";
	for(int i=0;i<15;++i)
		cout << arr[i] << ' ';
	cout << endl;
	bubblesort(arr,n);
	cout << "sorted:";
	for(int i=0;i<15;++i)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
