#pragma once
#include "InformationProvider.h"
#include "Expense.h"
#include <vector>
#include <iostream>

using namespace std;

void showExpenses(InformationProvider* temp)
{
	vector<Expense> showedData = temp->Filter();
	int showedDataSize = showedData.size();

	for (int i = 0; i < showedDataSize; i++) {
		cout << "Expense number "<< i + 1 << ":" << endl;
		cout << "	Expense Id: " << showedData[i].getId() << endl;
		cout << "	Name: " << showedData[i].getName() << endl;
		cout << "	Category: " << showedData[i].getCategory() << endl;
		cout << "	Cost: " << showedData[i].getCost() << endl;
		cout << "	Date: " << showedData[i].getDate().getDay() << "-" << showedData[i].getDate().getMonth() << "-" << showedData[i].getDate().getYear() << endl;
		cout << "	Wallet ID: " << showedData[i].getWalletId() << endl;
		cout << "___________________________" << endl;
	}
}