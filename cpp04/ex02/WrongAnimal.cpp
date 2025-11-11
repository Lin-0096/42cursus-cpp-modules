#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
:type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
:type(other.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongAnimal copy assignment\n";
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "generic WrongAnimal sound" << std::endl;
}


WrongAnimal::WrongAnimal(const std::string& type)
:type(type)
{
	std::cout << "WrongAnimal constructor with type " << std::endl;
}
