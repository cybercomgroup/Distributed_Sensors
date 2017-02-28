main: main.cpp client.o server.o
	g++ -std=c++11 -g main.cpp -o main client.o server.o -L/usr/local/lib/ -lboost_system -lpthread 

client.o: client.cpp client.h
	g++ -c client.cpp

server.o: server.cpp server.h
	g++ -c server.cpp
