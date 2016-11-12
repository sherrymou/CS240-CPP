#include "Heap.h"
#include <iostream>
#include <string>
using namespace std;

Heap::Heap(){
}

Heap::Heap(int maximum){
	array = new Song*[maximum];
	size = maximum;
	stored = 0;
}

Heap::~Heap(){}


int Heap::key(Time current, Song *song){
	int retval = (current - song->recentPlay)+ 1000*song->likability;
	return retval;
}

int Heap::add(Time current, Song *song){
	int index = stored;
	stored ++;
	array[index] = song;
	index = upward(current,index);
	return index; 
}

void Heap::swap(int index1, int index2){
	Song *temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

bool Heap::isGreater(Time current, int index1, int index2){
//	if (array[index1]==NULL) return false;
//	if (array[index2] == NULL) return true;
	int key1 = key(current, array[index1]);
	int key2 = key(current, array[index2]);
	if (key1 > key2) {
		return true;
	}else{
		return false;
	}
}


int Heap::downward(Time current, int index){
	if (index*2+2 < stored){
		if (index==0 && isGreater(current, index,2*index+1) && isGreater(current, index,2*index+2)){
			return index;
		}else if (isGreater(current, 2*index+1, index) || isGreater(current, 2*index+2,index)){
			if(!isGreater(current, 2*index+2,index*2+1)){
				swap(index,2*index+1);
				return downward(current, 2*index+1);
			}else{
				swap(index,2*index+2);
				return downward(current, 2*index+2);
			}
		}
	}else if (index*2+2 == stored){
		if (isGreater(current, 2*index+1, index)){
			swap(index, 2*index+1);
			return downward(current, 2*index+1);
		}
	}else{
		return index;
	}
}

int Heap::upward(Time current, int index){
	if (index==0) return 0;
	int root = (index-1)/2;
	if (isGreater(current, index, root)){
		swap(root, index);
		return upward(current, root);
	}else{
		return index;
	}
}

Song* Heap::getSong(int index){
	return array[index];
}

void Heap::show(Time current){
	cout <<"===HEAP==="<<endl;
	for (int i = 0; i < stored; i++){
		cout << array[i]->title << ": " << key(current, array[i]) << endl;
	}
	cout <<"==========" << endl;
}
