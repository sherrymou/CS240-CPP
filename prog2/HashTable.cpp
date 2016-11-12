#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

HashTable::HashTable(){}

HashTable::HashTable(int max){
	array = new Box[max];
	size = max;
}

HashTable::~HashTable(){
}

int HashTable::hash(string item){
	int retval=0;
	string title = item;
	for (unsigned int i = 0; i<10 && i <title.size(); i++){
		retval +=title[i];
	}
	retval = retval%size;
	return retval;
}

void HashTable::add(string title, int index){
	int pos = hash(title);
	while(array[pos].title!="") {
		pos++;
		if (pos == size) pos = 0;
	}
	Box bx;
	bx.title = title;
	bx.index = index;
	array[pos] = bx;
//	cout <<"Added song to hash table: " << title  << " with index " << index<< endl;
}

void HashTable::update(string title, int aft){
	int pos = hash(title);
	while(array[pos].title!=title){
		pos++;
		if(pos == size) pos = 0;
	}
	array[pos].index= aft;
//	cout <<"updated song: " << array[pos].title << " with index" << aft << endl;
}

int HashTable::find(string title){
	int pos = hash(title);
	while(array[pos].title!=title){
		pos++;
		if(pos == size) pos = 0;
	}
//	cout <<"Find Song: " << array[pos].title  << " with index "<< array[pos].index << endl;
	return array[pos].index;
}
