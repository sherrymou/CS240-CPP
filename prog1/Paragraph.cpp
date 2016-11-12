#include "Paragraph.h"
#include <iostream>

using namespace std;

//Constructor
Paragraph::Paragraph(){
	head = NULL;
	next = NULL;
//	cout <<"Called Paragraph::Paragraph() [default constructor]" << endl;
}


//Copy constructor
Paragraph::Paragraph(const Paragraph &it){
	if (it.head ==NULL){
		head = NULL;
		next= NULL;
		return;
	}
	Sentence *iter = it.head;
	head = new Sentence(*iter);
	Sentence *tmp = head;
	iter = iter->next;

	for(iter;iter!=NULL;iter = iter->next){
		tmp-> next = new Sentence(*iter);
		tmp = tmp->next;
	}
//	tmp->next = new Sentence(*iter);

	next = it.next;
//	cout << "Called Paragraph::Paragraph(const Paragraph &it) [copy constructor]" << endl;
}
Paragraph::Paragraph(const Sentence &it){
	head = new Sentence (it);
//	cout << "Called Paragraph::Paragraph(const Sentence &it) [copy constructor]" << endl;
}
//Destructor
Paragraph::~Paragraph(){
	if (head == NULL) return;
	Sentence *iter = head;
	Sentence *follow = head;
	for (iter;iter->next;iter = iter->next){
		follow = iter;
	}
	delete follow ->next;
	delete head;
//	cout << "Called Paragraph::~Paragraph() [destructor]" << endl;
}
//Methods
void Paragraph::append(char in) {
	if (head == NULL){
		head = new Sentence();
		head->append(in);
		return;
	}
	Sentence *iterator = head;
	Sentence *follow = head;
	while (iterator!= NULL) {
		follow = iterator;
		iterator = iterator->next;
	}

	if (in == '.' or in == '!' or in == '?') {
		follow ->append(in);
		follow -> next = new Sentence();
	}
	else if (in !='\n') {
		follow->append(in);
	}
}


//Overloading Operators
Paragraph &Paragraph::operator+ (const Paragraph &other){
	Paragraph *retval = new Paragraph(*this);
	Sentence *iter = retval->head;
	Sentence *iterp = other.head;
	
	for (iter;iter->next;iter=iter->next){}
	for (iterp; iterp; iterp = iterp->next){
		iter->next = new Sentence(*iterp);
		iter = iter->next;
	}

//	cout << "Called Paragraph::operator+(Paragraph): Will return a (new and bigger) Paragraph." << endl;
	return *retval;
}

Paragraph &Paragraph::operator+ (const Sentence &other){
//	cout << "Called Paragraph::operator+(Sentence): Will return a (new and bigger) Paragraph." << endl;
	Paragraph *retval = new Paragraph(*this);
	Sentence *iter = retval -> head;
	for (iter;iter->next!=NULL;iter = iter->next){}
	iter->next = new Sentence();
	Sentence *add = new Sentence(other);
	iter ->next = add;
	return *retval;
}

Story &Paragraph::operator+ (const Story &other){
//	cout << "Called Paragraph::operator+(Story): Will return a (new and bigger) Paragraph." << endl;
	Story *retval = new Story();
	retval -> head = new Paragraph(*this);
	Paragraph *iters = other.head;
	Paragraph *iter = retval->head;
	iter -> next = NULL;
	
	for (iters;iters;iters = iters->next){
		iter->next = new Paragraph(*iters);
		iter = iter -> next;
	}
	return *retval;
}


// ++ Paragraph
Paragraph &Paragraph::operator++ (){
	Sentence *iter = head;
	for (iter; iter; iter = iter->next){
		++(*iter);
		(*iter) = (*iter)+1;
	}
//	cout << "Called Paragraph::operator++(int) [prefix ++]. Will return this word in Pig Latin (if it isn't already)." << endl;
	return *this;

}


// Paragraph ++ 
Paragraph &Paragraph::operator++ (int){
//	cout << "Called Paragraph::operator++(int) [prefix ++]. Will return this word in Pig Latin (if it isn't already)."<< endl;
	Sentence *iter = head;
	for (iter; iter; iter = iter->next){
		(*iter)++;
	}
	return *this;
}

// -- Paragraph
Paragraph &Paragraph::operator-- (){
//	cout << "Called Paragraph::operator--() [postfix --]. Will return this word in all lowercase." << endl;
	Sentence *iter = head;
	for (iter; iter; iter = iter->next){
		--(*iter);
		(*iter)+1;
	}
	return *this;
}


// Paragraph --
Paragraph &Paragraph::operator-- (int){
//	cout << "Called Paragraph::operator--(int) [prefix --]. Will return this Word converted from Pig Latin to English." << endl;
	Sentence *iter = head;
	for (iter; iter; iter = iter->next){

		(*iter)--;
	}
	return *this;
}


Paragraph &Paragraph::operator+ (int i){
//	cout << "Called Paragraph::operator+(int): Will return this Paragraph with initial letters of Sentences capitalized." << endl;
	if ( i == 1){
		Sentence *iter = head;
		for (iter; iter; iter= iter->next){
			(*iter) = (*iter) +1;
		}
	}
	return *this;
}


Paragraph &Paragraph::operator= (const Paragraph it){
	if (it.head ==NULL){
		head = NULL;
		next= NULL;
		return *this;
	}
	Sentence *iter = it.head;
	head = new Sentence(*iter);
	Sentence *tmp = head;
	iter = iter->next;

	for(iter;iter!=NULL;iter = iter->next){
		tmp-> next = new Sentence(*iter);
		tmp = tmp->next;
	}

	next = it.next;
//	cout << "Called Paragraph::operator=(Paragraph) [assignment operator]." << endl;
	return *this;
}



ostream &operator<< (ostream &output, const Paragraph s){
	Sentence *iterator;
	output << '\t';
	for (iterator = s.head; iterator!= NULL; iterator = iterator-> next){
		output << *iterator;
		output << ' ';
	}
	output << '\n';
	return output;
}

//Linked List
Paragraph Paragraph::first(){
	Paragraph retval;
	retval.head = new Sentence(*head);
	(retval.head)->next = NULL;
	return retval;
}

Paragraph Paragraph::rest(){
	Paragraph retval;
	Sentence *iter = head;
	if (head->head){
		iter = iter->next;
		retval.head = new Sentence(*iter);
		Sentence *copy  = retval.head;
		iter = iter->next;
		for (iter; iter; iter = iter->next){
			copy->next = new Sentence(*iter);
			copy = copy->next;
		}
	}
	return retval;
}

//
void Paragraph::show(){
	cout << "Show paragraph: ";
	for (Sentence *se = head; se->next; se = se->next){
		(*se).show();
	}
}
