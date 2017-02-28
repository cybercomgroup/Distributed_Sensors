main: main.cpp client.o server.o
	g++ -g main.cpp -o main client.o server.o -L/usr/local/lib/ -lboost_system -lpthread
	
server.o: server.cpp server.h
	g++ -c server.cpp
