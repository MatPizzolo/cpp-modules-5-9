#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"
#include <fstream>


class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		// Constructors & Destructor
		AForm();
		AForm(std::string name);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

	    // Copy & Assignment (Orthodox Canonical AForm)
		AForm(AForm& copy);
		AForm &operator=(const AForm& other);
		
    	// Member Functions
		void beSigned(Bureaucrat& other);
		int checkGrade(int grade);
		virtual void execute(Bureaucrat const& executor) const = 0;
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

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};


};

std::ostream	&operator<<(std::ostream &o, AForm *a);

#endif