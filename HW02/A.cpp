#include<cstdio>
#include<algorithm>

int main(){
	printf("Input three different integers:");
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("Sum is %g\n",a+b+c);
	printf("Average is %g\n",(a+b+c)/3);
	printf("Product is %g\n",a*b*c);
	printf("Smallest number is %g\n",std::min(std::min(a,b),c));
	printf("Largest number is %g\n",std::max(std::max(a,b),c));
	scanf("%*d");
	return 0;
}
