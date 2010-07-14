/*
 * UDPConnection.cpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#include "UDPConnection.hpp"

#include <boost/bind.hpp>
#include <string>

UDPConnection::UDPConnection(boost::asio::io_service & io_service, int port) :
Connection(io_service, port), __socket(io_service, udp::endpoint(udp::v4(), port)) {}

UDPConnection::~UDPConnection() {}

void UDPConnection::start() {
	__socket.async_receive_from(boost::asio::buffer(__recv_buffer), __remote_endpoint,
			boost::bind(&UDPConnection::handle_receive, this,
				boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void UDPConnection::handle_receive(const boost::system::error_code & error, std::size_t bytes_transferred) {
	if (!error || error == boost::asio::error::message_size) {
		boost::shared_ptr<std::string> message( new std::string(__recv_buffer.elems) );
		__socket.async_send_to(boost::asio::buffer(*message), __remote_endpoint,
				boost::bind(&UDPConnection::handle_send, shared_from_this(),
						 boost::asio::placeholders::error,
						 boost::asio::placeholders::bytes_transferred));
	}
	start();
}

void UDPConnection::handle_send(const boost::system::error_code &,std::size_t) {

}
