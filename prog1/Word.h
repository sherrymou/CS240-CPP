#ifndef _WORD
#define _WORD
#include <iostream>
#include "Sentence.h"
#include "Letter.h"

using namespace std;

class Sentence;
class Letter;

class Word{
	public:
	Word();
	Word(const Word &it);
	~Word();
	
	//Elements
	Letter *head;
	Word * next;
	int pig;
	//Access
	void insert(char ch);
	void insert(int pos, char ch);
	void remove(int pos, char ch);

	//Methods
	void append(char in);

	//overloading
	Sentence &operator+ (const Word &other);
	Sentence &operator+ (const Sentence &other);
	Word &operator++ (); // ++ Word
	Word &operator++ (int); // Word ++ 
	Word &operator-- (); // -- Word
	Word &operator-- (int); // Word -- 
	Word &operator+ (int i);
	Word &operator= (const Word other);
	friend ostream &operator<< (ostream& os, const Word s);

	//temp
	
	void show();
};
#endif
