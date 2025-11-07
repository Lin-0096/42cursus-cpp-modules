#include "FragTrap.hpp"
#include <iostream>

int main()
{
	FragTrap frag("ff");

	frag.attack("zombie");
	frag.takeDamage(50);
	frag.beRepaired(30);
	frag.highFivesGuys();

	std::cout << "destruction order is:" << std::endl;
}

// int main()
// {
// 	FragTrap alice("Alice");
// 	FragTrap bob("Bob");
// 	alice.attack("Charlie");
// 	bob.highFivesGuys();
// }
