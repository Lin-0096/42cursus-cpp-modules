#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	:_rawBits(0)
{
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout<< "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << _fractionalBits;  // Multiply by 2^8
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * (1 << _fractionalBits));  // 1 << _fractionalBits = 256
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)_rawBits / (1 << _fractionalBits); //value/256
}

int Fixed::toInt( void ) const
{
	return _rawBits >> _fractionalBits; //Shift the bits to the right by 8
}





std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	return out << fixed.toFloat();
}
