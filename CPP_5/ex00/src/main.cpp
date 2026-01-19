#include "Bureaucrat.hpp"

void test_instantiating_too_high( void ) {
	std::cout
		<< "\n\033[1;36m========== TEST 1 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Instantiate a Bureaucrat with an too high grade\n"
		<< "\033[1;33mInput:\033[0m     Name = \"Alice\", Grade = 151\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;31mException thrown (Grade too high)\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";
	
	try {
		Bureaucrat a(151, "Alice");
		std::cout << "\033[1;31m[KO]\033[0m No exception thrown\n";
	} catch (std::exception& e) {
		std::cout << "\033[1;32m[OK]\033[0m " << e.what() << std::endl;
	}
}

void test_instantiating_too_low( void ) {
	std::cout
		<< "\n\033[1;36m========== TEST 2 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Instantiate a Bureaucrat with an too low grade\n"
		<< "\033[1;33mInput:\033[0m     Name = \"Alice\", Grade = 0\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;31mException thrown (Grade too low)\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";
	
	try {
		Bureaucrat a(0, "Alice");
		std::cout << "\033[1;31m[KO]\033[0m No exception thrown\n";
	} catch (std::exception& e) {
		std::cout << "\033[1;32m[OK]\033[0m " << e.what() << std::endl;
	}
}

void test_upgrade( void ) {
	std::cout
		<< "\n\033[1;36m========== TEST 3 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Upgrade a Bureaucrat from 150 to 1\n"
		<< "\033[1;33mInput:\033[0m     Name = \"Alice\", Grade = 150\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;32mName = \"Alice\", Grade = 1\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	try {
		Bureaucrat a(150, "Alice");
		for (int i = 1; i < 150; i++) a.upgrade();
		if (a.getGrade() == 1) {
			std::cout << "\033[1;32m[OK]\033[0m " << a << std::endl;
		} else {
			std::cout << "\033[1;31m[KO]\033[0m Alice is level " << a.getGrade() << "\n";
		}
	} catch (std::exception& e) {
		std::cout << "\033[1;31m[KO]\033[0m Exception thrown : " << e.what() << std::endl;
	}
}

void test_downgrade( void ) {
	std::cout
		<< "\n\033[1;36m========== TEST 4 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Downgrade a Bureaucrat from 1 to 150\n"
		<< "\033[1;33mInput:\033[0m     Name = \"Alice\", Grade = 1\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;32mName = \"Alice\", Grade = 150\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	try {
		Bureaucrat a(1, "Alice");
		for (int i = 1; i < 150; i++) a.downgrade();
		if (a.getGrade() == 150) {
			std::cout << "\033[1;32m[OK]\033[0m " << a << std::endl;;
		} else {
			std::cout << "\033[1;31m[KO]\033[0m Alice is level " << a.getGrade() << "\n";
		}
	} catch (std::exception& e) {
		std::cout << "\033[1;31m[KO]\033[0m Exception thrown : " << e.what() << std::endl;
	}
}

void test_upgrade_too_much( void ) {
	std::cout
		<< "\n\033[1;36m========== TEST 5 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Upgrade too much a Bureaucrat from 150 to 0\n"
		<< "\033[1;33mInput:\033[0m     Name = \"Alice\", Grade = 150\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;31mException thrown (Grade too high)\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";
	
	Bureaucrat a(150, "Alice");
	std::cout << a << std::endl;
	try {
		for (int i = 0; i < 150; i++) a.upgrade();
	} catch (std::exception& e) {
		std::cout << "\033[1;32m[OK]\033[0m Exception thrown : " << e.what() << std::endl;
	}
	std::cout << a << std::endl;
}

void test_downgrade_too_much( void ) {
	std::cout
		<< "\n\033[1;36m========== TEST 6 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Downgrade too_much a Bureaucrat from 1 to 151\n"
		<< "\033[1;33mInput:\033[0m     Name = \"Alice\", Grade = 1\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;31mException thrown (Grade too low)\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	Bureaucrat a(1, "Alice");
	std::cout << a << std::endl;
	try {
		for (int i = 0; i < 150; i++) a.downgrade();
	} catch (std::exception& e) {
		std::cout << "\033[1;32m[OK]\033[0m Exception thrown : " << e.what() << std::endl;
	}
	std::cout << a << std::endl;
}


int main() {
	test_instantiating_too_high();
	std::cout << std::endl;
	test_instantiating_too_low();
	std::cout << std::endl;
	test_upgrade();
	std::cout << std::endl;
	test_downgrade();
	std::cout << std::endl;
	test_upgrade_too_much();
	std::cout << std::endl;
	test_downgrade_too_much();
}