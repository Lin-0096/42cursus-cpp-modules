#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===" << std::endl;
	DiamondTrap d1("DiamondOne");
	d1.attack("Enemy");
	d1.guardGate();
	d1.highFivesGuys();
	d1.whoAmI();

	//copy di-d2
	std::cout << "===" << std::endl;
	DiamondTrap d2(d1); //DiamondTrap(const DiamondTrap& other)

	//assigning d1 to d3
	std::cout << "===" << std::endl;
	DiamondTrap d3;
	d3 = d1;
}
