//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015// 
//  FILENAME   : HW01A038.CPP 
//  DESCRIPTION: 
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

std::string alpha[40] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..","-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",".-.-.-", "--..--","..--.." }; 

int main(){
	std::fstream in,out;
	in.open("MorseCode.txt",std::ios_base::in);
	out.open("MorseCode.dat",std::ios_base::out);
	if(!in.is_open()||!out.is_open()){
		puts("Oh no I cant open");
		return 0;
	};
	char c;
	while(in.get(c)){
		//if(c==' ')
		//	out<<c;
		if('A'<=c && c<='Z')
			c=c-'A'+'a';
		if( 'a'<=c && c<='z')
			out<< alpha[c-'a'];
		else if('0'<=c && c<='9')
			out << alpha[c-'0'+26];
		else {
			switch(c){
				case '.':out<<alpha[36];break;
				case ',':out<<alpha[37];break;
				case '?':out<<alpha[38];break;
			}
			//no corresdpont no print
		}
	}
	in.close();
	out.close();
	return 0;
}
