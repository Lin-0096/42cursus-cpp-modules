#include "Animal.hpp"
#include <iostream>

Animal::Animal()
:type("Animal")
{
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal copy assignment\n";
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

const std::string& Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "* generic animal sound *" << std::endl;
}


Animal::Animal(const std::string& type)
:type(type)
{
	std::cout << "Animal constructor with type " << std::endl;
}
