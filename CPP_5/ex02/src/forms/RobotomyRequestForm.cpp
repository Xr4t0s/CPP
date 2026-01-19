#include "forms/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _mod(0), _target("random target") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm("RobotomyRequestForm", 72, 45), _mod(0), _target(name) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : AForm(copy), _mod(copy._mod), _target(copy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs ) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_mod = rhs._mod;
		_target = rhs._target;
	}
	return *this;
}

void RobotomyRequestForm::subExecute( void ) {
	std::cout << "Starting brain scanning..." << std::endl;
	std::cout << "Brain scan successfull." << std::endl;
	std::cout << "Diving into neuronal connection..." << std::endl;
	std::cout << "Found some intersting stuff, diving deeply..." << std::endl;
	std::cout << "Found target cell !" << std::endl;
	std::cout << "Trying to bypass molecular shield..." << std::endl;
	std::cout << "Molecular shield not bypassed !" << std::endl;
	std::cout << "Shield counter with some random genoms" << std::endl;
	std::cout << "Started secret weapon..." << std::endl;
	std::cout << "Robotomy ready !" << std::endl;
	std::cout << "Fire !" << std::endl;
	if (_mod % 2 == 0) {
		std::cout << _target << " have been robotomized !" << std::endl;
	} else {
		std::cout << "Robotomization failed !" << std::endl;
	}
	_mod++;
}

RobotomyRequestForm::~RobotomyRequestForm() {}