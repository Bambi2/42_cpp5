#include "Form.hpp"
#include "Bureaucrat.hpp"

const std::string START_RED = "\033[1;31m";
const std::string STOP_RED = "\033[0m";

int main() {
	std::cout << START_RED << "INITIALIZING FORM WITH GRADE TO SIGN AND EXECUTE EQUAL 1" << STOP_RED << std::endl;
	Form f = Form("Ecole 42", false, 1, 1);
	std::cout << START_RED << "INITIALIZING TWO BUREAUCRATS WITH GRADES EQUAL 20 ADN 1" << STOP_RED << std::endl;
	Bureaucrat j = Bureaucrat("Julia", 20);
	Bureaucrat c = Bureaucrat("Cole", 1);

	std::cout << START_RED << "PRINTING THE FORM" << STOP_RED << std::endl;
	std::cout << f << std::endl;
	std::cout << START_RED << "CALLING signForm ON 20 GRADE BUREAUCRAT (catching exception)" << STOP_RED << std::endl;
	j.signForm(f);
	std::cout << START_RED << "CALLING signForm ON 1 GRADE BUREAUCRAT (success)" << STOP_RED << std::endl;
	c.signForm(f);
	std::cout << START_RED << "PRINTING FORM AGAIN TO CHECK IT IS SIGNED NOW" << STOP_RED << std::endl;
	std::cout << f << std::endl;
}