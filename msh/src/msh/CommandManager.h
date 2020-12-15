/*
 * CommandManager.h
 *
 *  Created on: 2020年12月15日
 *      Author: mebius
 */

#ifndef COMMANDMANAGER_H_
#define COMMANDMANAGER_H_

#include <unordered_map>
#include <vector>

#include "Command.h"

namespace msh {

class CommandManager{
public:
	CommandManager();
	virtual ~CommandManager();
	void AddCommand(msh::Command* cmd);
	bool Check(std::vector<std::string>& args);
	int Run(std::vector<std::string>& args);

private:
	std::unordered_map<std::string, msh::Command*>* cmds;

};


} /* namespace msh */

#endif /* COMMANDMANAGER_H_ */
