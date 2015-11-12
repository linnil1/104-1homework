//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/11/2
//  FILENAME   : HW04D038.CPP 
//  DESCRIPTION: use random 
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
#include <ctime>

int expect[14]={0,0,1,2,3,4,5,6,5,4,3,2,1};
void dice(int ti){
	int stat[15];
	memset(stat,0,sizeof(stat));
	for(int i=0;i<ti;++i)
		++stat[ rand()%6 + rand()% 6 +2 ] ;

	printf("%d times\n",ti);
	puts("sum times     percetage   expect percetage  absolute different");
	double sum=0;
	for(int i=2;i<=12;++i){
		printf("%2d %6d      %7.2f%%      %7.2f%%     %7.2f%%\n"
				,i,stat[i],(double)stat[i]*100/ti,(double)expect[i]*100/36,
				 std::fabs((double)stat[i]*100/ti-(double)expect[i]*100/36));
		sum += std::fabs((double)stat[i]*100/ti-expect[i]*100/36);
	}
	printf("average different percetage %.2f \n",sum/11);
	puts("");
}


int main(){
	srand(time(NULL));
	dice(1000);	
	dice(10000);
	dice(100000);
	scanf("%*d");
	return 0;
}
