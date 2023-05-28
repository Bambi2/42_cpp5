#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

#define NUMBER_OF_FORMS 3

class Intern {
public:
	Intern();
	Intern(Intern const & copy);
	~Intern();

	Intern& operator=(Intern const &rhs);

	AForm* makeForm(std::string const &name, std::string const & target);
private:
	std::string typesOfForms[NUMBER_OF_FORMS];
	AForm* (Intern::*formBuilders[NUMBER_OF_FORMS])(std::string const &);
	AForm* buildPresedentialPardonForm(std::string const &target);
	AForm* buildRobotomyRequestForm(std::string const &target);
	AForm* buildShrubberyCreationForm(std::string const &target);
};

#endif