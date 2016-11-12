all: Tree

Tree: tree.o lab6.o
	g++ -std=c++0x tree.o lab6.o -o Tree

tree.o: tree.cpp
	g++ -std=c++0x -c tree.cpp
	
lab6.o: lab6.cpp
	g++ -std=c++0x -c lab6.cpp

clean:
	rm -f *.o Tree
