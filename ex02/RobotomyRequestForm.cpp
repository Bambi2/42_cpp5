#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm(
		"No Name",
		"RobotomyRequestForm",
		false,
		ROBOTOMY_REQUEST_FORM_REQUIRED_GRADE_TO_SIGN,
		ROBOTOMY_REQUEST_FORM_REQUIRED_GRADE_TO_EXEC
	) {
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : AForm(copy) {
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	AForm(
		target,
		"RobotomyRequestForm",
		false,
		ROBOTOMY_REQUEST_FORM_REQUIRED_GRADE_TO_SIGN,
		ROBOTOMY_REQUEST_FORM_REQUIRED_GRADE_TO_EXEC
	) {
	std::cout << "RobotomyRequestForm target constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	std::cout << "RobotomyRequestForm assigning operator is called" << std::endl;
	if (this == &rhs) {
		return *this;
	} else {
		return *this;
	}
}

void RobotomyRequestForm::executeForm() const {
	std::cout << "*DRILL NOISE*" << std::endl;
	std::srand(std::time(nullptr));
	int result = std::rand() % 2;
	if (result) {
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	} else {
		std::cout << "Robotomy failed" << std::endl;
	}
}
