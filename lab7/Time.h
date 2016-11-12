#include <string>
using namespace std;

class Time{
	public:
	int second;


	Time(string timestr);
	Time();
	Time(const Time &other);
	
	string toString();
	int &operator+ (const Time other);
	Time &operator= (const Time other);
	
};
