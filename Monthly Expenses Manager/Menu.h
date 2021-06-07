#pragma once
#include <iostream>
#include"InformationProvider.h"
#include <stdlib.h>
#include "InputChecker.h"
#include "addCategory.h"
#include "addExpense.h"
#include <stack>
#include "showExpenses.h"
using namespace std;
void AddWallet(InformationProvider*);
void ShowWallets(InformationProvider* program);
void WalletInfo(InformationProvider* program, int index);

//Na2es Search - Filter

void MainMenu(InformationProvider* program)
{
	while (true)
	{
		while (!program->UndoExpenseChange.empty())
			program->UndoExpenseChange.pop();

		system("CLS");
		cout << "---------------------------- Choose one of this option ----------------------------\n" << endl;
		cout << "-Press (a) to add a new Wallet" << endl; //DONE
		cout << "-Press (r) to remove a new Wallet" << endl; 
		cout << "-Press (u) to undo last change" << endl;
		cout << "-Press (v) to view your wallets" << endl; 
		cout << "-Press (c) to add expense category" << endl;
		cout << "-Press (0) to Logout" << endl;
		
		char choice = getData<char>("Please choose one of the choices :  ", true, vector <char> {'a' , 'r' , 'u' , 'v', 'c' ,'0'});
		
		if (choice == 'a')
		{
			AddWallet(program);
		}
		else if (choice == 'r')
		{
			ShowWallets(program);
			cout << "-Press the number of the wallet that you want to remove" << endl;
			cout << "-Press (0) to go back" << endl;
			vector<int> choices;
			choices.push_back(0);
			for (int i = 0; i < program->expenses.size(); i++)
			{
				choices.push_back(i + 1);
			}
			int choice = getData<int>("Please Enter Your Choice : ", true, choices);
			if (choice == 0)
			{
				break;
			}
			else {
				char c = getData<char>("are you sure you want to add this data ? (y / n) : ", 1, vector <char> {'y', 'n'});
				if (c == 'y')
				{
					program->DeleteWallet(program->wallets[choice - 1].GetId());
				}
				
				
			}
		}
		else if (choice == 'u')
		{
			char c = getData<char>("are you sure you want to undo last change ? (y / n) : ", 1, vector <char> {'y', 'n'});
			if (c == 'y')
			{
				program->UndoWallet();
			}
		}
		else if (choice == 'v')
		{
			//Choose Wallet
			while (true)
			{
				ShowWallets(program);
				cout << "-Press the number of a wallet to open it" << endl;
				cout << "-Press (0) to go back" << endl;
				vector<int> choices;
				choices.push_back(0);
				for (int i = 0; i < program->expenses.size(); i++)
				{
					choices.push_back(i + 1);
				}
				int choice = getData<int>("Please Enter Your Choice : ", true, choices);
				if (choice == 0)
				{
					break;
				}
				else {
					WalletInfo(program, choice - 1);
				}
			}
		}
		else if (choice == 'c')
		{
			getCategoryFromUser(program);
		}
	}

}
void AddWallet(InformationProvider* program)
{
    system("CLS");
	string walletName;
	cout << "Please Enter the name of the new Wallet : ";
	cin.ignore();
	getline(cin, walletName);
	cout << "Please Enter the name of the category : ";
	string categoryName;
	//cin.ignore();
	getline(cin, categoryName);
	long int w = getData<long int>("Please Enter the balance of your wallet : ");
	unsigned int walletBalance = (w > 0)?w:-w;
	w = getData<long int>("Please Enter the monthly income of your wallet : ");
	unsigned int monthlyIncome = (w>0)?w:-w;
	int day = getData<int>("Enter the day of the month start : ");
	Date date(day, 1, 2001);
	while (true)
	{
		try {
			
			char choice = getData<char>("are you sure you want to add this data ? (y / n) : ",1, vector <char> {'y' , 'n'});
			if(choice == 'y')
			{
				Wallet wallet(walletName, categoryName, walletBalance, monthlyIncome, date);
				program->AddWallet(wallet);
			}
			break;
		}
		catch (const char* e)
		{
			cout << e << endl;
			cout << "Please Enter the name of the new Wallet : ";
			cin.ignore();
			getline(cin, walletName);
		}
	}
}
void ShowWallets(InformationProvider* program)
{

	while (!program->UndoExpenseChange.empty())
		program->UndoExpenseChange.pop();
	system("CLS");
	cout << "---------------------------- Your Wallets ----------------------------\n\n";
	for (int i = 0; i < program->wallets.size(); i++)
	{
		cout << "(" << i + 1 << ") Wallet Name : " << program->wallets[i].GetName() << "  (" << program->wallets[i].GetCategory() << ")\n";
		cout << "-- Balance : " << program->wallets[i].GetBalance() << "$\n";
		cout << "-- Monthly Income : " << program->wallets[i].GetMonthlyIncome() << endl;
		unsigned int totalSpent = 0;
		for (auto j : program->expenses)
		{
			if (j.getWalletId() == program->wallets[i].GetId())
			{
				totalSpent += j.getCost();
			}
		}
		cout << "-- Total Spent Money : " << totalSpent << "$\n\n";
	}
	
}
void WalletInfo(InformationProvider* program, int index)
{

	while (true)
	{
		Wallet wallet = program->wallets[index];
		system("CLS");
		cout << "-----------------------------------------------------------------------------------\n\n";
		cout << "Choosed Wallet : " << wallet.GetName() << "  (" << wallet.GetCategory() << ")\n";
		cout << "Balance : " << wallet.GetBalance() << "$\n";
		cout << "Monthly Income : " << wallet.GetMonthlyIncome() << "$\n\n";
		cout << "---------------------------- Choose one of this option ----------------------------\n" << endl;
		cout << "-Press (a) to add a new expense" << endl;
		cout << "-Press (b) to add balance to wallet" << endl;
		cout << "-Press (v) to view all expenses" << endl;
		cout << "-Press (r) to remove expense" << endl;
		cout << "-Press (u) to undo last change" << endl;
		cout << "-Press (s) to search for expense" << endl;
		cout << "-Press (0) to go back" << endl;
		char choice = getData<char>("Please Enter Your Choice : ", true, vector<char>{'0', 'a', 'b', 'v', 'r', 'u', 's'});
		if (choice == '0')
			break;
		else if (choice == 'a')
		{
			getExpenseFromUser(program, program->wallets[index].GetId());
		}
		else if (choice == 'b')
		{
			int amount = getData<int>("Enter amount you want to add : ");

			char c = getData<char>("are you sure you want to add this data ? (y / n) : ", 1, vector <char> {'y', 'n'});
			if (c == 'y')
				program->wallets[index].deposit(amount);

		}
		else if (choice == 'v')
		{
			program->walletFilterID = program->wallets[index].GetId();
			showExpenses(program);
			cout << "-Press any key to go back\n";
			int choice = getData<int>("Please Enter Your Choice : ", true, vector<int>{0});
				
		}
		else if (choice == 'r')
		{
			vector<int> choices = showExpenses(program);
			choices.push_back(0);

			cout << "-Press the number of expense you want to delete\n";
			cout << "-Press (0) to go back\n";
			int c = getData<int>("Please Enter Your Choice : ", true, choices);
			if (c != 0)
			{
				char cc = getData<char>("are you sure you want to delete this expense ? (y / n) : ", 1, vector <char> {'y', 'n'});
				if (cc == 'y'){
					program->DeleteExpense(program->Filter()[c - 1].getId());
				}
			}
			


		}
		else if (choice == 'u')
		{
			char cc = getData<char>("are you sure you want to undo last change ? (y / n) : ", 1, vector <char> {'y', 'n'});
			if (cc == 'y') {
				program->UndoExpense();
			}
		}
		else if (choice == 's')
		{

		}
		
	}
}