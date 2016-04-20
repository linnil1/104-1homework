//================================================================
//  DATE       : 2015/10/19 
//  FILENAME   : HW03D038.CPP 
//  DESCRIPTION: use gcd 
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

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}// recursive

int main(){
	printf("      ");
	for(int i=1;i<=20;++i)
		printf("%3d",i);
	puts("");
	for(int i=0;i<70;++i)
		putchar('=');
	puts("");
	for(int i=1;i<=20;++i,puts("")){
		printf("%3d | ",i);
		for(int j=1;j<=20;++j)
		//	printf("%3d",std::__gcd(i,j));// it is buildin function XD
			printf("%3d",gcd(i,j));
	}
	scanf("%*d");
	return 0;
}
