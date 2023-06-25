#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

const std::string START_RED = "\033[1;31m";
const std::string STOP_RED = "\033[0m";

int main() {

	std::cout << START_RED << "-------MAKING FORMS BY INTERN-------" << STOP_RED << std::endl;
	Intern intern;
	AForm* presedentialForm = intern.makeForm("presidential pardon", "Cole");
	AForm* robotomyForm = intern.makeForm("robotomy request", "Mac");
	AForm* shrubberyForm = intern.makeForm("shrubbery creation", "William");
	AForm* nonExistingForm= intern.makeForm("non existing form", "Travis");

	std::cout << START_RED << "-------INITIALIZING 2 BUREAUCRATS: Joe(1 grade) AND Davis(80 grade) -------" << STOP_RED << std::endl;
	Bureaucrat j = Bureaucrat("Joe", 1);
	Bureaucrat d = Bureaucrat("Davis", 80);

	std::cout << START_RED << "-------EXECUTING WITHOUT SIGNING-------" << STOP_RED << std::endl;
	d.executeForm(*shrubberyForm);

	std::cout << START_RED << "-------SIGNING AND EXECUTING SHRUBBERY-------" << STOP_RED << std::endl;
	d.signForm(*shrubberyForm);
	d.executeForm(*shrubberyForm);

	std::cout << START_RED << "-------ALL SIGNED-------" << STOP_RED << std::endl;
	j.signForm(*robotomyForm);
	j.signForm(*presedentialForm);

	std::cout << START_RED << "-------EXECUTING WITH LOW GRADE-------" << STOP_RED << std::endl;
	d.executeForm(*robotomyForm);
	d.executeForm(*presedentialForm);

	std::cout << START_RED << "-------EXECUTING ROBOTOMY (RANDOM)-------" << STOP_RED << std::endl;
	j.executeForm(*robotomyForm);

	std::cout << START_RED << "-------EXECUTING PRESIDENTIAL-------" << STOP_RED << std::endl;
	j.executeForm(*presedentialForm);

	std::cout << START_RED << "-------DESTRUCTION-------" << STOP_RED << std::endl;
	if (nonExistingForm) {
		delete nonExistingForm;
	}
	delete presedentialForm;
	delete robotomyForm;
	delete shrubberyForm;
}