#include <string>
#include <iostream>
#include "MouKeniAccountFunctions.h"

using namespace std;

void New(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &balance){
	balance = 0;
	cout << "Please enter your last name:";
	cin >> lastName;
	cout << "Please enter your first name:";
	cin >> firstName;
	cout << "Please enter your age:";
	cin >> age;
	cout << "Please enter street number:";
	cin >> streetNumber;
	cout << "Please enter street name:";
	cin >> streetName;
	cout << "Please enter town:";
	cin >> town;
	cout << "Please enter zip code:";
	cin >> zipCode;
}

void Update(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &balance){
	cout << "Please update your last name";
	cin >> lastName;
	cout << "Please update your first name:";
	cin >> firstName;
	cout << "Please update your age:";
	cin >> age;
	cout << "Please update street number:";
	cin >> streetNumber;
	cout << "Please update street name:";
	cin >> streetName;
	cout << "Please update town:";
	cin >> town;
	cout << "Please update zip code:";
	cin >> zipCode;
}

void View(string lastName, string firstName, int age, int streetNumber, string streetName, string town, string zipCode, float balance){
	cout << "Account Info:" << endl;
	cout << firstName << " " << lastName << ": age " << age << endl;
	cout << streetNumber << " " << streetName << endl;
	cout << town << ", NY " << zipCode << endl;
	cout << "Current Balance: $" << balance << endl;
}

void Deposit(float &balance){
	float amount;
	cout << "Please enter the amount you want to deposit: ";
	cin >> amount;
	balance += amount;
}

void Withdraw(float &balance){
	float amount;
	cout << "Please enter the amount you want to withdraw: ";
	cin >> amount;
	balance -= amount;
}

void Balance(string &lastName, float balance){
	cout << lastName << ": $" << balance << endl;
}


