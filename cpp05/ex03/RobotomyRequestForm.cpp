#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* drilling noises *" << std::endl;
	
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(nullptr));
		seeded = true;
	}
	
	if (std::rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed on " << _target << "!" << std::endl;
	}
}
