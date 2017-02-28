/*
 * File:   logger.h
 * Author: Lindblad
 *
 * Created on February 28, 2017, 14:10
 */

 #include <string>

#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED
bool writeTopRow(std::string logFilename, std::string logText);
bool logger(std::string logFilename, int waittime);
#endif // LOGGER_H_INCLUDED
