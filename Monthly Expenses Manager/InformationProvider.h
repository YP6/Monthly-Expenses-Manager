#pragma once
#include "Wallet.h"
#include "Expense.h"
#include "Date.h"
#include <map>
using namespace std;

class InformationProvider
{


public:
	vector<Wallet> wallets;
	vector<Expense> expenses;
	vector<string> categories;
	bool categoryFilter, dateFilter;
	unsigned int walletFilterID;
	map<string, bool>categoryFilterName;
	Date dateFilterDay;

public:
	void AddWallet(Wallet);
	void AddExpense(Expense);
	void Add_category(string);
	Expense SearchExpense(string);
	int SearchExpense(unsigned int);
	Wallet SearchWallet(string);
	int SearchWallet(unsigned int);
	void DeleteWallet(unsigned int);
	void DeleteExpense(unsigned int);
	void Refund(unsigned int, int);
	vector<Expense> Filter();


};


