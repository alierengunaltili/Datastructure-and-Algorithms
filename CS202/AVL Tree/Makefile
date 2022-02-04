CC=g++
CFLAGS=-c -Wall
target: first
first: main.o AVLTree.o analysis.o
	$(CC) main.o AVLTree.o analysis.o -o q2
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
AVLTree.o: AVLTree.cpp
	$(CC) $(CFLAGS) AVLTree.cpp
analysis.o: analysis.cpp
	$(CC) $(CFLAGS) analysis.cpp
clean:
	rm *o hw3
