#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name)
:ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
		std::cout << "ScavTrap " << name << " is dead." << std::endl;
	else if (energyPoints == 0)
		std::cout << "ScavTrap " << name << " has no energy points!" << std::endl;
	else
	{
		energyPoints --;
		std::cout << "ScavTrap " << name << " attacks " << target
				<< " , causing" << attackDamage << " points of damage!"
				<< std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
