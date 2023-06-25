#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "AForm.hpp"
#include <string>
#include <ctime>
#include <cstdlib>

const int ROBOTOMY_REQUEST_FORM_REQUIRED_GRADE_TO_SIGN = 72;
const int ROBOTOMY_REQUEST_FORM_REQUIRED_GRADE_TO_EXEC = 45;

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const & target);
	RobotomyRequestForm(RobotomyRequestForm const & copy);
	~RobotomyRequestForm();
protected:
	void executeForm() const;
public:
	RobotomyRequestForm& operator=(RobotomyRequestForm const &rhs);
};

#endif // __ROBOTOMYREQUESTFORM_H__