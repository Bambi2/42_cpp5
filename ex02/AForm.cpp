#include "AForm.hpp"

AForm::AForm() : name("No Name"), isSigned(false), gradeToSign(MIN_GRADE), gradeToExecute(MIN_GRADE) {
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(AForm const & copy) : name(copy.name), isSigned(copy.isSigned),
	gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::AForm(std::string const & target, std::string const & name, bool isSigned, int gradeToSign, int gradeToExecute) :
	name(name), target(target), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE) {
		throw (AForm::GradeTooHighException());
	} else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE) {
		throw (AForm::GradeTooLowException());
	}
}

AForm::~AForm() {
	std::cout << "AForm Destructor called" << std::endl;
}

AForm& AForm::operator=(AForm const &rhs) {
	std::cout << "AForm assigning operator is called" << std::endl;
	if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

std::string const & AForm::getName() const {
	return this->name;
}

std::string const & AForm::getTarget() const {
	return this->target;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat const & bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign) {
		this->isSigned = true;
	} else {
		throw (AForm::GradeTooLowException());
	}
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned) {
		throw (AForm::FormIsNotSignedException());
	} else if (executor.getGrade() > this->gradeToExecute) {
		throw (AForm::GradeTooLowException());
	} else {
		this->executeForm();
	}
}

std::ostream & operator<<(std::ostream &o, AForm const & rhs) {
	o << rhs.getName() << " form,"
		<< " gradeToSign: " << rhs.getGradeToSign()
		<< " gradeToExecute: " << rhs.getGradeToExecute()
		<< " isSigned: " << rhs.getIsSigned();

	return o;
}