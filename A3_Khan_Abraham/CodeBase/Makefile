a.out: main.o Book.o DVD.o library.o LibraryItem.o magazine.o Member.o transaction.o
	g++ -g -o a.exe main.o Book.o DVD.o library.o LibraryItem.o magazine.o Member.o transaction.o

main.o: main.cpp Book.h DVD.h library.h LibraryItem.h magazine.h Member.h transaction.h
	g++ -c -g main.cpp

Book.o: Book.cpp Book.h LibraryItem.h
	g++ -c -g Book.cpp

DVD.o: DVD.cpp DVD.h LibraryItem.h
	g++ -c -g DVD.cpp

library.o: library.cpp library.h LibraryItem.h Member.h transaction.h
	g++ -c -g library.cpp

LibraryItem.o: LibraryItem.cpp LibraryItem.h
	g++ -c -g LibraryItem.cpp

magazine.o: magazine.cpp magazine.h LibraryItem.h
	g++ -c -g magazine.cpp

Member.o: Member.cpp Member.h 
	g++ -c -g Member.cpp

transaction.o: transaction.cpp transaction.h
	g++ -c -g transaction.cpp

clean:
	del -f *.o a.out a.exe