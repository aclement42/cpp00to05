#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	fabrice("fab", 42);
	Intern		test;

	AForm*		rrf;

	std::cout << "coucou:" << std::endl;
	rrf = test.makeForm("coucou", "bender");
	std::cout << "robotomy:" << std::endl;
	rrf = test.makeForm("robotomy request", "Bender");
	delete (rrf);
	std::cout << "shruberry:" << std::endl;
	rrf = test.makeForm("shrubbery creation", "Bender");
	fabrice.executeAForm(*rrf);
	fabrice.signAForm(*rrf);
	fabrice.signAForm(*rrf);
	fabrice.executeAForm(*rrf);
	delete (rrf);
	return (0);
}