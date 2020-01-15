# Makefile for project 1. will make use of make all to create executable named hash,
# Make run to fully run the program, make test to incrementaly test the program, and Make clean
# to clean all .o and executables.

CXX=g++
OBJECTS= HashEntry.o HashTable.o
CXXFLAGS = -std=c++11 -c -g -Wall

# all compiles both files and then links the object files to build the hash exe
all: $(OBJECTS)
	$(CXX) $(OBJECTS) -o hash
	
# creates the HashTable object file
HashTable.o: HashTable.cpp
	$(CXX) $(CXXFLAGS) HashTable.cpp

# creates the HashEntry object file
HashEntry.o: HashEntry.cpp
	$(CXX) $(CXXFLAGS) HashEntry.cpp

# function to compile build and run the program to save time testing	
run: all
	./hash
	
clean:
	$(RM) *o hash
