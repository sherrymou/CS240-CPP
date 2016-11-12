#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"
using namespace std;

Graph::Graph(){

}

Graph::Graph(string filename){
	ifstream data (filename);
	string line;
	data >> line;
	int numCity = atoi(line.c_str());
	city = new string[numCity];
	for (int i =0; i < numCity; i++){
		data >> line;
		city[i]  = line;
	}
	data >> line;
	numFlight = atoi(line.c_str());
	flight = new Edge[numFlight];
	for (int i = 0; i< numFlight; i++){
		string cityName;
		data >> cityName;
		flight[i].from = cityName;
		data >> cityName;
		flight[i].to = cityName;
	}
//	cout <<"End of the construction" << endl;
}

Graph::~Graph(){
//	delete flight;
//	delete city;
}

bool Graph::home(string city){
	string *result = new string[numFlight]; 
	result=findWay(city, city, result);
	if (result[0] == "No") {
		cout << "No" << endl;
		return false;
	}
	cout << city;
	for (int i = 0; i<numFlight; i++){
		cout <<" "  << result[i];
	}
	cout << endl;
	return true;
}

bool Graph::travel(string city1, string city2){
	string *result = new string[numFlight];
	result[0] = city1;
	result = findWay(city1, city2, result);
	if (result[0] == "No") {
		cout << "No" << endl;
		return false;
	}
	for (int i = 0; i<numFlight; i++){
		cout << result[i] << " ";
	}
	cout << endl;
	return true;
}

string* Graph::findWay(string currentCity, string destination, string *path){
	bool from = false;
	bool to = false;
	for (int i = 0; i < numFlight; i++){
		if (flight[i].to == destination){to = true;}
		if (flight[i].from == currentCity){from = true;}
		
	}
	if (!from or !to) {
		path[0] = "No";
		return path;
	}
/**Backup
	for (int i = 0; i < numFlight; i++){
		if (flight[i].from == currentCity && !find(path, flight[i].to)){
			string transfer = flight[i].to;
			if (transfer!=destination){
//				cout <<"Destination: " << destination << endl;
//				cout << "Transfer: " << transfer<< endl;
				return findWay(transfer, destination, append(path, transfer));
			}else{
				return append(path, transfer);
			}
		}
	}
*/	
	for (int i = 0; i < numFlight; i++){
		while (find(path, flight[i].to)) i++;
		if (i < numFlight){
			if (flight[i].from == currentCity){
				string transfer = flight[i].to;
				if (transfer!=destination){
					return findWay(transfer, destination, append(path, transfer));
				}else{
					return append(path, transfer);
				}
			}
		}
	}	
	path[0] = "No";
	return path;
}

string* append(string *array, string str){
	int i =0;
	for (i = 0; array[i]!= ""; i++){
	}
	array[i] = str;
	return array;
}

bool find(string *array, string ele){
	for (int i = 0; array[i] != ""; i++){
		if (array[i]==ele) return true;
	}
	return false;
}
