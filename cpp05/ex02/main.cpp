#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrubbery("home");
		
		std::cout << bob << std::endl;
		std::cout << shrubbery << std::endl;
		
		bob.signForm(shrubbery);
		bob.executeForm(shrubbery);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 45);
		RobotomyRequestForm robotomy("Bender");
		
		std::cout << alice << std::endl;
		std::cout << robotomy << std::endl;
		
		alice.signForm(robotomy);
		alice.executeForm(robotomy);
		alice.executeForm(robotomy);  // Try again to see random success/failure
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("President", 5);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 4: Grade too low to sign ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon("Someone");
		
		std::cout << intern << std::endl;
		intern.signForm(pardon);  // Should fail - grade too low
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 5: Try to execute unsigned form ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("garden");
		
		boss.executeForm(form);  // Should fail - not signed
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 6: Grade too low to execute ===" << std::endl;
	try
	{
		Bureaucrat signer("Signer", 5);
		Bureaucrat executor("Executor", 10);
		PresidentialPardonForm pardon("Prisoner");
		
		signer.signForm(pardon);
		executor.executeForm(pardon);  // Should fail - grade too low to execute
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
