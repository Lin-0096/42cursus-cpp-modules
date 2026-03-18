#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	const std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	const FormCreator creators[] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			AForm* createdForm = creators[i](target);
			std::cout << "Intern creates " << createdForm->getName() << std::endl;
			return createdForm;
		}
	}
	std::cerr << "Intern could not create form: unknown form name '" << formName << "'" << std::endl;
	return NULL;
}
