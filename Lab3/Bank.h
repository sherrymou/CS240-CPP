#include <iostream>
#include <string>
#include <sstream>
#include "Customer.h"
using namespace std;

class Bank{
	public:
		Bank(int maximum);
		Bank(int maximum, string filename);
		
		void newAccount();
		void login();
		void save();
		void load();
		void menu();
	
	private:
		int maximum;
		Customer customerList[1000];
		string inputFile;
		string checkId(string &input);
		bool letterDigitOnly(string sample);
};
