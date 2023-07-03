#include "../inc/iter.hpp"

void toUpper(char& c) {
	c = std::toupper(c);
}

template <typename T>
void printElement(const T& element) {
	std::cout << element;
}

void times_two(int const &n)  {
	std::cout << n * 2 << " ";
}

int main( void ) {
	char str[] = {'h', 'o', 'l', 'a'};
	size_t length = sizeof(str) / sizeof(char);
	str[length] = '\0';
	
	::iter(str, length, printElement<char>);
	std::cout << std::endl;
	iter(str, length, toUpper);
	iter(str, length, printElement<char>);
	std::cout << std::endl;
	std::cout << std::endl;

	int array[] = {1, 2, 3, 4, 5};
	::iter(array, 5, times_two);
}