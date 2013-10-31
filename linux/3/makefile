file:main.o sys_file.o
	g++ -o file main.o sys_file.o
main.o:main.cpp sys_file.h
	g++ -c main.cpp
sys_file.o:sys_file.cpp sys_file.h file_interface.h
	g++ -c sys_file.cpp
clean:
	rm file main.o sys_file.o
