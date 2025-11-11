#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	//because i and j are pointers to Animal, you cannot call Cat or Dog specific functions on them. The compiler only allows you to call functions that are part of the Animal interface.
	std::cout << j->getType() << " : ";
	j->makeSound();
	std::cout << i->getType() << " : ";
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << " : ";
	wrong->makeSound(); // Will call WrongAnimal's sound
	delete wrong;

	return (0);
}
