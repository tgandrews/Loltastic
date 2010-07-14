/*
 * Connection.hpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

namespace boost {
	namespace asio {
		class io_service;
	};
};

class Connection {
public:
	Connection(boost::asio::io_service & io_service, int port);
	virtual ~Connection();
	virtual void start();
};

#endif /* CONNECTION_HPP_ */
