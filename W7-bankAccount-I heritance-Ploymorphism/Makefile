bank.exe: Account.o main.o
	g++ Account.o main.o -o bank.exe

Account.o: Account.h Account.cpp
	g++ -c -g Account.cpp

main.o: main.cpp Account.h
	g++ -c -g main.cpp

clean:
	del *.o bank.exe

