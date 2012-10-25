# A simple makefile for CSE 100 P1

#use g++ for everything
CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -g -Wall

#include debugging symbols in executable
LDFLAGS= -g	

rst: test_RST.o countint.o
	g++ -o rst test_RST.o countint.o

benchtree: benchtree.cpp countint.o
	g++ -g -o benchtree benchtree.cpp countint.o

test_RST.o: BST.hpp BSTNode.hpp BSTIterator.hpp RST.hpp RSTNode.hpp

countint.o: countint.cpp countint.hpp

clean:
	mkdir -p trash/ > /dev/null && mv -f *.gch *.o test_BST trash/ > /dev/null
