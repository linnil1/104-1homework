#include<cstdio>

int main(){
	double w,h,age;
	printf("What is your weight in kilograms ?\n");
	scanf("%lf",&w);
	puts("What is your height in centimeters ?");
	scanf("%lf",&h);
	puts("What is your age in years ?");
	scanf("%lf",&age);
	puts("Enter you are Male or Female (M/F)");
	char c[2];
	scanf("%s",c);
	double bmr ;
	if(c[0]=='M')
		bmr = 66.5 + 13.75*w + 5.003 * h - 6.755 * age ;
	else if(c[0]=='F')
		bmr = 655 + 9.563 *w + 1.85 *h - 4.676 *age ;
	printf("Your Basal Metabolic Rate(BMR) is %lf calories to maintain your weight\n",bmr);
	return 0;
}
