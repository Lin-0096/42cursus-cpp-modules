#include "Point.hpp"

//u * v = u.x*v.y - u.y*v.x
//we want to know if p1 is at the same direction of p2-p3
//so we should do (p1-p3)*(p2-p3)
//u.x = p1.x - p3.x ; u.y = p1.y - p3.y
//v.x = p2.x - p3.x ; v.y = p2.y - p3.y
static Fixed	sign(Point const& p1, Point const& p2, Point const& p3)
{
	return (p1.getX()-p3.getX())*(p2.getY()-p3.getY())-(p1.getY()-p3.getY())*(p2.getX()-p3.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);
	return (d1 < 0 && d2 < 0 && d3<0) || (d1 > 0 && d2 > 0 && d3 > 0);
}
