#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
public:
	Intern() = default;
	Intern(const Intern& other) = default;
	Intern& operator=(const Intern& other) = default;
	~Intern() = default;

	AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
	typedef AForm* (*FormCreator)(const std::string& target);

	static AForm* createShrubberyCreationForm(const std::string& target);
	static AForm* createRobotomyRequestForm(const std::string& target);
	static AForm* createPresidentialPardonForm(const std::string& target);
};
