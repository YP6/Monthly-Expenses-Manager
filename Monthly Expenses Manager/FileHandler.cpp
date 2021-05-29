#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void FileHandler::initFile(string fileName, string username, string password, vector<Wallet> wallets, vector<Expense> expenses)
{
	int numOfWallets = wallets.size();
	int numOfExpenses = expenses.size();

	ofstream file(fileName, ios_base::app);

	file << "username" << "," << "password" << endl;
	file << username << "," << password << endl;

	file << "id" << "," << "name" << "," << "category" << "," << "balance" << "," << "monthlyIncome" << "," << "monthstartdate" << endl;
	for (int i = 0; i < numOfWallets; i++) {
		file << wallets[i].GetId() << "," << wallets[i].GetName() << "," << wallets[i].GetCategory() << "," << wallets[i].GetBalance() << "," << wallets[i].GetMonthlyIncome() << "," << wallets[i].getStartDate().getDay() << "-" << wallets[i].getStartDate().getMonth() << "-" << wallets[i].getStartDate().getYear() << endl;
	}

	file << "id" << "," << "name" << "," << "category" << "," << "cost" << "," << "date" << "," << "walledId" << endl;
	for (int i = 0; i < numOfExpenses; i++) {
		file << expenses[i].getId() << "," << expenses[i].getName() << "," << expenses[i].getCategory() << "," << expenses[i].getCost() << "," << expenses[i].getDate().getDay() << "-" << expenses[i].getDate().getMonth() << "-" << expenses[i].getDate().getYear() << "," << expenses[i].getWalletId() << endl;
	}
	file.close();

}
vector<string> FileHandler::readUserRecord(string fileName, string searchTerm) {
	vector<string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string username;
	string password;

	while (getline(file, username, ',') && !isFound)
	{
		getline(file, password, '\n');
		if (username == searchTerm) {
			isFound = 1;
			record.push_back(username);
			record.push_back(password);
			file.close();
			return record;
		}
	}
}
vector<string> FileHandler::readWalletRecordById(string fileName, string searchTerm) {
	vector <string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string name, category;
	string balance;
	string monthlyIncome, id;
	string monthStartDate;

	while (getline(file, id, ',') && !isFound)
	{
		getline(file, name, ',');
		getline(file, category, ',');
		getline(file, balance, ',');
		getline(file, monthlyIncome, ',');
		getline(file, monthStartDate, '\n');

		if (id == searchTerm) {
			isFound = 1;
			record.push_back(id);
			record.push_back(name);
			record.push_back(category);
			record.push_back(balance);
			record.push_back(monthlyIncome);
			record.push_back(monthStartDate);
			file.close();
			return record;
		}
	}

}
vector<string> FileHandler::readWalletRecordByName(string fileName, string searchTerm) {
	vector <string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string name, category;
	string balance;
	string monthlyIncome, id;
	string monthStartDate;

	while (getline(file, id, ',') && !isFound)
	{
		getline(file, name, ',');
		getline(file, category, ',');
		getline(file, balance, ',');
		getline(file, monthlyIncome, ',');
		getline(file, monthStartDate, '\n');

		if (name == searchTerm) {
			isFound = 1;
			record.push_back(id);
			record.push_back(name);
			record.push_back(category);
			record.push_back(balance);
			record.push_back(monthlyIncome);
			record.push_back(monthStartDate);
			file.close();
			return record;
		}
	}

}
vector<string> FileHandler::readExpenseRecordById(string fileName, string searchTerm) {
	vector <string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string id, name;
	string category,date;
	string cost, walletid;

	while (getline(file, id, ',') && !isFound)
	{
		getline(file, name, ',');
		getline(file, category, ',');
		getline(file, cost, ',');
		getline(file, date, ',');
		getline(file, walletid, '\n');

		if (id == searchTerm) {
			isFound = 1;
			record.push_back(id);
			record.push_back(name);
			record.push_back(category);
			record.push_back(cost);
			record.push_back(date);
			record.push_back(walletid);
			file.close();
			return record;
		}
	}

}
vector<string> FileHandler::readExpenseRecordByName(string fileName, string searchTerm) {
	vector <string> record;

	ifstream file(fileName);

	bool isFound = 0;
	string id, name;
	string category,date;
	string cost, walletid;

	while (getline(file, id, ',') && !isFound)
	{
		getline(file, name, ',');
		getline(file, category, ',');
		getline(file, cost, ',');
		getline(file, date, ',');
		getline(file, walletid, '\n');

		if (name == searchTerm) {
			isFound = 1;
			record.push_back(id);
			record.push_back(name);
			record.push_back(category);
			record.push_back(cost);
			record.push_back(date);
			record.push_back(walletid);
			file.close();
			return record;
		}
	}

}