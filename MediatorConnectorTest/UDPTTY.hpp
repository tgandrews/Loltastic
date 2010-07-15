/*
 * UDPTTY.hpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#ifndef UDPTTY_HPP_
#define UDPTTY_HPP_

#include <string>

class UDPTTY {
public:
	UDPTTY(std::string & s, int port);
	virtual ~UDPTTY();
};

#endif /* UDPTTY_HPP_ */
