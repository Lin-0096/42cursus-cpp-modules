#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data original;
	original.id = 42;
	original.name = "hello";

	uintptr_t raw = Serializer::serialize(&original);
	Data *result = Serializer::deserialize(raw);

	std::cout << "original ptr : " << &original << std::endl;
	std::cout << "raw value    : " << raw << std::endl;
	std::cout << "result ptr   : " << result << std::endl;
	std::cout << "equal        : " << (result == &original ? "true" : "false") << std::endl;
	std::cout << "result->id   : " << result->id << std::endl;
	std::cout << "result->name : " << result->name << std::endl;

	return 0;
}
