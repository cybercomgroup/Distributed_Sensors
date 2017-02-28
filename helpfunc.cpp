/* 
 * File:   helpfunc.cpp
 * Author: Lindblad
 *
 * Created on February 28, 2017, 11:52 AM
 */
#include "helpfunc.h"
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <stdio.h>

using namespace std;


std::string  getTemp(){
        double T;
				FILE * temperatureFile;
        temperatureFile = fopen ("/sys/class/thermal/thermal_zone0/temp", "r");
        if (temperatureFile == NULL)
                std::cout << "Temperature reading could not be done." << std::endl;
        fscanf (temperatureFile, "%lf", &T);
        T /= 1000;
	fclose (temperatureFile);
	return(std::to_string(T));
}

std::string getTime(){
	std::chrono::time_point<std::chrono::system_clock> current;
	current = std::chrono::system_clock::now();
	std::time_t current_time = std::chrono::system_clock::to_time_t(current);
	std::string s = std::ctime(&current_time);
	s.erase(s.length()-1);
	return(s);
}

std::time_t getEpoch(){
	std::chrono::time_point<std::chrono::system_clock> current;
	current = std::chrono::system_clock::now();
	return(std::chrono::system_clock::to_time_t(current));
}