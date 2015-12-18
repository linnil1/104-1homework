//================================================================
//  PROGRAMMER : 林弘曄
//  DATE       : 2015/12/18
//  FILENAME   : HW07A038.CPP 
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
#include <fstream>
#include <vector>
#define VI std::vector<int>
using std::string;

std::fstream fin,fout;

bool filestrcmp(int a,int b){
	string sa,sb;
	fout.seekg(a);
	getline(fout,sa);
	fout.seekg(b);
	getline(fout,sb);
	return sa<sb;
}

int main(){
	// init
	fin.open("words.txt",std::ios_base::in);
	fout.open("wordstxttmp",std::ios_base::out);
	if(!fin || !fout){
		puts("i can't open");
		scanf("%*c");
		return 0;
	}

	//reserve and store
	VI sto;
	sto = VI();
	string sin="",sout;
	int sum=0;
	while(getline(fin,sin)){
		string rev(sin.rbegin(),sin.rend());
		fout << rev << "\n";
		sto.push_back(sum);
		sum += sin.size()+1;
	}
	fout.close();
	fout.open("wordstxttmp",std::ios_base::in);

	//sorted
	std::sort(sto.begin(),sto.end(),filestrcmp);

	//compare
	//fin.seekg(0); beacuse it is eof
	fin.close();
	fin.open("words.txt",std::ios_base::in);
	string strmax ;
	for(int i=0;i<sto.size();++i){
		fout.seekg(sto[i]);
		getline(fout,sout);
		while( sin<sout && getline(fin,sin));
		if(sin < sout )//sin is end
			break;
		//if(sin == sout)
		//	std::cout << sin<< " " ;
		if(sin==sout && sin.size() > strmax.size())
			strmax =sin;
	}
	std::cout << "the longest words:"<<strmax<<"\n"; 
	fin.close();
	fout.close();

	return 0;
}
