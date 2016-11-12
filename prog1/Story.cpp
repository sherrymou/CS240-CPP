#include "Story.h"
#include <fstream>
#include <iostream>

using namespace std;

//Constructor
Story::Story(){
	head = NULL;
//	cout <<"Called Story::Story() [default constructor]" << endl;
}

Story::Story(char *file) {
//	cout << "Called Story(ifstream&) constructor" << endl;
	ifstream myfile(file);
	char in;
	head = new Paragraph();
	Paragraph *iterator = head;
//	Paragraph *follow = head;
	while (myfile.get(in)) {
		if (in == '\t') {
			if (head != NULL) {
				iterator -> next = new Paragraph();
				iterator = iterator->next;
			}
		}
		else if (in != '\n' ){
			(*iterator).append(in);
		}
	}
	myfile.close();
}

ostream &operator<< (ostream &output, const Story s){
	Paragraph *iterator;
	for (iterator = s.head; iterator!= NULL; iterator = iterator-> next){
		if (iterator->head!=NULL){
			output << *iterator;
			output << endl;
		}
	}
//	output << '\t' << iterator << endl;
	return output;
}

void Story::save(char *file){
	ofstream myfile(file);
	myfile << *this;
	myfile.close();
}

//Copy constructor
Story::Story(const Story &it){
	if (it.head == NULL){
		head =NULL;
		return;
	}
	
	Paragraph *iter = it.head;
	head = new Paragraph(*iter);
	Paragraph *tmp = head;
	iter = iter->next;
	
	for (iter; iter; iter = iter->next){
		tmp -> next = new Paragraph(*iter);
		tmp = tmp -> next;
	}

//	cout << "Called Story::Story(const Story &it) [copy constructor]" << endl;
}

Story::Story(const Paragraph &it){
	head = new Paragraph(it);
//	cout << "Called Story::Story(const Paragraph &it) [copy constructor]" << endl;
}

//Destructor
Story::~Story(){
	if (head == NULL) return;
	Paragraph *iter = head;
	Paragraph *follow = head;
	for (iter;iter->next;iter = iter->next){
		follow = iter;
	}
	delete follow ->next;
	delete head;
//	cout << "Called Story::~Story() [destructor]" << endl;
}

//Overloading Operators
Story &Story::operator+ (const Story &other){
	Story *retval = new Story(*this);
	Paragraph *iter = retval->head;
	Paragraph *iters = other.head;
	
	for (iter;iter->next; iter= iter->next){}
	for (iters;iters;iters = iters->next){
		iter->next = new Paragraph(*iters);
		iter = iter->next;
	}
	
//	cout << "Called Story::operator+(Story): Will return a (new and bigger) Story." << endl;
	return *retval;
}

Story &Story::operator+ (const Paragraph &other){
	Story *retval = new Story(*this);
	Paragraph* iter = retval -> head;
	for (iter;iter->next;iter= iter->next){}
	iter->next = new Paragraph(other);
	return *retval;

//	cout << "Called Story::operator+(Paragraph): Will return a (new and bigger) Story." << endl;
}



// ++ Story
Story &Story::operator++ (){
//	cout << "Called Story::operator++(int) [prefix ++]. Will return this word in Pig Latin (if it isn't already)." << endl;
	Paragraph *iter = head;
	for (iter; iter; iter = iter->next){
		++(*iter);
		(*iter)+1;
	}
	return *this;

}


// Story ++ 
Story &Story::operator++ (int){
//	cout << "Called Story::operator++(int) [prefix ++]. Will return this word in Pig Latin (if it isn't already)."<< endl;
	Paragraph *iter = head;
	for (iter; iter; iter = iter->next){
		(*iter)++;
	}
	
	return *this;
}

// -- Story
Story &Story::operator-- (){
//	cout << "Called Story::operator--() [postfix --]. Will return this word in all lowercase." << endl;
	Paragraph *iter = head;
	for (iter; iter; iter = iter->next){
		--(*iter);
	}
	
	return *this;
}


// Story --
Story &Story::operator-- (int){
//	cout << "Called Story::operator--(int) [prefix --]. Will return this Word converted from Pig Latin to English." << endl;
	Paragraph *iter = head;
	for (iter; iter; iter = iter->next){
		(*iter)--;
	}
	return *this;
}


Story &Story::operator+ (int i){
//	cout << "Called Story::operator+(int): Will return this Story with initial letters of Sentences capitalized." << endl;
	if ( i == 1){
//		cout << "Show operator + int i";
		Paragraph *iter = head;
		for (iter; iter; iter= iter->next){
			(*iter) +1;
		}
	}
	return *this;
}


Story &Story::operator= (const Story it){
	if (it.head == NULL){
		head =NULL;
		return *this;
	}
	
	Paragraph *iter = it.head;
	head = new Paragraph(*iter);
	Paragraph *tmp = head;
	iter = iter->next;
	
	for (iter; iter; iter = iter->next){
		tmp -> next = new Paragraph(*iter);
		tmp = tmp -> next;
	}
//	cout << "Called Story::operator=(Story) [assignment operator]." << endl;
	return *this;
}

//Linked list
Story Story::first(){
	Story retval;
	retval.head = new Paragraph(*(head->next));
	(retval.head)->next = NULL;
	return retval;
	
}

Story Story::rest(){
	Story retval;
	Paragraph *iter = head->next;
	if (head){
		iter = iter->next;
		retval.head = new Paragraph(*iter);
		Paragraph *copy  = retval.head;
		iter = iter->next;
		for (iter; iter; iter = iter->next){
			copy->next = new Paragraph(*iter);
			copy = copy->next;
		}
	}
	return retval;
}


//
void Story::show(){
}
