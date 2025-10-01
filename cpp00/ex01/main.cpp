#include "Phonebook.hpp"

int	main()
{
	std::string command;
	Phonebook phonebook;

	std::cout << "\033[31m" << "Welcome to my Awesome Phonebook!" << "\033[0m" << std::endl;
	std::cout << "Available commands: " << "\033[34m" << "ADD, SEARCH, EXIT" << "\033[0m" << std::endl;
	while(true)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContacts();
		else if (command == "SEARCH")
		{
			phonebook.displayContacts();
			std::cout << "Enter index between 0 and 7 to view details: ";
			std::string	input;
			std::getline(std::cin, input);
			if (input.length() != 1 || !isdigit(input[0]))
			{
				std::cout << "\033[31m" << "Invalid Index format!" << "\033[0m" << std::endl;
				std::cout << "\033[34m" << "Enter command (ADD / SEARCH /EXIT): " << "\033[0m";
				continue;
			}
			int index = input[0] - '0';
			phonebook.displayContactdetail(index);
		}
		else if (command == "EXIT")
		{
			std::cout << "Bye!" << std::endl;
			break;
		}
		else
			std::cout << "Unknown command, enter again!" << std::endl;
	}
}
