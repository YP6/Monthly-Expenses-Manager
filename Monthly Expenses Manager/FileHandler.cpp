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
        file << expenses[i].getId() << "," << expenses[i].getName() << "," << expenses[i].getCategory() << "," << expenses[i].getCost() << "," << expenses[i].getDate().getDay() << "-" << expenses[i].getDate().getMonth() << "-" << expenses[i].getDate().getYear() << expenses[i].getWalletId() << endl;
    }
    file.close();

}
