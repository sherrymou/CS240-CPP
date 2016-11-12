#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return; 
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
}

// Iterative Snsertion Sort
void Sorter::insertionSortI() {
	unsigned int i,j;
	int insertNum;
	for (i = 1; i <capacity; i++){
		insertNum = array[i];
		j=i;
		while (j>0 and array[j-1] > insertNum){
			array[j] = array[j-1];
			j = j-1;
		}
		array[j] = insertNum;
	}

//   cout << "Sorter::insertionSortI() not implemented yet." << endl << endl;
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
	unsigned int i, j, min;
	for (i =0; i< capacity -1; i++){
		min = i;
		for (j=i+1; j < capacity; j++){
			if (array[j]<array[min]) min = j;
		}
		swap (i,min);
	}
//   cout << "Sorter::selectionSortI() not implemented yet." << endl << endl;
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
	unsigned int i,j;
	for (i = capacity -1; i > 0; i--){
		for (j = 1; j <= i ; j++){
			if (array[j-1]>array[j])
				swap (j-1, j);
		}
	}

//   cout << "Sorter::bubbleSortI() not implemented yet." << endl << endl;
}

// Recursive Insertion Sort
void Sorter::insertionSortR() {
	ISout(1);
}

void Sorter::ISout(unsigned int pos){
	if (pos < capacity){
		ISin (pos, pos-1);
		ISout(pos+1);
	}
}


void Sorter::ISin(unsigned int pos, unsigned int comp){
	if (pos > 0){
	if (array[pos]<array[comp]){
		swap(pos,comp);
		ISin(pos-1,comp-1);
	}
	}
}


// Recursive Selection Sort
void Sorter::selectionSortR() {
	SSout(0);
//   cout << "Sorter::selectionSortR() not implemented yet." << endl << endl;
}

void Sorter::SSout(unsigned int start){
	if (start < capacity){
		SSin(start,start,start);
		SSout(start+1);
	}
}

void Sorter::SSin(unsigned int start, unsigned int pos, unsigned int min){
	if (pos < capacity ){
		if (array[pos]<array[min]){
			min = pos;
		}
		SSin(start,pos+1, min);
		swap (start,min);
//		show(25,10);
	}
	swap (start,min);
}


// Recursive Bubble Sort
void Sorter::bubbleSortR() {
	BSout(capacity);
//   cout << "Sorter::bubbleSortR() not implemented yet." << endl << endl;
}



void Sorter::BSout(unsigned int pos){
	if (pos > 0){
		BSin(0);
		BSout(pos-1);
	}
}


void Sorter::BSin(unsigned int comp){
	if (comp<capacity-1){
		if (array[comp] > array[comp+1]){
			swap(comp,comp+1);
		}
		BSin(comp+1);
	}

}

