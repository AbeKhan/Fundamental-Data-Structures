a.out: main.o static.o
	g++ -g main.o static.out

main.o: main.cpp static.h
	g++ -g -c main.cpp static.h

static.o: static.cpp static.h
	g++ -g -c static.cpp static.h

clean: 
	rm *.o a.out