#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm() = delete;
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other) = default;
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = default;
	~PresidentialPardonForm() = default;

protected:
	void executeAction() const override;

private:
	std::string _target;
};
