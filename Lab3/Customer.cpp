#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include "Customer.h"
using namespace std;

Customer::Customer(){
	
}

Customer::Customer(string userid) {
	balance = 0;
	string input;
	
	userId = userid;
	
	cout << "Create a password: ";
	cin >> input;
	password = checkPw(input);
	
	cout << "Please enter your last name:";
	cin >> input;
	lastName = checkName(input);

	cout << "Please enter your first name:";
	cin >> input;
	firstName = checkName(input);
	
	cout << "Please enter your age:";
	cin >> input;
	age = checkAge(input);
	
	cout << "Please enter street number:";
	cin >> input;
	streetNumber = checkNumber(input);
	
	cout << "Please enter street name:";
	cin >> input;
	streetName = checkAddress(input);
	
	cin.clear();
	cin.ignore(256,'\n');
	cout << "Please enter town: ";
	
	getline(cin, input);
	town = input;
	
	
	cout << "Please enter 2-charater state: ";
	cin >> input;
	checkState(input);
	
	cout << "Please enter zip code:";
	cin >> input;
	zipCode = checkZip(input);
}

Customer::Customer(string paramter[11]) {
	userId = paramter[0];
	password = paramter[1];
	lastName = paramter[2];
	firstName = paramter[3];
	age = atoi(paramter[4].c_str());
	streetNumber = atoi(paramter[5].c_str());
	streetName = paramter[6];
	town = paramter[7];
	setState(paramter[8]);
	zipCode = paramter[9];
	balance = (float)atof(paramter[10].c_str());
	
}

void Customer::update(){
	string echo; //user input

	cout << "Please select what you want to change" << endl;
	cout << "'last_name', 'first_name', 'age', 'street_name', 'street_number', 'town', 'state', 'zip_code', 'finished' :" << endl;	
	cin >> echo;
	while (echo!= "finished"){
		if (echo != "last_name" and echo != "first_name" and echo != "age" and echo != "street_name" and echo != "street_number" and echo != "town" and echo != "state" and echo != "zip_code"){
			cout << "Error: invalid command" << endl;
		}else{
			if (echo == "last_name"){
				cout << "Enter your last name" << endl;
				string input;
				cin >> input;
				lastName  = checkName(input);
			}else if(echo == "first_name"){
				cout << "Enter your first name" << endl;
				string input;
				cin >> input;
				firstName  = checkName(input);
			}else if (echo == "age"){
				cout << "Enter your age" << endl;
				string input;
				cin >> input;
				age = checkAge(input);
			}else if (echo == "street_name"){
				cout << "Enter your street" << endl;
				string input;
				cin >> input;
				streetName  = checkAddress(input);
			}else if (echo == "street_number"){
				cout << "Enter your street number" << endl;
				string input;
				cin >> input;
				streetNumber = checkNumber(input);
			}else if (echo == "town"){
				//attention
				string input;
				cin.clear();
				cin.ignore(256,'\n');
				cout << "Enter your town" << endl;
				getline(cin, input);
				town  = checkAddress(input);
			}else if (echo == "state"){
				cout << "Enter your state" << endl;
				string input;
				cin >> input;
				checkState(input);
			}else{ //zip
				cout << "Enter your zip code" << endl;
				string input;
				cin >> input;
				zipCode  = checkZip(input);
			}
		}
		cout << endl;
		cout << "Please select what you want to change"  << endl;
		cout << "'last_name', 'first_name', 'age', 'street_name', 'street_number', 'town', 'state', 'zip_code', 'finished' :"<< endl;
		cin >> echo;
		}
}

void Customer::changePassword() {
	string oldPass;
	string newPass1;
	string newPass2;
	cout << "Please type your old password" << endl;
	cin >> oldPass;
	while (oldPass != password) {
		cout << "Wrong password, please try again: ";
		cin >> oldPass;
	}
	cout << "Please type your new passowrd" << endl;
	cin >> newPass1;
	cout << "Please type your new passowrd again" << endl;
	cin >> newPass2;
	while (newPass1 != newPass2) {
		cout << "Wrong input, please try again: ";
		cout << "Please type your new passowrd: ";
		cin >> newPass1;
		cout << "Please type your new passowrd again: ";
		cin >> newPass2;
	}
	password = newPass1;
	cout << "Password changed successfully" << endl;
}


void Customer::view(){
	cout << "Account Info:" << endl;
	cout << "User ID: " << userId << endl;
	cout << firstName << " " << lastName << ": age " << age << endl;
	cout << streetNumber << " " << streetName << endl;
	cout << town << ", " << stateToString(state) << ", " << zipCode << endl;
	cout << "Current Balance: $" << setiosflags(ios::fixed) << setprecision(2) << balance << endl;
}

void Customer::deposit(){
	float amount;
	cout << "Please enter the amount you want to deposit: ";
	cin >> amount;
	while (amount <0){
		cout << "You can not deposit a negative amount of money" << endl;
		cin >> amount;
	}
	balance += amount;
	cout << "Deposit successfully" << endl;
}

void Customer::withdraw(){
	float amount;
	cout << "Please enter the amount you want to withdraw: ";
	cin >> amount;
	while (amount > balance or amount < 0) {
		cout << "You cannot withdraw a negative amount of money, nor a amount exceed your balance" << endl;
		cin >> amount;
	}
	balance -= amount;
	cout << "Withdraw successfully" << endl;
}

void Customer::showBalance(){
	cout << lastName << ": $" << setiosflags(ios::fixed) << setprecision(2) << balance << endl;
}

string Customer::getUserId(){
	return userId;
}

string Customer::getPassword(){
	return password;
}

