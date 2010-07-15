/*
 * UDPTTYRunnable.cpp
 *
 *  Created on: Jul 15, 2010
 *      Author: stephen001
 */

#include <MediatorConnectorTest/UDPTTY.hpp>
#include <MediatorConnectorTest/runnables/UDPTTYRunnable.hpp>

#include <string>
#include <sstream>
#include <iostream>

UDPTTYRunnable::UDPTTYRunnable() : Runnable("udp-tty") {}

UDPTTYRunnable::~UDPTTYRunnable() {}

void UDPTTYRunnable::run(int argc, char ** argv) {
	if (argc < 2) {
		std::cerr << "udp-tty was expecting at least 2 arguments." << std::endl;
		return;
	}
	std::string address(argv[0]);
	unsigned int port;
	std::string portStr(argv[1]);
	std::stringstream ss(portStr);
	ss >> port;
	UDPTTY tty(address, port);
}
