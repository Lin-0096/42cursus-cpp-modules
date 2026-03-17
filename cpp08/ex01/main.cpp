#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <random>
#include <vector>

static void subjectTest()
{
	std::cout << "[Subject test]" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void overflowTest()
{
	std::cout << "\n[Overflow test]" << std::endl;
	Span sp(2);
	sp.addNumber(1);
	sp.addNumber(2);
	try
	{
		sp.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void notEnoughValuesTest()
{
	std::cout << "\n[Not enough values test]" << std::endl;
	Span sp(5);
	sp.addNumber(42);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void duplicateValuesTest()
{
	std::cout << "\n[Duplicate values test]" << std::endl;
	Span sp(4);
	sp.addNumber(5);
	sp.addNumber(5);
	sp.addNumber(12);
	sp.addNumber(30);
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;
}

static void rangeInsertTest()
{
	std::cout << "\n[Range insert test]" << std::endl;
	Span sp(8);
	std::vector<int> values;
	for (int i = 10; i < 18; ++i)
		values.push_back(i);
	sp.addRange(values.begin(), values.end());
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;
}

static void bigTest()
{
	std::cout << "\n[Big test: 15000 numbers]" << std::endl;
	const int count = 15000;
	std::vector<int> values;
	values.reserve(count);
	for (int i = 0; i < count; ++i)
		values.push_back(i * 2);
	std::mt19937 generator(42);
	std::shuffle(values.begin(), values.end(), generator);

	Span sp(static_cast<unsigned int>(count));
	sp.addRange(values.begin(), values.end());
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;
}

int main()
{
	subjectTest();
	overflowTest();
	notEnoughValuesTest();
	duplicateValuesTest();
	rangeInsertTest();
	bigTest();
	return 0;
}
