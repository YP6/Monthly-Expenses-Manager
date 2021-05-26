
#include "inform_provider.h"

using namespace std;

// vector<string>::iterator it;


void information_provider::AddExpense(string name,string category, double cost, int day, int month, int year, unsigned int walletId)
{

	Date date(day, month, year);
	Expense exp = Expense(name,category, cost, date, walletId);
	ExpenseList.push_back(exp);
}
void information_provider::AddWallet(string name, string category, unsigned long long balance, unsigned int id, unsigned int monthlyIncome, int day, int month, int year)
{
	Date monthStartDate(day, month, year);
	Wallet newWallet = Wallet(name, category, balance, id, monthlyIncome, monthStartDate);
	wallets.push_back(newWallet);
}
void information_provider::Add_category(string nwCategory)
{

	categories.push_back(nwCategory);
}
Expense information_provider::Search(string name)
{


	int size = ExpenseList.size();

	for (int i = 0; i < size; i++)
	{
		if (ExpenseList[i].getName() == name)
		{

			return ExpenseList[i];
		}

	}

}
Expense information_provider::Search(unsigned int Id)
{


	int size = ExpenseList.size();

	for (int i = 0; i < size; i++)
	{
		if (ExpenseList[i].getId() == Id)
		{

			return ExpenseList[i];
		}

	}

}

void information_provider::Delete(Expense exp)
{
	
}
void information_provider::Refund(unsigned int value, int id)
{
	for (int i = 0; i < wallets.size(); i++)
	{
		if (wallets[i].GetId() == id)
		{
			wallets[i].deposit(value);
		}
		else
		{
			throw "Id not found";
		}
	}
}
void information_provider::filter(int day = -1, int month = -1, int year = -1, string category = NULL, int costAmount = -1)
{


	cout << "Filter amount: ";
	cin >> costAmount;
	filterByAmount(costAmount);

}
void information_provider::filterByAmount(int costAmount)
{

	for (int i = 0; i < ExpenseList.size(); i++)
	{
		if (ExpenseList[i].getCost() == costAmount)
		{
			filteredData.push_back(ExpenseList[i]);
			cout << "The product amount is:" << endl;
			cout << ExpenseList[i].getCost();
			cout << "The product name is:" << endl;
			cout << ExpenseList[i].getName();
			cout << "The product id is:" << endl;
			cout << ExpenseList[i].getId();
			cout << "The product category is:" << endl;
			cout << ExpenseList[i].getCategory();
			//cout << "The product currency is:" << endl;
			//cout << name1[i].currency;
			cout << "The product date DD/MM/YY:" << endl;
			cout << ExpenseList[i].getDate().getDay() << "/" << ExpenseList[i].getDate().getMonth() << "/" << ExpenseList[i].getDate().getYear();
		}
		else
			cout << "No data found!\n";
	}
}
void information_provider::filterByCategory(string category)
{
	// filteredData.assign(ExpenseList.begin(), ExpenseList.end());
	filteredData = ExpenseList;
	for (int i = 0; i < ExpenseList.size(); i++)
	{
		if (ExpenseList[i].getCategory() == category)
		{
			filteredData.push_back(ExpenseList[i]);
			cout << "The product amount is:" << endl;
			cout << ExpenseList[i].getCost();
			cout << "The product name is:" << endl;
			cout << ExpenseList[i].getName();
			cout << "The product id is:" << endl;
			cout << ExpenseList[i].getId();
			cout << "The product category is:" << endl;
			cout << ExpenseList[i].getCategory();
			//cout << "The product currency is:" << endl;
			//cout << name1[i].currency;
			cout << "The product date DD/MM/YY:" << endl;
			cout << ExpenseList[i].getDate().getDay() << "/" << ExpenseList[i].getDate().getMonth() << "/" << ExpenseList[i].getDate().getYear();
		}
		else
			cout << "No data found!\n";
	}
}
