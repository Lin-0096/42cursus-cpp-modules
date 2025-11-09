#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makesound() const
{
	std::cout << "Meow????" << std::endl;
}
