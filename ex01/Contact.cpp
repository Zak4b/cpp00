#include "Contact.hpp"
#include <string>
#include <iostream>

static std::string	format_field(std::string field)
{
	std::string	result(field);
	size_t		len;

	len = field.length();
	if (len > 10)
		result = result.substr(0, 9) + ".";
	else if (len < 10)
		result = std::string((10 - len), ' ') + result;
	return (result);
}

Contact::Contact(void)
{
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string secret)
: first_name(first_name), last_name(last_name), nick_name(nick_name), phone_number(phone_number), secret(secret)
{
}

Contact::~Contact()
{
}

std::string Contact::summarize(void)
{
	return (format_field(this->first_name) + "|" + format_field(this->last_name) + "|" + format_field(this->nick_name));
}

void	Contact::print(void)
{
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nick_name << std::endl;
	std::cout << this->phone_number << std::endl;
	std::cout << this->secret << std::endl;
}