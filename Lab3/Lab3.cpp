#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Bank.h"

using namespace std;

int main(int argc, char *argv[]) {
	if (atoi(argv[1])>1000){
		cout << "Maximum 1000 customers" << endl;
		return 1;
	}else{
	if (argc == 2){
		Bank bank = Bank(atoi(argv[1]));
		bank.menu();
	}else if (argc == 3){
		Bank bank  = Bank(atoi(argv[1]), argv[2]);
		bank.menu();
	}
	
	return 1;
	}
}


