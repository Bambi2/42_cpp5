#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("No Name"), grade(MIN_GRADE) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : name(copy.name), grade(copy.grade) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : name(name) {
	if (grade < MAX_GRADE) {
		throw (Bureaucrat::GradeTooHighException());
	} else if (grade > MIN_GRADE) {
		throw (Bureaucrat::GradeTooLowException());
	} else {
		this->grade = grade;
	}
	std::cout << "Bureaucrat Name and grade constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << "Bureaucrat assigning operator is called" << std::endl;
	if (this != &rhs) {
		this->grade = rhs.grade;
	}
	return *this;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::increment() {
	if (this->grade == MAX_GRADE) {
		throw (Bureaucrat::GradeTooHighException());
	} else {
		this->grade--;
	}
}

void Bureaucrat::decrement() {
	if (this->grade == MIN_GRADE) {
		throw (Bureaucrat::GradeTooLowException());
	} else {
		this->grade++;
	}
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	} catch (Form::GradeTooLowException) {
		std::cout << *this << " couldn't sign " << form << " because his/her grade is too low" << std::endl;
	}
}

std::string const & Bureaucrat::getName() const {
	return this->name;
}

std::ostream & operator<<(std::ostream &o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}