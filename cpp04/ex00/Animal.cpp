#include "Animal.hpp"
#include <iostream>

Animal::Animal()
:type("animal")
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
