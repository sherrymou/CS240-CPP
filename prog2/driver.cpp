#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "Radio.h"
using namespace std;

int main(){
	
	cout << "Enter a command" << endl;
	Radio radio = Radio();
	
	string echo;
	getline(cin, echo);
	bool quit = false;

	while (echo!= "QUIT" && !quit){
		istringstream ss(echo);
		string temp;
		ss >> temp;
		if (temp=="RUN"){
			ss >> temp;
			ifstream file(temp);
			while (getline(file, echo)) 
				quit = radio.run(echo);
			file.close();
		}else{
			radio.run(echo);
		}	
			if (!quit) getline(cin, echo);
		}
	cout << "End of the program " << endl;
}
