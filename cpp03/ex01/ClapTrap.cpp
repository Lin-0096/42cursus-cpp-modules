#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
:ClapTrap("ClapTrap") //Delegate default construction to the name-based constructor
{
}

ClapTrap::ClapTrap(const std::string& name)
:name(name),
hitPoints(10),
energyPoints(10),
attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		std::cout << "ClapTrap " << this->name << " assigned from " << other.name << std::endl;
	}
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other)
:name(other.name),
hitPoints(other.hitPoints),
energyPoints(other.energyPoints),
attackDamage(other.attackDamage)
{
	std::cout << "A clone of ClapTrap " << name << " created!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead." << std::endl;
	else if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energy points!" << std::endl;
	else
	{
		energyPoints --;
		std::cout << "ClapTrap " << name << " attacks " << target
				<< " , causing" << attackDamage << " points of damage!"
				<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead." << std::endl;
	else if(amount > hitPoints)
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount
				<< " points of damage and dies!" << std::endl;
	}
	else
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage."
		<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead and can't be repaired" << std::endl;
	else if(energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energy and can't be repaired" << std::endl;
	else
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired for " << amount
		<< " points." << std::endl;
	}
}
