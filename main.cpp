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

#include "client.h"
#include "server.h"

using namespace std;




/*
 *
 */
int main(int argc, char** argv) {

		client();

		boost::thread s{server()};
		s.join();
		
    std::cout << "Program run completed!" << std::endl;
    return 0;
}
