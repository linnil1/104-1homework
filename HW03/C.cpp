//================================================================
//  DATE       : 2015/10/19
//  FILENAME   : HW03C038.CPP 
//  DESCRIPTION: As question says
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

char table[10][5]={""," ","ABC","DEF","GHI","JKL",
	"MNO","PQRS","TUV","WXYZ"};
int main(){
	char c[10000];
	while(~scanf("%s",c)){
	// use number and times to determine what the word is
	for(int i=0,t=0,num=-1;c[i];++i)
		if(c[i]=='0'){
			putchar(table[num][t]);
			num=-1;
		}
		else if(num == -1 ){
			num = c[i]-'0';
			t=0;
		}
		else if(c[i]-'0' != num )
			puts("error");
		else
			++t;
	puts("");
}
	return 0;
}
