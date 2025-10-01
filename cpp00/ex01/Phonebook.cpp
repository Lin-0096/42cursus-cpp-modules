#include "Phonebook.hpp"
#include <iomanip>

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

static std::string formatfield(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0,9) + ".";
	else
		return std::string(10 - field.length(), ' ') + field;
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
	std::cout << "\033[32m" << "Contact added at index " << index << "\033[0m" << std::endl;
	index = (index + 1) % 8;
	if (count < 8)
		count++;
	std::cout << "\033[34m" << "Enter command (ADD / SEARCH / EXIT): "
			<< "\033[0m";
}

void Phonebook::displayContacts() const
{
	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|"
			<< std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|"
			<< formatfield(contact[i].getFirstName()) << "|"
			<< formatfield(contact[i].getLastName()) << "|"
			<< formatfield(contact[i].getNickName()) << "|"
			<< std::endl;
	}
}

void Phonebook::displayContactdetail(int index) const
{
	if (index < 0 || index > 7)
	{
		std::cout << "\033[31m" << "Invalid Index!" << "\033[0m" << std::endl;
		std::cout << "\033[34m" << "Enter command (ADD / SEARCH /EXIT): " << "\033[0m";
		return ;
	}
	else if (contact[index].getFirstName().empty())
	{
		std::cout << "No such contact!" << std::endl;
		std::cout << "\033[34m" << "Enter command (ADD / SEARCH /EXIT): " << "\033[0m";
		return ;
	}
	std::cout << "First name: " << contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contact[index].getNickName()<< std::endl;
	std::cout << "Phone Number: " << contact[index].getPhoneNumber()<< std::endl;
	std::cout << "Darkest secret: " << contact[index].getDarkestSecret() << std::endl;

	std::cout << "\033[34m" << "Enter command (ADD / SEARCH /EXIT): " << "\033[0m";
}
