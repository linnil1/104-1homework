//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015// 
//  FILENAME   : HW01A038.CPP 
//  DESCRIPTION: 
//================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <assert.h>
#define VI std::vector<int>
using std::string;

// it is for double !!
bool digIn(double &out){		//foolproof
	char c[100000]; int ok = 0; 
	while (!ok){
		ok = 1;
		if( scanf("%s", c) ==EOF)
			return 0;
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
	return 1;
}

int main(){
	puts("if finished  Enter ctrl+z to exit");
	double a;
	while(digIn(a)){
	}
	return 0;
}
