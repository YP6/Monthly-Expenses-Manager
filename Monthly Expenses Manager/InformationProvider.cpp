#include "InformationProvider.h"
using namespace std;

void InformationProvider::AddExpense(string name, string category, double cost, Date date, unsigned int walletId)
{
	Expense exp = Expense(name, category, cost, date, walletId);
	expenses.push_back(exp);
}

void InformationProvider::AddWallet(string name, string category, unsigned long long balance, unsigned int id, unsigned int monthlyIncome, Date monthStartDate)
{
	Wallet newWallet = Wallet(name, category, balance, id, monthlyIncome, monthStartDate);
	wallets.push_back(newWallet);
}

void InformationProvider::Add_category(string newCategory)
{
	for (auto c : categories)
		if (c == newCategory)
			return;

	categories.push_back(newCategory);
}

Expense InformationProvider::SearchExpense(string name)
{
	for (int i = 0; i < expenses.size(); i++)
		if (expenses[i].getName() == name)
			return expenses[i];

}

int InformationProvider::SearchExpense(unsigned int Id)
{
	for (int i = 0; i < expenses.size(); i++)
		if (expenses[i].getId() == Id)
			return i;
}

Wallet InformationProvider::SearchWallet(string name)
{
	for (int i = 0; i < wallets.size(); i++)
		if (wallets[i].GetName() == name)
			return wallets[i];

}

int InformationProvider::SearchWallet(unsigned int Id)
{
	for (int i = 0; i < wallets.size(); i++)
		if (wallets[i].GetId() == Id)
			return i;
}

void InformationProvider::DeleteWallet(unsigned int id)
{
	int index = SearchWallet(id);
	wallets.erase(wallets.begin() + index);
}

void InformationProvider::DeleteExpense(unsigned int id)
{
	int index = SearchExpense(id);
	expenses.erase(expenses.begin() + index);
}

void InformationProvider::Refund(unsigned int value, int id)
{
	for (int i = 0; i < wallets.size(); i++)
	{
		if (wallets[i].GetId() == id)
			wallets[i].deposit(value);
		else
			throw "Id not found";
	}
}

