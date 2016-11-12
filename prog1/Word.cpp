#include "Word.h"
#include <iostream>

using namespace std;

//Constructor
Word::Word(){
	head = NULL;
	next = NULL;
	pig = 0;
//	cout <<"Called Word::Word() [default constructor]" << endl;
}

//Copy constructor
//Update!
Word::Word(const Word &it){
//	cout <<"Enter Word copy constructor" << endl;
	if (it.head ==NULL){
		head = NULL;
		next= NULL;
		return;
	}

	Letter *iter = it.head;
	head = new Letter(*iter);
	Letter *tmp = head;
	iter = iter->next;
	
	for(iter;iter!=NULL;iter = iter->next){
		tmp-> next = new Letter(*iter); // Problem
		tmp = tmp->next;
	}
//	if (iter != NULL) tmp = new Letter(*iter);
	next = it.next;
	pig = it.pig;
}

//Destructor
Word::~Word(){
	if (head == NULL) return;
	Letter *iter = head;
	Letter *follow = head;
	for (iter;iter->next;iter = iter->next){
		follow = iter;
	}
	delete follow ->next;
	delete head;
	
//	cout << "Called Word::~Word() [destructor]" << endl;
}

//Methods:
void Word::append(char in) {
	if (head == NULL) {
		head = new Letter(in);
		return;
	}
	Letter *iterator = head;
	Letter *follow = head;
	while (iterator!= NULL) {
		follow = iterator;
		iterator = iterator->next;
	}
	follow->next = new Letter(in);
}

//Overloading Operators
Sentence &Word::operator+ (const Word &other){
//	cout << "Called Word::operator+(Word): Will return a (new and bigger) Word." << endl;
	Sentence *retval = new Sentence();
	retval->head = new Word(*this);
	(retval->head)->next = new Word(other);
	return *retval;
}

Sentence &Word::operator+ (const Sentence &other){
//	cout << "Called Word::operator+(Sentence): Will return a (new and bigger) Word." << endl;
	Sentence *retval = new Sentence();
	retval->head = new Word(*this);

	Word *iters = other.head;
	
	Word *iter = (*retval).head;
	iter->next = NULL;

	for (iters;iters!=NULL;iters= iters->next){
		Word* add = new Word(*iters);
		add->next = NULL;
		iter->next = add;
		iter = iter->next;
	}
	
/**
	*retval = Sentence(other);
	Word add = Word(*this);
	add.next = retval->head;
	retval->head = &add;
*/

	retval->punctuation = other.punctuation;
	return *retval;
}

// ++ Word
Word &Word::operator++ (){
//	cout << "Called Word::operator++(int) [prefix ++]. Will return this word in Pig Latin  (if it isn't already)." << endl;
	Letter *iter = head;
	Letter *iter2;
	
	bool valid = false;

	for (iter; iter; iter = iter->next){
		if (iter->letter >= 'A' && iter-> letter <='Z')
			iter->letter = (iter ->letter) + 32;
	}
	
	iter = head;
	for (iter; iter; iter = iter->next){
		if (iter->letter == 'a' or iter->letter == 'e' or iter->letter == 'i' or iter->letter == 'o' or iter->letter == 'u') {
			valid = true;
		}
	}
	if (!valid){
		return *this;
	}
	
	iter = head;
	if (head->letter == 'a' or head->letter == 'e' or head->letter == 'i' or head->letter == 'o' or head->letter == 'u'){
//		for (iter; iter!=NULL;iter = iter->next){}
		append('w');
		append('a');
		append('y');
	}else{
		for (iter = head; (iter->letter != 'a' and iter->letter != 'e' and iter->letter != 'i' and iter->letter != 'o' and iter->letter != 'u'); iter = head){
			Letter tmp = *iter;
			append(tmp.letter);
			head = iter->next;
			pig ++;
//			for (iter2 = retval.head; iter2; iter2 = iter2->next){}	
		}
		append ('a');
		append ('y');
	}

	return *this;

}

// Word ++ 
Word &Word::operator++ (int){
	//cout << "Called Word::operator++(int) [postfix ++]. Will return this word in Capital"<< endl;
	Letter *iter = head;
	for (iter; iter; iter = iter->next){
		if (iter->letter >= 'a' && iter-> letter <= 'z')
			iter->letter = (iter ->letter) - 32;
	}
	return *this;
}

// -- Word
Word &Word::operator-- (){
//	cout << "Called Word::operator--() [prefix --]. Will converted from Pig Latin to English." << endl;
	Letter *iter = head;
	Letter *iter2 =head;

	for (iter; iter; iter = iter->next){
		if (iter->letter >= 'A' && iter-> letter <= 'Z')
			iter->letter = (iter ->letter) + 32;
	}
	iter = head;
	if (!iter or !iter->next){
		return *this;
	}
	
	for (int i = 0; i<2; i++){
		for (iter=head;iter->next!=NULL;iter =iter->next){iter2 = iter;}
		iter2->next = NULL;
//		cout << "iter2" << iter2->letter<<endl;
	}
	
	if (pig == 0){
		for (iter=head; iter->next!=NULL; iter = iter->next){iter2= iter;}
		iter2->next = NULL;
	}else{
		for (int i = 0; i < pig; i++){

			for (iter = head; iter->next!=NULL; iter= iter-> next){iter2 = iter;}
			iter2->next = NULL;
			Letter *temp = iter;
			temp -> next = head;
			head = temp;
		}
	}

	return *this;
}


// Word --
Word &Word::operator-- (int){
	Letter *iter = head;
	for (iter; iter; iter = iter->next){
		if (iter->letter >= 'A' && iter-> letter <= 'Z')
			iter->letter = (iter ->letter) + 32;
	}
	return *this;
}


Word &Word::operator+ (int i){
	if (i == 1){
		if (head){
			if (head->letter >= 'a' && head-> letter <= 'z'){
				head->letter = (head->letter) - 32;
				}
		}
	}
	return *this;
}


Word &Word::operator= (const Word it){
	if (it.head ==NULL){
		head = NULL;
		next= NULL;
		return *this;
	}

	Letter *iter = it.head;
	head = new Letter(*iter);
	Letter *tmp = head;
	iter = iter->next;
	
	for(iter;iter!=NULL;iter = iter->next){
			tmp-> next = new Letter(*iter);
			tmp = tmp->next;
	}
	if (iter != NULL) tmp = new Letter(*iter);
	next = it.next;
	//head = other.head;
	//next = other.next;
//	cout << "Called Word::operator=(Word) [assignment operator]." << endl;
	
	return *this;
}



ostream &operator<< (ostream &os, const Word s){
	Letter *iterator = s.head;
	for (iterator; iterator!= NULL; iterator = iterator-> next){
		if ((*iterator).letter != 0){
		os << (*iterator).letter;
		}
	}
	if (iterator!=NULL) 
		os << iterator->letter;
	return os;
}


void Word::show(){
//	cout <<"Show word: " ;
//	for (Letter *le=head; le->next; le=le->next){
//		cout << le->letter;
//	}
//	cout <<endl;

	cout <<*this<< endl;
}
