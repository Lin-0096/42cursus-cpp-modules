#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal& type);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	const std::string& getType() const;
	virtual void makeSound()const; //virtual for polymorphism
};

#endif

