/*
 * Command.h
 *
 *  Created on: 2020年12月15日
 *      Author: mebius
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <iostream>

namespace msh {

class Command {
public:
	virtual int run(std::vector<std::string> &args) = 0;
	virtual std::string name() = 0;
};

} /* namespace msh */

#endif /* COMMAND_H_ */
