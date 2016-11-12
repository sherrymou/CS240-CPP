#include "Song.h"
using namespace std;

class Heap{
	private:
	Song **array;
	int size;
	int stored;
	
	void swap(int index1, int index2);
	bool isGreater(Time current, int index1, int index2);
	int key(Time current, Song *song);

    public:
	Heap();
	Heap(int maximum);
	~Heap();
	int add(Time current, Song *asong);
	int upward(Time current, int index);
	int downward(Time current, int index);
	Song* getSong(int index);
	void show(Time current);
};
