#include "MutantStack.hpp"

int main() {
	MutantStack<int>	mstack;

	mstack.push(1);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(1);
	mstack.push(12);
	mstack.push(252);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while(it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> stack(mstack);

	return 0;
}