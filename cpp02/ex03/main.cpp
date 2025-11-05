#include "Point.hpp"

int main()
{
	Point a(0,0);
	Point b(8,0);
	Point c(0,8);

	Point p1(2, 2); //inside
	Point p2(9, 9); //ouside
	Point p3(4, 0); //edge
	Point p4(8, 0); //vertex

	std::cout << "p1: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "p4: " << bsp(a, b, c, p4) << std::endl;
}
