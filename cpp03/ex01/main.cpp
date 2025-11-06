#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scav("ss");

	scav.attack("intruder");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "destruction order is:" << std::endl;
}
