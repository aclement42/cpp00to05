#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <fstream>
#include <sstream>

class AForm;

class   ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const & obj);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & obj);

        ShrubberyCreationForm(std::string target);
        void    execute(Bureaucrat const & executor) const;

};
