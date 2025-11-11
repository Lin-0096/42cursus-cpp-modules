#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	Animal(); //Making it protected is cleaner and more intentional — it signals this class is for inheritance only.
	std::string type;
	Animal(const std::string& type);

public:

	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();//A virtual member is a member function that can be redefined in a derived class,

	const std::string& getType() const;
	virtual void makeSound()const = 0; //The = 0 doesn’t mean “return zero.” It means: “This function has no implementation in this class, and must be overridden by derived classes.”
};

#endif

/*
-abstraact bass class defines what behaviors derived classes must have, but not how they are implemented.
-A class becomes abstract when it has at least one pure virtual function.
-
*/
