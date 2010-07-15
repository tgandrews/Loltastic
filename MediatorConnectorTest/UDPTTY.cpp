/*
 * UDPTTY.cpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#include <MediatorConnectorTest/UDPTTY.hpp>

#include <string>
#include <iostream>
#include <sstream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

UDPTTY::UDPTTY(std::string & s, int port) {
	boost::asio::io_service io_service;
	boost::asio::ip::address address(boost::asio::ip::address::from_string(s.c_str()));
	udp::endpoint endpoint(address, port);
	udp::socket socket(io_service);
	socket.open(udp::v4());
	while (true) {
		std::string s;
		std::getline(std::cin, s);
		socket.send_to(boost::asio::buffer(s), endpoint);
	}
}

UDPTTY::~UDPTTY() {}
