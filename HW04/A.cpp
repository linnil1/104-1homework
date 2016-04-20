//================================================================
//  DATE       : 2015/11/4 
//  FILENAME   : HW04A038.CPP 
//  DESCRIPTION: find perfect number
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
#include <vector>
#define pb push_back
#define ll long long int
#define VI std::vector<ll>
#define MM 100000000 // every 8 digit in long long int 

void nozero(VI &v){// do not have 000021
	int len = v.size();
	for(;len>0&&v[len-1]==0;--len);
	v.resize(len);
}

VI init(std::string s){ // input a number 
	VI v;
	for(int i=s.size()-1,now=MM;i>=0;--i,now*=10){
		if(now==MM){ // every MM a int
			now=1;
			v.pb(0);
		}
		v.back()+=now*(s[i]-'0');
	}
	nozero(v);
	return v;
}
bool IN(VI &v){
	std::string s;
	if(std::cin>>s){
		v = init(s);
		return 1;
	}
	return 0;
}
	
void print(VI v){
	if(v.size()==0){
		printf("0\n");
		return ;
	}
	printf("%lld",v.back());
	for(int i=v.size()-2;i>=0;--i)
		printf("%08lld",v[i]);
	puts("");
}

VI operator + (VI &a,VI &b){
	int r=0;
	VI c;
	for(int i=0;i<a.size()||i<b.size();++i){
		ll x = i<a.size() ? a[i] : 0,
		   y = i<b.size() ? b[i] : 0;
		c.pb(x+y+r);
		r=0;
		if(c.back()>=MM){
			r = 1;
			c.back()-=MM;
		}
	}
	if(r)
		c.pb(r);
	nozero(c);
	return c;
}
			
			
VI operator * (VI a,VI b){
	ll r=0;
	VI c(a.size()+b.size()+1);
	for(int i=0;i<a.size();++i){
		for(int j=0;j<b.size();++j)
			c[i+j]+= a[i]*b[j];
		if(i%100==0){ // avoid for overflow
			for(int i=0;i<c.size();++i)
				if(c[i]>=MM){
					c[i+1]+=c[i]/MM;
					c[i]%=MM;
				}
		}
	}
	for(int i=0;i<c.size();++i)
		if(c[i]>=MM){
			c[i+1]+=c[i]/MM;
			c[i]%=MM;
		}
	nozero(c);
	return c;
}

VI operator * (VI &a,int b){// more effectency
	ll r=0;
	VI c;
	for(int i=0;i<a.size();++i){
		c.pb(a[i]*b+r);
		r=0;
		if(c[i]>=MM){
			r=c[i]/MM;
			c[i]%=MM;
		}
	}
	if(r)
		c.pb(r);
	nozero(c);
	return c;
}
			
int comp(VI &a,VI b,int st=0){//compare from st position
	//if more digits
	if(a.size() < b.size()+st )
		return -1;
	if(a.size() > b.size()+st )
		return 1;
	// same digits comare from the top
	for(int i=0;i<b.size();++i)
		if(a[a.size()-1-i] < b[b.size()-1-i] )
			return -1;
		else if(a[a.size()-1-i] > b[b.size()-1-i] )
			return 1;
	return 0;
}

VI minus(VI a,VI b,int st=0){// a>=b
	if(comp(a,b,st)<0)
		puts("error");
	for(int i=0;i+st<a.size() ;++i){
	   ll y = i   <b.size() ? b[i   ] : 0;
	   a[i+st]-=y;
		if(a[i+st]<0){
			a[i+st]+=MM;
			a[i+st+1]--;	
		}
	}
	nozero(a);
	return a;
}


VI div(VI &a,VI &b){ // attention: the value will be changed
	if(comp(a,b)<0)
		return VI();//special for zero  it's quicker
	VI c(a.size()-b.size()+1);
	for(int i=a.size()-b.size();i>=0;--i){ // binary search 
		ll min=0,max=MM,mid;
		while(min+1<max){
			mid = (min+max)>>1;
			if( comp(a,b*mid,i)<0)
				max = mid;
			else
				min = mid;
		}
		c[i]=min;
		a = minus(a,b*min,i);
	}
	nozero(a);
	nozero(c);
	return c;
}

//package
VI operator - (VI a,VI &b){
	return minus(a,b);
}
VI operator / (VI a,VI &b){
	return div(a,b);
}
VI operator % (VI a,VI &b){
	div(a,b);
	return a;
}

VI pow(VI a,int t){// divide and conquar
	VI sum=init("1");
	while(t){
		//printf("%d ",t);
		if(t&1)
			sum = sum * a;
		t>>=1;
		a = a*a;
	}
	return sum;
}

// also see https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test
bool lucas_lehmer(int p){ // to test if it is mersenne prime
	VI now=init("4");
	VI two=init("2");
	VI MOD = pow(two,p);
	MOD[0]--;
	for(int i=0;i<p-2;++i){
		//print(now);
		//printf("%d ",i); puts("zxc");
		now = now*now%MOD;
	    if( comp(now,two)<0)
			now = now+MOD-two;
		else
			now = now - two;
	}
	return now.size() == 0 ;
}

bool PerfectNumber(ll num){
	ll sum=0;
	int lim = (int)sqrt(num);
	for(int i=1;i<=lim;++i)
		if(num%i==0)
			sum+=i+num/i;
	return num*2 == sum ;// beacuse it add itself once
}
int main(){
	puts("find perfect number between 1 and 10000");
	for(int i=1;i<=10000;++i)
		if(PerfectNumber(i))
			printf("%d ",i);
	puts("");
	/*test*/
	/*
	VI a,b;
	while(IN(a) && IN(b)){
		print(a/b);
	}
	*/

	int p=2200;
	puts("wait for finding perfect number about a minutes");
	while(1){
		//printf("%d\n",p);
		if(lucas_lehmer(p))
			break;
		puts("wait !!");
		++p;
	}
	puts("i find it !!");
	printf("It is (2^(%d-1))*((2^%d)-1)\n",p,p);
	scanf("%*c");
	VI two=init("2");
	VI tmp = pow(two,p);
	--tmp[0];
	print(pow(two,p-1)*tmp);

	return 0;
}
