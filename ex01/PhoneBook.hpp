#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

// tableau de contact
// 8 max

class PhoneBook
{
private:
	int		index;
	int		count;
	Contact	list[8];
public:
	PhoneBook(void);
	~PhoneBook();
	void	add(Contact new_contact);
	void	search(void);
};


#endif