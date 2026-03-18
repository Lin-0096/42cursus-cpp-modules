#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm() = delete;
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other) = default;
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = default;
	~RobotomyRequestForm() = default;

protected:
	void executeAction() const override;

private:
	std::string _target;
};
