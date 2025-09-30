#include "Phonebook.hpp"

int	main()
{
	std::string command;
	Phonebook phonebook;

	while(true)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContacts();
		else if (command == "SEARCH")
			phonebook.displayContacts();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command" << std::endl;
	}
}
