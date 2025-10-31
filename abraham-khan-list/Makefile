a.out: list.o main.o
	g++ -g list.o main.o

list.o: list.cpp list.h
	g++ -c -g list.cpp

main.o: list.h main.cpp
	g++ -c -g main.cpp

clean:
	rm *.o a.out

