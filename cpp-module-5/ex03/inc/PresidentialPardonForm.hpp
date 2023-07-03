#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		std::string target;

	public:
		// Constructors & Destructor
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		// Copy & Assignment (Orthodox Canonical AForm)
		PresidentialPardonForm(PresidentialPardonForm& copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& other);

		void execute(Bureaucrat const& executor) const;
		std::string getTarget() const ;

};

#endif