#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	//Animal a;
	// error: cannot declare variable ‘a’ to be of abstract type ‘Animal’

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	delete dog;
	delete cat;

	return 0;
}
