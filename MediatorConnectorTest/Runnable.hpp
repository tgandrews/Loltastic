/*
 * Runnable.hpp
 *
 *  Created on: Jul 14, 2010
 *      Author: stephen001
 */

#ifndef RUNNABLE_HPP_
#define RUNNABLE_HPP_

#include <string>

class Runnable {
public:
	Runnable(std::string c);
	virtual ~Runnable();
	bool applies(std::string & c);
	virtual void run(int argc, char ** argv);
private:
	std::string & __command;
};

#endif /* RUNNABLE_HPP_ */
