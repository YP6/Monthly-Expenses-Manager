#pragma once
#include <string>
#include "Date.h"
using namespace std;
class Wallet
{
protected:
	static unsigned int nextId;
	string name , category;
	unsigned long long balance;
	unsigned int id , monthlyIncome;
	Date monthStartDate;

public:
	Wallet(string, string, unsigned long long, unsigned int , Date);
	void loadNextID();
	string GetName();
	string GetCategory();
	unsigned long long GetBalance();
	unsigned int GetId();
	unsigned int GetMonthlyIncome();
	void deposit(unsigned int);
	void withdraw(unsigned int);
	~Wallet();
};

