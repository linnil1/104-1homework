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
// why can't use std::swap(a,b) QQ
template <class c>
void swap(c &a,c &b){
	c tmp=a;a=b;b=tmp;
}
// why can't use std::sort() ?? QQ
#define left(x) (2*x+1)
#define right(x) (2*x+2)
template <class c>
void heapsort(c *st,c *en,bool comp(c,c)){
	int n = en -st ;
	c *arr = st;
	//build heap
	for(int i=1;i<n;++i){
		int now=i;
		while(now && comp(arr[now>>1],arr[now])){
			swap(arr[now>>1],arr[now]);	
			now>>=1;
		}
	}
	// find max and put it to back
	for(int i=n-1;i>=0;--i){
		swap(arr[0],arr[i]);
		int now=0;
		while(left(now)<i){
			c *child;
			if( right(now)<i && comp(arr[left(now)],arr[right(now)]) )//find the max
				child = arr + right(now);
			else
				child = arr + left(now);
			if( comp(arr[now],*child) ){// change to child
				swap(arr[now],*child);
				now = child - st ;
			}
			else
				break;
		}
					
	}
}

bool testmp(int a,int b){return a<b;}

void test(){
	int n;scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;++i)
		scanf("%d",arr+i);
	heapsort(arr,arr+n,testmp);
	for(int i=0;i<n;++i)
		printf("%d ",arr[i]);
	puts("");

}
int main(){
	//test();
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
//	std::sort(arr,arr+n,comquan);
	heapsort(arr,arr+n,comquan);
	puts("       Part NO.        Quantity");
	for(int i=n-1;i>=0;--i)
		printf("%15g %15g\n",arr[i].num,arr[i].quan);

	// question b
	puts("question B:");
//	std::sort(arr,arr+n,comnum);
	heapsort(arr,arr+n,comnum);
	puts("       Part NO.        Quantity");
	for(int i=0;i<n;++i)
		printf("%15g %15g\n",arr[i].num,arr[i].quan);

	scanf("%*d");
	return 0;
}
