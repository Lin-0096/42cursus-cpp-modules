#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename);
	
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

	outfile << "       *" << std::endl;
	outfile << "      ***" << std::endl;
	outfile << "     *****" << std::endl;
	outfile << "    *******" << std::endl;
	outfile << "   *********" << std::endl;
	outfile << "      |||" << std::endl;
	outfile << "      |||" << std::endl;

	outfile.close();
}
