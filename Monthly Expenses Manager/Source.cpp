#include<iostream>
#include "Date.h"

#include "inform_provider.h"
using namespace std;


int main()
{
	Date d;
	string date = d.toString();
	cout << date << endl;
	information_provider info;

	//Expense exp = Expense("a", 223, d, 222);
	//info.ExpenseList.push_back(exp);
	//info.Add_category();
	//
	//string null = "q";
	//int choice;
	//float value;
	//cout << "to search by name press 1" << endl
	//	<< "to search by cost press 2\n";
	//cin >> choice;

	//if (choice == 1)//exception
	//{
	//	cout << "enter name";
	//	cin >> null;
	//	info.Search(null, choice);
	////	info.search(null,choice);
	//}
	//else if (choice == 2)
	//{
	//	cout << "enter value";
	//	cin >> value;
	//	info.Search(null, choice, value);
	////	info.search(null, choice,value);
	//}
	//
}