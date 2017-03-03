
main: main.cpp server.o helpfunc.o logger.o
	g++ -std=c++11 -g main.cpp -o main server.o helpfunc.o logger.o -L/usr/local/lib/ -lboost_system -lpthread

server.o: server.cpp server.h
	g++ -std=c++11 -g -c server.cpp -L/usr/local/lib/ -lboost_system -lpthread

helpfunc.o: helpfunc.cpp helpfunc.h
	g++ -std=c++11 -c helpfunc.cpp

logger.o: logger.cpp logger.h
	g++ -std=c++11 -c logger.cpp
