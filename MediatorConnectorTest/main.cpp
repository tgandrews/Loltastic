/*
 * main.cpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#include <map>
#include <string>
#include <iostream>
#include <MediatorConnectorTest/Runnable.hpp>
#include <MediatorConnectorTest/runnables/UDPLoopbackRunnable.hpp>
#include <MediatorConnectorTest/runnables/UDPTTYRunnable.hpp>

std::map<std::string, Runnable *> runnables;

int main(int argc, char ** argv) {
	runnables["udp-loop"] 	= new UDPLoopbackRunnable();
	runnables["udp-tty"]	= new UDPTTYRunnable();
	if ( argc < 2 ) {
		std::cerr << "No command found." << std::endl;
		return 1;
	}
	std::string command(argv[1]);
	argc -= 2;
	argv += 2;
	std::map<std::string, Runnable *>::const_iterator it = runnables.find(command);
	if (it == runnables.end()) {
		std::cerr << "No command found that matches " << command << std::endl;
		return 1;
	}
	Runnable * runnable = it->second;
	runnable->run(argc, argv);
	return 0;
}
