#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "===== TEST 1: Valid Form Creation =====" << std::endl;
	try
	{
		Form f1("Tax Form", 50, 25);
		std::cout << f1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 2: Invalid Form (Grade Too High) =====" << std::endl;
	try
	{
		Form f2("Secret Form", 0, 10);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 3: Invalid Form (Grade Too Low) =====" << std::endl;
	try
	{
		Form f3("Garbage Form", 151, 10);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4: Successful Signing =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 40);
		Form f4("Leave Request", 50, 20);

		std::cout << bob << std::endl;
		std::cout << f4 << std::endl;

		bob.signForm(f4);
		std::cout << f4 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 5: Failed Signing (Grade Too Low) =====" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 100);
		Form f5("Top Secret", 50, 10);

		std::cout << jim << std::endl;
		std::cout << f5 << std::endl;

		jim.signForm(f5);
		std::cout << f5 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 6: Boundary Grades =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);

		Form f7("Boundary Form", 150, 1);

		boss.signForm(f7);     // should succeed
		intern.signForm(f7);  // should fail
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== ALL TESTS COMPLETED =====" << std::endl;
	return 0;
}


