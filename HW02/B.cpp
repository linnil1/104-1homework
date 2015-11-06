#include<cstdio>

int main(){
	double  a,b;
	puts("GIve me how many hours and minutes");
	scanf("%lf%lf",&a,&b);
	double t = a + b/60;
	printf("%g\n",(double)4*t*t/(t+2) - 20 );
	scanf("%*d");
	return 0;
}
