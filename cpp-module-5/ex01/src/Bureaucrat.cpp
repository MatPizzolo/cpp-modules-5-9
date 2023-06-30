#include "../inc/Bureaucrat.hpp"

// Max grade checker function
bool isGradeToLow(int grade) {
	if (grade <= 0)
		return (true);
	return (false);
}

bool isGradeToHigh(int grade) {
	if (grade > 150)
		return (true);
	return (false);
}

// Constructors && Destructor
Bureaucrat::Bureaucrat(): name("default"), grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): name(name), grade(150) {
	std::cout << "Bureaucrat " << name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade) {
	std::cout << "Bureaucrat " << name << " constructor called" << std::endl;
	try {
		if (isGradeToHigh(grade))
			throw GradeTooHighException();
	}
	catch (const GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		this->grade = 150;
	}
	try {
		if (isGradeToLow(grade))
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		this->grade = 150;
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->name << " destructor called" << std::endl;
}

// Copy & Assignment (Orthodox Canonical Form)
Bureaucrat::Bureaucrat(Bureaucrat& copy) {
	this->grade = copy.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->grade = other.getGrade();
	return *this;
}

// Member Functions
std::string Bureaucrat::getName() const {
	return (name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::decrementGrade() {
	try {
		if (isGradeToHigh(this->grade + 1))
			this->grade += 1;
		else
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade() {
	try {
		if (isGradeToLow(this->grade - 1))
			this->grade -= 1;
		else
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(std::string name, bool sign) {
	if (sign)
		std::cout << this->name << " signed " << name << std::endl;
	else
		std::cout << this->name << " couldn't sign " << name << " because of grade too low " << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->getName() << ", Bureaucrat grade: " << a->getGrade() << std::endl;
	return (o);
}