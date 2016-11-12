#include "Sentence.h"
#include <iostream>

using namespace std;

//Constructor
Sentence::Sentence(){
	head = NULL;
	next = NULL;
	punctuation = '\0';
//	cout <<"Called Sentence::Sentence() [default constructor]" << endl;
}

//Copy constructor
Sentence::Sentence(const Sentence &it){
//	cout << "Enter Sentence Copy constructor" << endl;
	if (it.head ==NULL){
		head = NULL;
		next= NULL;
		punctuation = '\0';
		return;
	}
	Word *iter = it.head;
	head = new Word(*iter);
	Word *tmp = head;
	iter = iter->next;

	for(iter;iter!=NULL;iter = iter->next){
		tmp-> next = new Word(*iter);
		tmp = tmp->next;
	}
//	if (iter != NULL) tmp = new Word(*iter);
	punctuation = it.punctuation;
	next = it.next;
}

Sentence::Sentence(const Word &it){
	head = new Word(it);;
//	cout << "Called Sentence::Sentence(const Word &it) [copy constructor]" << endl;
}

//Destructor
Sentence::~Sentence(){
	if (head == NULL) return;
	Word *iter = head;
	Word *follow = head;
	for (iter;iter->next;iter = iter->next){
		follow = iter;
	}
	delete follow ->next;
	delete head;
//	cout << "Called Sentence::~Sentence() [destructor]" << endl;
}

//Methods:
void Sentence::append(char in) {
	if (head == NULL){
		head = new Word();
		if (in!=' ')head->append(in);
		return;
	}
	Word *iterator = head;
	Word *follow = head;
	while (iterator != NULL) {
		follow = iterator;
		iterator = iterator->next;
	}
	if (in == ' ') {
		follow->next = new Word();
	}
	else if(in == '.' or in == '!' or in == '?'){
		punctuation = in;
//		next = new Sentence();
	}else{
		follow->append(in);
	//	(*iterator).append(in);
	}
}
//Overloading Operators
Paragraph &Sentence::operator+ (const Sentence &other){
	Paragraph *retval = new Paragraph();
	retval ->head = new Sentence(*this);
	retval->head->next = new Sentence (other);

//	cout << "Called Sentence::operator+(Sentence): Will return a (new and bigger) Sentence." << endl;
	return *retval;
}


Sentence &Sentence::operator+ (const Word &other){
	Sentence *retval = new Sentence(*this);
	Word *iter = retval->head;

	for (iter; iter->next!=NULL; iter = iter->next){}
	iter->next = new Word(other);	
//	cout << "Called Sentence::operator+(Word): Will return a (new and bigger) Sentence." << endl;
	return *retval;
}

Paragraph &Sentence::operator+ (const Paragraph &other){
	Paragraph *retval = new Paragraph();
	retval -> head = new Sentence(*this);
	Sentence *iters = other.head;
	Sentence *iter = retval->head;
	iter->next = NULL;
	
	for (iters;iters;iters = iters->next){
		iter->next = new Sentence(*iters);
		iter = iter->next;
	}
//	cout << "Called Sentence::operator+(Paragraph): Will return a (new and bigger) Sentence." << endl;
	return *retval;
}

// ++ Sentence
Sentence &Sentence::operator++ (){
	Word *iter = head;
	for (iter; iter; iter = iter->next){
		++(*iter);
	}
	return *this;

}

// Sentence ++ 
Sentence &Sentence::operator++ (int){
	Word *iter = head;
	for (iter; iter; iter = iter->next){
		(*iter)++;
	}
	return *this;
}

// -- Sentence
Sentence &Sentence::operator-- (){
//	cout << "Called Sentence::operator--()" << endl;
	Word *iter = head;
	for (iter; iter; iter = iter->next){
		--(*iter);
	}
	return *this;
}


// Sentence --
Sentence &Sentence::operator-- (int){
	Word *iter = head;
	for (iter; iter; iter = iter->next){
		(*iter)--;
	}
	return *this;
}


Sentence &Sentence::operator+ (int i){
	if (i == 1){
		if (head!=NULL){
			(*this)--;
			*head = (*head)+1;
		}
	}
	return *this;
}


Sentence &Sentence::operator= (const Sentence it){
//	cout <<"Called sentence operator= " <<endl;
//	head = other.head;
//	next = other.next;
	
	if (it.head ==NULL){
		head = NULL;
		next= NULL;
		punctuation = '\0';
		return *this;
	}
	Word *iter = it.head;
	head = new Word(*iter);
	Word *tmp = head;
	iter = iter->next;

	for(iter;iter!=NULL;iter = iter->next){
		tmp-> next = new Word(*iter);
		tmp = tmp->next;
	}
//	if (iter != NULL) tmp = new Word(*iter);
	punctuation = it.punctuation;
	next = it.next;
	
	
	return *this;
}

Sentence Sentence::first(){
	Sentence retval;
	retval.head = new Word(*head);
	(retval.head)->next = NULL;
	return retval;
}

Sentence Sentence::rest(){
	Sentence retval;
	Word *iter = head;
	if (head->head){
		iter = iter->next;
		retval.head = new Word(*iter);
		Word *copy  = retval.head;
		iter = iter->next;
		for (iter; iter; iter = iter->next){
			copy->next = new Word(*iter);
			copy = copy->next;
		}
	}
	return retval;
}

ostream &operator<< (ostream &output, const Sentence s){
//	cout << "enter Operator << "<< endl;
	Word *iterator;
	for (iterator = s.head; iterator!= NULL; iterator = iterator-> next){
			output << *iterator;
			if (iterator->next) output << ' ' ;
	}
		if (s.punctuation== '.' or s.punctuation == '!' or s.punctuation == '?') {
			output<< s.punctuation;
		}else if (s.punctuation!= '\0'){output << '.';}
	return output;
}

void Sentence::show(){
	int a= 0;
	cout <<"Show sentence: ";
	for (Word *wo = head; wo!=NULL; wo = wo->next){
		cout << *wo << " ";
	}
//	cout << *wo;
	cout << endl;
}
