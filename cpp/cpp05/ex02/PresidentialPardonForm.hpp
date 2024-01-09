#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const & obj);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
        
        PresidentialPardonForm(std::string target);
        void        execute(Bureaucrat const & executor) const;
};

#include "PresidentialPardonForm.hpp"
