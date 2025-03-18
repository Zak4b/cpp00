#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
: index(0), count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add(Contact new_contact)
{
	this->list[this->index % 8] = new_contact;
	this->index++;
	if (this->count < 8)
		this->count++;
}

void	PhoneBook::search(void)
{
	int	offset;

	offset = (this->count < 8) ? 0 : this->index;
    for (int i = 0; i < this->count; i++)
	{
        std::cout << this->list[(offset + i) % 8].to_string() << std::endl;
	}
}