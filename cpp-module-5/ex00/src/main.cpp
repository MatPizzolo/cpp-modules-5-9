#include <iostream>

#include "../inc/Bureaucrat.hpp"

int main()
{
	Bureaucrat mateo("mateo", 150);
	std::cout << &mateo;

	std::cout << std::endl;

	Bureaucrat low("low", 1);
	std::cout << &low;
	low.incrementGrade();
	std::cout << &low;

	std::cout << std::endl;

	Bureaucrat high("high", 150);
	std::cout << &high;
	high.decrementGrade();
	std::cout << &high;

	std::cout << std::endl;

	Bureaucrat a("other", 1150);
	std::cout << &a;
	Bureaucrat b("other", -100);
	std::cout << &b;
	
	std::cout << std::endl;

	Bureaucrat *c = new Bureaucrat("pepe");
	std::cout << c;

	std::cout << std::endl;

	delete c;
}