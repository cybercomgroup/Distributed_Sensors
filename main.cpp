/*
 * File:   main.cpp
 * Author: Team bäst
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
#include <unistd.h>
#include <stdlib.h>
#include <thread>

#include "datatable.cpp"
#include "server.h"
#include "helpfunc.h"
#include "logger.h"

using namespace std;

//Globals:
string sensor;
DeviceTable dt;
bool run = true;

void sendHellos(boost::asio::io_service &io_service, boost::asio::ip::udp::endpoint &local_endpoint,unsigned short port){
	while(run)
	{
		usleep(1000);


		string* validIps = dt.getValidIP();
		int size = atoi(validIps[0].c_str());
		//string* validIps[] = {"192.168.0.1","192.168.0.11","192.168.0.15","192.168.0.17","169.254.191.147"};
		for( int i = 1; i < size; i++){
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string(validIps[i]), port);
			send_socket.send_to(boost::asio::buffer("H"+sensor,(sensor.size()+1)),endpoint);
		}
	}
}

void reciever(boost::asio::io_service &io_service, boost::asio::ip::udp::endpoint &local_endpoint,unsigned short recievePort){

	//Set up
	boost::asio::ip::udp::socket socket(io_service);
	socket.open(boost::asio::ip::udp::v4());
	socket.bind(local_endpoint);

	string command,variable,response ="Not a valid command!";

	boost::array<char, 128> recv_buf;
	while(1) {

		boost::asio::ip::udp::endpoint sender_endpoint;
		size_t len = socket.receive_from(
		boost::asio::buffer(recv_buf), sender_endpoint);

		std::cout << "Recieved data from IPv4: " << sender_endpoint.address().to_string() << std::endl;
		//std::cout << recv_buf.data() << endl;

		sleep(1);
		//Make message more manageable
		string message(recv_buf.data(), len);
		command = message.substr(0,1);
		variable = message.substr(1);
		cout<<"Message recieved was: " << message<<endl;

		//Respond to messages
		//Respond to hello
		if(command.compare("H") == 0){
			response = "R"+sensor;
			dt.addOrUpdateDowntime(sender_endpoint.address().to_string(),variable);
			//cout<<response<<endl;
			//Insert into my table
			/*
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			sender_endpoint.port(recievePort);
			send_socket.send_to(boost::asio::buffer(response,response.size()),sender_endpoint);
			*/
		}
		//Write to console (MAINLY FOR TESTING)
		if(command.compare("W") == 0){
			//response = "Writing";
			cout<<"Writing on request from "<<sender_endpoint.address().to_string()<<endl;
			dt.print();
			/*
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			sender_endpoint.port(recievePort);
			send_socket.send_to(boost::asio::buffer(response,response.size()),sender_endpoint);*/
		}
		if(command.compare("F") == 0){
			response = "W" + getTemp();
			boost::asio::ip::udp::socket send_socket(io_service,boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(),0));
			sender_endpoint.port(recievePort);
			send_socket.send_to(boost::asio::buffer(response,response.size()),sender_endpoint);
		}
		//Exit
		if(command.compare("E") == 0){
			response = "Exiting now";

			cout<<"Reciever will now terminate"<<endl;
			break;
		}
	}
}

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


		//string* validIps[] = {"192.168.0.1","192.168.0.11","192.168.0.15","192.168.0.17","169.254.191.147"};
		//Hello aspects
		dt.add("192.168.0.1","UNKNOWN");
		dt.add("192.168.0.11","UNKNOWN");
		dt.add("192.168.0.15","UNKNOWN");
		dt.add("192.168.0.17","UNKNOWN");


		thread t1 (sendHellos, boost::ref(io_service), boost::ref(local_endpoint),boost::lexical_cast<int>(argv[2]));
		reciever(boost::ref(io_service), boost::ref(local_endpoint),boost::lexical_cast<int>(argv[2]));

		t1.join();
	}catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}


    std::cout << "Program run completed!" << std::endl;
    return 0;
}
