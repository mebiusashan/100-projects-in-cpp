/*
 * main.cpp
 *
 *  Created on: 2020年12月15日
 *      Author: mebius
 */

#include <iostream>
#include <unistd.h>

#include "Msh.h"
#include "Config.h"
#include "commands/Help.h"
#include "commands/Exit.h"

namespace msh {

Msh::Msh() {
	this->commandManager = new msh::CommandManager();
	this->commandManager->AddCommand(new Help());
	this->commandManager->AddCommand(new Exit());
}

Msh::~Msh() {
	delete this->commandManager;
}

void Msh::loop() {
	int status;
	do {
		std::cout << "> ";
		std::string line = readLine();
		std::vector<std::string> args = parseLine(line);
		status = execute(args);
	} while (status);
}

std::string Msh::readLine() {
	std::string str;
	std::getline(std::cin, str);
	return str;
}

std::vector<std::string> Msh::parseLine(std::string &line) {
	std::vector<std::string> res;
	if (line == "") {
		return res;
	}
	char *strs = new char[line.length() + 1];
	std::strcpy(strs, line.c_str());
	char *p = std::strtok(strs, MSH_TOK_DELIM);
	while (p) {
		std::string s = p;
		res.push_back(s);
		p = std::strtok(NULL, MSH_TOK_DELIM);
	}
	return res;
}

int Msh::launch(std::vector<std::string> &args) {
	pid_t pid, wpid;
	int status;
	pid = fork();
	if (pid == 0) {
		char *argv[args.size() + 1];
		for (int i = 0; i < args.size(); i++) {
			argv[i] = const_cast<char*>(args[i].c_str());
		}
		argv[args.size()] = NULL;
		if (execvp(argv[0], argv) == -1) {
			std::cerr << "msh" << std::endl;
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		std::cerr << "msh" << std::endl;
	} else {
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

int Msh::execute(std::vector<std::string> &args) {
	if (args.empty()) {
		return MSH_DOT_HAVE_ARGS;
	}
	if (this->commandManager->Check(args) == MSH_BUILTIN_CMD) {
		return this->commandManager->Run(args);
	}
	return launch(args);
}

} /* namespace msh */
