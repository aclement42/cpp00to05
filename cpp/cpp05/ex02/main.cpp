#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\x1b[38;5;221m******************TEST SHRUBBERY******************" << std::endl;
	std::cout << "To creat a Shrubbery Form, it required grades: sign:145, exec:137\x1b[0m" << std::endl;
    std::cout << "\x1b[38;5;221m--------------THAT WORKS--------------\x1b[0m" << std::endl;
    try
	{
		Bureaucrat Alvin("Alvin", 130);
		ShrubberyCreationForm shrubbery("F1");
		std::cout << Alvin;
		std::cout << "F1's grade: sign:" << shrubbery.getGradesigned() << ", exec: " << shrubbery.getGradexec() << std::endl;
		Alvin.signAForm(shrubbery);
		Alvin.executeAForm(shrubbery);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
   	std::cout << "\x1b[38;5;221m-----------THAT DOESN'T WORKS-----------\x1b[0m" << std::endl;
	try
	{
		Bureaucrat Theodor("Theodor", 150);
		ShrubberyCreationForm shrubbery("F2");
		std::cout << Theodor;
		std::cout << "F2's grade: sign:" << shrubbery.getGradesigned() << ", exec: " << shrubbery.getGradexec() << std::endl;
		Theodor.signAForm(shrubbery);
		Theodor.executeAForm(shrubbery);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "\x1b[38;5;221m******************TEST ROBOTOMY******************" << std::endl;
	std::cout << "To creat a Robotomy Form, it required grades: sign:72, exec:45\x1b[0m" << std::endl;
    std::cout << "\x1b[38;5;221m--------------THAT WORKS--------------\x1b[0m" << std::endl;
	try
	{
		Bureaucrat Alvin("Alvin", 10);
		RobotomyRequestForm robot("R1");
		std::cout << Alvin;
		std::cout << "R1's grade: sign: " << robot.getGradesigned() << ", exec: " << robot.getGradexec() << std::endl;
		Alvin.signAForm(robot);
		Alvin.executeAForm(robot);
		Alvin.executeAForm(robot);
		Alvin.executeAForm(robot);
		Alvin.executeAForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "\x1b[38;5;221m-----------THAT DOESN'T WORKS-----------\x1b[0m" << std::endl;
	try
	{
		Bureaucrat Theodor("Theodor", 100);
		RobotomyRequestForm robot("R2");
		std::cout << Theodor;
		std::cout << "R2's grade: sign: " << robot.getGradesigned() << ", exec: " << robot.getGradexec() << std::endl;
		Theodor.signAForm(robot);
		Theodor.executeAForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\x1b[38;5;221m*****************TEST PRESIDENTIAL*****************" << std::endl;
	std::cout << "To creat a Presidential Form, it required grades: sign:25, exec:5\x1b[0m" << std::endl;
    std::cout << "\x1b[38;5;221m--------------THAT WORKS--------------\x1b[0m" << std::endl;
    try
	{
		Bureaucrat Simon("Simon", 4);
		PresidentialPardonForm president("P1");
		std::cout << Simon;
		std::cout << "P1's grade: sign: " << president.getGradesigned() << ", exec: " << president.getGradexec() << std::endl;
		Simon.signAForm(president);
		Simon.executeAForm(president);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "\x1b[38;5;221m-----------THAT DOESN'T WORKS-----------\x1b[0m" << std::endl;
	try
	{
		Bureaucrat Theodor("Theodor", 40);
		PresidentialPardonForm president("P2");
		std::cout << Theodor;
		std::cout << "P2's grade: sign: " << president.getGradesigned() << ", exec: " << president.getGradexec() << std::endl;
		Theodor.signAForm(president);
		Theodor.executeAForm(president);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\x1b[38;5;221m***************************************************\x1b[0m" << std::endl;
	return (0);
}