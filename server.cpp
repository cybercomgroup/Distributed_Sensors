/* 
 * File:   server.cpp
 * Author: Laving
 *
 * Created on February 32, 2017, 9:32 AM
 */
#include "server.h"
#include <iostream>

using namespace std;

 
void server(){listenForNode();}
 
 
void listenForNode(){
	string sensor = "temp";
	boost::array<char, 128> recv_buf;
	while(1) {
			
		boost::asio::ip::udp::endpoint sender_endpoint;
		size_t len = socket.receive_from(
		boost::asio::buffer(recv_buf), sender_endpoint);

		std::cout << "Recieved data from IPv4:" << sender_endpoint.address().to_string() << std::endl;
		std::cout.write(recv_buf.data(), len);	
			
		
		
		//send
		send_socket.send_to(boost::asio::buffer(sensor,sensor.size()),sender_endpoint);	
		}
}

void sendHellos(){
	
		string validIps[] = {"192.168.0.11","192.168.0.17","192.168.0.1"};
		for( int i = 0; i < sizeof(validIps)/sizeof(validIps[0]); i++){
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string(validIps[i]), 51885);
			send_socket.send_to(boost::asio::buffer("Hello",5),endpoint);
		}
}