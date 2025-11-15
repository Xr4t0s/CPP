#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

		void	_slice(std::string attr) const;

	public:
		Contact();

		void	create(std::string* infos);
		void	display(void) const;
		void	getInfos(std::string attr) const;

		~Contact();
};

#endif