#include "Array.hpp"

class Test {
	private:
		std::string _name;

	public:
		void setName(const std::string& name) {
			this->_name = name;
		}

		const std::string& getName( void ) const {
			return this->_name;
		}

	};

std::ostream& operator<<(std::ostream& os, const Test& out) {
	os << out.getName();
	return os;
}

int main() {
	Array<Test> arr(5);

	std::cout << arr[2] << std::endl;
	arr[2].setName("jul");
	std::cout << arr[2] << std::endl;
}