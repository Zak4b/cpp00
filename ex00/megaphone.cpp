#include <iostream>
#include <string>

std::string str_upper(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			std::cout << str_upper(str);
		}
	}
	std::cout << std::endl;
}