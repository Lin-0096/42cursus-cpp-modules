#include "Zombie.hpp"

int main()
{
	int N = 6;
	Zombie *horde = zombieHorde(N, "good");
	if (!horde)
	{
		std::cout << "failed to create horde" << std::endl;
		return 1;
	}
	for(int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
