/*
 * Help.cpp
 *
 *  Created on: 2020年12月16日
 *      Author: mebius
 */

#include <iostream>
#include "Help.h"

namespace msh {

int Help::run(std::vector<std::string> &args){
	std::cout<< "MSH\n这里可以写一些命令的帮助信息。" << std::endl;
	return 1;
}

std::string Help::name(){
	return "help";
}

} /* namespace msh */
