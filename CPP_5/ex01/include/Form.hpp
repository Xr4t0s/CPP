#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signReqGrade;
		const int			_execReqGrade;
	
	public:
		struct GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		struct GradeTooLowException : std::exception {
			public:
				const char* what() const throw();
		};

		Form();
		Form( const std::string& name, const int signReqGrade, const int execReqGrade);
		Form( const Form& copy);
		Form& operator=( const Form& rhs);
		
		const std::string& 	getName( void ) const;
		bool				getSigned( void ) const;
		const int&			getSignGrade( void ) const;
		const int&			getExecGrade( void ) const;

		void beSigned( const Bureaucrat& bureaucrat);

		~Form();
};

std::ostream& operator<<( std::ostream&, const Form& form);