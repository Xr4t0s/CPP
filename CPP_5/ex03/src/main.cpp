#include <iostream>
#include "office/Intern.hpp"
#include "office/Bureaucrat.hpp"

int main() {
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("presidential request", "Boss");
	if (!rrf) return 0;

	Bureaucrat boss(1, "Boss");

	try {
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
	} catch (std::exception& e) {}
	
	delete rrf;
}
