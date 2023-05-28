#include "Bureaucrat.hpp"


int main() {
	Bureaucrat b;

	b.increment();
	std::cout << b << std::endl;

	try {
		Bureaucrat c = Bureaucrat("Cole", 155);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		b.decrement();
		b.decrement();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}