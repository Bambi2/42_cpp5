#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
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

	class FormIsNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "FormIsNotSigned";
		}
	};

	AForm();
	AForm(std::string const & target, std::string const & name, bool isSigned, int gradeToSign, int gradeToExecute);
	AForm(AForm const & copy);
	virtual ~AForm();

	AForm& operator=(AForm const &rhs);

	std::string const & getName() const;
	std::string const & getTarget() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat const & bureaucrat);
	virtual void execute(Bureaucrat const & executor) const;
protected:
	virtual void executeForm() const = 0;
private:
	const std::string name;
	const std::string target;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
};

std::ostream & operator<<(std::ostream &o, AForm const & rhs);

#endif