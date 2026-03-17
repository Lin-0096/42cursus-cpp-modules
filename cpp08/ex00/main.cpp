#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

static void testVector()
{
	std::vector<int> values;
	values.push_back(10);
	values.push_back(20);
	values.push_back(30);

	std::vector<int>::iterator found = easyfind(values, 20);
	std::cout << "vector: found " << *found << std::endl;

	try
	{
		easyfind(values, 99);
	}
	catch (const std::exception &e)
	{
		std::cout << "vector: " << e.what() << std::endl;
	}
}

static void testList()
{
	std::list<int> values;
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);

	std::list<int>::iterator found = easyfind(values, 4);
	std::cout << "list: found " << *found << std::endl;
}

static void testConstDeque()
{
	const std::deque<int> values(3, 7);

	std::deque<int>::const_iterator found = easyfind(values, 7);
	std::cout << "const deque: found " << *found << std::endl;
}

int main()
{
	testVector();
	testList();
	testConstDeque();
	return 0;
}
