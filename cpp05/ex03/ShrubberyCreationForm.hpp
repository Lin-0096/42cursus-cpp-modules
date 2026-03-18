#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm() = delete;
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other) = default;
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = default;
	~ShrubberyCreationForm() = default;

protected:
	void executeAction() const override;

private:
	std::string _target;
};

