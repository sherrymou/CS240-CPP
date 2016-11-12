#include <iostream>
#include <fstream>
#include "Word.h"
#include "Sentence.h"
#include "Paragraph.h"
#include "Story.h"

using namespace std;

int main ( ) {
	Word wd1;
	Word wd2;
	Sentence st1;
	Sentence st2;
	
	wd1.append('F');
	wd1.append('l');
	wd1.append('o');
	wd1.append('o');
	wd1.append('r');
	cout << "====Wd1 is  "<< wd1 << endl;
	
	wd2.append('a');
	wd2.append('l');
	wd2.append('c');
	wd2.append('o');
	wd2.append('n');
	wd2.append('d');
	cout << "====Wd2 is  " << wd2 << endl;
	
	st2.append('A');
	st2.append(' ');	
	st2.append('S');
	st2.append('e');	
	st2.append('n');
	st2.append(' ');	
	st2.append('T');
	st2.append('e');	
	st2.append('.');
	cout << "====st2 is  " << st2 << endl;

	Paragraph pr;
	pr.append('A');
	pr.append(' ');	
	pr.append('P');
	pr.append('i');	
	pr.append(' ');
	pr.append('o');	
	pr.append('.');
	pr.append(' ');	
	pr.append('B');
	pr.append('e');
	pr.append(' ');	
	pr.append('h');
	pr.append('a');	
	pr.append('p');
	pr.append('p');	
	pr.append('y');
	pr.append('!');
	
	cout << "====pr is  " << pr << endl;
	
	Story mystory = Story("Brady.txt");


	st1 = wd1+wd2;

	cout << "wd1+wd2 " << st1 << endl;
	cout << "wd1+st2  " << wd1+st2 << endl;

	cout << "st2 + wd2 " << st2 + wd2 << endl; 
	cout << "st1 + st2 " << st1 + st2 << endl;
	cout << "st2 + pr " << st2 + pr << endl;
	
	cout << "pr + st1 " << endl << pr+st1 << endl; 
	cout << "pr + pr " << endl << pr + pr << endl;
	cout << "pr + mystory " << endl << pr + mystory << endl; 
	
	cout << "mystory + mystory" << endl << mystory+mystory << endl;
	cout << "mystory + pr "<< endl <<mystory+pr << endl;
	
	Sentence st3 = Sentence (wd1);
	cout << "constructor Sentence (word) " << endl << st3 << endl;
	Paragraph pr1 = Paragraph(st2);
	cout << "constructor Paragraph (sentence) " << endl << pr1 << endl;
	Story sr = Story(pr);
	cout << "constructor Story (paragraph) " << endl << sr << endl;


	cout << "++wd1 " << ++wd1 << endl;
	cout << "--wd1 " << --wd1 << endl;
	cout << "++wd2 " << ++wd2 << endl;
	cout << "--wd2 " << --wd2 << endl;

	cout << "++st1 " << ++st1 << endl;
	cout << "--st1 " << --st1 << endl;
	
	cout << "++pr " << ++pr << endl;
	cout << "--pr " << --pr << endl;

	cout << "wd1++  "<< wd1++ << endl;
	cout << "wd1--  "<< wd1-- << endl;
	cout << "wd1+1 "<< wd1+1 << endl;

	cout << "st1++  "<< st1++ << endl;
	cout << "st2-- "<< st2-- << endl;
	cout << "st2+1 "<< st2+1 << endl;

	cout << "pr++ " << pr++ << endl;
	cout << "pr-- " << pr-- << endl;
	cout << "pr+1 " << pr+1 << endl;



	cout << "st2.first()" << st2.first() << endl;
	cout << "st2.rest()" << st2.rest() << endl;
	
	cout << "pr.first()" << pr.first() << endl;
	cout << "pr.rest()" << pr.rest() << endl;


	mystory.save("out.txt");
	++mystory;
	mystory.save("++mystory.txt");
	--mystory;
	mystory.save("--mystory.txt");
	mystory++;
	mystory.save("mystory++.txt");
	mystory--;
	mystory.save("mystory--.txt");
	
	cout << "mystory.first()" << endl << mystory.first() << endl;
	cout << "mystory.rest()" << endl << mystory.rest() << endl;
	
	mystory = mystory+1;
	mystory.save("mystory+1.txt");

}

