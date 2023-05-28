#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

class Bureaucrat {
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade Is Too High";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade Is Too Low";
		}
	};

	Bureaucrat();
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(Bureaucrat const & copy);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const &rhs);

	int getGrade() const;
	std::string const & getName() const;
	void increment();
	void decrement();
	void signForm(AForm& form) const;
	void executeForm(AForm const & form);
private:
	const std::string name;
	int grade;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const & rhs);

#endif