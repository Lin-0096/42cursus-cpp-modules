#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <stdexcept>

static void printChar(double v)
{
	std::cout << "char: ";
	if (std::isnan(v) || std::isinf(v)
		|| v < std::numeric_limits<char>::min()
		|| v > std::numeric_limits<char>::max())
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(static_cast<char>(v))))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(v) << "'\n";
}

static void printInt(double v)
{
	std::cout << "int: ";
	if (std::isnan(v) || std::isinf(v)
		|| v < static_cast<double>(std::numeric_limits<int>::min())
		|| v > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(v) << "\n";
}

static void printFloat(double v)
{
	float f = static_cast<float>(v);
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff") << "\n";
	else if (std::floor(f) == f)
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	else
		std::cout << f << "f\n";
}

static void printDouble(double v)
{
	std::cout << "double: ";
	if (std::isnan(v))
		std::cout << "nan\n";
	else if (std::isinf(v))
		std::cout << (v > 0 ? "+inf" : "-inf") << "\n";
	else if (std::floor(v) == v)
		std::cout << std::fixed << std::setprecision(1) << v << "\n";
	else
		std::cout << v << "\n";
}

static const std::string impossible =
	"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";

void ScalarConverter::convert(const std::string &s)
{
	double v;

	if (s == "nanf" || s == "nan")
		v = std::numeric_limits<double>::quiet_NaN();
	else if (s == "+inff" || s == "+inf")
		v = std::numeric_limits<double>::infinity();
	else if (s == "-inff" || s == "-inf")
		v = -std::numeric_limits<double>::infinity();
	else if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		v = static_cast<double>(s[0]);
	else if (!s.empty() && s.back() == 'f' && s.find('.') != std::string::npos)
	{
		try { v = std::stod(s.substr(0, s.size() - 1)); }
		catch (...) { std::cout << impossible; return; }
	}
	else if (s.find('.') != std::string::npos)
	{
		try { v = std::stod(s); }
		catch (...) { std::cout << impossible; return; }
	}
	else
	{
		try { v = std::stod(s); }
		catch (...) { std::cout << impossible; return; }
	}

	printChar(v);
	printInt(v);
	printFloat(v);
	printDouble(v);
}
