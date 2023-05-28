#include "Intern.hpp"

Intern::Intern() {
	this->typesOfForms[0] = "shrubbery creation";
	this->typesOfForms[1] = "robotomy request";
	this->typesOfForms[2] = "presidential pardon";
	this->formBuilders[0] = &Intern::buildShrubberyCreationForm;
	this->formBuilders[1] = &Intern::buildRobotomyRequestForm;
	this->formBuilders[2] = &Intern::buildPresedentialPardonForm;
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(Intern const & copy) {
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << std::endl;
}

Intern& Intern::operator=(Intern const &rhs) {
	std::cout << "Intern assigning operator is called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < NUMBER_OF_FORMS; i++) {
			this->typesOfForms[i] = rhs.typesOfForms[i];
			this->formBuilders[i] = rhs.formBuilders[i];
		}
	}
	return *this;
}

AForm* Intern::makeForm(std::string const &name, std::string const & target) {
	for (int i = 0; i < NUMBER_OF_FORMS; i++) {
		if (this->typesOfForms[i] == name) {
			return (this->*formBuilders[i])(target);
		}
	}
	std::cout << name << " form doesn't exist" << std::endl;
	return NULL;
}

AForm* Intern::buildPresedentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::buildRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::buildShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}