main: main.cpp
	g++ -g main.cpp -o main -L/usr/local/lib/ -lboost_system -lpthread
