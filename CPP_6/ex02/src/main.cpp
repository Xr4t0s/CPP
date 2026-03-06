#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base*	generate( void ) {
	int random = std::rand() % 3;

	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		
		default:
			break;
	}

	return NULL;
}

void	identify(Base* p) {
	Base* ret;

	ret = dynamic_cast<A*>(p);
	if (!ret) {
		std::cout << "Type of pointer is not A" << std::endl;
		ret = dynamic_cast<B*>(p);
		if (!ret) {
			std::cout << "Type of pointer is not B" << std::endl;
			ret = dynamic_cast<C*>(p);
			if (!ret) {
				std::cout << "Type of pointer is not C" << std::endl;
			} else {
				std::cout << "Type of pointer is C" << std::endl;
			}
		} else {
			std::cout << "Type of pointer is B" << std::endl;
		}
	} else {
		std::cout << "Type of pointer is A" << std::endl;
	}
}

void	identify(Base& p) {
	try {
		Base& ret1 = dynamic_cast<A&>(p);
		std::cout << "Type of reference is A" << std::endl;
		static_cast<void>(ret1);
	} catch (std::exception& bc) {
		std::cout << "Cast error : " << bc.what() << std::endl;
		try {
			Base& ret2 = dynamic_cast<B&>(p);
			std::cout << "Type of reference is B" << std::endl;
			static_cast<void>(ret2);
		} catch (std::exception& bc) {
			std::cout << "Cast error : " << bc.what() << std::endl;
			try {
				Base& ret3 = dynamic_cast<C&>(p);
				std::cout << "Type of reference is C" << std::endl;
				static_cast<void>(ret3);
			} catch (std::exception& bc) {
				std::cout << "Cast error : " << bc.what() << std::endl;
			}
		}
	}
}

int main() {
	std::srand(std::time(0));

	Base* genZ = generate();
	if (!genZ) return 1;

	identify(genZ);
	identify(*genZ);

	return 0;
}