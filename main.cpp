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
#include <string>

#include "client.h"
#include "server.h"

using namespace std;


bool SendHellos(){
	
	string validIps[] = {"192.168.0.11","192.168.0.17","192.168.0.1"};
		for( int i = 0; i < sizeof(validIps)/sizeof(validIps[0]); i++){
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string(validIps[i]), 51885);
			send_socket.send_to(boost::asio::buffer("H",1),endpoint);
		}
}
void listenForNode(){
	string sensor = "temp";
	boost::array<char, 128> recv_buf;
	while(1) {
			
		boost::asio::ip::udp::endpoint sender_endpoint;
		size_t len = socket.receive_from(
		boost::asio::buffer(recv_buf), sender_endpoint);

		std::cout << "Recieved data from IPv4:" << sender_endpoint.address().to_string() << std::endl;
		std::cout.write(recv_buf.data(), len);	
			
		//Respong to message
		if(recv_buf.data() == "H"){
			send_socket.send_to(boost::asio::buffer(sensor,sensor.size()),sender_endpoint);	
		}
	}
}

/*
 * 
 */
int main(int argc, char** argv) {
	
	client();
	
	try{
		if (argc != 3){
			std::cerr << "Usage: programname <host> <port>" << std::endl;
		return 1;
		}
		boost::asio::io_service io_service;
		
		boost::asio::ip::udp::endpoint local_endpoint(
		boost::asio::ip::address::from_string(argv[1]), 
		boost::lexical_cast<int>(argv[2]));
		std::cout << "Local bind " << local_endpoint << std::endl;
		
			
		//boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::udp::v4(), 12345);
		
		//Recieve socket
		boost::asio::ip::udp::socket socket(io_service);
		socket.open(boost::asio::ip::udp::v4());
		socket.bind(local_endpoint); 
	
		//Send socket
		
		boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
		/*
		boost::asio::ip::udp::endpoint sender_endpoint(boost::asio::ip::address::from_string("192.168.0.1"), 51885);
		send_socket.send_to(boost::asio::buffer("hej",4),sender_endpoint);
		*/
		boost::array<char, 128> recv_buf;
		
		while(1) {
			
			boost::asio::ip::udp::endpoint sender_endpoint;
			size_t len = socket.receive_from(
			boost::asio::buffer(recv_buf), sender_endpoint);

			std::cout << "Recieved data from IPv4:" << sender_endpoint.address().to_string() << std::endl;
			std::cout.write(recv_buf.data(), len);	
			
			//send
			send_socket.send_to(boost::asio::buffer("hej",4),sender_endpoint);
			
		}
	
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	
    std::cout << "Program run completed!" << std::endl;
    return 0;
}



