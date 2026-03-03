#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <iostream>
#include <office/Bureaucrat.hpp>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool							_signed;
		const int					_signReqGrade;
		const int					_execReqGrade;
	
	public:
		struct GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		struct GradeTooLowException : std::exception {
			public:
				const char* what() const throw();
		};
		struct NotSigned : std::exception {
			public:
				const char* what() const throw();
		};

		AForm();
		AForm( const std::string& name, const int signReqGrade, const int execReqGrade);
		AForm( const AForm& copy);
		AForm& operator=( const AForm& rhs);
		
		const std::string& 	getName( void ) const;
		bool								getSigned( void ) const;
		const int&					getSignGrade( void ) const;
		const int&					getExecGrade( void ) const;

		void beSigned( const Bureaucrat& bureaucrat);

		void execute(Bureaucrat const & executor);

		virtual void subExecute( void ) = 0;

		virtual ~AForm();
};

std::ostream& operator<<( std::ostream&, const AForm& AForm);

#endif