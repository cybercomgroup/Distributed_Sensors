/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: aalex & Lindblad
 *
 * Created on den 15 februari 2017, 09:46
 */

 
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/ref.hpp>
#include "helpfunc.h"
#include "logger.h"
#include "network.h"




using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	boost::asio::io_service io_service;
	boost::asio::ip::udp::endpoint local_endpoint( boost::asio::ip::address::from_string(argv[1]), boost::lexical_cast<int>(argv[2]));
	thread loggerThread (logger, "log0001", 500); // funcname, logfilename, #of ms between logging each data point
	thread networkRecieveThread (networkRecieve, 500, boost::ref(io_service), boost::ref(local_endpoint), boost::lexical_cast<int>(argv[2])); // Will run about 2 times every second
	thread networkHelloThread (networkHello, 20000, boost::ref(io_service), boost::ref(local_endpoint), boost::lexical_cast<int>(argv[2])); // Will run about 2 times every second
	loggerThread.join();
	networkRecieveThread.join();
	networkHelloThread.join();

    return 0;
}

