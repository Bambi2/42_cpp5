#include "Form.hpp"
#include "Bureaucrat.hpp"


int main() {
	Form f = Form("Ecole 42", false, 1, 1);
	Bureaucrat j = Bureaucrat("Julia", 20);
	Bureaucrat c = Bureaucrat("Cole", 1);

	std::cout << f << std::endl;
	j.signForm(f);
	c.signForm(f);
	std::cout << f << std::endl;
}