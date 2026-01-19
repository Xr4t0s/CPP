#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
#define __PRESIDENTIAL_PARDON_FORM_HPP__

#include "forms/AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm( const PresidentialPardonForm& copy );
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& rhs );

		void subExecute( void );

		~PresidentialPardonForm();
};

#endif