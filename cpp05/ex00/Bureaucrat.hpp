#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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
	~Bureaucrat();

	int getGrade()const;
	const std::string& getName()const;
	void incrementGrade();
	void decrementGrade();
	class GradeTooHighException : public std::exception{
		const char* what()const throw(){
			return "Grade too high";
		}
	};

	class GradeTooLowException : public std::exception{
		const char* what() throw(){
			return "Grade too high";
		}
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
