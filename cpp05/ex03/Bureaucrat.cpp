#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
:_grade(1),
_name("default")
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
:_grade(grade),
_name(name)
{
	if(_grade < 1)
		throw GradeTooHighException();
	if(_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
:_grade(other._grade),
_name(other._name)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		_grade = other._grade;
	return *this;
}

int Bureaucrat::getGrade()const
{
	return (this->_grade);
}

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because "
					<< e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because "
					<< e.what() << std::endl;
	}
}

const std::string& Bureaucrat::getName()const
{
	return (this->_name);
}


void Bureaucrat::incrementGrade()
{
	if(_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if(_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
