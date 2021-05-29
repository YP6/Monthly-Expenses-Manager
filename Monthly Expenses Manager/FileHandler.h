#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "InformationProvider.h"

using namespace std;

class FileHandler
{
public:
	static void initFile(string fileName, string, string, vector<Wallet>, vector<Expense>);
	static vector<string> readUserRecord(string, string);
	static	vector<string> readWalletRecordById(string, string);
	static	vector<string> readWalletRecordByName(string, string);
	static vector<string> readExpenseRecordById(string, string);
	static vector<string> readExpenseRecordByName(string, string);

};
