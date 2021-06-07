#pragma once
#include "InformationProvider.h"
#include <string>
#include "InputChecker.h"
void getCategoryFromUser(InformationProvider *temp)
{
	string category;
	system("CLS");
	cout << "Enter category name : ";
	cin.ignore();
	getline(cin, category);
	char c = getData<char>("are you sure you want to add this data ? (y / n) : ", 1, vector <char> {'y', 'n'});
	if (c == 'y')
	{
		temp->Add_category(category);
		userSignUp("db.csv");
		FileHandler::initFileContent("db.csv", temp->wallets, temp->expenses, temp->categories);
	}

}
