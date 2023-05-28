#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


int main() {
	AForm* presedentialForm = new PresidentialPardonForm("Cole");
	AForm* robotomyForm = new RobotomyRequestForm("Mac");
	AForm* shrubberyForm = new ShrubberyCreationForm("William");

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
	delete presedentialForm;
	delete robotomyForm;
	delete shrubberyForm;
}