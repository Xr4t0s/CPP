#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <sstream>
#include <stack>
#include <vector>
#include <cstdlib>

struct InvalidToken : std::exception {
	public:
		const char* what() const throw();
};

void run(char *input);

#endif