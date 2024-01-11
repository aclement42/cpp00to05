
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default contructor called" << std::endl; 
}

Intern::~Intern()
{
    std::cout << "Intern default destructor called" << std::endl; 
}

Intern::Intern(Intern const & obj)
{
    *this = obj;
    std::cout << "Intern copy constructor called" << std::endl; 
}

Intern & Intern::operator=(Intern const &)
{
    std::cout << "Intern assign operator called" << std::endl;
    return (*this);
}

AForm* Intern::makeForm(std::string name, std::string form)
{
    std::string list[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int i;
    for (i = 0; i < 3; i++)
        if (list[i] == name)
            break ;            
    if (i > 2)
    {
        std::cout << "the form name passed doesn't exist: presidential form, robotomy request, or shrubbery creation needed" << std::endl;
        return (NULL);
    }
    AForm* AForm[3] = {new PresidentialPardonForm(form), new RobotomyRequestForm(form), new ShrubberyCreationForm(form)};
    for (int j = 0;j < 3; j++)
        if (j != i)
            delete (AForm[j]);
    return (AForm[i]);
}