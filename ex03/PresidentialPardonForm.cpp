#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("No Name", "PresidentialPardonForm", false, 25, 5) {
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : AForm(copy) {
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm(target, "PresidentialPardonForm", false, 25, 5) {
	std::cout << "PresidentialPardonForm target constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	std::cout << "PresidentialPardonForm assigning operator is called" << std::endl;
	if (this == &rhs) {
		return *this;
	} else {
		return *this;
	}
}

void PresidentialPardonForm::executeForm() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
