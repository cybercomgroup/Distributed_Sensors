
main: main.cpp client.o server.o helpfunc.o
	g++ -std=c++11 -g main.cpp -o main client.o server.o helpfunc.o -L/usr/local/lib/ -lboost_system -lpthread

client.o: client.cpp client.h
	g++ -c client.cpp

server.o: server.cpp server.h
	g++ -c server.cpp

helpfunc.o: helpfunc.cpp helpfunc.h
	g++ -std=c++11 -c helpfunc.cpp
