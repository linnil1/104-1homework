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
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

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
		friend istream& operator >> (istream &in,Fractions &a){
			int n,den;
			char c;
			in>>n>>c>>den;
			if(c!='/')
				throw 0;
			a = Fractions(n,den);
			return in;
		}
		friend ostream& operator << (ostream &out,Fractions &a){
			if(a.num){
				out << a.num ;
				if(a.denum!=1)
					out << "/" << a.denum ;
			}
			else
				out << "0";
			return out;
		}
};

int main(){
	puts("puts ctrl+z to end ");
	puts("inputs like this: 1/3 + 2/5");
	Fractions a,b,ans;
	while(1){
		try{
			cin>>a;
			cin.exceptions(istream::failbit | istream::badbit);
			//get +-*
			char c;
			do
				cin >> c;
			while(c!='+' && c!='-'&& c!='*'&& c!='/');
			cin>>b;
			cin.exceptions(istream::failbit | istream::badbit);
			switch(c){
				case '+':ans = a+b;break;
				case '-':ans = a-b;break;
				case '*':ans = a*b;break;
				case '/':ans = a/b;break;
			}
			cout << ans <<"\n";
		}
		catch(int){
//			while(getchar()!='\n');
//			cin.clear();
			cin.ignore(0x7fffffff,'\n');
			puts("no answer");
		}
		catch(istream::failure){
			break;
		}

	}
	return 0;
}
