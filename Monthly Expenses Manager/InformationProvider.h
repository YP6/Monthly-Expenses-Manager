#pragma once
#include "Wallet.h"
#include "Expense.h"
#include "Date.h"
using namespace std;

class InformationProvider
{


private:
	vector<Wallet> wallets;
	vector<Expense> expenses;
	vector<string> categories;

public:
	void AddWallet(string, string, unsigned long long, unsigned int, unsigned int, Date);
	void AddExpense(string, string, double, Date, unsigned int);
	void Add_category(string);
	Expense SearchExpense(string);
	int SearchExpense(unsigned int);
	Wallet SearchWallet(string);
	int SearchWallet(unsigned int);
	void DeleteWallet(unsigned int);
	void DeleteExpense(unsigned int);
	void Refund(unsigned int, int);


};


