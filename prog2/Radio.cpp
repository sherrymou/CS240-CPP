#include <iostream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <cstddef>
#include <fstream>
#include "Radio.h"
using namespace std;

Radio::Radio(){}

Radio::~Radio(){}

void Radio::init(string time, int maxSongs){
	current = Time(time);
	table = HashTable(maxSongs);
	heap = Heap(maxSongs);
//	cout <<"Default Constructor: current: " << current.toString() << endl;
}

void Radio::addSong(string data){
	// ex: <Song Title> , <Artist> , <Runtime> Seperate w/ comma
	//	cout << "###Debug: ";
	//	heap.show(current);//debug
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
	Song *song = new Song(current, title, artist, runtime);
	int index = heap.add(current, song);
	//index = heap.upward(current, index);
	table.add(song->title, index);
}

void Radio::play(int num){
	for (int i = 0; i < num; i++){
//		cout << "###Debug: ";
//		heap.show(current);//debug
		Song *playing = heap.getSong(0);
		lastPlayed = playing->title;
		cout <<"["<<current.toString() <<"] " << playing->title << " by " << playing->artist << endl;
		current = current + playing->duration;
		playing->recentPlay = current;
		int index = heap.downward(current, 0);
	//	cout <<"Radio::play: index = " << index << endl;
		table.update(playing->title, index);
	}
	//cout << "###Debug: ";
	//heap.show(current);//debug
}

void Radio::rest(string time){
	Time addTime = Time(time);
	current = current + addTime;
	cout << "Rested: " << time << endl;
}

void Radio::like(string song){
//	cout << "###Debug: ";
//	heap.show(current);//debug
	int index = table.find(song);
	Song *temp = heap.getSong(index);
	temp->like();
	index = heap.upward(current, index);
	table.update(song, index);
	cout <<"Liked song: " << song << endl;
}

void Radio::like(){
//	cout << "###Debug: ";
//	heap.show(current);//debug
	int index = table.find(lastPlayed);
	Song *temp = heap.getSong(index);
	temp->like();
	index = heap.upward(current, index);
	table.update(lastPlayed, index);
	cout <<"Liked recent played song: " <<temp->title << endl;
}

void Radio::dislike(string song){
//	cout << "###Debug: ";
//	heap.show(current);//debug
	int index = table.find(song);
	Song *temp = heap.getSong(index);
	temp->dislike();
	index = heap.downward(current, index);
	table.update(song, index);
	cout << "Disliked song: " << song << endl;
}

void Radio::dislike(){
//	cout << "###Debug: ";
//	heap.show(current);//debug
	int index = table.find(lastPlayed);
	Song *temp = heap.getSong(index);
	temp->dislike();
	index = heap.downward(current, index);
	table.update(lastPlayed, index);
	cout << "Disliked recent played song: "  << temp->title<< endl;
}

bool Radio::run(string commandfile){
	stringstream file;
	file.str(commandfile);
	string echo;
	while (file >> echo){
		if (echo == "QUIT"){
			return true;
		}
//		while (echo!= "QUIT"){
			if (echo == "INIT"){
				string timestr;
				file >> timestr;
				int maxSong;
				file >> maxSong;
				init (timestr, maxSong);
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
				boost::trim(title);
				if (title != ""){
					like(title);
				}else{
					like();
				}
			}else if (echo == "DISLIKE"){
				string title;
				getline(file,title);
				boost::trim(title);
				if (title != ""){
					dislike(title);
				}else{
					dislike();
				}
			}
			file >> echo;
//		}
	}
	return false;
}

