#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
:DiamondTrap("Diamond")
{
}

DiamondTrap::DiamondTrap(const std::string& name)
:ClapTrap(name + "_clap_name"),
name(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	std::cout << "Diamond " << name << " constructed!" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other)
:ClapTrap(other)
{
	std::cout << "A clone of DiamondTrap " << other.name << " created!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "DiamondTrap " << this->name << " assigned from " << other.name << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name is " << this->name << std::endl;
	std::cout << "ClapTrap's name is " << ClapTrap::name << std::endl;
}
