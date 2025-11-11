#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain deconstructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called."<< std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy assignment called" << std::endl;
	return *this;
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i > 100)
		return "";
	return ideas[i];
}

void Brain::setIdea(int i, std::string& idea)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
}
