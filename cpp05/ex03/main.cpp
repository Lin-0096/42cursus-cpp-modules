#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	std::cout << "=== Create and execute robotomy request ===" << std::endl;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n=== Create and execute shrubbery creation ===" << std::endl;
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
	if (scf)
	{
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	std::cout << "\n=== Create and execute presidential pardon ===" << std::endl;
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (ppf)
	{
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	std::cout << "\n=== Unknown form name ===" << std::endl;
	AForm* unknown = someRandomIntern.makeForm("coffee request", "Campus");
	delete unknown;

	return 0;
}
