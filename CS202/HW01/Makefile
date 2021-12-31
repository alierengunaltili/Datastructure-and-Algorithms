run: ConsoleApplication2.o sorting.o
	g++ ConsoleApplication2.o sorting.o -o run

ConsoleApplication.o: ConsoleApplication2.cpp
	g++ main.cpp
sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp
clean:
	rm *.o run
