#include <iostream>

#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

void big_test() {
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		Intern *z = new Intern();
		AForm *b = z->makeForm("RobotomyRequestForm", "Bender");
		AForm *c = z->makeForm("ShrubberyCreationForm", "Cristmas");
		// Form *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		b->beSigned(*a);
		a->signForm(*c);
		std::cout << std::endl;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		for (int i= 0; i < 10; i++)
			b->execute(*a);
		a->executeForm(*c);
		// c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		delete z;
		std::cout << std::endl;
	}
}

void small_test() {
	Bureaucrat mateo("mateo", 143);
	ShrubberyCreationForm a;

	std::cout << "-" << std::endl;
	a.beSigned(mateo);
	std::cout << "-" << std::endl;
	ShrubberyCreationForm b(a);
	std::cout << "-" << std::endl;
	mateo.executeForm(a);
	std::cout << "-" << std::endl;
}

int main()
{
	// small_test();
	big_test();

}