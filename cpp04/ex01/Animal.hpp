#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;
	Animal(const std::string& type);

public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();//A virtual member is a member function that can be redefined in a derived class,

	const std::string& getType() const;
	virtual void makeSound()const; //virtual for polymorphism
};

#endif

