#include "../inc/whatever.hpp"

template<typename T>
void big_test(T& a, T& b) {

	std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

	T minimum = ::min(a, b);
	std::cout << "Minimum value: " << minimum << std::endl;
	T maximum = ::max(a, b);
	std::cout << "Maximum value: " << maximum << std::endl;
}

void ex_test() {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main( void ) {
	int a = 10;
	int b = 20;
	big_test<int>(a, b);
	std::cout << std::endl;
	double c = 22.5;
	double d = 10.2;
	big_test<double>(c, d);
	std::cout << std::endl;
	char e = 'e';
	char f = 'f';
	big_test<char>(e, f);
	std::cout << std::endl;
	std::string str1 = "hola";
	std::string str2 = "chau";
	big_test<std::string>(str1, str2);
	return 0;
}