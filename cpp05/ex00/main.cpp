#include "Bureaucrat.hpp"

int main()
{
	//
	// Bureaucrat c("c", 1);
	// Bureaucrat d("d", 150);
	// Bureaucrat e("e", 67);
	// Bureaucrat f(e);
	// Bureaucrat g;
	// g = a;
	try
	{
		Bureaucrat a;
		std::cout << a << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	try
	{
		throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Alice", 42);
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Bob", 0);
		std::cout << c << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat d("Charlie", 151);
		std::cout << d << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

