/*
 * msh.h
 *
 *  Created on: 2020年12月15日
 *      Author: mebius
 */

#ifndef MSH_H_
#define MSH_H_


#include "CommandManager.h"
#include <iostream>
#include <vector>

namespace msh {

class Msh {
private:
	msh::CommandManager* commandManager;
	std::string readLine();
	std::vector<std::string> parseLine(std::string& line);
	int launch(std::vector<std::string>& args);
	int execute(std::vector<std::string>& args);

public:
	Msh();
	virtual ~Msh();
	void loop();
};

} /* namespace msh */

#endif /* MSH_H_ */
