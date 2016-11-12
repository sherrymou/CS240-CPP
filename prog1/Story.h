#ifndef _STORY_H_
#define _STORY_H_

#include <iostream>
#include <fstream>
#include "Paragraph.h"
class Paragraph;

using namespace std;

class Story{
	public:
	Story();
	Story(char *file);
	Story(const Story &it);
	Story(const Paragraph &it);
	~Story();
	
	Paragraph  *head;
	
	
	//overloading
	Story &operator+ (const Story &other);
	Story &operator+ (const Paragraph &other);
	Story &operator++ (); // ++ story
	Story &operator++ (int); // story ++ 
	Story &operator-- (); // -- story
	Story &operator-- (int); // story -- 
	Story &operator+ (int i);
	Story &operator= (const Story other);
	friend ostream &operator<< (ostream &output, const Story s);
	
	//Linked list
	Story first();
	Story rest();
	
	//
	void save(char *file);
	
	//For internal
	void show();
	
};

#endif
