#include<cstdio>

int main(){
	int face,sum=0;
	for(int i=0;i<3;++i){
		scanf("%d",&face);
		if(face>10)
			sum+=10;
		else if(face==1)
			if(sum+11<=21)
				sum+=11;
			else
				sum+=1;
		else
			sum += face ;
	}
	printf("The sum of three cards are %d\n",sum);
	return 0;
}
