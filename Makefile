main: main.cpp client.o
	g++ -g main.cpp -o main client.o -L/usr/local/lib/ -lboost_system -lpthread 

client.o: client.cpp client.h
	g++ -c client.cpp