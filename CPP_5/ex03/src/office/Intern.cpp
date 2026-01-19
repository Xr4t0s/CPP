#include "office/Intern.hpp"
#include "forms/PresidentialPardonForm.hpp"
#include "forms/RobotomyRequestForm.hpp"
#include "forms/ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& copy) {
	(void)copy;
}
Intern& Intern::operator=(const Intern& rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return *this;
}

AForm* shruberry(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}
AForm* robotomy(const std::string& target) {
	return (new RobotomyRequestForm(target));
}
AForm* president(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	const std::string forms[3] = {
		"shrubbery request",
		"robotomy request",
		"presidential request"
	};

	AForm* (*func_ptr[3])(const std::string&) = {
		&shruberry,
		&robotomy,
		&president
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return func_ptr[i](target);
		}
	}

	std::cout << "Intern couldn't create form \"" << name << "\"" << std::endl;
	return NULL;
}

Intern::~Intern() {}