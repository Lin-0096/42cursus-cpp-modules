#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& type);
	WrongAnimal& operator=(const WrongAnimal& other);
	~WrongAnimal(); //wrong

	const std::string& getType() const;
	void makeSound() const;//wrong
};

#endif
