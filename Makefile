main: main.cpp logger.o helpfunc.o
	g++ -std=c++11 -g main.cpp -o main logger.o helpfunc.o  -L/usr/local/lib/ -lboost_system -lpthread 

logger.o: logger.cpp logger.h
	g++ -std=c++11 -c logger.cpp
	
helpfunc.o: helpfunc.cpp helpfunc.h
	g++ -std=c++11 -c helpfunc.cpp
