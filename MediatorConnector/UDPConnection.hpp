/*
 * UDPConnection.hpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#ifndef UDPCONNECTION_HPP_
#define UDPCONNECTION_HPP_

#include <MediatorConnector/Connection.hpp>

#include <vector>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class UDPConnection: public Connection {
public:
	UDPConnection(boost::asio::io_service & io_service, int port);
	virtual ~UDPConnection();
	virtual void start();
private:
	void handle_receive(
			std::vector<char> * array,
			const boost::system::error_code & error,
			std::size_t bytes_transferred);
	void handle_send(const boost::system::error_code & error, std::size_t bytes_transferred);
	udp::endpoint 				__remote_endpoint;
	udp::socket					__socket;
};

#endif /* UDPCONNECTION_HPP_ */
