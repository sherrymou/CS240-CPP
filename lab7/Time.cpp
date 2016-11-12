#include <string>
#include <iostream>
#include <sstream>
#include "Time.h"
using namespace std;

Time::Time(string timestr){
	
	istringstream ss(timestr);
	string hourstr;
	string minutestr;
	string secondstr;
	if (timestr.length() >5){
		getline(ss, hourstr, ':');
		getline(ss, minutestr, ':');
		getline(ss, secondstr, ':');
	}else{
		getline(ss, minutestr,':');
		getline(ss, secondstr, ':');
		hourstr = "0";
	}
	second = atoi(hourstr.c_str())*60*60+atoi(minutestr.c_str())*60+atoi(secondstr.c_str());
//	cout << "second: " << second << endl;
}

Time::Time(){
	second = 0;
}

Time::Time(const Time &other){
	second = 0;

}

string Time::toString (){
	string retval;
	string ap = "am";
	int data = second;
	int sec = data%(60);
	data = (data - sec)/60;
	int minute = data%(60);
	data = (data - minute)/60;
	int hour = data%(24);
	data = (data -hour)/24;
	int day = data +1;
	if (hour >= 12) {
		ap = "pm";
		hour = hour-12;
	}
	retval = "Day " + to_string(day) + ": " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(sec) +ap;
	return retval;
}

int &Time::operator+(const Time other){
	second = second + other.second;
}

Time &Time::operator=(const Time other){
	second  = other.second;
	return *this;
}
