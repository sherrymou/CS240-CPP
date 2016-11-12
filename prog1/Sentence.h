#ifndef _SENTENCE
#define _SENTENCE
#include <iostream>
#include "Word.h"
#include "Paragraph.h"
class Paragraph;
class Word;

using namespace std;

class Sentence{
	public:
	Sentence();
	Sentence (const Sentence &it);
	Sentence (const Word &it);
	~Sentence();
	
	//Elements
	Word *head;
	Sentence *next;
	char punctuation;

	//Methods
	void append(char in);
	
	//overloading
	Paragraph &operator+ (const Sentence &other);
	Sentence &operator+ (const Word &other);
	Paragraph &operator+ (const Paragraph &other);
	Sentence &operator++ (); // ++ Sentence
	Sentence &operator++ (int); // Sentence ++ 
	Sentence &operator-- (); // -- Sentence
	Sentence &operator-- (int); // Sentence -- 
	Sentence &operator+ (int i);
	Sentence &operator= (const Sentence other);
	friend ostream &operator<< (ostream &output, const Sentence s);
	
	//Linked List
	Sentence first();
	Sentence rest();
	
	void show();
	//Sentence *dummy;
};

#endif
