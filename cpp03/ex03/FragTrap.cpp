#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
:FragTrap("Fragtrap")
{
}

FragTrap::FragTrap(const std::string& name)
:ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
:ClapTrap(other)
{
	std::cout << "A clone of FragTrap " << other.name << " created!" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << this->name << " assigned from " << other.name << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (hitPoints == 0)
		std::cout << "FragTrap " << name << " is too dead to request high fives." << std::endl;
	else
		std::cout << "FragTrap " << name << " requests high fives." << std::endl;
}
