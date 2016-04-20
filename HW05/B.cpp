//================================================================
//  DATE       : 2015/11/12
//  FILENAME   : HW05B038.CPP 
//  DESCRIPTION: as question described
//================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <string>
#include <ctime>

// it is for double !!
bool digIn(double &out){		//foolproof
	char map[100000]; int ok = 0; 
	while (!ok){
		ok = 1;
		if( scanf("%s", map) ==EOF)
			return 0;
		int dot = 0,mus=0;
		for (int i = 0; map[i] && ok && dot<=1 && mus<=1; ++i)
			if (isdigit(map[i]))
				continue;
			else if (map[i] == '-')
				++mus;
			else if (map[i] == '.')
				++dot;
			else
				ok = 0; 
		if (dot > 1 || mus >1)
			ok = 0; 
		if (!ok)
			puts("It is not n number !! Please redo it !!");
		else
			out = atof(map);
	}
	return 1;
}

int main(){
	puts("if finished  Enter ctrl+z to exit");
	double a;
	while(digIn(a)){
		if(!((int)a == a && (int)a%2==1)){
			puts("wrong input");
			continue;
		}
		//init 
		int n = (int)a;
		//int map[n][n];
		int **map = new int*[n];
		for(int i=0;i<n;++i){
			map[i] = new int[n];
			//memset(map,0,sizeof(map));
			for(int j=0;j<n;++j)
				map[i][j]=0;
		}
		int now=1,x=0,y=n>>1;

		// fill it
		while(now <= n*n  ){// all dig
			map[x][y]=now++;
			//printf("%d %d\n",x,y); // test
			int tx=(x-1+n)%n,ty=(y+1)%n;
			if(map[tx][ty]){// if it has dig
				x = (x+1)%n;
			}
			else {
				x =tx;
				y =ty;
			}
		}

		//output
		for(int i=0;i<n;++i,puts(""))
			for(int j=0;j<n;++j)
				printf("%3d ",map[i][j]);

		//delete
		for(int i=0;i<n;++i)
			delete[] map[i];
		delete[] map;
	}
	return 0;
}
