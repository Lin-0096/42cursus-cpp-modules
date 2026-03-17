#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <stdexcept>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	long long minSpan = LLONG_MAX;
	for (std::size_t i = 1; i < sorted.size(); ++i)
	{
		long long currentSpan = static_cast<long long>(sorted[i]) - static_cast<long long>(sorted[i - 1]);
		if (currentSpan < minSpan)
			minSpan = currentSpan;
	}
	return static_cast<unsigned int>(minSpan);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	const int minValue = *std::min_element(_numbers.begin(), _numbers.end());
	const int maxValue = *std::max_element(_numbers.begin(), _numbers.end());
	return static_cast<unsigned int>(static_cast<long long>(maxValue) - static_cast<long long>(minValue));
}
