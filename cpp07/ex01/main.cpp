#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printValue(const T &value)
{
	std::cout << value << std::endl;
}

template <typename T>
void incrementValue(T &value)
{
	++value;
}

int main()
{
	int numbers[] = {1, 2, 3, 4};
	const std::size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "Before increment:" << std::endl;
	iter(numbers, numbersLen, printValue<int>);

	iter(numbers, numbersLen, incrementValue<int>);

	std::cout << "After increment:" << std::endl;
	iter(numbers, numbersLen, printValue<int>);

	const std::string words[] = {"hello", "iter", "template"};
	const std::size_t wordsLen = sizeof(words) / sizeof(words[0]);

	std::cout << "Const string array:" << std::endl;
	iter(words, wordsLen, printValue<std::string>);

	return 0;
}
