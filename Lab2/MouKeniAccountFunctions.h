#include <string>
#include <iostream>

using namespace std;

void New(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &balance);

void Update(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &balance);

void View(string lastName, string firstName, int age, int streetNumber, string streetName, string town, string zipCode, float balance);

void Deposit(float &balance);

void Withdraw(float &balance);

void Balance(string &lastName, float balance);
