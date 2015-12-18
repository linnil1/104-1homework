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

std::fstream fin;

bool bisear(std::fstream &fin,VI &sto,string s){
	int min=0,max=sto.size(),mid;
	while(min +1 < max ){
		mid = (min+max)>>1;
		string midst;
		fin.seekg(sto[mid]);
		getline(fin,midst);
		if( midst <= s)
			min = mid;
		else
			max = mid;
	}
	string near ;
	fin.seekg(sto[min]);
	getline(fin,near);
	return near == s ;
}

bool stocmp(int a,int b){
	string sa,sb;
	fin.seekg(a);
	getline(fin,sa);
	fin.seekg(b);
	getline(fin,sb);
	return sa < sb;
}

int main(){
	// init
	fin.open("words.txt",std::ios_base::in);
	if(!fin){ 
		puts("i can't open");
		scanf("%*c");
		return 0;
	}

	//get pos
	VI sto;
	sto = VI();
	string sin;
	int sum=0;
	while(getline(fin,sin)){
		sto.push_back(sum);
		sum += sin.size()+1;
	}

	//binary search
	fin.close();
	fin.open("words.txt",std::ios_base::in);
	std::sort(sto.begin(),sto.end(),stocmp);
	string maxsin;
	for(int i=0;i<sto.size();++i){
		fin.seekg(sto[i]);
		getline(fin,sin);
//		if(bisear(fin,sto, string(sin.rbegin(),sin.rend())) )
//			std::cout << sin <<" ";
		if(bisear(fin,sto, string(sin.rbegin(),sin.rend())) && sin.size() > maxsin.size())
			maxsin = sin;
	}
	std::cout << "the longest:" << maxsin <<"\n";
	fin.close();


	return 0;
}
