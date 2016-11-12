#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#include "TSorter.h"


template <typename Type>
TSorter<Type>::TSorter() {
}

template <typename Type>
TSorter<Type>::TSorter(unsigned int initialCapacity) {
   v = vector<Type>(initialCapacity);
}

template <typename Type>
unsigned int TSorter<Type>::makeSpace(unsigned int newCapacity) {
	v = vector<Type>(newCapacity);
/**
   vector<Type> old; 
   unsigned int i;
   if (newCapacity > v.capacity()) {
      old = v; 
      v = vector<Type>(newCapacity); 
      for (i=0; i<v.size(); i++) 
         v[i] = old[i]; 
   }
*/
   return v.capacity();

}

template <typename Type>
void TSorter<Type>::swap(typename vector<Type>::iterator  i, typename vector<Type>::iterator j) {
   Type tmp;
   tmp = *i; 
   *i = *j;
   *j = tmp; 
   return; 
}

template <typename Type>
void TSorter<Type>::clear() {
	numElements = 0;
   return; 
}

template <typename Type>
bool TSorter<Type>::insert(Type element) {
	v.push_back(element);
   return true;
}

template <typename Type>
TSorter<Type>::~TSorter() {
//   if (v!=NULL) {
//      delete v; 
//      numElements = 0; 
//   }
}


// Shuffle v elements
template <typename Type>
void TSorter<Type>::shuffle() {
/**
	typename vector<Type>::iterator i;
	typename vector<Type>::iterator j;
   for (i = v.begin(); i != v.end();++i ) {
      j = rand() % i; 
      swap(i, j); 
   }
*/

	random_shuffle(v.begin(), v.end());
}


// Show the first n elements, k per line, using << 
template <typename Type>
void TSorter<Type>::show(unsigned int n, unsigned int k) {
	for (typename vector<Type>::iterator it = v.begin(); it!=v.end(); ++it){
		cout << *it << " ";
	}
	
	cout << endl << endl;
	
	
/**	
   unsigned int toShow = ((n < numElements) ? n : v.capacity()); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << v[i] << " "; 
   }
   cout << endl << endl;
*/
}

// Iterative Snsertion Sort
template <typename Type>
void TSorter<Type>::insertionSortI() {
	typename vector<Type>::iterator i;
	typename vector<Type>::iterator j;
	int insertNum;
	for (i = v.begin(); i!=v.end(); ++i){
		insertNum = *i;
		j=i;
		while (*(j-1) > insertNum){
			*j = *(j-1);
			j = j-1;
		}
		*j = insertNum;
	}

//   cout << "TSorter<Type>::insertionSortI() not implemented yet." << endl << endl;
}

// Iterative Selection Sort
template <typename Type>
void TSorter<Type>::selectionSortI() {
	typename vector<Type>::iterator i, j, min;
	for (i=v.begin();i!=v.end();++i){
		min = i;
		for (j = i; j!=v.end(); ++j){
			if (*j<*min) min = j;
		}
		swap (i,min);
	}
//   cout << "TSorter<Type>::selectionSortI() not implemented yet." << endl << endl;
}

// Iterative Bubble Sort
template <typename Type>
void TSorter<Type>::bubbleSortI() {
	typename vector<Type>::iterator i,j;
	for (i = v.end(); i!=v.begin(); --i){
		for (j = v.begin(); j != i; ++j){
			if (*(j-1) > *j)
				swap (j-1, j);
		}
	}

//   cout << "TSorter<Type>::bubbleSortI() not implemented yet." << endl << endl;
}

// Recursive Insertion Sort
template <typename Type>
void TSorter<Type>::insertionSortR() {
	iter = v.begin();
	ISout(iter);
}


template <typename Type>
void TSorter<Type>::ISout(typename vector<Type>::iterator pos){
	if (pos != v.end()){
		ISin (pos, pos-1);
		ISout(pos+1);
	}
}

template <typename Type>
void TSorter<Type>::ISin(typename vector<Type>::iterator pos,typename vector<Type>::iterator comp){
	if (pos != v.begin()){
	if (*pos<*comp){
		swap(pos,comp);
		ISin(pos-1,comp-1);
	}
	}
}


// Recursive Selection Sort
template <typename Type>
void TSorter<Type>::selectionSortR() {
	iter = v.begin();
	SSout(iter);

//   cout << "TSorter<Type>::selectionSortR() not implemented yet." << endl << endl;
}

template <typename Type>
void TSorter<Type>::SSout(typename vector<Type>::iterator  start){
	if (start!=v.end()){
		SSin(start,start,start);
		*start++;
		SSout(start);
	}
}

template <typename Type> 
void TSorter<Type>::SSin(typename vector<Type>::iterator start, typename vector<Type>::iterator pos, typename vector<Type>::iterator min){
	if (pos != v.end()){
		if (*pos<*min){
			min = pos;
		}
			*pos++;
			 SSin(start, pos, min);
		swap (start,min);
//		show(25,10);
	}
	swap (start,min);
}


// Recursive Bubble Sort
template <typename Type>
void TSorter<Type>::bubbleSortR() {
	iter = v.end();
	BSout(iter);
//   cout << "TSorter<Type>::bubbleSortR() not implemented yet." << endl << endl;
}


template <typename Type>
void TSorter<Type>::BSout(typename vector<Type>::iterator pos){
	if (pos != v.begin()){
		BSin(v.begin());
		BSout(pos-1);
	}
}

template <typename Type>
void TSorter<Type>::BSin(typename vector<Type>::iterator comp){
	if (comp!=(v.end()-1)){
		if (*comp > *(comp+1)){
			swap(comp,comp+1);
		}
		BSin(comp+1);
	}

}


template class TSorter<int>;
template class TSorter<char>;
template class TSorter<double>;
template class TSorter<float>;
