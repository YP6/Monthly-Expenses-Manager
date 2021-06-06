#pragma once
#include <iostream>
#include"InformationProvider.h"
#include <stdlib.h>
#include "InputChecker.h"


using namespace std;
void AddWallet(InformationProvider*);
void MainMenu(InformationProvider* program)
{
	cout << "---------------------------- Choose one of this option ----------------------------\n" << endl;
	cout << "-Press (a) to add a new Wallet" << endl;
	cout << "-Press (b) to remove a new Wallet" << endl;
	cout << "-Press (c) to undo last change" << endl;
	cout << "-Press (d) to show your wallet info" << endl;
	while (true)
	{
		
		char choice = getData<char>("Please choose one of the choices :  ", true, vector <char> {'a' , 'b' , 'c' , 'd'}); 
		
		if (choice == 'a')
		{
			AddWallet(program);
			break;
		}
		else if (choice == 'b')
		{

		}
		else if (choice == 'c')
		{

		}
		else if (choice == 'd')
		{

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
	cin.ignore();
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
			
			Wallet wallet(walletName, categoryName, walletBalance, monthlyIncome, date);
			program->AddWallet(wallet);
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
void chooseWallet(InformationProvider* program)
{
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