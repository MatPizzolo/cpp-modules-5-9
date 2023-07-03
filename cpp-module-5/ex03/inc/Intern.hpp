#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include "AForm.hpp"

class AForm;

class Intern {
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern &operator=(const Intern& other);
		AForm* makeForm(std::string form, std::string target);
};

#endif