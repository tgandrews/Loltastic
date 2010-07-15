/*
 * UDPTTYRunnable.hpp
 *
 *  Created on: Jul 15, 2010
 *      Author: stephen001
 */

#ifndef UDPTTYRUNNABLE_HPP_
#define UDPTTYRUNNABLE_HPP_

#include <MediatorConnectorTest/Runnable.hpp>

class UDPTTYRunnable: public Runnable {
public:
	UDPTTYRunnable();
	virtual ~UDPTTYRunnable();
	void run(int argc, char ** argv);
};

#endif /* UDPTTYRUNNABLE_HPP_ */
