#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	Fixed(const int value);
	Fixed(const float value);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _rawBits; //it actually represents is a fixed-point float (value * 256)
	static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed); //Convert the fixed-point number into a real float(unlock and show the true value)
// we can't do std::cout << a (if Fixed a), so we should redefine << to let it print the class Fixed
//std::ostream&: return type, a reference to the output stream
//(std::ostream& out, const Fixed& fixed): out is the output stream (like std::cout); fixed is the object you're trying to print

#endif
