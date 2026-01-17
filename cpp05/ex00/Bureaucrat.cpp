#include "Bureaucrat.hpp"

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

Bureaucrat::~Bureaucrat(){}

int Bureaucrat::getGrade()const
{
	return (this->_grade);
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
