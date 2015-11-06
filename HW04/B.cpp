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
bool digInLine(double *arr,int &n){	// input in a line 
	puts("input in a line ");
	char c[10000];
	if(fgets(c,10000,stdin)==NULL){//not NULL 
		return 0;
	}
	n=0;
	char *now=strtok(c," \n");// use strtok the separate space
	while(now!=NULL){//foolproof
		int dot = 0,mus=0,ok=1;
		char *st=now;
		for (; *now  && dot<=1 && ok && mus<=1; ++now)
			if (isdigit(*now))
				continue;
			else if (*now == '-')
				++mus;
			else if (*now == '.')
				++dot;
			else
				ok = 0; 
		if (dot > 1 || mus >1)
			ok = 0; 
		if (!ok)
			printf("%s is not a number !! i will ignore it !!\n",st);
		else
			arr[n++] = atof(st);
		now = strtok(NULL," \n");
	}
	return 1;
}

int main(){
	//input 
	puts("Enter ctrl+z to stop the input");
	double arr[100];
	int n;

	while(digInLine(arr,n)){
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
	}
	return 0;

}
