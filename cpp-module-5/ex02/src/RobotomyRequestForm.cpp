#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45), target("default") {
	std::cout << "Constructor RobotomyRequestForm called" << std::endl;
	std::cout << "Make some drilling noises " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45), target(target) {
	std::cout << "Constructor RobotomyRequestForm called" << std::endl;
	std::cout << "Make some drilling noises " << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();

	std::cout << "Some drilling noises" << std::endl;
	// 50/50 for the robotomize
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}

// Copy & Assignment (Orthodox Canonical Form)
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy): AForm(copy), target(copy.getTarget()) {
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->target = other.getTarget();
	return *this;
}