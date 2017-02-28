/*
 * File:   main.cpp
 * Author: Valentin Lindblad
 *
 * Created on February 14, 2017, 9:32 AM
 */

#include <cstdlib>
#include <cstdio>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <stdio.h>

#include "datatable.cpp"

using namespace std;

/*

 *
 */
int main(int argc, char** argv) {

		DeviceTable dt;
		dt.add("test\n");
		dt.add("abc\n");
		dt.print();


    std::cout << "Program run completed!" << std::endl;
    return 0;
}
