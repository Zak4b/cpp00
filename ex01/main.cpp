#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::string	line;
	PhoneBook	*rep = new PhoneBook();
	// ADD, SEARCH et EXIT

	while (true)
	{	
		std::cin >> line;
		if (!line.compare("ADD"))
		{
			Contact	*e = new Contact("a");
			rep->add(e);
		}
		else if (!line.compare("SEARCH"))
			rep->search();
		else if (!line.compare("EXIT"))
			return (0);
		else
			std::cout << "Unknown command" << std::endl;
	}
}
