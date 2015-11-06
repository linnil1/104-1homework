//================================================================
//  PROGRAMMER : ¿¿¿
//  DATE       : 2015/10/19
//  FILENAME   : HW03B038.CPP 
//  DESCRIPTION: find prime number 
//================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <string>


// linear sieve
struct prim{
	const static int MM=100000000;
	int pr[MM/10],ps;
	char c[MM+1];
	void init(){
		ps=0;
		memset(c,1,sizeof(c));
		for(int i=2;i<=MM;++i){
			if(c[i])pr[ps++]=i;
			for(int j=0;j<ps && pr[j]*i<=MM ; ++j){
				c[ pr[j]*i ] = 0 ;
				if(i%pr[j]==0)
					break;
			};			
		}
	}
	// is prime nubmers
	long long int isprim(long long int a){		
		//be careful at 0,1 
		int n = (int)sqrt(a);
		for(int i=0;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	
}p;
int main(){
	p.init();
	puts("all the prime numbers less than 1000:");
	for(int i=0;i<p.ps && p.pr[i]<1000;++i)
		printf("%d ",p.pr[i]);
	puts("");
	// bonus
	puts("all the twin prime numbers less than 1000:");
	for(int i=5;i<=1000;i+=2)
		if(p.c[i-2] && p.c[i])
			printf("(%d,%d) ",i-2,i);
	
	//find max twin
	long long int max=0;
	for(long long int i=10000000000000000LL-1;i;i-=2)
		if(p.isprim(i)==i && p.isprim(i-2) ==i-2){
			max = i ;
			break;
		}
	printf("\nThe greatest twin primes is (%lld,%lld)\n",max-2,max);
	scanf("%*d");
	return 0;
}
