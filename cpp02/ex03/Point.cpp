#include "Point.hpp"

Point::Point() :_x(0), _y(0)
{
};

Point::Point(const float a, const float b)
:_x(a), _y(b)
{
};

Point::Point(const Point& other) :_x(other._x), _y(other._y)
{
};


Point& Point::operator=(const Point& other)
{
	(void)other; //const member can't be reasigned
	return *this;
}

Point::~Point()
{
};

Fixed Point::getX() const
{
	return this->_x;
}

Fixed Point::getY() const
{
	return this->_y;
}
