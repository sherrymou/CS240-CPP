#ifndef _LETTER 
#define _LETTER 
#include <iostream>
#include "Word.h"
class Letter;

using namespace std;

class Word;
class Letter;

class Letter {
public:
	Letter();
	Letter(char in);
	Letter(const Letter &it);
	~Letter();

	//Elements
	char letter;
	Letter * next;

	//Methods
	void append(char in);
	Letter &operator= (const Letter &ther);	
	//friend ostream &operator << (ostream &output, const Letter &le)
};
#endif
