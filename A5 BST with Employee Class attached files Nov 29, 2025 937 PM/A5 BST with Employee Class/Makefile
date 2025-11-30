bst.exe: main.o Employee.o
	g++ -g main.o Employee.o

main.o: main.cpp BinaryTree.h Employee.h ErrorCode.h 
	g++ -c -g main.cpp

Employee.o: Employee.cpp Employee.h 
	g++ -c -g Employee.cpp

clean:
	rm *.o *.exe