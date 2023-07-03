#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5), target("default") {
	std::cout << "Constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential", 25, 5), target(target) {
	std::cout << "Constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}

// Copy & Assignment (Orthodox Canonical Form)
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy): AForm(copy), target(copy.getTarget()) {
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->target = other.getTarget();
	return *this;
}