//================================================================
//  PROGRAMMER : ªL¥°¾ç 
//  DATE       : 2015/9/24 
//  FILENAME   : HW01Cb04611017.CPP 
//  DESCRIPTION: Fine the speed  
//================================================================
#include<iostream>
#include<cstdlib>
using std::cout;
int main(){
	double speed, fe, fr;
	fe = 2e10;
	fr = 2.00000035e10;// i only change this one
	speed = 6.685e8 * (fr - fe) / (fr + fe);
	cout << "The speed is " << speed << "miles/hour " << std::endl;
	system("pause");
	
	return 0;
}
