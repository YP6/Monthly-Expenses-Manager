#include<iostream>
#include"InformationProvider.h"
#include "DebitCard.h"
#include "FileHandler.h"
#include "logInAndRegister.h"
#include "addCategory.h"
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
	


	/*for (auto i : program.categories)
	{
		cout << i << " ";
	}
	cout << endl;*/

	Expense expense("T-Shirt", "Shopping", 200, Date(3, 2, 2021), program.SearchWallet("CIB").GetId());
	Expense expense1("Bus", "Transport", 20, Date(5, 2, 2021), program.SearchWallet("CIB").GetId());
	Expense expense2("Food", "Home", 100, Date(3, 2, 2021), program.SearchWallet("CIB").GetId());
	Expense expense5("Mobile", "Shopping", 2000, Date(6, 2, 2021), program.SearchWallet("CIB").GetId());
	Expense expense3("Taxi", "Transport", 600, Date(3, 2, 2021), program.SearchWallet("QNB").GetId());
	Expense expense4("Mobile", "Personal", 1000, Date(6, 2, 2021), program.SearchWallet("QNB").GetId());

	program.AddExpense(expense);
	program.AddExpense(expense1);
	program.AddExpense(expense2);
	program.AddExpense(expense3);
	program.AddExpense(expense4);
	program.AddExpense(expense5);


	cout << program.SearchWallet("Wallet#1").GetBalance() << "$\n";

	////delete expense
	//for (int i = 0; i < program.expenses.size(); i++)
	//{
	//	if (program.expenses[i].getName() == "Mobile" && program.wallets[program.SearchWallet(program.expenses[i].getWalletId())].GetName() == "Wallet#1")
	//	{
	//		program.DeleteExpense(program.expenses[i].getId());
	//	}
	//}

	//cout<<program.SearchWallet("Wallet#1").GetBalance()<<"$\n";

	////Search expense name
	//for (int i = 0; i < program.expenses.size(); i++)
	//{
	//	if (program.expenses[i].getName() == "Mobile")
	//	{
	//		cout << program.expenses[i].getCost() << "$\n";
	//	}
	//}
	////before
	//cout << "before deleting cib wallet \n\n";
	//for (int i = 0; i < program.expenses.size(); i++)
	//{

	//	cout << program.wallets[program.SearchWallet(program.expenses[i].getWalletId())].GetName() << "      " << program.expenses[i].getCost() << "$\n";

	//}
	////Delete CIB
	//cout << "After deleting cib wallet \n\n";
	//cout << program.expenses.size() << endl;
	//program.DeleteWallet(program.SearchWallet("QNB").GetId());
	//cout << program.expenses.size() << endl;

	//for (int i = 0; i < program.expenses.size(); i++)
	//{
	//	cout << program.wallets[program.SearchWallet(program.expenses[i].getWalletId())].GetName()<< "      " << program.expenses[i].getCost() << "$\n";	
	//}
	program.walletFilterID = 1;
	program.dateFilterDay = Date(3, 2, 2021);
	program.categoryFilterName["Shopping"] = 1;
	program.categoryFilter = 1;
	program.dateFilter = 0;
	vector<Expense> z = program.Filter();
	for (auto i : z)
	{
		cout << i.getName() << "    ";
		cout << i.getDate().toString() << endl;
	}

	userSignUp("db.csv");
	FileHandler::initFileContent("db.csv", program.wallets, program.expenses, program.categories);
	bool l = logIn("db.csv");

	cout << "bool value :" << l<<endl;
	getCategoryFromUser(&program);
	
	for (int i = 0; i < program.categories.size(); i++)
	{
		cout << program.categories[i]<<endl;
	}
	
	

}