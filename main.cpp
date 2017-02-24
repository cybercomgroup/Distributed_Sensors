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
#include <boost/ref.hpp>
#include <string>

#include "client.h"
#include "server.h"

using namespace std;


struct tableRow
{
	string ip;
	string sensor;
};


bool sendHellos(boost::asio::io_service &io_service, boost::asio::ip::udp::endpoint &local_endpoint){
	
	string validIps[] = {"192.168.0.11","192.168.0.17","192.168.0.1", "169.254.191.147"};
		for( int i = 0; i < sizeof(validIps)/sizeof(validIps[0]); i++){
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string(validIps[i]), 58292);
			send_socket.send_to(boost::asio::buffer("H",1),endpoint);
		}
}
void reciever(boost::asio::io_service &io_service, boost::asio::ip::udp::endpoint &local_endpoint){
	
	//Set up
		
	boost::asio::ip::udp::socket socket(io_service);
	socket.open(boost::asio::ip::udp::v4());
	socket.bind(local_endpoint); 
		
	string message,command,variable,response ="Not a valid command!";
		
	string sensor = "temp";
	boost::array<char, 128> recv_buf;
	while(1) {
				
		boost::asio::ip::udp::endpoint sender_endpoint;
		size_t len = socket.receive_from(
		boost::asio::buffer(recv_buf), sender_endpoint);

		std::cout << "Recieved data from IPv4: " << sender_endpoint.address().to_string() << std::endl;
		std::cout.write(recv_buf.data(), len);	
		
		//Make message more manageable
		strcpy(recv_buf.data(),message);
		command = str.substr(0,1);
		variable = str.substr(1);
		cout<<"Command recieved was: " << command<<endl;
		cout<<"Vaiable recieved was: " << command<<endl;
		
		//Respond to messages
		//Respond to hello
		if(strcmp(command, "H") == 0){
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			response = sensor;
			//Insert into my table
		}
		//Write to console table
		if(strcmp(command, "W") == 0){
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			response = "Exiting now"; 	
		}
		//Exit
		if(strcmp(command, "E") == 0){
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			response = "Exiting now"; 
		}
		send_socket.send_to(boost::asio::buffer(response,response.size()),sender_endpoint);
	}
}

/*
 * 
 */
int main(int argc, char** argv) {
	
	
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
		
		
		
		//Hello aspects
		//std::vector<tableRow> nodeTable; function(std::vector<tableRow>* nodeTable)
		sendHellos(boost::ref(io_service), boost::ref(local_endpoint));
		reciever(boost::ref(io_service), boost::ref(local_endpoint), &nodeTable);
		
		
		
		//boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::udp::v4(), 12345);
		
		//Recieve socket
		boost::asio::ip::udp::socket socket(io_service);
		socket.open(boost::asio::ip::udp::v4());
		socket.bind(local_endpoint); 
	
		//Send socket
		
		boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));

		//boost::asio::ip::udp::endpoint sender_endpoint(boost::asio::ip::address::from_string("192.168.0.1"), 51885);
		//send_socket.send_to(boost::asio::buffer("hej",4),sender_endpoint);
		
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
	
	}catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	
    std::cout << "Program run completed!" << std::endl;
    return 0;
}



