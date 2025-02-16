#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>
# include <list>

// tableau de contact
// 8 max

class PhoneBook
{
private:
	unsigned short int	contact_count;
	std::list<Contact *>	list;
public:
	PhoneBook(void);
	~PhoneBook();
	void	add(Contact *e);
	void	search(void);
};

PhoneBook::PhoneBook(void)
{
	this->contact_count = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add(Contact *e)
{
	if (this->contact_count >= 8)
	{
		this->list.pop_front();
		this->contact_count--;
	}
	this->list.push_back(e);
	this->contact_count++;
}

void	PhoneBook::search(void)
{
    for (std::list<Contact *>::iterator it = this->list.begin(); it != this->list.end(); ++it) {
        std::cout << (*it)->name << std::endl;
    }
	
}

#endif