CPPFLAGS=-I../src -I../include
CXXFLAGS=-std=c++17 -Wall -O2
#OBJECTS = Utilities.o optimizer.o

all: test
test: test.o
	g++ test.o -o test

test.o: optimizer.o Utilities.o
	g++ -l Utilities.o -l optimizer.o -c test.cpp $(CPPFLAGS)
Utilities.o: ../src/Utilities.cpp
	g++ -c ../src/Utilities.cpp
optimizer.o: ../src/optimizer.cpp
	g++ -c ../src/optimizer.cpp
clean:
	rm test test.o Utilities.o optimizer.o
