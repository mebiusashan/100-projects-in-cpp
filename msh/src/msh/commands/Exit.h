/*
 * Exit.h
 *
 *  Created on: 2020年12月16日
 *      Author: mebius
 */

#ifndef MSH_COMMANDS_EXIT_H_
#define MSH_COMMANDS_EXIT_H_

#include "../Command.h"
#include <vector>

namespace msh {

class Exit: public Command {
public:
	int run(std::vector<std::string> &args);
		std::string name();
};

} /* namespace msh */

#endif /* MSH_COMMANDS_EXIT_H_ */
