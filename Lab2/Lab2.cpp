#include <iostream>
#include <string>
#include "MouKeniAccountFunctions.h"

using namespace std;
int main(){
	string lastName;
	string firstName;
	int age;
	string streetName;
	int streetNumber;
	string town;
	string zipCode;
	float balance;

	string echo; //user input

	cout << "Please enter any of the following commands:" << endl;
	cout << "'New','Update','View','Deposit','Withdraw','Balance','Quit': " << endl;	
	cin >> echo;
	while (echo!= "Quit"){
		if (echo != "New" and echo != "Update" and echo != "View" and echo != "Deposit" and echo != "Withdraw" and echo != "Balance"){
			cout << "Error: invalid command" << endl;
		}else{
			if (echo == "New"){
				New(lastName, firstName, age, streetNumber, streetName, town, zipCode, balance);		
			}else if(echo == "Update"){
				Update(lastName, firstName, age, streetNumber, streetName, town, zipCode, balance);
			}else if (echo == "View"){
				View(lastName, firstName, age, streetNumber, streetName, town, zipCode, balance);
			}else if (echo == "Deposit"){
				Deposit(balance);
			}else if (echo == "Withdraw"){
				Withdraw(balance);
			}else{
				Balance(lastName, balance);
			}
		}
		cout << endl;
		cout << "Please type any of the following commands:" << endl;
		cout << "'New','Update','View','Deposit','Withdraw','Balance','Quit'" << endl;
		cin >> echo;
	}
	return 1;
}
