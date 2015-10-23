//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015// 
//  FILENAME   : HW01A038.CPP 
//  DESCRIPTION: 
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

// it is for positive double !!
double digIn(){		//foolproof
	char c[100000]; int ok = 0; double out;
	while (!ok){
		ok = 1;
		scanf("%s", c);
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
	scanf("%*d");
	return 0;
}
