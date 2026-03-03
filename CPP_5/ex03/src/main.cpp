#include <iostream>
#include "office/Intern.hpp"
#include "office/Bureaucrat.hpp"

int main() {
	Intern someRandomIntern;
	AForm* form;
	form = someRandomIntern.makeForm("presidential request", "Boss");
	if (!form) return 0;

	Bureaucrat boss(1, "Boss");

	try {
		boss.signForm(*form);
		boss.executeForm(*form);
	} catch (std::exception& e) {}
	
	delete form;
}