string Customer::getInfo(){
	//int to string
	ostringstream oss1;
	ostringstream oss2;
	ostringstream oss3;
	
	oss1 << age;
	string ageString = oss1.str();

	oss2 << streetNumber;
	string streetNumberString = oss2.str();

	oss3 << balance;
	string balanceString = oss3.str();
	
	string stateString = stateToString(state);
	if (userId != ""){
		return userId + '\n' + password  + '\n' + firstName  + '\n' + lastName  + '\n' + ageString + '\n' + streetNumberString  + '\n' + streetName + '\n' + town + '\n' + stateString  + '\n' + zipCode + '\n' + balanceString + '\n';
	}else{return "";}
}

void Customer::menu(){
	string echo; //user input

	cout << "Please enter any of the following commands:" << endl;
	cout << "'Update','Passwd','View','Deposit','Withdraw','Balance','Logout': " << endl;	
	cin >> echo;
	while (echo!= "Logout"){
		if (echo != "Passwd" and echo != "Update" and echo != "View" and echo != "Deposit" and echo != "Withdraw" and echo != "Balance"){
			cout << "Error: invalid command" << endl;
		}else{
			if (echo == "Passwd"){
				changePassword();
			}else if(echo == "Update"){
				update();
			}else if (echo == "View"){
				view();
			}else if (echo == "Deposit"){
				deposit();
			}else if (echo == "Withdraw"){
				withdraw();
			}else{
				showBalance();
			}
		}
		cout << endl;
		cout << "Please type any of the following commands:" << endl;
		cout << "'Update','Passwd','View','Deposit','Withdraw','Balance','Logout'" << endl;
		cin >> echo;
	}
}



//Private checkers
bool Customer::lettersOnly(string sample) {
	bool retVal = true;
	char character;
	for (int i = 0; i < sample.length(); i++) {
		character = sample.at(i);
		if (!(character >= 'a' and character <= 'z' and !(character >= 'A' and character <= 'Z'))){
			retVal = false;
		}
	}
	return retVal;
}

bool Customer::letterSpaceOnly(string sample){
	bool retVal = true;
	char character;
	for (int i = 0; i < sample.length(); i++){
		character = sample.at(i);
		if (!(character >= 'a' and character <= 'z') and !(character >= 'A' and character <= 'Z') and character != 0x20 and character != 0x9){
			retVal = false;
		}
	}
	return retVal;
}
bool Customer::digitsOnly(string sample){
	bool retVal = true;
	char character;
	for (int i = 0; i < sample.length(); i++){
		character = sample.at(i);
		if (!(character >= '0' and character <= '9')){
			retVal = false;
		}
	}
	return retVal;
}

bool Customer::letterDigitOnly(string sample){
	bool retVal = true;
	char character;
	for (int i = 0; i < sample.length(); i++){
		character = sample.at(i);
		if (!(character >= 'a' and character <= 'z') and !(character >= 'A' and character <= 'Z') and !(character >= '0' and character <= '9')){
			retVal = false;
		}
	}
	return retVal;
}

string Customer::checkName(string &input){
	while (!lettersOnly(input)){
		cout << "Names can only contain letters: ";
		cin >> input;
	}
	
	return input;
}

int Customer::checkAge(string &input){
	while (!digitsOnly(input) or atoi(input.c_str()) < 12){
		cout << "Age must be a number greater than or equal to 12: ";
		cin >> input;
	}
	return atoi(input.c_str());
}

int Customer::checkNumber(string &input){
	while (!digitsOnly(input) or atoi(input.c_str()) <= 0){
		cout << "Stree number must be a positive number";
		cin >> input;
	}
	return atoi(input.c_str());
}

string Customer::checkAddress(string &input){
	while (!letterSpaceOnly(input)){
		cout << "Address contains words only";
		cin >> input;
	}
	
	return input;
}

string Customer::checkZip(string &input){
	while (!digitsOnly(input) or input.length()!=5){
		cout << "Zip code must be 5 digits" << endl;
		cin >> input;
	}
	return input;
}

string Customer::checkPw(string &input){
	while(input.length() <6 or lettersOnly(input)){
		if (lettersOnly(input) and input.length() > 6){
			cout << "password must contain at least one non-letter character" << endl;
		}else if (!lettersOnly(input) and input.length() < 6){
			cout << "password must be at least 6 characters" << endl;
		}else{
			cout << "password must be at least 6 characters and contains at least one non-letter character" << endl;
		}
		cin >> input;
	}
	return input;
}


void Customer::checkState(string &input){
	int indicator = 0;
	while (indicator == 0) {
		if (input != "NY" and input != "PA" and input != "ME" and input != "RI" and input != "MA" and input != "VT" and input != "CT" and input != "NE") {
			cout << "Wrong input, enter a 2-character state: ";
			cin >> input;
		}
		else {
			indicator = 1;
		}
	}

	setState(input);
}

void Customer::setState(string input){
	
	if (input == "NY") {
		state = NY;
	}
	else if (input == "PA") {
		state = PA;
	}
	else if (input == "ME") {
		state = ME;
	}
	else if (input == "RI") {
		state = RI;
	}
	else if (input == "MA") {
		state = MA;
	}
	else if (input == "VT") {
		state = VT;
	}
	else if (input == "CT") {
		state = CT;
	}
	else if (input == "NE") {
		state = NE;
	}
}


string Customer::stateToString(States input){
	string states;
	if (input == NY) {
		states = "NY";
	}
	else if (input == PA) {
		states = "PA";
	}
	else if (input == ME) {
		states = "ME";
	}
	else if (input == RI) {
		states = "RI";
	}
	else if (input == MA) {
		states = "MA";
	}
	else if (input == VT) {
		states = "VT";
	}
	else if (input == CT) {
		states = "CT";
	}
	else if (input == NE) {
		states = "NE";
	}
	
	return states;
}
