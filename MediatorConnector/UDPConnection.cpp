/*
 * UDPConnection.cpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#include "UDPConnection.hpp"

#include <boost/bind.hpp>
#include <string>
#include <iostream>

UDPConnection::UDPConnection(boost::asio::io_service & io_service, int port) :
Connection(io_service, port), __socket(io_service, udp::endpoint(udp::v4(), port)) {}

UDPConnection::~UDPConnection() {}

void UDPConnection::start() {
	std::vector<char> * array = new std::vector<char>(1024);
	__socket.async_receive_from(boost::asio::buffer(*array), __remote_endpoint,
			boost::bind(&UDPConnection::handle_receive, this, array,
				boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void UDPConnection::handle_receive(
		std::vector<char> * buffer,
		const boost::system::error_code & error,
		std::size_t bytes_transferred) {
	if (!error || error == boost::asio::error::message_size) {
		std::cout << "From: " << __remote_endpoint.address().to_string() << ":" <<
				__remote_endpoint.port() << std::endl;
		__remote_endpoint.port(41588);
		std::cout << "To:   " << __remote_endpoint.address().to_string() << ":" <<
						__remote_endpoint.port() << std::endl;
		std::string data(buffer->begin(), buffer->end());
		std::cout << "Data: " << data << std::endl;
		__socket.async_send_to(boost::asio::buffer(*buffer), __remote_endpoint,
				boost::bind(&UDPConnection::handle_send, this,
						 boost::asio::placeholders::error,
						 boost::asio::placeholders::bytes_transferred));
	}
	delete buffer;
	start();
}

void UDPConnection::handle_send(const boost::system::error_code & error,std::size_t size) {}
