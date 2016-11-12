#include <string>
using namespace std;

class Graph{
	public:
	struct Edge{
		string from;
		string to;
	};

	Edge *flight;
	string *city;
	int numFlight;

	Graph();
	Graph(string filename);
	~Graph();

	//Methods
	bool home(string city);
	bool travel(string city1, string city2);
	string* findWay(string city1, string city2, string *path);
};

//Array functions
string* append(string *array, string str);
bool find(string *array, string str);
