#include "Wallet.h"
#include "Expense.h"

using namespace std;

class information_provider
{


public:
	vector<Expense> filteredData;
	vector<string> categories;
	vector<Expense> ExpenseList;
	vector<Wallet> wallets;

	void AddWallet(string, string, unsigned long long, unsigned int, unsigned int, int, int, int);
	void AddExpense(string,string, double, int, int, int, unsigned int);
	void filter(int, int, int, string, int);
	void filterByAmount(int);
	void filterByCategory(string);
	void Add_category(string);
	Expense Search(string);
	Expense Search(unsigned int);
	void Delete(Expense);
	void Refund(unsigned int, int);

	
};
