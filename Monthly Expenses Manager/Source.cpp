#include<iostream>
#include"InformationProvider.h"
#include "DebitCard.h"
#include "FileHandler.h"
#include "logInAndRegister.h"
#include "addCategory.h"
#include "Menu.h"
using namespace std;


int main()
{

	InformationProvider* program = new InformationProvider();
	program->AddWallet(Wallet("Pocket Wallet", "Cash", 5000, 2000, Date(22, 3, 2021)));
	program->AddWallet(Wallet("CIB", "Credit Card", 20000, 10000, Date(22, 3, 2021)));
	program->AddWallet(Wallet("QNB", "Debit Card", 3000, 1300, Date(22, 3, 2021)));

	program->Add_category("Shopping");
	program->Add_category("Transport");
	program->Add_category("Home");
	program->Add_category("Personal");
	program->Add_category("Education");

	Expense expense("T-Shirt", "Shopping", 200, Date(3, 2, 2021), program->SearchWallet("Pocket Wallet").GetId());
	Expense expense1("Bus", "Transport", 20, Date(5, 2, 2021), program->SearchWallet("Pocket Wallet").GetId());
	Expense expense2("Food", "Home", 100, Date(3, 2, 2021), program->SearchWallet("CIB").GetId());
	Expense expense3("Taxi", "Transport", 600, Date(3, 2, 2021), program->SearchWallet("QNB").GetId());
	Expense expense4("Mobile", "Personal", 1000, Date(6, 2, 2021), program->SearchWallet("QNB").GetId());
	Expense expense5("Mobile", "Shopping", 2000, Date(6, 2, 2021), program->SearchWallet("CIB").GetId());

	program->AddExpense(expense);
	program->AddExpense(expense1);
	program->AddExpense(expense2);
	program->AddExpense(expense3);
	program->AddExpense(expense4);
	program->AddExpense(expense5);
	MainMenu(program);







































	InformationProvider program;

	/* 
	This line must be called before initilazing user & file content & getCategoryFromUser.
	program.categories= FileHandler::readCategories("db.csv");
	*/
}