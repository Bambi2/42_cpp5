#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "AForm.hpp"
#include <string>
#include <ctime>
#include <cstdlib>

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