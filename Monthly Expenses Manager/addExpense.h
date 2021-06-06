#pragma once
#include "InformationProvider.h"
#include "logInAndRegister.h"
#include <string>


using namespace std;
void getExpenseFromUser(InformationProvider* temp)
{
	Expense tempExpense;
	string name, category;
	double cost;
	Date date;
	unsigned int id;
	unsigned int walletId;
	cout << "Enter expense name: ";
	getline(cin, name);
	cout << "Enter expense category: ";
	getline(cin, category);
	cout << "Enter expense cost: ";
	/*cost = getData<double>("Enter expense cost: ", True, vector<double>{});*/
	cin >> cost;
	cout << "Enter expense day: ";
	cout << "Enter expense month: ";
	cout << "Enter expense year: ";
	cout << "Enter expense walletid: ";



	temp->AddExpense(tempExpense);
	userSignUp("db.csv");
	FileHandler::initFileContent("db.csv", temp->wallets, temp->expenses, temp->categories);
}

