/*
 * Exit.cpp
 *
 *  Created on: 2020年12月16日
 *      Author: mebius
 */

#include "Exit.h"

namespace msh {

int Exit::run(std::vector<std::string> &args){
//	std::cout<< "退出" << std::endl;
	return 0;
}

std::string Exit::name(){
	return "exit";
}

} /* namespace msh */
