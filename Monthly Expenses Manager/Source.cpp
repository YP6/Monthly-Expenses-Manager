#include<iostream>
#include"InformationProvider.h"
#include "FileHandler.h"
#include "logInAndRegister.h"
#include "addCategory.h"
#include "Menu.h"
#include "addExpense.h"
using namespace std;

InformationProvider* program = new InformationProvider();
string Username, Password;
void save()
{
	FileHandler::initFileUser("db.csv", Username, Password);
	FileHandler::initFileContent("db.csv", program->wallets, program->expenses, program->categories);
}
int main()
{
	atexit(save);
	while (true)
	{
		while (true)
		{
			system("CLS");
			cout << "------------------------------ Welcome To Monthly Expenses Manager ------------------------------\n";
			cout << "-Press (L) if you are already a user\n";
			cout << "-Press (S) if you are new\n";
			cout << "-Press (0) to exit\n";
			char choice = getData<char>("Please Enter your choice : ", true, vector<char>{'0', 'l', 's'});
			if (choice == '0')
				exit(1);
			else if (choice == 'l')
			{
				bool loggedIN = logIn("db.csv");
				if (loggedIN)
					break;
				else
					continue;
			}
			else if (choice == 's')
			{
				userSignUp("db.csv");
			}
		}


		program->wallets = FileHandler::readWallets("db.csv");
		program->categories = FileHandler::readCategories("db.csv");
		program->expenses = FileHandler::readExpenses("db.csv");



		program->Add_category("Shopping");
		program->Add_category("Transport");
		program->Add_category("Home");
		program->Add_category("Personal");
		program->Add_category("Education");

		MainMenu();

		/*program->AddWallet(Wallet("Pocket Wallet", "Cash", 5000, 2000, Date(22, 3, 2021)));
		program->AddWallet(Wallet("CIB", "Credit Card", 20000, 10000, Date(22, 3, 2021)));
		program->AddWallet(Wallet("QNB", "Debit Card", 3000, 1300, Date(22, 3, 2021)));
		Expense expense("T-Shirt", "Shopping", 200, Date(3, 2, 2021), program->SearchWallet("Pocket Wallet").GetId());
		Expense expense1("Bus", "Transport", 20, Date(5, 2, 2021), program->SearchWallet("Pocket Wallet").GetId());
		Expense expense7("Mobile Phone", "Shopping", 200, Date(3, 2, 2021), program->SearchWallet("Pocket Wallet").GetId());
		Expense expense8("Cell phone", "Shopping", 20, Date(5, 2, 2021), program->SearchWallet("Pocket Wallet").GetId());
		Expense expense9("phoneee", "Shopping", 20, Date(5, 2, 2021), program->SearchWallet("Pocket Wallet").GetId());
		Expense expense2("Food", "Home", 100, Date(3, 2, 2021), program->SearchWallet("QNB").GetId());
		Expense expense3("Taxi", "Transport", 600, Date(3, 2, 2021), program->SearchWallet("QNB").GetId());
		Expense expense4("Mobile", "Personal", 1000, Date(6, 2, 2021), program->SearchWallet("QNB").GetId());
		Expense expense5("Mobile", "Shopping", 2000, Date(6, 2, 2021), program->SearchWallet("QNB").GetId());*/


	}




































	/* 
	This line must be called before initilazing user & file content & getCategoryFromUser.
	program.categories= FileHandler::readCategories("db.csv");
	*/
}