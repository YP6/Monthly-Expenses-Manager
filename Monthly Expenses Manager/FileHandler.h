#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "InformationProvider.h"

using namespace std;

class FileHandler
{
	public:
		static void initFile(string fileName, string, string, vector<Wallet>, vector<Expense>);

};