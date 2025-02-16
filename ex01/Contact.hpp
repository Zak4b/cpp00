#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
private:
	/* data */
public:
	std::string	name;
	Contact(std::string name);
	~Contact();
	std::string	to_string(void);
};

Contact::Contact(std::string name)
{
	this->name = name;
}

Contact::~Contact()
{
}

std::string Contact::to_string(void)
{
	return (this->name);
}

#endif