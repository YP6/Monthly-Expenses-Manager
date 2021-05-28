#include "InformationProvider.h"
using namespace std;

//GOOD
void InformationProvider::AddExpense(Expense expense)
{
	if(!count(categories.begin(), categories.end(), expense.getCategory()))
	{
		cout << "Not a right category";
		return;
	}

	if (expense.getCost() <= wallets[SearchWallet(expense.getWalletId())].GetBalance())
	{
		expenses.push_back(expense);
		wallets[SearchWallet(expense.getWalletId())].withdraw(expense.getCost());
	}
	else {
		cout<< "In sufficient money";
	}
}

//GOOD
void InformationProvider::AddWallet(Wallet wallet)
{
	wallets.push_back(wallet);
}

//GOOD
void InformationProvider::Add_category(string newCategory)
{
	for (auto c : categories)
		if (c == newCategory)
			return;

	categories.push_back(newCategory);
}

//GOOD
Expense InformationProvider::SearchExpense(string name)
{
	for (int i = 0; i < expenses.size(); i++)
		if (expenses[i].getName() == name)
			return expenses[i];

}

//GOOD
int InformationProvider::SearchExpense(unsigned int Id)
{
	for (int i = 0; i < expenses.size(); i++)
		if (expenses[i].getId() == Id)
			return i;
}

//GOOD
Wallet InformationProvider::SearchWallet(string name)
{
	for (int i = 0; i < wallets.size(); i++)
		if (wallets[i].GetName() == name)
			return wallets[i];

}

//GOOD
int InformationProvider::SearchWallet(unsigned int Id)
{
	for (int i = 0; i < wallets.size(); i++)
		if (wallets[i].GetId() == Id)
			return i;
}


void InformationProvider::DeleteWallet(unsigned int id)
{
	int index = SearchWallet(id);
	for (int i = 0; i < expenses.size(); i++) {
		if (expenses[i].getWalletId() == id)
		{
			DeleteExpense(expenses[i].getId());
			i--;
		}
	}
			
	wallets.erase(wallets.begin() + index);
}

//GOOD
void InformationProvider::DeleteExpense(unsigned int id)
{
	int index = SearchExpense(id);
	int cost = expenses[index].getCost();
	unsigned int walletId = expenses[index].getWalletId();
	Refund(walletId, cost);
	expenses.erase(expenses.begin() + index);
}

//GOOD
void InformationProvider::Refund(unsigned int id, int value)
{
	for (int i = 0; i < wallets.size(); i++)
	{
		if (wallets[i].GetId() == id)
		{
			wallets[i].deposit(value);
			return;
		}
	}

	throw "ID Not Found!!";
}

