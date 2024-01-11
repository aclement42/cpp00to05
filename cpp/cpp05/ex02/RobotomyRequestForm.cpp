#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("Unkwown target")
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & obj)
{
    *this = obj;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    this->_target = rhs._target;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target)
{

}


void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > 45)
        throw AForm::ExecuteProblem();
    else if (getIssigned() == 0)
        throw AForm::Isnotsigned();
    else
    {
        std::cout << this->_target << " is making drilling noises!" << std::endl;
        static int i = 1;
        if (i > 0)
            std::cout << this->_target << " has been robotomized successfully!" << std::endl;
        else
            std::cout << this->_target << ": the robotomy failed!" << std::endl;
        i *= -1;
    }
}