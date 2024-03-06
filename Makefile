main_test.exe: main_test.o voce.o set_element_error.o
	g++ -std=c++0x main_test.o voce.o set_element_error.o -o main_test.exe

main_test.o: main_test.cpp set.h
	g++ -std=c++0x -c main_test.cpp -o main_test.o

voce.o: voce.cpp
	g++ -std=c++0x -c voce.cpp -o voce.o

set_element_error.o: set_element_error.cpp
	g++ -std=c++0x -c set_element_error.cpp -o set_element_error.o
