#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	read_line(std::string prompt)
{
	std::string	out;

	std::cout << prompt << " ";
	std::getline(std::cin, out);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cin.ignore(2000000, '\n');
	}
	return (out);
}

int main()
{
	std::string	line;
	PhoneBook	rep;

	while (true)
	{
		line = read_line("CMD:");
		if (!line.compare("ADD"))
		{
			std::string first_name = read_line("first_name:");
			std::string last_name = read_line("last_name:");
			std::string nick_name = read_line("nick_name:");
			std::string phone_number = read_line("phone_number:");
			std::string secret = read_line("secret:");
			Contact	new_contact(first_name, last_name, nick_name, phone_number, secret);
			rep.add(new_contact);
		}
		else if (!line.compare("SEARCH"))
			rep.search();
		else if (!line.compare("EXIT"))
			return (0);
		else
			std::cout << "Unknown command" << std::endl;
	}
}
