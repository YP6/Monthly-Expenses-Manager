#include "DebitCard.h"

DebitCard::DebitCard(string name, string category, unsigned long long balance, unsigned int monthlyIncome, Date monthStartDate, unsigned int debt)
: Wallet(name, category, balance, monthlyIncome, monthStartDate)
{
	this->debt = debt;
}

void DebitCard::withdraw(unsigned int value)
{
	if (value > balance)
	{
		balance = 0;
		debt += value - balance;
	}
	else {
		Wallet::withdraw(value);
	}
}

void DebitCard::deposit(unsigned int value)
{
	if (!debt)
		Wallet::deposit(value);
	else
	{
		if (debt > value)
			debt -= value;
		else
		{
			Wallet::deposit(value - debt);
			debt = 0;
		}
	}
}

DebitCard::~DebitCard()
{
	//Call delete wallet function in the provider
}
