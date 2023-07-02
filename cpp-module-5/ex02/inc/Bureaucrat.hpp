#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

    private:
        const std::string name;
        int grade;
    
    public:
    // Constructors && Destructor
        Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
    
    // Copy & Assignment (Orthodox Canonical Form)
        Bureaucrat(Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat& other);

    // Member Functions
        std::string getName() const;
        int getGrade() const;
        void decrementGrade();
        void incrementGrade();
        void signForm(std::string name, bool sign);

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

bool isGradeToHigh(int grade);
bool isGradeToLow(int grade);

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif