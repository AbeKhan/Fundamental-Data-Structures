main.exe: Deque.o main.o
	g++ -g Deque.o main.o -o main.exe

Deque.o: Deque.cpp Deque.hpp
	g++ -c -g Deque.cpp

main.o: Deque.hpp main.cpp
	g++ -c -g main.cpp

clean:
	rm *.o main.exe

