#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _rawBits;
	static const int _fractionalBits = 8;
};

#endif

//if we don't define =, = just does shallow copy,so if b=a, both a and b point to the same memory, if one is changed or deleted, the other is affected, this is shallow copy.
//wiht custom operate=, it is deep copy, after b=a, they have different memory block, same value


