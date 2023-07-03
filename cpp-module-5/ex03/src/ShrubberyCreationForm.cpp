#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), target("default") {
	std::cout << "Constructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137), target(target) {
	std::cout << "Constructor ShrubberyCreationForm with target " << target << " called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
	for (int i = 0; i < 3; i++)
	{
		outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
	std::endl;
	}
	outfile.close();
}

// Copy & Assignment (Orthodox Canonical Form)
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy): AForm(copy), target(copy.getTarget()){
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->target = other.getTarget();
	return *this;
}