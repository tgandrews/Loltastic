/*
 * UDPServer.hpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#ifndef UDPSERVER_HPP_
#define UDPSERVER_HPP_

#include <MediatorConnector/ConnectionGateway.hpp>
#include <MediatorConnector/UDPConnection.hpp>

class UDPLoopbackServer {
public:
	UDPLoopbackServer(int port);
	virtual ~UDPLoopbackServer();
private:
	boost::asio::io_service			 __io_service;
	ConnectionGateway<UDPConnection> __gateway;
};

#endif /* UDPSERVER_HPP_ */
