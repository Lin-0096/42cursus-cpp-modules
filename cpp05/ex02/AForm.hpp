#pragma once

#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
public:
	AForm() = delete;
	AForm(const std::string& name, int _signGrade, int _executeGrade);
	AForm(const AForm& other) = default;
	AForm& operator=(const AForm& other) = default;
	virtual ~AForm()= default;

	const std::string& getName() const;
	bool getIsSigned()const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);
	void execute(const Bureaucrat& b) const;

	class GradeTooHighException: public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			 return "Grade too high";
		}
	};

	class GradeTooLowException: public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "Grade too low";
		}
	};

	class NotSignedException: public std::exception
	{
	public:
		const char* what() const noexcept override //test with and without const
		{
			return "Form is not signed";
		}
	};

protected:
	virtual void executeAction() const = 0;

private:
	const std::string _name;
	bool _isSigned = false;
	const int _gradeToSign;
	const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);
