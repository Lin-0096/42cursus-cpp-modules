#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	:_rawBits(0)
{

}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
	if(this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}

Fixed::~Fixed()
{

}

Fixed::Fixed(const int value)
{
	_rawBits = value << _fractionalBits;  // value Multiply by 2^8
}

Fixed::Fixed(const float value)
{
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

bool Fixed::operator>(const Fixed& other) const
{
	return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long long ltr = static_cast<long long>(this->_rawBits);
	long long lor = static_cast<long long>(other._rawBits);
	result.setRawBits(static_cast<int>(ltr * lor / (1 << _fractionalBits)));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long long ltr = static_cast<long long>(this->_rawBits);
	long long lor = static_cast<long long>(other._rawBits);
	result.setRawBits(static_cast<int>((ltr << _fractionalBits) / lor));
	return result;
}

Fixed& Fixed::operator++()
{
	this->_rawBits += 1;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->_rawBits -= 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_rawBits += 1;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_rawBits -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	return out << fixed.toFloat();
}
