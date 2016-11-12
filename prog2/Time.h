#include <string>
using namespace std;

class Time{
	private:
	long second;

	public:
	Time(string timestr);
	Time();
	Time(const Time &other);
	
	string toString();
	Time operator+ (const Time &time1) const;
	int operator- (const Time &time1) const;
	Time operator= (const Time &other);
	
};
