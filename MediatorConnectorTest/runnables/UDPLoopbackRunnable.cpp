/*
 * UDPLoopbackRunnable.cpp
 *
 *  Created on: Jul 15, 2010
 *      Author: stephen001
 */

#include <MediatorConnectorTest/runnables/UDPLoopbackRunnable.hpp>
#include <MediatorConnectorTest/UDPLoopbackServer.hpp>
#include <iostream>
#include <sstream>

UDPLoopbackRunnable::UDPLoopbackRunnable() : Runnable(std::string("udp-loop")) {}

UDPLoopbackRunnable::~UDPLoopbackRunnable() {}

void UDPLoopbackRunnable::run(int argc, char ** argv) {
	if (argc < 1) {
		std::cerr << "udp-loop was expecting at least 1 argument." << std::endl;
		return;
	}
	unsigned int port;
	std::string lol(argv[0]);
	std::stringstream ss(lol);
	ss >> port;
	UDPLoopbackServer server(port);
}
