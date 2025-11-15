#include "PhoneBook.hpp"

int main() {
	PhoneBook phonebook;
	int error;

	while (1)
	{
		error = 0;
		std::string input;

		std::cout << "What do you want to do ? (ADD, SEARCH, EXIT)\n> ";
		std::getline(std::cin, input);
		for (int i = 0; input[i]; i++)
			input[i] = std::tolower(input[i]);
		std::cout << "\033[2J\033[H";
		if (input == "add")
		{
			std::string infos[5];
			std::cout << "Enter the new contact information :" << std::endl;
			std::cout << "\tFirst name : ";
			std::getline(std::cin, infos[0]);
			std::cout << "\tLast name : ";
			std::getline(std::cin, infos[1]);
			std::cout << "\tNickname : ";
			std::getline(std::cin, infos[2]);
			std::cout << "\tPhone number : ";
			std::getline(std::cin, infos[3]);
			std::cout << "\tDarkest secret : ";
			std::getline(std::cin, infos[4]);
			for (int i = 0; i < 5; i++) {
				if (infos[i].empty() || infos[i] == "\n" ) {
					error = -1;
					std::cout << "Invalid parameters in the requests" << std::endl;
					break ;
				}
			}
			if (!error)
				phonebook.addContact(infos);
		}
		if (input == "search")
		{
			std::string index;
			phonebook.displayContacts();
			std::cout << "Enter the contact index you want to display : ";
			std::getline(std::cin, index);
			std::cout << "\033[2J\033[H";
			if (index == "1")
				phonebook.searchContact(1);
			else if (index == "2")
				phonebook.searchContact(2);
			else if (index == "3")
				phonebook.searchContact(3);
			else if (index == "4")
				phonebook.searchContact(4);
			else if (index == "5")
				phonebook.searchContact(5);
			else if (index == "6")
				phonebook.searchContact(6);
			else if (index == "7")
				phonebook.searchContact(7);
			else if (index == "8")
				phonebook.searchContact(8);
			else
				std::cout << "Phonebook can only store 8 contacts !" << std::endl;
		}
		if (input == "exit")
			return 0;			
	}
}