#pragma once
#include "InformationProvider.h"
#include <string>

 void getCategoryFromUser(InformationProvider *temp)
{
	string category;
	cout << "Enter category name: ";
	getline(cin, category);
	temp->Add_category(category);
	userSignUp("db.csv");
	FileHandler::initFileContent("db.csv", temp->wallets, temp->expenses, temp->categories);

}
