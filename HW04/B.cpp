//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/11/2 
//  FILENAME   : HW04B038.CPP 
//  DESCRIPTION: calc standard deviation as question described 
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
int myexit; // for EOF 
double digIn(){		//foolproof
	char c[100000]; int ok = 0; double out;
	while (!ok){
		ok = 1;
		if( scanf("%s", c) ==EOF )
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

int main(){
	//input 
	puts("Enter number. Enter ctrl+z to stop the input");
	myexit=0;
	double arr[100];
	int n=-1;// record the numbers 0f number.
	while(!myexit){
		arr[++n]=digIn();
	}

	//calc standard deviation
	double sd=0,avg=0;
	for(int i=0;i<n;++i)
		avg += arr[i];
	avg/=n;
	for(int i=0;i<n;++i)
		sd+= (arr[i]-avg)*(arr[i]-avg);
	sd = sqrt(sd/n);
	
	// discard two sd away
	int oldn=n;n=0;
	for(int i=0;i<oldn;++i)
		if( std::abs(arr[i]-avg) <= 2*sd )
			arr[n++]=arr[i];
			
	//recalc sd
	sd=0,avg=0;
	for(int i=0;i<n;++i)
		avg += arr[i];
	avg/=n;
	for(int i=0;i<n;++i)
		sd+= (arr[i]-avg)*(arr[i]-avg);
	sd = sqrt(sd/n);	

	//ouput
	puts("the number i keep");
	for(int i=0;i<n;++i)
		printf("%g ",arr[i]);
	puts("");
	printf("new average : %g \nnew standard deviation : %g \n",avg,sd);
	scanf("%*d");
	return 0;

}
