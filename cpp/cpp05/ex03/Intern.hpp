#pragma once

#include "iostream"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class   Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const & obj);
        Intern & operator=(Intern const & rhs);

        AForm* makeForm(std::string name, std::string form);
};
