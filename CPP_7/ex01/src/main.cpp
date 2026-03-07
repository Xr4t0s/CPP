#include "Iter.tpp"

template< typename T >
void print(const T& element) {
	std::cout << element << std::endl;
}

int main() {
	std::string strings[] = {"hello", "world"};

	iter(strings, 2, print<std::string>);

	int ints[] = {1,2,3,4,5};

	iter(ints, 5, print<int>);
}