#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Customer {
public:
		Customer();
		Customer(string userid);
		Customer(string paramter[12]);
		void update();
		void changePassword();
		void view();
		void deposit();
		void withdraw();
		void showBalance();
		
		string getUserId();
		string getPassword();
		
		string getInfo();

		void menu();
		
//		string checkId(string &input);
		enum States {NY, PA, RI, MA, VT, CT, NE, ME};
		
private:
	
	string userId, password;
	string lastName, firstName;
	int age;
	string streetName, town;
	States state;
	int streetNumber;
	string zipCode;
	float balance;
	
	// checkers
	bool lettersOnly(string sample);
	bool digitsOnly(string sample);
	bool letterSpaceOnly(string sample);
	bool letterDigitOnly(string sample);
	
	string checkName(string &input);
	int checkAge(string &input);
	string checkPw(string &input);
	int checkNumber(string &input);
	string checkAddress(string &input);
	
	void checkState(string &input);
	void setState(string input);
	string stateToString(States state);
	string checkZip(string &input);
	
	
	
};


