/*
 * File:   client.cpp
 * Author: Laving & Mårlind
 *
 * Created on February 14, 2017, 9:32 AM
 */
#include "client.h"
#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

using namespace std;


 void wait(int seconds) {
   boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
 }

 void client(){
    while(1) {
      wait(1);
	    std::cout << "CLINET HERE" << std::endl;
    }
 }
