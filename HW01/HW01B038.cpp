//================================================================
//  DATE       : 2015/9/24 
//  FILENAME   : HW01Bb04611017.CPP 
//  DESCRIPTION: Give a b c and can the averge of the three. 
//================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	double grade1;  // declare grade1 as a double variable
	double grade2;  // declare grade2 as a double variable
	
	double total;   // declare total as a double variable
	double average; // declare average as a double variable
	grade1 = 85.5;
	grade2 = 97.0;
	
	// here cames the differents !!
	double grade3;
	cout << "Please input a number\n";
	cin >> grade3;
	total = grade1 + grade2 + grade3;
	average = total / 3.0;  // divide the total by 3.0
	cout << "The average grade is " << average << endl;
	system("pause");
	return 0;
}
