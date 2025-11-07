#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scav("ss");
	ScavTrap bob("bob");
	scav.attack("zombie");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	bob = scav;
	ScavTrap eric = bob;
	std::cout << "destruction order is:" << std::endl;
}
