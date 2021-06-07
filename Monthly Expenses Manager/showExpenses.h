#pragma once
#include "InformationProvider.h"
#include "Expense.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> showExpenses(InformationProvider* temp)
{
	vector<int> choices;
	vector<Expense> showedData = temp->Filter();
	int showedDataSize = showedData.size();
	system("CLS");
	for (int i = 0; i < showedDataSize; i++) {
		cout << "Expense number "<< "(" << i + 1 << ") :" << endl;
		cout << "	Name: " << showedData[i].getName() << endl;
		cout << "	Category: " << showedData[i].getCategory() << endl;
		cout << "	Cost: " << showedData[i].getCost() << endl;
		cout << "	Date: " << showedData[i].getDate().getDay() << "-" << showedData[i].getDate().getMonth() << "-" << showedData[i].getDate().getYear() << endl;
		cout << "___________________________" << endl;
		choices.push_back(i + 1);
	}
	return choices;
}