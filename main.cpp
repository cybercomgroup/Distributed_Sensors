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
#include <iostream>
#include <thread>
#include "helpfunc.h"
#include "logger.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {


	thread t1 (logger, "log0001", 500); // funcname, logfilename, #of ms between logging each data point
	t1.join();

    return 0;
}

