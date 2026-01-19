#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_form_initialisation( void ) {
	std::cout
		<< "\n\033[1;36m========== TEST 1 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Create a form with bad values\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;31mException thrown (Grade too high/low)\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	int testValues[][2] = {
		{151, 10},
		{0, 10},
		{10, 151},
		{10, 0},
		{10, 10}
	};

	for (int i = 0; i < 5; ++i) {
		int sign = testValues[i][0];
		int exec = testValues[i][1];

		std::cout
			<< "\033[1;33m[Test]\033[0m sign=" << sign
			<< ", exec=" << exec << " → ";

		try {
			Form a("alice", sign, exec);
			if (i < 5)
				std::cout << "\033[1;32m[OK]\033[0m no exception\n";
			else
				std::cout << "\033[1;31m[KO]\033[0m no exception\n";

		}
		catch (std::exception& e) {
			if (i < 5)
				std::cout << "\033[1;32m[OK]\033[0m " << e.what() << std::endl;
			else
				std::cout << "\033[1;31m[KO]\033[0m " << e.what() << std::endl;

		}
	}
}


void test_form_signature( void ) {
	std::cout
		<< "\n\033[1;36m========== TEST 2 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Bureaucrat tries to sign a form\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	struct TestCase {
		const char* name;
		int bureaucratGrade;
		int formSignGrade;
		bool shouldSucceed;
	};

	TestCase tests[] = {
		{"Alice", 145, 148, true},
		{"Bob",   150, 148, false},
		{"Eve",   1,   1,   true},
		{"Tom",   149, 1,   false}
	};

	for (int i = 0; i < 4; ++i) {
		std::cout
			<< "\033[1;33m[Test]\033[0m "
			<< tests[i].name
			<< " (grade " << tests[i].bureaucratGrade
			<< ") → signGrade " << tests[i].formSignGrade
			<< " : ";

		try {
			Bureaucrat b(tests[i].name, tests[i].bureaucratGrade);
			Form f("Contract", tests[i].formSignGrade, 130);

			b.signForm(f);

			if (tests[i].shouldSucceed)
				std::cout << "\033[1;32m[OK]\033[0m signed\n";
			else
				std::cout << "\033[1;31m[KO]\033[0m should not sign\n";
		}
		catch (std::exception& e) {
			if (!tests[i].shouldSucceed)
				std::cout << "\033[1;32m[OK]\033[0m " << e.what() << std::endl;
			else
				std::cout << "\033[1;31m[KO]\033[0m " << e.what() << std::endl;
		}
	}
}


int main() {
	test_form_initialisation();
	test_form_signature();
}