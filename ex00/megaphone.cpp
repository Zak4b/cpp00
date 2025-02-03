#include <iostream>
#include <string>

char	*str_upper(char *str)
{
	for (size_t i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (size_t i = 1; i < argc; i++)
			std::cout << str_upper(argv[i]);
	}
	std::cout << "\n";
}