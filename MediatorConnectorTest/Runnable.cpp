/*
 * Runnable.cpp
 *
 *  Created on: Jul 15, 2010
 *      Author: stephen001
 */

#include <MediatorConnectorTest/Runnable.hpp>

Runnable::Runnable(std::string c) : __command(c) {}

Runnable::~Runnable() {}

bool Runnable::applies(std::string & c) {
	return __command == c;
}

void Runnable::run(int argc, char ** argv) {}
