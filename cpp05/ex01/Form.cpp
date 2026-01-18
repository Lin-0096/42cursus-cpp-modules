#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int _signGrade, int _executeGrade)
:_name(name),
_gradeToSign(_signGrade),
_gradeToExecute(_executeGrade)
{
	if(_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if(_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& b)
{
	if(b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned()const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.getName()
		<<", signed: " << (f.getIsSigned() ? "yes" : "NO")
		<<", grade to sign: " << f.getGradeToSign()
		<<", grade to execute: " << f.getGradeToExecute();
	return out;
}
