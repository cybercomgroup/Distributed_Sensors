/*
 * File:   main.cpp
 * Author: Valentin Lindblad
 *
 * Created on February 14, 2017, 9:32 AM
 */

#include <cstdlib>
#include <cstdio>


#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <stdio.h>
#include <unistd.h>

#include "datatable.cpp"

using namespace std;

/*

 *
 */
int main(int argc, char** argv) {

		DeviceTable dt;
		dt.add("test","temp");
		dt.add("abc","temp");
		dt.add("toobe","temp");
		//sleep(2);
		dt.updateDeviceDowntime("toobe");
		dt.getValidIP();
		//dt.add("valle","temp");
		dt.print();


    std::cout << "Program run completed!" << std::endl;
    return 0;
}
