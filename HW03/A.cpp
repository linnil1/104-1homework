//================================================================
//  DATE       : 2015/10/19 
//  FILENAME   : HW03A038.CPP 
//  DESCRIPTION: calculate PI
//================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>

void usearray(){// use array to calculate
	const int dig=100;
	int arr[dig];
	memset(arr,0,sizeof(arr));
	//divide
	for(int i=0;i<10000000;++i){
		int now=4,pl=i%2==0,div=2*i+1;
		for(int j=0;j<dig;++j,now=now%div*10)
			if(pl)
				arr[j]+=now/div;
			else
				arr[j]-=now/div;
	}
	// carry 
	for(int j=dig-1;j>0;--j){
		arr[j-1]+=arr[j]/10;
		arr[j]%=10;
		if(arr[j]<0){
			arr[j]+=10;
			arr[j-1]--;
		}
	}
	//output
	printf("%d.",arr[0]);
	for(int i=1;i<dig;++i)
		printf("%d",arr[i]);
	puts("");
};
double calpi(int ti){//calculate pi
	double sum=0;
	for(int i=0;i<ti;++i)
		sum += (double)(i&1?-1:1)/(2*i+1);
	printf("k=%d -> %3.10lf\n",ti,sum*4);
	return sum;
}
int main()
{
	calpi(1000);
	calpi(10000);
	calpi(100000);
	//use long double
	long double ldsum=0;
	for(int i=0;i<10000000;++i)
		ldsum += (long double)(i%2?-1:1)*4/(2*i+1);
	printf("%.18Lf\n",ldsum);
	puts("It takes time !! Please wait !!");
	usearray();
	scanf("%*d");
	return 0;
}
