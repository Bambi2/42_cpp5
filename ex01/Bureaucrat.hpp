#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

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

	// constructors 
	Bureaucrat();
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(Bureaucrat const & copy);

	// destructor
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const &rhs);

	// getters and setters 
	int getGrade() const;
	std::string const & getName() const;

	// methods 
	void increment();
	void decrement();
	void signForm(Form& form) const;
private:
	const std::string name;
	int grade;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const & rhs);

#endif