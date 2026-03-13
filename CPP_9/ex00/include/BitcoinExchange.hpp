#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>

#include "errors/Errors.hpp"

extern	std::map<std::string, double> rate;
extern	std::ifstream									fs;

void	processLine(std::string line, uint nLine);
void	run();

#endif