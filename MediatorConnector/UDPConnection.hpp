/*
 * UDPConnection.hpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#ifndef UDPCONNECTION_HPP_
#define UDPCONNECTION_HPP_

#include <MediatorConnector/Connection.hpp>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::udp;

class UDPConnection: public Connection, public boost::enable_shared_from_this<UDPConnection> {
public:
	UDPConnection(boost::asio::io_service & io_service, int port);
	virtual ~UDPConnection();
	virtual void start();
private:
	void handle_receive(const boost::system::error_code & error, std::size_t bytes_transferred);
	void handle_send(const boost::system::error_code & error, std::size_t bytes_transferred);
	boost::array<char, 1024>	__recv_buffer;
	udp::endpoint 				__remote_endpoint;
	udp::socket					__socket;
};

#endif /* UDPCONNECTION_HPP_ */
