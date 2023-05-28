#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main() {

	std::cout << "-------MAKING FORMS BY INTERN-------" << std::endl;
	Intern intern;
	AForm* presedentialForm = intern.makeForm("presidential pardon", "Cole");
	AForm* robotomyForm = intern.makeForm("robotomy request", "Mac");
	AForm* shrubberyForm = intern.makeForm("shrubbery creation", "William");
	AForm* nonExistingForm= intern.makeForm("non existing form", "Travis");

	Bureaucrat j = Bureaucrat("Joe", 1);
	Bureaucrat d = Bureaucrat("Davis", 80);

	std::cout << "-------EXECUTING WITHOUT SIGNING-------" << std::endl;
	d.executeForm(*shrubberyForm);

	std::cout << "-------SIGNING AND EXECUTING SHRUBBERY-------" << std::endl;
	d.signForm(*shrubberyForm);
	d.executeForm(*shrubberyForm);

	std::cout << "-------ALL SIGNED-------" << std::endl;
	j.signForm(*robotomyForm);
	j.signForm(*presedentialForm);

	std::cout << "-------EXECUTING WITH LOW GRADE-------" << std::endl;
	d.executeForm(*robotomyForm);
	d.executeForm(*presedentialForm);

	std::cout << "-------EXECUTING ROBOTOMY (RANDOM)-------" << std::endl;
	j.executeForm(*robotomyForm);

	std::cout << "-------EXECUTING PRESIDENTIAL-------" << std::endl;
	j.executeForm(*presedentialForm);

	std::cout << "-------DESTRUCTION-------" << std::endl;
	if (nonExistingForm) {
		delete nonExistingForm;
	}
	delete presedentialForm;
	delete robotomyForm;
	delete shrubberyForm;
}