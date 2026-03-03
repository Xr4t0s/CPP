#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructions
Form::Form() : _name("Basic form"), _signed(false), _signReqGrade(150), _execReqGrade(150) {}
Form::Form(const std::string& name, const int signReqGrade, const int execReqGrade) : 
	_name(name),
	_signed(false),
	_signReqGrade(signReqGrade),
	_execReqGrade(execReqGrade)
{
	if (_signReqGrade > 150 || _execReqGrade > 150)
		throw Form::GradeTooLowException();
	if (_signReqGrade <= 0 || _execReqGrade <= 0)
		throw Form::GradeTooHighException();
}

Form::Form( const Form& copy ) :
	_name(copy._name),
	_signed(copy._signed),
	_signReqGrade(copy._signReqGrade),
	_execReqGrade(copy._execReqGrade)
{}

Form& Form::operator=( const Form& rhs ) {
	if (this != &rhs) {
		_signed = rhs._signed;
		// _name, _signReqGrade et _execReqGrade sont constants donc pas dassignation
	}
	return *this;
}

void	Form::beSigned( const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_signReqGrade)
		// throw Form::GradeTooHighException();
		throw Bureaucrat::GradeTooLowException(); 	// le sujet demande AForm::GradeTooLow... mais Bureaucrat est plus logique
													// Si un formulaire ne peut etre signé son grade serait trop grand pas trop petit
	_signed = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade too high !";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade too low !";
}

// Functions

const std::string& Form::getName( void ) const {
	return _name;
}
bool Form::getSigned( void ) const {
	return _signed;
}
const int& Form::getSignGrade( void ) const {
	return _signReqGrade;
}
const int& Form::getExecGrade( void ) const {
	return _execReqGrade;
}

/// @brief Surcharge l'opérateur <<
/// @param os Le stream à utiliser
/// @param obj Le bureaucrat à logger
/// @return Le stream mis à jour
std::ostream& operator<<( std::ostream& os, const Form& obj ) {
	os <<
		"Form data : {\n\t" <<
		obj.getName() << "\n\t" <<
		obj.getSigned() << "\n\t" <<
		obj.getSignGrade() << "\n\t" <<
		obj.getExecGrade() << "\n}" <<
	std::endl;
	return os;
}

Form::~Form() {}