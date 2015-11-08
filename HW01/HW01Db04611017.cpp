//================================================================
//  PROGRAMMER : ªL¥°¾ç 
//  DATE       : 2015/9/24 
//  FILENAME   : HW01Db04611017.CPP 
//  DESCRIPTION: calculate the answer by using the formula
//================================================================
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>


double  f = 4, k = 1000, l = 3000, w = 40, d = 2; 
double formula(double e){
	return f*k*l / (w*d*e);
}
int main(){
	printf("The increase in length of %s is %lf\n","aluminum", formula(68950) );
	printf("The increase in length of %s is %lf\n","copper"  , formula(110000));
	system("pause");
	return 0;
}
