#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   RobotomyRequestForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const & obj);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & obj);

        RobotomyRequestForm(std::string target);
        void    execute(Bureaucrat const & executor) const;
};