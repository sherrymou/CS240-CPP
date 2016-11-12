#
# Specifiy the target
all:	Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Hello:	Mou_Keni_Hello.o Mou_Keni_Hello_Class.o
	g++  Mou_Keni_Hello.o Mou_Keni_Hello_Class.o -o Hello.exe

# Specify how the object files should be created from source files
Mou_Keni_Hello_Class.o:		Mou_Keni_Hello_Class.cpp
	g++ -c Mou_Keni_Hello_Class.cpp


Mou_Keni_Hello.o: 	Mou_Keni_Hello.cpp
	g++ -c Mou_Keni_Hello.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Hello.exe

