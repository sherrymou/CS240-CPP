#include <string>
#include <iostream>
#include <fstream>
#include "Radio.h"
using namespace std;

int main(){
	cout <<"====Test Time class=====" << endl;
	
	Time time1 = Time();
	Time time2 = Time("15:23:33");
	Time time3 = Time("4:36");
	
	cout << "time1: " << time1.toString() << endl;
	cout << "time2: " << time2.toString() << endl;
	cout << "time3: " << time3.toString() << endl;
	
	cout << "====Test Song class=====" << endl;
	
	Song song1 = Song("Song title", "Artist" , time3);
	song1.like();
	song1.like();
	cout << "Song 1 likability: " << song1.likability << endl;
	
	song1.dislike();
	cout << "Song 1 likability: " << song1.likability << endl;
	song1.dislike();
	song1.dislike();
	song1.dislike();
	song1.dislike();
	cout << "Song 1 likability: " << song1.likability << endl;
	
	cout << "====Test Radio=====" << endl;
	
	cout << "Enter RUN and a file name" << endl;
	string command;
	cin >> command;
	if (command == "RUN"){
		cin >> command;
		Radio radio = Radio();
		radio.run(command);
	}
	cout << "End the program " << endl;
}
