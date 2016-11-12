#include <iostream>
#include <string>
#include "Heap.h"
#include "HashTable.h"
using namespace std;

class Radio{
	private:
	Time current;
	HashTable table;
	string lastPlayed;
	Heap heap;
	
	public:
	Radio();
	~Radio();
	bool run(string commandfile);
	void init(string time, int maxSongs);
	void addSong(string data);
	void command(string comfile);
	void play(int num);
	void rest(string time);
	void like(string song);
	void like();
	void dislike(string song);
	void dislike();
};
