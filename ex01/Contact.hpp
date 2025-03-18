#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string secret;
public:
	Contact(void);
	Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string secret);
	~Contact();
	std::string	to_string(void);
};

#endif