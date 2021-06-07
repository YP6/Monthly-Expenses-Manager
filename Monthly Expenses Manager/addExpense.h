#pragma once
#include "InformationProvider.h"
#include "logInAndRegister.h"
#include "InputChecker.h"
#include <string>


using namespace std;
void getExpenseFromUser(InformationProvider* temp, unsigned int walletId)
{

	int walletsSize = temp->wallets.size();

	string name, category;
	double cost;
	int day, month, year;
	cout << "Enter expense name: ";
	cin.ignore();
	getline(cin, name);
	vector<int> categoriesChoices;
	cout << "Choose the corresponding number for the category" << endl;
	for (int i = 0; i < temp->categories.size(); i++)
	{
		cout << "(" << i + 1 << ") " << temp->categories[i] << endl;
		categoriesChoices.push_back(i + 1);
	}
	int categoryChoice = getData<int>("Enter expense number: ", true, categoriesChoices);
	category = temp->categories[categoryChoice - 1];

	cost = getData<double>("Enter expense cost: ");
	day = getData<int>("Enter expense day: ");
	month = getData<int>("Enter expense month: ");
	year = getData<int>("Enter expense year: ");

	Date date(day, month, year);



	Expense tempExpense(name, category, cost, date, walletId);

	char choice = getData<char>("are you sure you want to add this data?(y/n) : ", true, vector<char>{'y', 'n'});
	if (choice == 'y')
	{
		temp->AddExpense(tempExpense);
		userSignUp("db.csv");
		FileHandler::initFileContent("db.csv", temp->wallets, temp->expenses, temp->categories);
	}
}

