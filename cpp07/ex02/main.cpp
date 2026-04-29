#include <iostream>
#include "Array.hpp"

int	main(void)
{
	Array<int>	a(5);
	unsigned int	i;

	i = 0;
	while (i < a.size())
	{
		a[i] = i * 10;
		i++;
	}

	std::cout << "Original array:" << std::endl;
	i = 0;
	while (i < a.size())
	{
		std::cout << a[i] << std::endl;
		i++;
	}

	Array<int>	b(a);
	b[0] = 999;

	std::cout << "After copy modification:" << std::endl;
	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "b[0] = " << b[0] << std::endl;

	Array<std::string>	s(3);
	s[0] = "hello";
	s[1] = "cpp";
	s[2] = "templates";

	std::cout << "String array:" << std::endl;
	i = 0;
	while (i < s.size())
	{
		std::cout << s[i] << std::endl;
		i++;
	}

	try
	{
		std::cout << a[100] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: index out of bounds" << std::endl;
	}

	return (0);
}
