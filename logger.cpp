/* 
 * File:   helpfunc.cpp
 * Author: aalex & Lindblad
 *
 * Created on February 28, 2017, 13:49
 */
#include "logger.h"
#include "helpfunc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

bool logger(std::string logFilename, int waittime){
	int i = 20;
	while(0 < i--){
		writeTopRow(logFilename, getTime() + string("	CPU temp: 	") + getTemp() + string("C") );
		usleep( waittime * 1000 );
	}
	return 1;
}

bool writeTopRow(std::string logFilename, std::string logText){
	ofstream logfile;
    logfile.open(logFilename, ios::app);
    logfile << logText << std::endl;
	logfile.close();
	return(1);
}