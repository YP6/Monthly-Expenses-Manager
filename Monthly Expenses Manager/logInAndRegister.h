#pragma once
#include <iostream>
#include <string>
#include"FileHandler.h"

bool logIn(string fileName)
{
	vector<string> userInfo = FileHandler::readUserRecord(fileName);
	vector<string> userEnteredData(2);
	cout << "Enter your username: ";
	getline(cin, userEnteredData[0]);
	cout << "Enter your password: ";
	getline(cin, userEnteredData[1]);
	if (userInfo[0] == userEnteredData[0] && userInfo[1] == userEnteredData[1])
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void userSignUp(string fileName)
{
	string username, password;

	FileHandler::initFileUser(fileName, "test username", "test password");

}
