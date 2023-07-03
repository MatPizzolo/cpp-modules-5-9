#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		// Constructors & Destructor
		Form();
		Form(std::string name);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
		~Form();

	    // Copy & Assignment (Orthodox Canonical Form)
		Form(Form& copy);
		Form &operator=(const Form& other);

    	// Member Functions
		void beSigned(Bureaucrat& other);
		int checkGrade(int grade);
    	// Getters Functions
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		// Class throw exceptions
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &o, Form *a);

#endif