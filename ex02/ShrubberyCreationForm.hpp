#ifndef SHRUBBERYCREATIONFROM_H
#define SHRUBBERYCREATIONFROM_H

#include "AForm.hpp"
#include <string>
#include <fstream>

const int SHRUBBERY_CREATION_FORM_REQUIRED_GRADE_TO_SIGN = 145;
const int SHRUBBERY_CREATION_FORM_REQUIRED_GRADE_TO_EXEC = 137;

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const & copy);
	~ShrubberyCreationForm();
protected:
	void executeForm() const;
public:
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &rhs);
};

#endif