/*
 * File:   network.h
 * Author: Laving & Mårlind & Lindblad
 *
 * Created on February 14, 2017, 9:32 AM
 */



#include <cstdlib>
#include <cstdio>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/ref.hpp>
#include <string>
#include <iostream>
#include <unistd.h>

#include <cstdlib>
#include <cstdio>


#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED
void networkRecieve(int waittime, boost::asio::io_service &io_service, boost::asio::ip::udp::endpoint &local_endpoint, unsigned short port);
void networkHello(int waittime, boost::asio::io_service &io_service, boost::asio::ip::udp::endpoint &local_endpoint, unsigned short port);
void reciever(boost::asio::io_service &io_service, boost::asio::ip::udp::endpoint &local_endpoint,unsigned short recievePort);
void sendHellos(boost::asio::io_service &io_service, boost::asio::ip::udp::endpoint &local_endpoint,unsigned short port);


#endif // NETWORK_H_INCLUDED