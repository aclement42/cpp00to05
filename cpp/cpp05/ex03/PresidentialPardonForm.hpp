#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <fstream>
#include <sstream>

class AForm;

class   PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const & obj);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & obj);

        PresidentialPardonForm(std::string target);
        void    execute(Bureaucrat const & executor) const;

};
