#include "forms/AForm.hpp"
#include "office/Bureaucrat.hpp"

// Constructions
AForm::AForm() : _name("Basic AForm"), _signed(false), _signReqGrade(150), _execReqGrade(150) {}
AForm::AForm(const std::string& name, const int signReqGrade, const int execReqGrade) : 
	_name(name),
	_signed(false),
	_signReqGrade(signReqGrade),
	_execReqGrade(execReqGrade)
{
	if (_signReqGrade > 150 || _execReqGrade > 150)
		throw AForm::GradeTooLowException();
	if (_signReqGrade <= 0 || _execReqGrade <= 0)
		throw AForm::GradeTooHighException();
}

AForm::AForm( const AForm& copy ) :
	_name(copy._name),
	_signed(copy._signed),
	_signReqGrade(copy._signReqGrade),
	_execReqGrade(copy._execReqGrade)
{}

AForm& AForm::operator=( const AForm& rhs ) {
	if (this != &rhs) {
		_signed = rhs._signed;
		// _name, _signReqGrade et _execReqGrade sont constants donc pas dassignation
	}
	return *this;
}

void	AForm::beSigned( const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_signReqGrade)
		throw Bureaucrat::GradeTooLowException(); 	// le sujet demande AForm::GradeToo... mais Bureaucrat est plus logique
													// sinon on peut faire la condition inverse et renvoyer les exceptions de AForm
	_signed = true;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade too high !";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade too low !";
}
const char* AForm::NotSigned::what() const throw() {
	return "Form not signed !";
}

// Functions

const std::string& AForm::getName( void ) const {
	return _name;
}
bool AForm::getSigned( void ) const {
	return _signed;
}
const int& AForm::getSignGrade( void ) const {
	return _signReqGrade;
}
const int& AForm::getExecGrade( void ) const {
	return _execReqGrade;
}

void AForm::execute(const Bureaucrat& executor) {
	if (!this->getSigned())
		throw AForm::NotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	this->subExecute();
	std::cout << executor.getName() << " executed " << this->getName() << " successfully !" << std::endl;
}

/// @brief Surcharge l'opérateur <<
/// @param os Le stream à utiliser
/// @param obj Le bureaucrat à logger
/// @return Le stream mis à jour
std::ostream& operator<<( std::ostream& os, const AForm& obj ) {
	os <<
		"AForm data : {\n\t" <<
		obj.getName() << "\n\t" <<
		obj.getSigned() << "\n\t" <<
		obj.getSignGrade() << "\n\t" <<
		obj.getExecGrade() << "\n}" <<
	std::endl;
	return os;
}

AForm::~AForm() {}