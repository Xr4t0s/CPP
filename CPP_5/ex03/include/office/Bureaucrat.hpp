#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include "forms/AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string 	_name;
		int					_grade;
	
	public:
		struct GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		struct GradeTooLowException : std::exception {
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(int grade, const std::string&);
		Bureaucrat( const Bureaucrat& );
		Bureaucrat& operator=( const Bureaucrat& );

		const std::string& 	getName( void ) const;
		const int&			getGrade( void ) const;

		void upgrade( void );
		void downgrade( void );

		void signForm( AForm& );
		void executeForm( AForm& );

		~Bureaucrat();
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj );

#endif