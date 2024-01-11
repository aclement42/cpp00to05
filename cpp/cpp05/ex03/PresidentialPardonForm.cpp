
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("Unkwown target")
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & obj)
{
    *this = obj;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    this->_target = rhs._target;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), _target(target)
{

}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (executor.getGrade() > 5)
        throw AForm::ExecuteProblem();
    else if (getIssigned() == 0)
        throw AForm::Isnotsigned();
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}