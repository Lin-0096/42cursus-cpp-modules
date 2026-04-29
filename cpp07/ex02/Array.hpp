#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>   // for std::out_of_range

template <typename T>
class Array
{
	private:
		T* _data;  //pointer to array
		unsigned int _size;

	public:
		Array() : _data(nullptr), _size(0) {}
		Array(unsigned int n) : _data(new T[n]()), _size(n) {}
		Array(const Array& other) : _data(new T[other._size]()), _size(other._size)
		{
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}

		Array(Array&& other) noexcept : _data(other._data), _size(other._size)
		{
			other._data = nullptr;
			other._size = 0;
		}

		~Array()
		{
			delete[] _data;
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				T* new_data = new T[other._size]();

				for (unsigned int i = 0; i < other._size; ++i)
					new_data[i] = other._data[i];

				delete[] _data;
				_data = new_data;
				_size = other._size;
			}
			return *this;
		}

		Array& operator=(Array&& other) noexcept
		{
			if (this != &other)
			{
				delete[] _data;

				_data = other._data;
				_size = other._size;

				other._data = nullptr;
				other._size = 0;
			}
			return *this;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}

		unsigned int size() const
		{
			return _size;
		}
};

#endif
