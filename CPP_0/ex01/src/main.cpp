#include "PhoneBook.hpp"

int is_valid_data(std::string* infos) {
	for (int i = 0; infos[0][i]; i++) {
		if (infos[0][i] < 65 || (infos[0][i] > 90 && infos[0][i] < 97) || infos[0][i] > 123) {
			std::cout << "\033[2J\033[H";
			std::cout << "The first name need to be only alphabetic" << std::endl;
			return 0;
		}
	}
	for (int i = 0; infos[1][i]; i++) {
		if (infos[1][i] < 65 || (infos[1][i] > 90 && infos[1][i] < 97) || infos[1][i] > 123) {
			std::cout << "\033[2J\033[H";
			std::cout << "The last name need to be only alphabetic" << std::endl;
			return 0;
		}
	}
	for (int i = 0; infos[2][i]; i++) {
		if (infos[2][i] < 65 || (infos[2][i] > 90 && infos[2][i] < 97) || infos[2][i] > 123) {
			std::cout << "\033[2J\033[H";
			std::cout << "The username need to be only alphabetic" << std::endl;
			return 0;
		}
	}
	for (int i = 0; infos[3][i]; i++) {
		if ((infos[3][i] < 48 && infos[3][i] > 57) || i > 15  ) {
			std::cout << "\033[2J\033[H";
			std::cout << "The phone number needs to match +<13 digits max> format" << std::endl;
			return 0;
		}
	}
	if (infos[3].length() < 10) {
		std::cout << "\033[2J\033[H";
		std::cout << "The phone number needs to match +<13 digits max> format" << std::endl;
		return 0;
	}
	return 1;
}

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
					std::cout << "\033[2J\033[H";
					std::cout << "Invalid parameters in the requests" << std::endl;
					break ;
				}
			}
			if (!error && is_valid_data(infos)) {
				phonebook.addContact(infos);
				std::cout << "\033[2J\033[H";
			}
		}
		if (input == "search")
		{
			std::string index;
			phonebook.displayContacts();
			std::cout << "Enter the contact index you want to display : ";
			std::getline(std::cin, index);
			std::cout << "\033[2J\033[H";
			if (index != "1" && index != "2" && index != "3" && index != "4" && index != "5" && index != "6" && index != "7" && index != "8")
				error = -1;
			if (error)
				std::cout << "You have to enter a number between 1 and 8" << std::endl;
			else if (index == "1")
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