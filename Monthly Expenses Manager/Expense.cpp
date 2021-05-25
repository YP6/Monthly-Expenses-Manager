#include "Expense.h"
unsigned int Expense::nextId = 0;
Expense::Expense( string category, double cost, Date date , unsigned int walletId)
{
	this->category = category;
	this->cost = cost;
	this->date = date;
	id = nextId;
	this->walletId = walletId;
	loadNextId();
}

void Expense::loadNextId()
{
	nextId++;
}
