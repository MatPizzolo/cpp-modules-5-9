#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		std::string target;

	public:
		// Constructors & Destructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

	    // Copy & Assignment (Orthodox Canonical AForm)
		ShrubberyCreationForm(ShrubberyCreationForm& copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);

		void execute(Bureaucrat const& executor) const;
		std::string getTarget() const ;

};

#endif