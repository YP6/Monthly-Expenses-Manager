#pragma once
#include <string>
#include "Date.h"
#include <vector>
using namespace std;

class Expense
{
private:
	static unsigned int nextId;
	unsigned int id;
	string  category,name;
	double cost;
	Date date;
	unsigned int walletId;

public:
	static void loadNextId();
	Expense(string,string, double , Date , unsigned int);
	string getName();
	string getCategory();
	unsigned int getId();
	double getCost();
	Date getDate();
};



