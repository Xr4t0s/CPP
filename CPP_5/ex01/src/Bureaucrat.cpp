#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructions
Bureaucrat::Bureaucrat() : _name("Random"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooLowException(); 
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	}

	_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
	if (this != &rhs) {
		_grade = rhs._grade;
		// _name est constant donc pas dassignation
	}
	return *this;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high !";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low !";
}

// Fonctions

/// @brief Name getter
/// @return Référence constante vers le nom du bureaucrat 
const std::string& Bureaucrat::getName() const {
	return _name;
}

/// @brief Grade getter
/// @return Référence constante vers le grade du bureaucrat 
const int& Bureaucrat::getGrade() const {
	return _grade;
}

/// @brief Downgrade le bureaucrat
void Bureaucrat::downgrade() {
	if (_grade >= 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

/// @brief Upgrade le bureaucrat
void Bureaucrat::upgrade() {
	if (_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because of " << e.what() << std::endl;
		throw;
	}
}

/// @brief Surcharge l'opérateur <<
/// @param os Le stream à utiliser
/// @param obj Le bureaucrat à logger
/// @return Le stream mis à jour
std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj ) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}

Bureaucrat::~Bureaucrat() {}