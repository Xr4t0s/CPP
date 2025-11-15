#include "Contact.hpp"

void	Contact::_slice(std::string attr) const {
	int len = attr.length();
	for (int i = 0; i < 10 - len && i < 10; i++)
		std::cout << " ";
	if (len > 10)
	{
		for (int i = 0; attr[i] && i < 9; i++)
			std::cout << attr[i];
		std::cout << ".";
	}
	else
		std::cout << attr;
}

Contact::Contact() {}

void	Contact::create(std::string* infos) {
	_first_name = infos[0];
	_last_name = infos[1];
	_nickname = infos[2];
	_phone_number = infos[3];
	_darkest_secret = infos[4];
}

void	Contact::display( void ) const {
	std::cout << "First name\t : " << _first_name << std::endl;
	std::cout << "Last name\t : " << _last_name << std::endl;
	std::cout << "Nickname\t : " << _nickname << std::endl;
	std::cout << "Phone number\t : " << _phone_number << std::endl;
	std::cout << "Darkest secret\t : " << _darkest_secret << std::endl;
	std::cout << std::endl;
}

void	Contact::getInfos(std::string attr) const {
	if (attr == "first_name")
		_slice(_first_name);
	else if (attr == "last_name")
		_slice(_last_name);
	else if (attr == "nickname")
		_slice(_nickname);
	else if (attr == "phone_number")
		_slice(_phone_number);
}

Contact::~Contact() {}