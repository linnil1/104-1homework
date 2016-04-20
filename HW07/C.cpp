//================================================================
//  DATE       : 2015/12/18
//  FILENAME   : HW07C038.cpp
//  DESCRIPTION: solve sudoku
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
#include <fstream>
#include <vector>
#include <assert.h>
#define VI std::vector<int>
using std::string;

int map[9][9];
VI fill;//store fill pos
int block[3][3];// a block
int row[9],col[9];

#define at(a,num) (a&(1<<num))
bool dfs(int num){
	if(num==fill.size())
		return 1;
	int r=fill[num]/9,c=fill[num]%9;
	for(int i=0;i<9;++i)
		if(at(row[r],i) && at(col[c],i) && at(block[r/3][c/3],i)){
			row[r] ^= 1<<i; 
			col[c] ^= 1<<i;
			block[r/3][c/3] ^= 1<<i;
			map[r][c] = i ;
			if( dfs(num+1))
				return 1;
			row[r] ^= 1<<i; 
			col[c] ^= 1<<i;
			block[r/3][c/3] ^= 1<<i;
		}
	return 0;
}

int main(int argc,char **argv){
	if(argc!=2){
		puts("drag file to exe to get solve");
		return 0;
	}
	//file input
	std::fstream f;
	f.open(argv[1],std::ios_base::in);
	if(!f){
		puts("oh on... i can't open");
		return 0;
	}
	for(int i=0;i<9;++i){
		char c[20];
		f >> c;
		if(strlen(c)!=9){
			puts("wrong input");
			return 0;
		}
		for(int j=0;j<9;++j)
			map[i][j] = c[j]-'1';
		
	}
	f.close();

	//dfs
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			block[i][j]=0777;
	for(int i=0;i<9;++i)
		row[i]=col[i]=0777;

	fill = VI();
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			if(map[i][j]<0)
				fill.push_back(i*9+j);
			else {
				row[i] ^= 1<< map[i][j];
				col[j] ^= 1<< map[i][j];
				block[i/3][j/3] ^= 1<< map[i][j];
			}
	
	//outpu
	if(dfs(0))
		for(int i=0;i<9;++i,puts(""))
			for(int j=0;j<9;++j)
				printf("%d ",map[i][j]+1);
	else
		puts("no answer");

	return 0;
}
