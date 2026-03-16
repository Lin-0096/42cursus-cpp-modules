#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	int _grade;
	const std::string _name;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat() = default;

	int getGrade()const;
	const std::string& getName()const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& form) const;
	void executeForm(const AForm& form) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade too high";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade too low";
			}
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
