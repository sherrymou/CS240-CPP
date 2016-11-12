#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <cstdlib>

template <typename Type>
class TSorter {

   private:
	vector<Type> v;
	unsigned int numElements;
	//v.capacity(); size
	//v.size(); elements
	typename vector<Type>::iterator iter;
	void swap(typename vector<Type>::iterator i, typename vector<Type>::iterator j); 

  public:
      TSorter<Type>();
      TSorter<Type>(unsigned int initialCapacity);
      ~TSorter<Type>();

      void clear(); 
      bool insert(Type value); 

      // Make sure the array contains at least newCapacity elements.
      // If not, grow it to that size and copy in old values
      unsigned int makeSpace(unsigned int newCapacity); 

      // Show the first n elements, k per line using << 
      void show(unsigned int n, unsigned int k); 

      // "Shuffle" the array elements
      void shuffle(); 
      void insertionSortI();
      void selectionSortI();
      void bubbleSortI();     
      void insertionSortR(); 
      void selectionSortR();	
      void bubbleSortR(); 	

	//aux
	void SSout(typename vector<Type>::iterator start);
	void SSin(typename vector<Type>::iterator start, typename vector<Type>::iterator pos, typename vector<Type>::iterator min);
	void ISout(typename vector<Type>::iterator pos);
	void ISin(typename vector<Type>::iterator pos, typename vector<Type>::iterator comp);
	void BSout(typename vector<Type>::iterator pos);
	void BSin(typename vector<Type>::iterator comp);
};

