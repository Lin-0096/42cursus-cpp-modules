#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap //Every ScavTrap inherits all members (variables & functions) of ClapTrap.
{
public:
	ScavTrap(const std::string& name);
	~ScavTrap();

	void attack(const std::string& target); // override
	void guardGate(); // new behavior
};

#endif
