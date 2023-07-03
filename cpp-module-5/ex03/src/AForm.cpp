#include "../inc/AForm.hpp"

// Constructors & Destructor
AForm::AForm(): name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {
	std::cout << "AForm default Constructor called" << std::endl;
}
AForm::AForm(std::string name): name(name), isSigned(false), gradeToSign(1), gradeToExecute(1) {
	std::cout << "AForm " << name << " Constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
 	: name(name), isSigned(false), gradeToSign(checkGrade(gradeToSign)), gradeToExecute(checkGrade(gradeToExecute)) {
	std::cout << "AForm " << name << " Constructor called" << std::endl;
}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute)
 	: name(name), isSigned(isSigned), gradeToSign(checkGrade(gradeToSign)), gradeToExecute(checkGrade(gradeToExecute)) {
	std::cout << "AForm " << name << " Constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm " << this->name << " Destructor called" << std::endl;
}

// Member Functions
int AForm::checkGrade(int grade) {
	try {
		if (isGradeToHigh(grade))
			throw GradeTooHighException();
		if (isGradeToLow(grade))
			throw GradeTooLowException();
	} catch (const GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return (1);
	} catch (const GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (grade);
}

void AForm::beSigned(Bureaucrat &other) {
	if (this->isSigned) {
		std::cout << "Form is already signed" << std::endl;
		return ;
	}
	if (other.getGrade() > this->gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	else {
		this->isSigned = true;
		std::cout << other.getName() << " signed " << name << std::endl;
	}
}

std::string AForm::getName() const {
	return (this->name);
}
bool AForm::getIsSigned() const {
	return (this->isSigned);
}
int AForm::getGradeToSign() const {
	return (this->gradeToSign);
}
int AForm::getGradeToExecute() const {
	return (this->gradeToExecute);
}

// Copy & Assignment (Orthodox Canonical Form)
AForm::AForm(AForm& copy): name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->isSigned = other.getIsSigned();
	return *this;
}


// Class throw exceptions
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for Form");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for Form");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form isn't signed");
};

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	std::string sig;
	if (a->getIsSigned())
		sig = "is signed";
	else
		sig = "isn't signed";
	o << "Form: " << a->getName() << "; " << sig << ", grade to sign: " << a->getGradeToSign() << "; grade to execute: " << a->getGradeToExecute() << std::endl;
	return (o);
}