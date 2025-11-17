CC=g++
CCFLAGS= -c -g -Wall
HEADERS= Employee.h BN.h BT.h BST.h DB.h Filter.h 
OBJS=main.o Employee.o DB.o
bst: $(OBJS) 
	$(CC) -o $@ $(OBJS) 
%.o: %.cpp $(HEADERS)
	$(CC) $(CCFLAGS) $< 
clean:
	rm -f *.o bst
