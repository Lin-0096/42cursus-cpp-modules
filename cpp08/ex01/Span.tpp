#ifndef SPAN_TPP
#define SPAN_TPP

template <typename InputIt>
void Span::addRange(InputIt first, InputIt last)
{
	std::vector<int> values(first, last);
	if (_numbers.size() + values.size() > _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.insert(_numbers.end(), values.begin(), values.end());
}

#endif
