#include "Base.hpp"

#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}
	int random = std::rand() % 3;
	if (random == 0)
		return new A;
	if (random == 1)
		return new B;
	return new C;
}
