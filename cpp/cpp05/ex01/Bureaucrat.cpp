
#include "Bureaucrat.hpp"

void        Bureaucrat::IncrementGrade()
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = this->_grade - 1;
    std::cout << getName() << ": I am " << getName() << "'s bureaucrat INCREMENTGRADE at grade " << getGrade() << "!" << std::endl;
}

void        Bureaucrat::DecrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = this->_grade + 1;
    std::cout << getName() << ": I am " << getName() << "'s bureaucrat DECREMENTGRADE at grade " << getGrade() << "!" << std::endl;
}

void         Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    std::cout << getName() << ": I am " << getName() << "'s bureaucrat SETGRADE at grade " << getGrade() << "!" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int         Bureaucrat::getGrade() const
{
    return (this->_grade);
}

Bureaucrat::Bureaucrat() : _name("Unknown") , _grade(150)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & obj)
{
    *this = obj;
    std::cout << "Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    this->_name = rhs.getName();
    this->_grade = rhs.getGrade();
    std::cout << "Bureaucrat's copy assignation constructor called" << std::endl;
    return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    std::cout << getName() << "'s constructor called with grade : " << getGrade() << "!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const & src)
{
    out << src.getName() << " , bureaucrat grade " << src.getGrade() << "." << std::endl;
    return (out);
}


void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getNameForm() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cout << getName() << " could't sign " << form.getNameForm() << " because " << e.what() << "." << std::endl;
    }
    
}