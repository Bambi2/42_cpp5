#ifndef SHRUBBERYCREATIONFROM_H
#define SHRUBBERYCREATIONFROM_H

#include "AForm.hpp"
#include <string>
#include <fstream>

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