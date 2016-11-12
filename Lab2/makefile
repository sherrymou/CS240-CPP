all: Bank

Bank: MouKeniAccountFunctions.o Lab2.o
	g++ MouKeniAccountFunctions.o Lab2.o -o Bank

MouKeniAccountFunctions.o: MouKeniAccountFunctions.cpp
	g++ -c MouKeniAccountFunctions.cpp

Lab2.o: Lab2.cpp
	g++ -c Lab2.cpp

clean:
	rm -f *.o Bank
