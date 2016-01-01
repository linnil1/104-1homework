//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/12/18
//  FILENAME   : HW07B038.CPP 
//  DESCRIPTION: Fraction operation
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


int gcd(int a,int b){return b?gcd(b,a%b):a;}

class Fractions{
	private:
		int num,denum;
		void reduce(){
			int g = gcd(num,denum);
			num/=g;
			denum/=g;
		}
	public:
		//init
		Fractions(){num=denum=1;};
		Fractions(int _num,int _denum){
			if(!_denum)
				throw 0;
			num=_num;denum=_denum;
			reduce();
		};

		//operator
		Fractions operator + (Fractions b){
			return Fractions(num*b.denum+denum*b.num,denum*b.denum); }
		Fractions operator - (Fractions b){
			return Fractions(num*b.denum-denum*b.num,denum*b.denum); }
		Fractions operator * (Fractions b){
			return Fractions(num*b.num,denum*b.denum); }
		Fractions operator / (Fractions b){
			return Fractions(num*b.denum,denum*b.num); }

		//io
		bool in(){
			int n,den;
			if(scanf("%d/%d",&n,&den)==EOF)
				return 0;
			*this = Fractions(n,den);
			return 1;
		}
		void print(){
			if(num)
				printf("%d/%d",num,denum);
			else
				putchar('0');
		}
};
int main(){
	puts("puts ctrl+z to end ");
	puts("inputs like this: 1/3 + 2/5");
	Fractions a,b,ans;
	while(1){
		try{
			if(!a.in())
				break;
			char ch[10];scanf("%s",ch);
			if(!b.in())
				break;
			switch(ch[0]){
				case '+':ans = a+b;break;
				case '-':ans = a-b;break;
				case '*':ans = a*b;break;
				case '/':ans = a/b;break;
			}
			ans.print();
			puts("");
		}
		catch(int){
			while(getchar()!='\n');
			puts("no answer");
		}

	}
	return 0;
}
