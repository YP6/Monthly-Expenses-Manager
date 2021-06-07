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
		UndoExpenseChange.push(Operation<Expense>(expense, operations::insert));
		canExpenseUndo = true;
	}
	else {
		cout<< "In sufficient money";
	}
}

void InformationProvider::AddWallet(Wallet wallet)
{
	if (AddWalletCheck(wallet))
	{
		Operation<Wallet>temp(wallet, operations::insert);
		UndoWalletChange.push(temp);
		canWalletUndo = true;
		wallets.push_back(wallet);
	}
	else throw "Wallet Name Is Taken";
}
bool InformationProvider::AddWalletCheck(Wallet wallet)
{
	for (auto w : wallets)
	{
		if (w.GetName() == wallet.GetName())return 0;
	}
	return 1;
}


//GOOD
void InformationProvider::Add_category(string newCategory)
{
	for (auto c : categories)
		if (c == newCategory)
			return;
	categoryFilterName[newCategory] = 0;
	categories.push_back(newCategory);
}

//GOOD
Expense InformationProvider::SearchExpense(string name)
{
	for (int i = 0; i < expenses.size(); i++)
		if (expenses[i].getName() == name)
			return expenses[i];

}

vector<Expense> InformationProvider::SearchExpense(string name, string walletName)
{
	vector<Expense> tmp;
	for (int i = 0; i < expenses.size(); i++)
		if (expenses[i].getName() == name && expenses[i].getWalletId() == SearchWallet(walletName).GetId())
			tmp.push_back(expenses[i]);

	return tmp;
}

vector<Expense> InformationProvider::SearchExpense(string name, unsigned int id)
{
	vector<Expense> tmp;
	for (int i = 0; i < expenses.size(); i++)
		if (expenses[i].getName() == name && expenses[i].getWalletId() == id)
			tmp.push_back(expenses[i]);

	return tmp;
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
	Operation<Wallet>temp(wallets[index], operations::remove1);
	UndoWalletChange.push(temp);
	canWalletUndo = true;
	wallets.erase(wallets.begin() + index);
}

//GOOD
void InformationProvider::DeleteExpense(unsigned int id)
{
	int index = SearchExpense(id);
	int cost = expenses[index].getCost();
	unsigned int walletId = expenses[index].getWalletId();
	Refund(walletId, cost);
    UndoExpenseChange.push(Operation<Expense>(expenses[index], operations::remove1));
	canExpenseUndo = true;
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
vector<Expense> InformationProvider::Filter()
{
	vector<Expense> filteredData;
	for (auto i : expenses)
	{
		if (walletFilterID == i.getWalletId())
		{
			filteredData.push_back(i);
		}
	}
	if (dateFilter)
	{
		for (int i = 0; i < filteredData.size(); i++)
		{
			if (!(filteredData[i].getDate() == dateFilterDay))
			{
				filteredData.erase(filteredData.begin() + i);
				i--;
			}
		}
	}
	if (categoryFilter)
	{
		for (int i = 0; i < filteredData.size(); i++)
		{
			for (auto x : categoryFilterName)
			{
				if (x.first == filteredData[i].getCategory() && x.second == 0)
				{
					filteredData.erase(filteredData.begin() + i);
					i--;
				}

			}
		}
	}
	return filteredData;
}

void InformationProvider::UndoExpense()
{
	if (canExpenseUndo)
	{
		Operation<Expense> tmp = UndoExpenseChange.top();
		//If i inserted then now remove1
		if (tmp.getOperation() == operations::insert)
		{
			DeleteExpense(tmp.getChange().getId());
			UndoExpenseChange.pop();
		}
		//If i remove1d then now i insert
		else if (tmp.getOperation() == operations::remove1)
		{
			AddExpense(tmp.getChange());
			UndoExpenseChange.pop();
		}
		UndoExpenseChange.pop();
		canExpenseUndo = UndoExpenseChange.size();
	}

	
}

void InformationProvider::UndoWallet()
{
	if (canWalletUndo)
	{
		Operation<Wallet>temp = UndoWalletChange.top();
		// if insert fa ha remove
		if (temp.getOperation() == operations::insert)
		{
			DeleteWallet(temp.getChange().GetId());
			UndoWalletChange.pop();
		}
		//if remove fa ha insert
		else if (temp.getOperation() == operations::remove1)
		{
			AddWallet(temp.getChange());
			reUndoWalletExpenses(temp.getChange());
			UndoWalletChange.pop();
		}
	}
	UndoWalletChange.pop();
	canWalletUndo = UndoWalletChange.size();
}
void InformationProvider::reUndoWalletExpenses(Wallet wallet)
{
	while (UndoExpenseChange.top().getChange().getWalletId() == wallet.GetId())
	{
		UndoExpense();
	}
}


