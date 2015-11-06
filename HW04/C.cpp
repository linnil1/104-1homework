//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/11/2
//  FILENAME   : HW04C038.CPP 
//  DESCRIPTION: use struct to sorting 
//================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <string>

// it is for double !!
int myexit;//for EOF END
double digIn(){		//foolproof
	char c[100000]; int ok = 0; double out;
	while (!ok){
		ok = 1;
		if( scanf("%s", c) ==EOF)
			{myexit=1;return 0;}
		int dot = 0,mus=0;
		for (int i = 0; c[i] && ok && dot<=1 && mus<=1; ++i)
			if (isdigit(c[i]))
				continue;
			else if (c[i] == '-')
				++mus;
			else if (c[i] == '.')
				++dot;
			else
				ok = 0; 
		if (dot > 1 || mus >1)
			ok = 0; 
		if (!ok)
			puts("It is not a number !! Please redo it !!");
		else
			out = atof(c);
	}
	return out;
}

// build a struct is more easier to use std::sort
struct part{
	double num,quan;
};
bool comnum(part a,part b){
	return a.num < b.num;
}
bool comquan(part a,part b){
	return a.quan < b.quan;
}

int main(){
	//input
	myexit=0;
	puts("first enter number and second enter quantity per part");
	puts("enter EOF to stop input");
	int n=-1;
	part arr[1000];
	while(!myexit){
		arr[++n].num=digIn();
		if(myexit)
			break;
		arr[n].quan=digIn();
	}
	
	// question a
	puts("question A:");
	std::sort(arr,arr+n,comquan);
	puts("       Part NO.        Quantity");
	for(int i=n-1;i>=0;--i)
		printf("%15g %15g\n",arr[i].num,arr[i].quan);

	// question b
	puts("question B:");
	std::sort(arr,arr+n,comnum);
	puts("       Part NO.        Quantity");
	for(int i=0;i<n;++i)
		printf("%15g %15g\n",arr[i].num,arr[i].quan);

	scanf("%*d");
	return 0;
}
