A6.exe: main.o Heap.o
	g++ -g main.o Heap.o -o A6.exe

main.o: main.cpp Heap.h
	g++ -c -g main.cpp

Heap.o: Heap.cpp Heap.h 
	g++ -c -g Heap.cpp