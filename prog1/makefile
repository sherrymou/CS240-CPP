all: Story

Story: driver.o Paragraph.o Sentence.o Word.o Story.o Letter.o
	g++ -g driver.o Paragraph.o Sentence.o Word.o Story.o Letter.o -o Story

driver.o: driver.cpp
	g++  -g -c driver.cpp
	
Paragraph.o: Paragraph.cpp
	g++ -g -c Paragraph.cpp

Sentence.o: Sentence.cpp
	g++ -g -c Sentence.cpp
	
Word.o: Word.cpp
	g++ -g -c Word.cpp

Story.o: Story.cpp
	g++ -g -c Story.cpp

Letter.o: Letter.cpp
	g++ -g -c Letter.cpp

clean:
	rm -f *.o Story
