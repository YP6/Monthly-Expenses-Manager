#pragma once
#include "Wallet.h"
class DebitCard : Wallet
{
private:
	unsigned int debt;

public:
	DebitCard(string, string, unsigned long long, unsigned int, Date, unsigned int);
	void withdraw(unsigned int);
	void deposit(unsigned int);
	~DebitCard();

};

