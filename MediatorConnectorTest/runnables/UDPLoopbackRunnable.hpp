/*
 * UDPLoopbackRunnable.hpp
 *
 *  Created on: Jul 15, 2010
 *      Author: stephen001
 */

#ifndef UDPLOOPBACKRUNNABLE_HPP_
#define UDPLOOPBACKRUNNABLE_HPP_

#include <MediatorConnectorTest/Runnable.hpp>

class UDPLoopbackRunnable: public Runnable {
public:
	UDPLoopbackRunnable();
	virtual ~UDPLoopbackRunnable();
	void run(int argc, char ** argv);
};

#endif /* UDPLOOPBACKRUNNABLE_HPP_ */
