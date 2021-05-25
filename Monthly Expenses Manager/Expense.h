#pragma once
#include <string>
#include "Date.h"
using namespace std;
class Expense
{
private:
	static unsigned int nextId;
	unsigned int id;
	string  category;
	double cost;
	Date date;
	unsigned int walletId;

public:
	static void loadNextId();
	Expense(string , double , Date , unsigned int);

};

