#include <string>
using namespace std;

class HashTable{
	private:
	struct Box{
		string title;
		int index;
	};
	Box* array;
	int size;
	int hash(string item);

	public:
	HashTable();
	HashTable(int size);
	~HashTable();
	void add(string title, int index);
	void update(string title, int aft);
	int find(string title); // return "title"'s index

};
