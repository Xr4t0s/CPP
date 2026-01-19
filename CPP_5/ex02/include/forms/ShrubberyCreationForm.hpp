#ifndef __SHURBBERY_CREATION_FORM_HPP__
#define __SHURBBERY_CREATION_FORM_HPP__

#include "office/Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& name);
		ShrubberyCreationForm( const ShrubberyCreationForm& copy );
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& rhs );

		void subExecute( void );

		~ShrubberyCreationForm();
};

#endif