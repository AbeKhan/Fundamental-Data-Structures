bank.exe: Account.o main.o Savings.o Checking.o
	g++ Account.o main.o Savings.o Checking.o -o bank.exe

Account.o: Account.h Account.cpp
	g++ -c -g Account.cpp

Savings.o: Account.h Savings.h Savings.cpp
	g++ -c -g Savings.cpp

Checking.o: Account.h Checking.h Checking.cpp
	g++ -c -g Checking.cpp

main.o: main.cpp Account.h
	g++ -c -g main.cpp

clean:
	del *.o bank.exe

