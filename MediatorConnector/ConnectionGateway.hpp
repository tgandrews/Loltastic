/*
 * ConnectionGateway.hpp
 *
 *  Created on: Jul 13, 2010
 *      Author: stephen001
 */

#ifndef CONNECTIONGATEWAY_HPP_
#define CONNECTIONGATEWAY_HPP_

namespace boost {
	namespace asio {
		class io_service;
	};
};

template <class T>
class ConnectionGateway {
public:
	ConnectionGateway(boost::asio::io_service & io_service, int port) : __socket(io_service, port) { __socket.start(); };
	virtual ~ConnectionGateway() {};
private:
	T __socket;
};

#endif /* CONNECTIONGATEWAY_HPP_ */
