#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"
using namespace std;

int main(){
	//Import
	cout <<"Enter a file name " ;
	string file;
	cin >> file;
	Graph map = Graph(file);

	//Commands
	cout << "Enter a command" << endl;
	string command;
	string city1;
	string city2;
	cin  >> command;
	if (command == "HOME"){
		cin >> city1;
		map.home(city1);
	}

	if (command  == "TRAVEL"){
		cin >> city1 >> city2;
		map.travel(city1,city2);
	}
	
	return 1;
};
