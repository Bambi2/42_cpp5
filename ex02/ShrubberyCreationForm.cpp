#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("No Name", "ShrubberyCreationForm", false, 145, 137) {
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm(copy) {
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm(target, "ShrubberyCreationForm", false, 145, 137) {
	std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	std::cout << "ShrubberyCreationForm assigning operator is called" << std::endl;
	if (this == &rhs) {
		return *this;
	} else {
		return *this;
	}
}

void ShrubberyCreationForm::executeForm() const {
	std::ofstream ofs(this->getTarget() + "_shrubbery");

	if (ofs.fail()) {
		std::cerr << "Couldn't create '" << this->getTarget() + "_shrubbery" << "' file" << std::endl;
		return ;
	}

	ofs << "/\\" << std::endl
		<< "/\\*\\" << std::endl
		<< "/\\O\\*\\" << std::endl
		<< "/*/\\/\\/\\" << std::endl
		<< "/\\O\\/\\*\\/\\" << std::endl
		<< "/\\*\\/\\*\\/\\/\\" << std::endl
		<< "/\\O\\/\\/*/\\/O/\\" << std::endl
		<< "||" << std::endl
		<< "||" << std::endl
		<< "||" << std::endl
		<< std::endl;
}
