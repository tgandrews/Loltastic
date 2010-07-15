/*
 * UDPServer.cpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#include <MediatorConnectorTest/UDPLoopbackServer.hpp>
#include <iostream>

UDPLoopbackServer::UDPLoopbackServer(int port) : __io_service(), __gateway(__io_service, port) {
	std::cout << "Starting UDP on port " << port << std::endl;
	__io_service.run();
}

UDPLoopbackServer::~UDPLoopbackServer() {}
