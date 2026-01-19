#include "forms/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("random target") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm("ShrubberyCreationForm", 145, 137), _target(name) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs ) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::subExecute( void ) {
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open()) {
		file << "   *   \n";
		file << "  ***  \n";
		file << " ***** \n";
		file << "*******\n";
		file << "   *   \n";
		file.close();
	} else {
		std::cout << "Failed to open file\n";
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}