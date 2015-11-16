//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/11/16
//  FILENAME   : HW05A038.CPP 
//  DESCRIPTION: basic cell game 
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

struct cellmap{
	char **map;
	int c,r;
	
	void init(){
		map= new char*[c];
		for(int i=0;i<c;++i)
			map[i] = new char[r+2];// for \0
	}

	bool input(){
		if(scanf("%d%d",&c,&r)==EOF)
			return 0; // stop
		init();

		// input map
		for(int i=0;i<c;++i)
			scanf("%s",map[i]);

		// change to 01
		for(int i=0;i<c;++i)
			for(int j=0;j<r;++j)
				map[i][j]-='0';
		return 1;
	}

	void end(){
		for(int i=0;i<c;++i)
			delete[] map[i];
		delete[] map;
	}

	void print(){
		for(int x=0;x<c;++x,puts(""))
			for(int y=0;y<r;++y)
				putchar(map[x][y]+'0');
	};

	void nextgen(){
		cellmap tmp=*this;// only copy c and r
		tmp.init();
		
		for(int i=0;i<c;++i)
			for(int j=0;j<r;++j){//every grid
				int around=0;//find around grid
				for(int x=-1;x<=1;++x)
					for(int y=-1;y<=1;++y)
						if(x+i<c && x+i >=0 && j+y<r && y+j>=0 && !(x==0 && y==0)&& map[x+i][y+j])
							++around;
				//cal is live or not
				tmp.map[i][j] = map[i][j] ? (2<=around && around <= 3) : around==3;
			}

		// copy to map
		for(int i=0;i<c;++i)
			for(int j=0;j<r;++j)
				map[i][j] = tmp.map[i][j];

		tmp.end();
	}

};

int main(){
	puts("use 0 to exit");
	cellmap map;
	while(map.input()){
		//start
		int gen;
		scanf("%d",&gen);
		for(int i=1;i<=gen;++i){
			// output
			printf("%d generation\n",i);
			map.print();
			map.nextgen();
		}
		map.end();
	}
	return 0;
}
