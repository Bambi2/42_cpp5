#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	// exceptions
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade Is Too Low";
		}
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade Is Too High";
		}
	};

	// constructors
	Form();
	Form(std::string const & name, bool isSigned, int gradeToSign, int gradeToExecute);
	Form(Form const & copy);

	// destructor
	~Form();

	// operators
	Form& operator=(Form const &rhs);

	// getters and setters 
	std::string const & getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// methods
	void beSigned(Bureaucrat const & bureaucrat);
private:
	const std::string name;
	const int gradeToSign;
	const int gradeToExecute;

	bool isSigned;
};

std::ostream & operator<<(std::ostream &o, Form const & rhs);

#endif