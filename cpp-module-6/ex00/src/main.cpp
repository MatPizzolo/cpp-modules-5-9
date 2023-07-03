#include "../inc/ScalarConverter.hpp"


int main(int argc, char **argv) {
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	} else {
		std::cout << "One argument is required" << std::endl;
	}
}