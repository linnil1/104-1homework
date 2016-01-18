#include<bits/stdc++.h>

#define vs std::vector<std::string>
using std::string;
vs getwhere(string where){
	FILE *f = popen(((string)"dir \""+where+"\" /b").c_str(),"r");
	vs v;
	char c[1000];
	while(fgets(c,1000,f)){
		v.push_back(c);
		while(v.back().back()=='\n')
			v.back().pop_back();
	}
	return v; 
}
int main(int argn , char **argv){
	if(argn==1){
		return 0;
	}
		
	string prname ;string hw = argv[1];
	for(int i=hw.size()-1;i>=0;--i)
		if(hw[i]=='\\'){
			for(int j=i+1;j<hw.size();++j)
				prname.push_back(hw[j]);
			break;
		}
	std::cout<< hw << "\n";
	popen(("del /q "+prname+"\\submit").c_str(),"w");
	popen(("mkdir "+prname+"\\submit").c_str(),"w");
	
	vs hwdir = getwhere(hw);
	for(int i=0;i<hwdir.size();++i){
		if(hwdir[i]=="submit")
			continue;
		popen(		 ("copy \""+hw+"\\"+hwdir[i]+"\\"+hwdir[i]+"\\"+hwdir[i]+".cpp\" \""+hw+"\\submit\\"+prname+hwdir[i]+"038.cpp\"\n").c_str() ,"r");
		std::cout << ("copy \""+hw+"\\"+hwdir[i]+"\\"+hwdir[i]+"\\"+hwdir[i]+".cpp\" \""+hw+"\\submit\\"+prname+hwdir[i]+"038.cpp\"\n") ;
		popen(		 ("copy \""+hw+"\\"+hwdir[i]+"\\Release\\"     +hwdir[i]+".exe\" \""+hw+"\\submit\\"+prname+hwdir[i]+"038.exe\"\n").c_str() ,"r");
		std::cout << ("copy \""+hw+"\\"+hwdir[i]+"\\Release\\"     +hwdir[i]+".exe\" \""+hw+"\\submit\\"+prname+hwdir[i]+"038.exe\"\n") ;
	}
	scanf("%*d");
	
	
	
} 
