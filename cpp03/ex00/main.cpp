#include "ClapTrap.hpp"

int main()
{
	ClapTrap k("KK");
	ClapTrap a("AA");
	for (int i = 0; i < 10; i++) {
		k.attack("CC");
		a.beRepaired(2);
	}
	a.takeDamage(6);
	k.takeDamage(1);
	a = k ;
	ClapTrap c = a;
}
