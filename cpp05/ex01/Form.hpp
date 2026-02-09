#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
public:
	Form(const std::string& name, int _signGrade, int _executeGrade);
	Form(const Form& other) = default;
	Form& operator=(const Form& other)=delete;
	~Form()= default;

	const std::string& getName() const;
	bool getIsSigned()const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);

	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			 return "Grade too high";
		}
	};

	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Grade too low";
		}
	};

private:
	const std::string _name;
	bool _isSigned = false;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
