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
	hitPoints(FragTrap::hitPoints);
	energyPoints(ScavTrap::energyPoints);
	attackDamage(FragTrap::attackDamage);
	std::cout << "Diamond " << name << " constructed!" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other)
{

}
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	void attack(const std::string& target);
	void whoAmI();
