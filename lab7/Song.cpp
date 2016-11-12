#include <string>
#include "Song.h"
using namespace std;

Song::Song(string tit, string art, Time dur){
	title = title;
	artist = art;
	duration = dur;
	likability = 0;
	recentPlay = Time();
}

Song::Song(){
	title = "";
}

Song::Song(const Song &other){
	title = other.title;
	artist = other.artist;
	duration = other.duration;
	likability = other.likability;
	recentPlay = other.recentPlay;
}

Song &Song::operator= (const Song other){
	title = other.title;
	artist = other.artist;
	duration = other.duration;
	likability = other.likability;
	recentPlay  = other.recentPlay;
	return *this;
}

void Song::like(){
	if (likability>=0){
		likability++;
	}else{
		likability = 1;
	}
}

void Song::dislike(){
	if (likability <=0){
		likability --;
	}else{
		likability = -1;
	}
}


