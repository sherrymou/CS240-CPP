all: Lab8

Lab8: Graph.o Lab8.o
	g++ -std=c++0x Graph.o Lab8.o -o Lab8

Lab8.o: Lab8.cpp
	g++ -std=c++0x -c Lab8.cpp
	
Graph.o: Graph.cpp
	g++ -std=c++0x -c Graph.cpp

clean:
	rm -f *.o Lab8
