#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("a", 200);
	Bureaucrat b("b", 0);
	Bureaucrat c("c", 1);
	Bureaucrat d("d", 150);
	Bureaucrat e("e", 67);
	Bureaucrat f(e);
	Bureaucrat g;
	g = a;

	try{
		throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception & e){

	}
}

