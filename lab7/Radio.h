#include <iostream>
#include <string>
#include "Song.h"
//#include "Time.h"
using namespace std;

class Radio{
	private:
	Time current;
	Song *songlist;
	
	public:
	Radio();
	~Radio();
	void run(string commandfile);
	void init(string time, int maxSongs);
	void addSong(string data);
	void command(string comfile);
	void play(int num);
	void rest(string time);
	void like(string song);
	void like();
	void dislike(string song);
	void dislike();
//	void menu();
	
};
