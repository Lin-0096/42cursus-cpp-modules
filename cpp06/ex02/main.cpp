#include "Base.hpp"

#include <iostream>

int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		Base *instance = generate();
		std::cout << "From pointer:   ";
		identify(instance);
		std::cout << "From reference: ";
		identify(*instance);
		delete instance;
	}
	return 0;
}
