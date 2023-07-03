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

static int robot_fail = 0;

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();

	if (robot_fail++ % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
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