#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	index = 0;
	count = 0;
}

Phonebook::~Phonebook() {}

static std::string	promptfield(const std::string& fieldname)
{
	std::string	input;
	while (true)
	{
		std::cout << "Enter " << fieldname << ":";
		std::getline(std::cin, input);
		if (!input.empty())
			return input;
		std::cout << "Empty input" << std::endl;
	}
}

void	Phonebook::addContacts()
{
	std::string	input;
	input = promptfield("First Name");
	contact[index].setFirstName(input);
	input = promptfield("Last Name");
	contact[index].setLastName(input);
	input = promptfield("Nickname");
	contact[index].setNickName(input);
	input = promptfield("Phone Number");
	contact[index].setPhoneNumber(input);
	input = promptfield("Darkest Secret");
	contact[index].setDarkestSecret(input);
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}

void Phonebook::displayContacts()
{
	
}
