#target: dependencies
#tab command about how to create the target
#start with a final target, executable
#executable: dependencies, list all .o files
#command: how to create the executable
#		a command line must start with a tab
#g++ -g main.o Song.o -o Song.exe --> call a linker
#	linking stage requires -o option
Song.exe: main.o Song.o
	g++ -g main.o Song.o -o Song.exe

#for each .o file, give instructions on how to create it
#if main.cpp or Song.h is changed, rebuild main.o
main.o: main.cpp Song.h #Song.cpp is not included because main.cpp does not need to know how the functions work, It only needs the function prototype to be able to call the functions and use them
	g++ -g -c main.cpp 
#g++ command line: never include .h --> Song.h is already included
#Why NOT include Song.cpp?
#-c: eliminate linking from the entire complication processes
#-g: create information for the debugger.
#						the main goal of complication-->create a binary code for a function
#1. Check the time stampe of the target : t1
#2. Check the timestamp of the dependencies : t2, t3, ...
#3. if t1 < t2 or t3, or ... ==> rebuild the target
Song.o: Song.cpp 
	g++ -g -c Song.cpp 

#clean: not a target, but for clean up and rebuild your project
#make clean
#	del: delete file(s) for Windows
#	rm: 				for MacOS or Linux
#	*.o: * is called wildcard
clean: 
	del *.o Song.exe