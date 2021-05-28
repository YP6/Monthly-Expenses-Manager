#include<iostream>
#include"InformationProvider.h"
#include "DebitCard.h"
using namespace std;


int main()
{
	InformationProvider program;
	Wallet wallet("Wallet#1", "Cash", 5000, 3500, Date(1, 2, 2020));
	program.AddWallet(wallet);
	Wallet wallet2("CIB", "Credit", 20000, 10000, Date(1, 2, 2020));
	program.AddWallet(wallet2);
	Wallet wallet3("QNB", "Credit", 2000, 500, Date(1, 2, 2020));
	program.AddWallet(wallet3);

	program.Refund(program.SearchWallet("Wallet#1").GetId(), 2000);

	program.Add_category("Personal");
	program.Add_category("Transport");
	program.Add_category("Home");
	program.Add_category("Shopping");

	for (auto i : program.categories)
	{
		cout << i << " ";
	}
	cout << endl;

	Expense expense("T-Shirt", "Shopping", 200, Date(3,2,2021), program.SearchWallet("CIB").GetId());
	Expense expense1("Bus", "Tran4sport", 20, Date(5, 2, 2021), program.SearchWallet("CIB").GetId());
	Expense expense2("Food", "Home", 100, Date(6, 2, 2021), program.SearchWallet("Wallet#1").GetId());
	Expense expense5("Mobile", "Personal", 2000, Date(6, 2, 2021), program.SearchWallet("Wallet#1").GetId());
	Expense expense3("Taxi", "Transport", 600, Date(3, 2, 2021), program.SearchWallet("QNB").GetId());
	Expense expense4("Mobile", "Personal", 1000, Date(6, 2, 2021), program.SearchWallet("QNB").GetId());

	program.AddExpense(expense);
	program.AddExpense(expense1);
	program.AddExpense(expense2);
	program.AddExpense(expense3);
	program.AddExpense(expense4);
	program.AddExpense(expense5);


	cout << program.SearchWallet("Wallet#1").GetBalance() << "$\n";

	//delete expense
	for (int i = 0; i < program.expenses.size(); i++)
	{
		if (program.expenses[i].getName() == "Mobile" && program.wallets[program.SearchWallet(program.expenses[i].getWalletId())].GetName() == "Wallet#1")
		{
			program.DeleteExpense(program.expenses[i].getId());
		}
	}

	cout<<program.SearchWallet("Wallet#1").GetBalance()<<"$\n";

	//Search expense name
	for (int i = 0; i < program.expenses.size(); i++)
	{
		if (program.expenses[i].getName() == "Mobile")
		{
			cout << program.expenses[i].getCost() << "$\n";
		}
	}


	

}