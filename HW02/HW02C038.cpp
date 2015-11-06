//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/10/1 
//  FILENAME   : HW01C038.CPP 
//  DESCRIPTION: calculate BMR
//================================================================
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<conio.h> // i really don't like this library because it is not pure c++
double digIn(){		//foolproof
	char c[100000]; int ok = 0; double out;
	while (!ok){
		ok = 1;
		scanf("%s", c);
		int dot = 0;
		for (int i = 0; c[i] && ok && dot <= 1; ++i)//prevent strange characters
			if (isdigit(c[i]))
				continue;
			else if (c[i] == '.')
				++dot;
			else
				ok = 0;
		if (dot > 1)
			ok = 0;
		if (!ok)
			puts("It is not a possitive number !! Please redo it !!");
		else
			out = atof(c);
	}
	return out;
}
int main(){
	double w, h, age;
	printf("What is your weight in kilograms ?\n");
	w = digIn(); 
	puts("What is your height in centimeters ?");
	h = digIn();
	puts("What is your age in years ?");
	age = digIn();
	/*originally use basic c++　method
	char c[2000];
	do{
		puts("Enter you are Male or Female (M/F)");
		scanf("%s", c);
	} while (c[0] != 'M' && c[0] != 'F');
	if (c[0] == 'M')
		bmr = 66.5 + 13.75*w + 5.003 * h - 6.755 * age;
	else if (c[0] == 'F')
		bmr = 655 + 9.563 *w + 1.85 *h - 4.676 *age;*/

	// use conio.h
	char ch;
	do{
		printf("Enter you are Male or Female (M/F)");
		ch = toupper(_getche());
	} while (ch != 'M' && ch!= 'F');
	puts("");
	double bmr;
	if (ch == 'M')
		bmr = 66.5 + 13.75*w + 5.003 * h - 6.755 * age;
	else if (ch == 'F')
		bmr = 655 + 9.563 *w + 1.85 *h - 4.676 *age;
	printf("Your Basal Metabolic Rate(BMR) is %g calories to maintain your weight\n", bmr);
	printf("You need to eat at least %d numbers of chocolate bars\n", (int)ceil(bmr/230));
	scanf("%*d");
	return 0;
}
