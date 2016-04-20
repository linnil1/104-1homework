//================================================================
//  DATE       : 2015/10/1 
//  FILENAME   : HW02A038.CPP 
//  DESCRIPTION: As a problem described 
//================================================================
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
double digIn(){		//foolproof
	char c[100000]; int ok = 0; double out;
	while (!ok){
		ok = 1;
		scanf("%s", c);
		int dot = 0,mus=0;
		for (int i = 0; c[i] && ok && dot<=1 && mus<=1; ++i)//prevent strange characters
			if (isdigit(c[i]))
				continue;
			else if (c[i] == '.')
				++dot;
			else if (c[i] == '-')
				++mus;
			else
				ok = 0; 
		if (dot > 1 || mus>1)
			ok = 0; 
		if (!ok)
			puts("It is not a number !! Please redo it !!");
		else
			out = atof(c);
	}
	return out;
}
int main(){
	printf("Input three different integers:");
	double a, b, c;
	a = digIn();b = digIn();c = digIn();
	printf("Sum is %g\n", a + b + c);
	printf("Average is %g\n", (a + b + c) / 3);
	printf("Product is %g\n", a*b*c);
	printf("Smallest number is %g\n", std::min(std::min(a, b), c));
	printf("Largest number is %g\n", std::max(std::max(a, b), c));
	scanf("%*d");
	return 0;
}
