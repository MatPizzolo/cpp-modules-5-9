#include <iostream>

#include "../inc/Form.hpp"

int main()
{
	Bureaucrat mateo("mateo", 150);
	Bureaucrat harvey("harvey", 1);
	std::cout << &mateo;
	std::cout << &harvey;
	std::cout << std::endl;

	Form mat("mat");
	std::cout << &mat;
	std::cout << std::endl;

	Form lol("lol", 2, 120);
	std::cout << &lol;
	lol.beSigned(mateo);
	lol.beSigned(harvey);
	std::cout << &lol;
	std::cout << std::endl;

	Form trol("trol", true, 5, 5);
	std::cout << &trol;
	trol.beSigned(harvey);
	std::cout << &trol;
	std::cout << std::endl;

}