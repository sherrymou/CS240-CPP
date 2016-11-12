#include <iostream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <cstddef>
#include <fstream>
#include "Radio.h"
using namespace std;

Radio::Radio(){

}

Radio::~Radio(){

}

void Radio::init(string time, int maxSongs){
	cout << "Called INIT" << endl;
	current = Time(time);
	songlist = new Song[maxSongs];
}

void Radio::addSong(string data){
	// ex: <Song Title> , <Artist> , <Runtime> Seperate w/ comma
//	cout << "Called addSong function " << endl;
//	cout << "string data" << data << endl;
	
	istringstream ss(data);
	string title;
	string artist;
	string runtimestr;
	
	getline(ss, title, ',');
	getline(ss, artist, ',');
	getline(ss, runtimestr, ',');
	
	boost::trim(title);
	boost::trim(artist);
	boost::trim(runtimestr);
	
	Time runtime = Time(runtimestr);
	
	int index = 0;
	while (songlist[index].title != "") {
		index ++;
	}
	songlist[index] = Song (title, artist, runtime);
	cout << "Song: '" << title << "' has been added" << endl; 
}

void Radio::play(int num){
	cout << "Playing... " << endl;
}

void Radio::rest(string time){
	cout << "Resting... " << endl;
}

void Radio::like(string song){
	cout <<"liked song " << song << endl;
}

void Radio::like(){
	cout <<"liked recent played song " << endl;
}

void Radio::dislike(string song){
	cout << "disliked song " << song << endl;
}

void Radio::dislike(){
	cout << "disliked recent played song " << endl;
}

void Radio::run(string commandfile){
	cout << "Opened file" << endl;
	ifstream file (commandfile);
	string echo;
	while (file >> echo){
		while (echo!= "QUIT"){
			if (echo == "INIT"){
				string timestr;
				file >> timestr;
				int maxSong;
				file >> maxSong;
				init (timestr, maxSong);
//				init ((string)timein, (int)maxSongin);
			}else if(echo == "ADD"){
				string data;
				getline(file, data);
				addSong(data);
			}else if (echo == "PLAY"){
				string linestr;
				file>>linestr;
				int line = atoi(linestr.c_str());
				play(line);
			}else if (echo == "REST"){
				string timestr;
				file >> timestr;
				rest(timestr);
			}else if (echo == "LIKE"){
				string title;
				getline(file,title);
			//	cout << "debug: like song get line:" << title << endl;
				if (title != " "){
					like(title);
				}else{
					like();
				}
			}else if (echo == "DISLIKE"){
				string title;
				getline(file,title);
				if (title != " "){
					dislike(title);
				}else{
					dislike();
				}
			}
			file >> echo;
		}
	}
//	cout << "Get out" << endl;
//	file.close();
}

/**
void Radio::run(string commandfile){
	cout << "Opened file" << endl;
	ifstream file (commandfile);
	string echo;
	while (file >> echo){
		while (echo!= "QUIT"){
			if (echo == "INIT"){
				string timestr;
				file >> timestr;
				int maxSong;
				file >> maxSong;
				init (timestr, maxSong);
//				init ((string)timein, (int)maxSongin);
			}else if(echo == "ADD"){
				string data;
				getline(file, data);
				addSong(data);
			}else if (echo == "PLAY"){
				string linestr;
				file>>linestr;
				int line = atoi(linestr.c_str());
				play(line);
			}else if (echo == "REST"){
				string timestr;
				file >> timestr;
				rest(timestr);
			}else if (echo == "LIKE"){
				string title;
				file >> title;
			
				if (title != ""){
					like(title);
				}else{
					like();
				}
			}else if (echo == "DISLIKE"){
				string title;
				file >> title;

				if (title != ""){
					dislike(title);
				}else{
					dislike();
				}
			}
			file >> echo;
		}
	}
	file.close();
}
*/

/**
void Radio::menu(){
	string echo;
	cin >> echo;
	while (echo!= "QUIT"){
		if (echo == "INIT"){
			string timestr;
			cin >> timestr;
			int maxSong;
			cin >> maxSong;
			init (timestr, maxSong);
		}else if(echo == "ADD"){
			string data;
			getline(cin, data);
			addSong(data);
		}else if (echo == "PLAY"){
			string linestr;
			getline(cin,linestr);
			int line = atoi(linestr.c_str());
			play(line);
		}else if (echo == "REST"){
			string timestr;
			cin >> timestr;
			rest(timestr);
		}else if (echo == "LIKE"){
			string title;
			cin >> title;
			if (title != ""){
				like(title);
			}else{
				like();
			}
		}else if (echo == "DISLIKE"){
			string title;
			cin >> title;

			if (title != ""){
				dislike(title);
			}else{
				dislike();
			}

		}
		cin >> echo;
	}
}
*/

