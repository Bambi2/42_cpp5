#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const std::string START_RED = "\033[1;31m";
const std::string STOP_RED = "\033[0m";

int main() {
	std::cout << START_RED << "-------INITIALIZING PRESIDENTIAL, ROBOTOMY AND SHRUBBERY FORMS -------" << STOP_RED << std::endl;
	AForm* presedentialForm = new PresidentialPardonForm("Cole");
	AForm* robotomyForm = new RobotomyRequestForm("Mac");
	AForm* shrubberyForm = new ShrubberyCreationForm("William");

	std::cout << START_RED << "-------INITIALIZING 2 BUREAUCRATS: Joe(1 grade) AND Davis(80 grade) -------" << STOP_RED << std::endl;
	Bureaucrat j = Bureaucrat("Joe", 1);
	Bureaucrat d = Bureaucrat("Davis", 80);

	std::cout << START_RED << "-------EXECUTING WITHOUT SIGNING-------" << STOP_RED << std::endl;
	d.executeForm(*shrubberyForm);

	std::cout << START_RED << "-------SIGNING AND EXECUTING SHRUBBERY (check the file)-------" << STOP_RED << std::endl;
	d.signForm(*shrubberyForm);
	d.executeForm(*shrubberyForm);

	std::cout << START_RED << "------- SIGN ALL -------" << STOP_RED << std::endl;
	j.signForm(*robotomyForm);
	j.signForm(*presedentialForm);

	std::cout << START_RED << "-------EXECUTING WITH LOW GRADE-------" << STOP_RED  << std::endl;
	d.executeForm(*robotomyForm);
	d.executeForm(*presedentialForm);

	std::cout << START_RED << "-------EXECUTING ROBOTOMY (RANDOM)-------" << STOP_RED  << std::endl;
	j.executeForm(*robotomyForm);

	std::cout << START_RED << "-------EXECUTING PRESIDENTIAL-------" << STOP_RED  << std::endl;
	j.executeForm(*presedentialForm);

	std::cout << START_RED << "-------DESTRUCTION-------" << STOP_RED  << std::endl;
	delete presedentialForm;
	delete robotomyForm;
	delete shrubberyForm;
}