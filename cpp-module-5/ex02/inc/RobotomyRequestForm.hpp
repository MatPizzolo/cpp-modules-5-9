#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm {
	private:
		std::string target;
	
	public:
		// Constructors & Destructor
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		
		// Copy & Assignment (Orthodox Canonical AForm)
		RobotomyRequestForm(RobotomyRequestForm& copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);

		std::string getTarget() const ;
		void execute(Bureaucrat const& executor) const;
};

#endif