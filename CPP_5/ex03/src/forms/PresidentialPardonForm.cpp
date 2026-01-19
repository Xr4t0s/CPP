#include "forms/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("random target") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm("PresidentialPardonForm", 25, 5), _target(name) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs ) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

void PresidentialPardonForm::subExecute( void ) {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}