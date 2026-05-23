#include "RPN.hpp"
#include <iostream>

static std::stack<int>	stack;
static std::size_t			stack_size = 0;

const char*	InvalidToken::what() const throw() {
	return "Invalid token";
}
const char*	ZeroDivision::what() const throw() {
	return "Divison by zero !";
}

void run(char *input) {
	std::stringstream ss(input);
	std::string token;
	
	while (ss >> token) {
		if (token.length() != 1)
			throw InvalidToken();
		if (isdigit(token[0])) {
			stack.push(token[0] - 48);
			stack_size++;
		} else {
			if (stack_size < 2) {
				throw InvalidToken();
			}
			int a, b = 0;
			switch (token[0]) {
				case '*':
					a = stack.top();
					stack.pop();
					b = stack.top();
					stack.pop();
					stack.push(a * b);
					stack_size--;
					break;

				case '+':
					a = stack.top();
					stack.pop();
					b = stack.top();
					stack.pop();
					stack.push(a + b);
					stack_size--;
					break;

				case '/':
					a = stack.top();
					if (a == 0)
						throw ZeroDivision();
					stack.pop();
					b = stack.top();
					stack.pop();
					stack.push(b / a);
					stack_size--;
					break;

				case '-':
					a = stack.top();
					stack.pop();
					b = stack.top();
					stack.pop();
					stack.push(b - a);
					stack_size--;
					break;
				
				default:
					throw InvalidToken();
					break;
			}
		}
	}
	if (stack_size != 1)
		throw InvalidToken();
	std::cout << stack.top() << std::endl;
}