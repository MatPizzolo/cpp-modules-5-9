#include "../inc/Form.hpp"

// Constructors & Destructor
Form::Form(): name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {
	std::cout << "Form default Constructor called" << std::endl;
}
Form::Form(std::string name): name(name), isSigned(false), gradeToSign(1), gradeToExecute(1) {
	std::cout << "Form " << name << " Constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
 	: name(name), isSigned(false), gradeToSign(checkGrade(gradeToSign)), gradeToExecute(checkGrade(gradeToExecute)) {
	std::cout << "Form " << name << " Constructor called" << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute)
 	: name(name), isSigned(isSigned), gradeToSign(checkGrade(gradeToSign)), gradeToExecute(checkGrade(gradeToExecute)) {
	std::cout << "Form " << name << " Constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form " << this->name << " Destructor called" << std::endl;
}


// Member Functions
int Form::checkGrade(int grade) {
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

void Form::beSigned(Bureaucrat &other) {
	if (this->isSigned) {
		std::cout << "Form is already signed" << std::endl;
		return ;
	}
	try {
		if (other.getGrade() > this->gradeToSign) {
			other.signForm(this->name, false);
			throw GradeTooLowException();
		}
		else {
			this->isSigned = true;
			other.signForm(this->name, true);
		}
	} catch(const GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

std::string Form::getName() const {
	return (this->name);
}
bool Form::getIsSigned() const {
	return (this->isSigned);
}
int Form::getGradeToSign() const {
	return (this->gradeToSign);
}
int Form::getGradeToExecute() const {
	return (this->gradeToExecute);
}


// Class throw exceptions
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for Form");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for Form");
};

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	std::string sig;
	if (a->getIsSigned())
		sig = "is signed";
	else
		sig = "isn't signed";
	o << "Form: " << a->getName() << "; " << sig << ", grade to sign: " << a->getGradeToSign() << "; grade to execute: " << a->getGradeToExecute() << std::endl;
	return (o);
}