all: Radio

Radio: driver.o Time.o Song.o Radio.o HashTable.o Heap.o
	g++ -std=c++0x -g driver.o Time.o Song.o Radio.o Heap.o HashTable.o -o Radio
	
driver.o: driver.cpp
	g++ -std=c++0x -g -c driver.cpp

Time.o: Time.cpp
	g++ -std=c++0x -g -c Time.cpp
	
Song.o: Song.cpp
	g++ -std=c++0x -g -c Song.cpp
	
Radio.o: Radio.cpp
	g++ -std=c++0x -g -c Radio.cpp
	
HashTable.o: HashTable.cpp
	g++ -std=c++0x -g -c HashTable.cpp
	
Heap.o: Heap.cpp
	g++ -std=c++0x -g -c Heap.cpp
	
clean:
	rm -f *.o Radio
