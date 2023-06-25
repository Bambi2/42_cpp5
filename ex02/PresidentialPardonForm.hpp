#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include "AForm.hpp"
#include <string>

const int PRESEDENTIAL_PARDON_FORM_REQUIRED_GRADE_TO_SIGN = 25;
const int PRESEDENTIAL_PARDON_FORM_REQUIRED_GRADE_TO_EXEC = 5;

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const & copy);
	~PresidentialPardonForm();
protected:
	void executeForm() const;
public:
	PresidentialPardonForm& operator=(PresidentialPardonForm const &rhs);
};

#endif // __PRESIDENTIALPARDONFORM_H__