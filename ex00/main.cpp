#include "Bureaucrat.hpp"

const std::string START_RED = "\033[1;31m";
const std::string STOP_RED = "\033[0m";

int main() {
	std::cout << START_RED << "INITIALIZING BUREAUCRAT" << STOP_RED << std::endl;
	Bureaucrat b;

	std::cout << START_RED << "INCREMENTING ITS GRADE AND PRINTING" << STOP_RED << std::endl;
	b.increment();
	std::cout << b << std::endl;

	std::cout << START_RED << "TRYING TO DECREMENT ITS GRADE 2 TIMES (MUST CATCH AN EXCEPTION)" << STOP_RED << std::endl;
	try {
		b.decrement();
		b.decrement();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << START_RED << "TRYING TO INITIALIZE A BUREAUCRAT WITH -2 GRADE (MUST CATCH AN EXCEPTION)" << STOP_RED << std::endl;
	try {
		Bureaucrat c = Bureaucrat("Cole", -2);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	
}