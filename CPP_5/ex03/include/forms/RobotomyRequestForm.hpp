#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
#define __ROBOTOMY_REQUEST_FORM_HPP__

#include "office/Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	private:
		int			_mod;
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name);
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& rhs );

		void subExecute( void );

		~RobotomyRequestForm();
};

#endif