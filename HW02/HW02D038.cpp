//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/10/1 
//  FILENAME   : HW01D038.CPP 
//  DESCRIPTION: AS question described
//================================================================
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
int faceIn(){		//foolproof
	// it can be input as a 2 3 4 5 j q k
	// or just 1 2 3 4 5 10 11 12
	char c[100000]; int ok = 0; 
	while (!ok){
		ok = 1;
		scanf("%s", c);
		if (strlen(c) == 1)//separate string to one word and two words
			if (isdigit(c[0]) && c[0]!='0')
				return c[0] - '0';
			else {
				switch (tolower(c[0])){
					case 'a':return 1;
					case 'j':return 11;
					case 'q':return 12;
					case 'k':return 13;
					default: puts("Invalid!! Redo it !!"); ok = 0; break;
				}
			}
		else if (strlen(c) == 2 && c[0] == '1' && c[1] >= '0' && c[1] <= '3')
			return 10 + c[1] - '0';
		else{
			ok = 0;
			puts("Invalid!! Redo it !!");
		}
	}
}
int main(){
	puts("Enter three faces");
	int sum=0,ace=0;
	for (int i = 0; i<3; ++i){
		int face = faceIn();
		if (face>10)
			sum += 10, printf("%d->%d\n", face, 10);
		else if (face == 1)
			++ace;
		else
			sum += face, printf("%d->%d\n", face, face);
	}
	//special case not for greedy
	if (ace == 2 && sum == 10)
		sum += 2, ace = 0;
	//greedy
	while (ace--)
		if (sum + 11 <= 21)
			sum += 11, printf("%d->%d\n", 1, 11);
		else
			++sum, printf("%d->%d\n", 1, 1);
	printf("The sum of three cards are %d\n", sum);
	scanf("%*d");
	return 0;
}
