#include <string>
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "Time.h"
using namespace std;

Time::Time(string timestr){
	boost::trim(timestr);
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
//	cout << "second: " << second << endl; // DEBUG
}

Time::Time(){
	second = 0;
}

Time::Time(const Time &other){
	second = other.second;

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
	}
	if (hour > 12){
		hour = hour-12;
	}
	string minstr = to_string(minute);
	if (minute<10) minstr = "0"+minstr;
	string secstr = to_string(sec);
	if (sec<10) secstr = "0"+secstr;
	retval = "Day " + to_string(day) + ": " + to_string(hour) + ":" + minstr + ":" + secstr +ap;
	return retval;
}

Time Time::operator+(const Time &time1) const{
	Time retval = Time();
	retval.second = this->second + time1.second;
	return retval;
}

int Time::operator-(const Time &time1)const {
	int retval;
	retval = this->second - time1.second;
	return retval;
}

Time Time::operator=(const Time &other){
	second  = other.second;
	return *this;
}
