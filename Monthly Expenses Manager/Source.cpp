#include<iostream>
#include"Date.h";

using namespace std;


int main()
{
	Date d1(1, 12, 2020), d2 (1,11,2020), d3(1,1,2021);

	cout << (d1 > d2) << "   " << (d3 > d1);
}