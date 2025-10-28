#include "Harl.hpp"

int	getLevel(const std::string& string);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return (1);
	}
	Harl harl;
	int levelIndex = getLevel(argv[1]);
	switch (levelIndex)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			//fallthrough
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			//fallthrough
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			//fallthrough
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}

int	getLevel(const std::string& string)
{
	int	level = -1;
	if (string == "DEBUG")
		level = 0;
	else if (string == "INFO")
		level = 1;
	else if (string == "WARNING")
		level = 2;
	else if (string== "ERROR")
		level = 3;
	return (level);
}
