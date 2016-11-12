#include "Letter.h"

using namespace std;

Letter::Letter(char in) {
	letter = in;
	next = NULL;
}

Letter::Letter() {
	letter = 0;
	next = NULL;
}

Letter::~Letter() {

}

Letter::Letter(const Letter &it){
//cout<<"entered letter cc"<<it.letter<<endl;
	if (it.letter!=0){ 
		letter = it.letter;
	}else{
		letter = 0;	
	}
	next = NULL;
//		cout << "De" << letter << endl;
}


Letter &Letter::operator=(const Letter &other){
	cout << "Called Letter::operator=" << endl;
	letter = other.letter;
	next = other.next;
	return *this;

}

/**
ostream operator<< (ostream &output, const Letter &le){
	Letter iterator;
	for (iterator = s; iterator->next != NULL; iterator = iterator-> next){
		output << iterator-> letter;
	}
	return output;
}
*/
