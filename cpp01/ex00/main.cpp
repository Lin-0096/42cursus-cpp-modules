#include "Zombie.hpp"

int	main()
{
	Zombie *heapzombie = newZombie("heapzombie");
	heapzombie->announce();
	delete heapzombie;

	randomChump("stackzombie");
}
