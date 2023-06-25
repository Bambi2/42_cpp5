#include "Form.hpp"

Form::Form() : name("No Name"), gradeToSign(MIN_GRADE), gradeToExecute(MIN_GRADE), isSigned(false) {
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(Form const & copy) : name(copy.name),
	gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute), isSigned(copy.isSigned)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form::Form(std::string const & name, bool isSigned, int gradeToSign, int gradeToExecute) :
	name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(isSigned)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE) {
		throw (Form::GradeTooHighException());
	} else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE) {
		throw (Form::GradeTooLowException());
	}
}

Form::~Form() {
	std::cout << "Form Destructor called" << std::endl;
}

Form& Form::operator=(Form const &rhs) {
	std::cout << "Form assigning operator is called" << std::endl;
	if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

std::string const & Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign) {
		this->isSigned = true;
	} else {
		throw (Form::GradeTooLowException());
	}
}

std::ostream & operator<<(std::ostream &o, Form const & rhs) {
	o << rhs.getName() << " form,"
		<< " gradeToSign: " << rhs.getGradeToSign()
		<< " gradeToExecute: " << rhs.getGradeToExecute()
		<< " isSigned: " << rhs.getIsSigned() << std::endl;

	return o;
}