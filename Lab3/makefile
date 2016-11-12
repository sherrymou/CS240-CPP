all: Bank

Bank: Bank.o Customer.o Lab3.o
	g++ Bank.o Customer.o Lab3.o -o Bank

Bank.o: Bank.cpp
	g++ -c Bank.cpp

Customer.o: Customer.cpp
	g++ -c Customer.cpp
	
Lab3.o: Lab3.cpp
	g++ -c Lab3.cpp

clean:
	rm -f *.o Bank
