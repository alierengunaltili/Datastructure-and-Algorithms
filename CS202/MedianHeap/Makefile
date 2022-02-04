CC=g++
CFLAGS=-c -Wall
target: first
first: main.o MinHeap.o MaxHeap.o MedianHeap.o
	$(CC) main.o MinHeap.o MaxHeap.o MedianHeap.o -o q1
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
MinHeap.o: MinHeap.cpp
	$(CC) $(CFLAGS) MinHeap.cpp
MaxHeap.o: MaxHeap.cpp
	$(CC) $(CFLAGS) MaxHeap.cpp
MedianHeap.o: MedianHeap.cpp
	$(CC) $(CFLAGS) MedianHeap.cpp
clean:
	rm *o hw3
