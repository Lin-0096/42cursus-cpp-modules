#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int _signGrade, int _executeGrade)
:_name(name),
_gradeToSign(_signGrade),
_gradeToExecute(_executeGrade)
{
	if(_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if(_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned()const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if(b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(const Bureaucrat& b) const
{
	if(!_isSigned)
		throw NotSignedException();
	if (b.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << f.getName()
	<<", signed: " << (f.getIsSigned() ? "yes" : "no")
	<<", grade to sign: " << f.getGradeToSign()
	<<", grade to execute: " << f.getGradeToExecute();

	return out;
}
