#include <iostream>

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
		Bureaucrat(int, const std::string&);
		Bureaucrat( const Bureaucrat& );
		Bureaucrat& operator=( const Bureaucrat& );

		const std::string& 	getName( void ) const;
		const int&			getGrade( void ) const;

		void upgrade();
		void downgrade();

		~Bureaucrat();
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj );
