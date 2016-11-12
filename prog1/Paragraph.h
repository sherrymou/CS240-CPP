#ifndef _PARAGRAPH_H_
#define _PARAGRAPH_H_
#include <iostream>
#include "Sentence.h"
#include "Story.h"
class Story;
class Sentence;

using namespace std;

class Paragraph{
	public:
	Paragraph();
	Paragraph(const Paragraph &it);
	Paragraph(const Sentence &it);
	~Paragraph(); 
	
	Sentence *head;
	Paragraph *next;

	//Methods
	void append(char in);
	
	//overloading
	Paragraph &operator+ (const Paragraph &other);
	Paragraph &operator+ (const Sentence &other);
	Story &operator+ (const Story &other);
	Paragraph &operator++ (); // ++ Paragraph
	Paragraph &operator++ (int); // Paragraph ++ 
	Paragraph &operator-- (); // -- Paragraph
	Paragraph &operator-- (int); // Paragraph -- 
	Paragraph &operator+ (int i);
	Paragraph &operator= (const Paragraph it);
	friend ostream &operator<< (ostream &output, const Paragraph s);
	
	//Linked list
	Paragraph first();
	Paragraph rest();
	
	void show();
};

#endif
