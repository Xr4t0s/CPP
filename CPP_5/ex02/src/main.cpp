#include <iostream>
#include "office/Bureaucrat.hpp"
#include "forms/AForm.hpp"
#include "forms/ShrubberyCreationForm.hpp"
#include "forms/RobotomyRequestForm.hpp"
#include "forms/PresidentialPardonForm.hpp"

/* ============================================================
   TEST 1 — Execute unsigned form
   ============================================================ */
void test_execute_unsigned(void) {
	std::cout
		<< "\n\033[1;36m========== TEST 1 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Execute an unsigned form\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;31mException thrown\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	Bureaucrat boss(1, "Boss");
	RobotomyRequestForm form("Marvin");

	try {
		boss.executeForm(form);
		std::cout << "\033[1;31m[KO]\033[0m No exception thrown\n";
	} catch (std::exception& e) {
		std::cout << "\033[1;32m[OK]\033[0m " << e.what() << std::endl;
	}
}

/* ============================================================
   TEST 2 — Sign & execute ShrubberyCreationForm
   ============================================================ */
void test_shrubbery(void) {
	std::cout
		<< "\n\033[1;36m========== TEST 2 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Sign & execute ShrubberyCreationForm\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;32m<target>_shrubbery file created\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	Bureaucrat gardener(130, "Gardener");
	ShrubberyCreationForm form("home");

	try {
		gardener.signForm(form);
		gardener.executeForm(form);
		std::cout << "\033[1;32m[OK]\033[0m Shrubbery created\n";
	} catch (std::exception& e) {
		std::cout << "\033[1;31m[KO]\033[0m " << e.what() << std::endl;
	}
}

/* ============================================================
   TEST 3 — RobotomyRequestForm (50% success)
   ============================================================ */
void test_robotomy(void) {
	std::cout
		<< "\n\033[1;36m========== TEST 3 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Sign & execute RobotomyRequestForm\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;32mRandom success or failure\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	Bureaucrat surgeon(1, "Surgeon");
	RobotomyRequestForm form("Bender");

	try {
		surgeon.signForm(form);
		surgeon.executeForm(form);
		std::cout << "\033[1;32m[OK]\033[0m Robotomy attempted\n";
	} catch (std::exception& e) {
		std::cout << "\033[1;31m[KO]\033[0m " << e.what() << std::endl;
	}
}

/* ============================================================
   TEST 4 — PresidentialPardonForm
   ============================================================ */
void test_presidential_pardon(void) {
	std::cout
		<< "\n\033[1;36m========== TEST 4 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Sign & execute PresidentialPardonForm\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;32mTarget pardoned by Zaphod Beeblebrox\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	Bureaucrat president(1, "President");
	PresidentialPardonForm form("Arthur Dent");

	try {
		president.signForm(form);
		president.executeForm(form);
		std::cout << "\033[1;32m[OK]\033[0m Pardon executed\n";
	} catch (std::exception& e) {
		std::cout << "\033[1;31m[KO]\033[0m " << e.what() << std::endl;
	}
}

/* ============================================================
   TEST 5 — Execute with grade too low
   ============================================================ */
void test_execute_grade_too_low(void) {
	std::cout
		<< "\n\033[1;36m========== TEST 5 ==========\033[0m\n"
		<< "\033[1;33mScenario:\033[0m  Execute a signed form with low grade\n"
		<< "\033[1;33mExpected:\033[0m  \033[1;31mException thrown\033[0m\n"
		<< "\033[1;36m----------------------------\033[0m\n";

	Bureaucrat boss(1, "Boss");
	Bureaucrat intern(150, "Intern");
	PresidentialPardonForm form("Ford Prefect");

	try {
		boss.signForm(form);
		intern.executeForm(form);
		std::cout << "\033[1;31m[KO]\033[0m No exception thrown\n";
	} catch (std::exception& e) {
		std::cout << "\033[1;32m[OK]\033[0m " << e.what() << std::endl;
	}
}

/* ============================================================
   MAIN
   ============================================================ */
int main(void) {
	test_execute_unsigned();
	std::cout << std::endl;

	test_shrubbery();
	std::cout << std::endl;

	test_robotomy();
	std::cout << std::endl;

	test_presidential_pardon();
	std::cout << std::endl;

	test_execute_grade_too_low();
}
