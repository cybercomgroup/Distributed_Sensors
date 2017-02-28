
main: main.cpp helpfunc.o
	g++ -std=c++11 -g main.cpp -o main client.o server.o helpfunc.o

helpfunc.o: helpfunc.cpp helpfunc.h
	g++ -std=c++11 -c helpfunc.cpp
