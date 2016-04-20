//================================================================
//  DATE       : 2015/10/19
//  FILENAME   : HW03C038.CPP 
//  DESCRIPTION: As question says
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
#include <conio.h> // i don't like this not standard library
char table[10][5] = { "", " ", "ABC", "DEF", "GHI", "JKL",
"MNO", "PQRS", "TUV", "WXYZ" };
/*int main(){
	char c[10000];
	while (~scanf("%s", c)){
		// use number and times to determine what the word is
		for (int i = 0, t = 0, num = -1; c[i]; ++i)
		if (c[i] == '0'){
			putchar(table[num][t]);
			num = -1;
		}
		else if (num == -1){
			num = c[i] - '0';
			t = 0;
		}
		else if (c[i] - '0' != num)
			puts("error");
		else
			++t;
		puts("");
	}
	return 0;
}*/

int main(){
	int num = -1, t = -1;
	std::string s;
	while (1){
		char c = _getch();// to fool proof
		// use number and times to determine what the word is
		if (!isdigit(c))
			continue;
		if (c == '0'){
			if (num == -1){
				_putch(c);
				break;//end for consective 0 or first 0
			}
			s.push_back(table[num][t]);
			num = -1;//to init
		}
		else if (num == -1){//to init
			num = c - '0';
			t = 0;
		}
		else if (c - '0' != num)//strange input
			continue;
		else{// no character like 22220
			if (num == 1)// it can be almost one space at a time
				if (t > -1)
					continue;
				else
					++t;
			else if (num == 7 || num == 9) 
				if (t > 2)
					continue;
				else
					++t;
			else if (t > 1)
				continue;
			else
				++t;
		}
		_putch(c);
	}
	std::cout << "\n" << s << "\n";
	scanf("%*c");
	return 0;
}
