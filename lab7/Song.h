#include <string>
#include "Time.h"
using namespace std;

class Song{
	public:
	string title;
	string artist;
	Time duration;
	
	int likability;
	Time recentPlay;
	
	Song();
	Song(string tit, string art, Time dur);
	Song (const Song &other);
	void like();
	void dislike();
	Song &operator= (const Song other);
	
};
