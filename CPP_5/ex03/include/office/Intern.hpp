#include "forms/AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& rhs);

		AForm*	makeForm(const std::string& name, const std::string& target);

		~Intern();
};