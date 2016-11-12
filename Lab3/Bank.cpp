#include "Bank.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <istream>
using namespace std;

Bank::Bank(int max){
	maximum = max;
}

Bank::Bank(int max, string filename){
	maximum = max;
	string line;
	ifstream myfile (filename.c_str());
	
	string parameter[11];
	int index2 =0;
	int index=0;
	string newstring;
	while (getline(myfile, newstring)){
		parameter[index] = newstring;
		if (index == 10){
			customerList[index2] = Customer(parameter);
			index2++;
			index=-1;
		}
		index++;
	}
	
}

void Bank::newAccount(){
	int index = 0;
	while (customerList[index].getUserId() != "" and index < maximum){
		index++;
	}
	
	if (index >= maximum){
		cout << "This Bank is full" << endl;
		return;
	}
	
	cout << "Please enter a user id: ";
	string input;
	cin >> input;
	
	int unique = 0;
	while (unique == 0){
		unique = 1;
		input = checkId(input);
		for (int j =0; j < index; j++){
			if (customerList[j].getUserId() == input){
				unique = 0;
			}
		}
		if (unique == 0){
			cout << "User Id already exists, please enter another one" << endl; 
			cin >> input;
		}
	}
	
	customerList[index] = Customer(input);
}

void Bank::login(){
	string inputid;
	string inputPassword;
	string userid = "";
	string password;
	int index = 0;
	cout << "Please input your user id" << endl;
	cin >> inputid;
	
	while (userid == ""){
		for (int i = 0; i < maximum; i++){

			if (customerList[i].getUserId() == inputid){
				userid = inputid;
				index = i;
			}
		}
		if (userid ==""){
			cout << "user id does not exist, please try again" << endl;
			cin >> inputid;
		}
	}
	password = customerList[index].getPassword();
	cout << "Please input your password" << endl;
	cin >> inputPassword;
	while (inputPassword != password){
		cout << "Wrong Password, try again" << endl;
		cin >> inputPassword;
	}
	
	customerList[index].menu();
}

void Bank::save(){
	string filename;
	int indicator = 0;
	while (indicator == 0){
		cout << "Input the file name you want to save to, end with '.txt'" << endl;
		cin >> filename;
		ifstream myfile;
		myfile.open(filename.c_str());
		string line;
		getline(myfile,line);
		if (line !=""){
			cout << "file alreay exists, enter '1' to overwrite this file or enter '0' to select different file name" << endl; 
			int echo; 
			cin >> echo;
			if (echo == 1){
				indicator = 1;
			}
		}else{
			indicator = 1;
		}
		myfile.close();
	}
		
	ofstream myfile;
	myfile.open(filename.c_str());
	for (int i = 0; i < maximum; i++){
		myfile << customerList[i].getInfo();
	}
	myfile.close();
	cout << "Saved!" << endl;
}

void Bank::menu(){
	string echo; //user input

	cout << "Please enter any of the following commands:" << endl;
	cout << "'New','Login','Save','Load','Quit': " << endl;	
	cin >> echo;
	
	while (echo!= "Quit"){
		if (echo != "New" and echo != "Login" and echo != "Save" and echo != "Load"){
			cout << "Error: invalid command" << endl;
		}else{
			if (echo == "New"){
				newAccount();
			}else if(echo == "Login"){
				login();
			}else if (echo == "Save"){
				save();
			}else if (echo == "Load"){
				load();
			}
		}
		cout << endl;
		cout << "Please type any of the following commands:" << endl;
		cout << "'New','Login','Save','Load','Quit': " << endl;
		cin >> echo;
	}
	
	if (echo == "Quit"){
		cout << "Do you want to save this bank? Enter 1 to save or 0 to quit" << endl;
		int input;
		cin >> input;
		if (input == 1){
			save();
		}
	}
}

void Bank::load()
{
	cout << "enter the file name" << endl;
	string filename;
	cin >> filename;

	string line;
	ifstream myfile (filename.c_str());
	
	
	string parameter[11];
	int index2 =0;
	int index=0;
	string newstring;
	while (getline(myfile, newstring)){
		parameter[index] = newstring;
		if (index == 10){
			customerList[index2] = Customer(parameter);
			index2++;
			index=-1;
		}
		index++;
	}

	cout << "Loaded!" << endl; 

}


string Bank::checkId(string &input){
	while (!letterDigitOnly(input) or (input.length()<5 or input.length() >= 10) ){
		cout << "user id contains only letters and digits, and must be at least 5 characters but no more than 10"<< endl;
		cin >> input;
	}

	return input;
}


bool Bank::letterDigitOnly(string sample){
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

