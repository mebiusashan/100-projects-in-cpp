/*
 * CommandManager.cpp
 *
 *  Created on: 2020年12月15日
 *      Author: mebius
 */

#include "CommandManager.h"
#include "Config.h"

namespace msh {

CommandManager::CommandManager() {
	this->cmds = new std::unordered_map<std::string, msh::Command*>();
}

CommandManager::~CommandManager() {
	delete this->cmds;
}

void CommandManager::AddCommand(msh::Command *cmd) {
	std::string name = cmd->name();
	std::pair<std::string, msh::Command*> c(name, cmd);
	this->cmds->insert(c);
}

bool CommandManager::Check(std::vector<std::string> &args) {
	std::string cmd = args[0];
	if (this->cmds->find(cmd) == this->cmds->end()) {
		return false;
	}
	return MSH_BUILTIN_CMD;
}

int CommandManager::Run(std::vector<std::string> &args) {
	if (Check(args) == MSH_BUILTIN_CMD) {
		std::string c = args[0];
		std::unordered_map<std::string, msh::Command*>::const_iterator cmd = this->cmds->find(c);
		return cmd->second->run(args);
	}
	return -1;
}

} /* namespace msh */
