#include "Wallet.h"
unsigned int Wallet::nextId = 0;
Wallet::Wallet(string name, string category, unsigned long long balance, unsigned int monthlyIncome , Date monthStartDate)
{
	this->name = name;
	this->category = category;
	this->balance = balance;
	this->monthlyIncome = monthlyIncome;
	this->monthStartDate = monthStartDate;

	this->id = nextId;
	loadNextID();
}

void Wallet::loadNextID()
{
	nextId++;
}

string Wallet::GetName()
{
	return name;
}

string Wallet::GetCategory()
{
	return category;
}

unsigned long long Wallet::GetBalance()
{
	return balance;
}

unsigned int Wallet::GetId()
{
	return id;
}

unsigned int Wallet::GetMonthlyIncome()
{
	return monthlyIncome;
}

void Wallet::deposit(unsigned int value)
{
	balance += value;
}

void Wallet::withdraw(unsigned int value)
{
	if (balance < value)
		throw "Insufficient balance!";
	else 
		balance -= value;
}

Wallet::~Wallet()
{
	//call delete wallet function in the infromation provider
}
