//================================================================
//  DATE       : 2015/10/1 
//  FILENAME   : HW01B038.CPP 
//  DESCRIPTION: Display the temperature in a freezer
//================================================================
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
int  digInint(int lim){		//foolproof
	char c[100000],ok=0;int out;
	while (!ok){
		ok = 1;
		scanf("%s", c);
		for (int i = 0; c[i] && ok ; ++i)//prevent strange characters
			if (!isdigit(c[i])){
				puts("It is not a posstive Interger !! Please redo it !!");
				ok = 0;
			}
		if (strlen(c) > 5){
			puts("It is too big !! Please redo it !!");
			ok = 0;
		}
			
		if(ok){
			out = atoi(c);
			/*if (out < 0){ // negitive has out when '-' on strange characters
				puts("It can't be negitive  !! Please reenter it !!");
				ok = 0;
			}*/
			if (out >lim){
				printf("It can't be more than %d !! Please redo it !!\n",lim);
				ok = 0;
			}
		}
	}
	return out;
}
int main(){
	double  a, b;
	puts("GIve me how many hours and minutes");
	a = digInint(24); b = digInint(60);
	double t = a + b / 60;
	printf("The estimated temperture in a freezer is %g\n", (double)4 * t*t / (t + 2) - 20);
	scanf("%*d");
	return 0;
}
