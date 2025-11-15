#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_index;
		int		_count;
	public:
		PhoneBook();

		void	addContact(std::string* infos);
		void	searchContact(int index) const;
		void	displayContacts() const;

		~PhoneBook();
};

#endif