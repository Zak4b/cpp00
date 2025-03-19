#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

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

void	PhoneBook::print(void)
{
	int	offset;

	offset = (this->count < 8) ? 0 : this->index;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << " " << (i + 1) << " | " << this->list[(offset + i) % 8].summarize() << std::endl;
	}
}

void	PhoneBook::search(void)
{
	if (this->count == 0)
		return ;
	this->print();
	std::cout << "Index: ";
	std::string a;
	std::getline(std::cin, a);
	int	index;
	std::stringstream(a) >> index;
	if (index < 1 || index > this->count)
		return ;
	int offset = (this->count < 8) ? 0 : this->index;
	this->list[(offset + index - 1) % 8].print();
}