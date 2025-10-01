#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

#define CAPACITY 8

class Phonebook
{
private:
	Contact	contact[8];
	int	index;
	int	count;
public:
	Phonebook();
	~Phonebook();

	void	addContacts();
	void	displayContacts() const;
	void	displayContactdetail(int index) const;
};

#endif
