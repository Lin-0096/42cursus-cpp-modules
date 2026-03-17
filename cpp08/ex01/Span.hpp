#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span
{
  private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

  public:
	Span();
	explicit Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	template <typename InputIt>
	void addRange(InputIt first, InputIt last);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#include "Span.tpp"

#endif
