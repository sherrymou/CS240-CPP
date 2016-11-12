all: Radio

Radio: driver.o Time.o Song.o Radio.o
	g++ -std=c++0x -g driver.o Time.o Song.o Radio.o -o Radio
	
driver.o: driver.cpp
	g++ -std=c++0x -g -c driver.cpp

Time.o: Time.cpp
	g++ -std=c++0x -g -c Time.cpp
	
Song.o: Song.cpp
	g++ -std=c++0x -g -c Song.cpp
	
Radio.o: Radio.cpp
	g++ -std=c++0x -g -c Radio.cpp
	
clean:
	rm -f *.o Radio
