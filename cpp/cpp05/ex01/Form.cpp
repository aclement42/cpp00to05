
#include "Form.hpp"

Form::Form(Form const & obj) : _name(obj._name), _issigned(false), _gradesign(obj._gradesign), _gradeexec(obj._gradeexec)
{
    *this = obj;
    std::cout << "Form: Copy constructor called" << std::endl;
}

Form & Form::operator=(Form const &)
{
    //if (this != &rhs)
    //    this->_issigned = rhs._issigned;
    std::cout << "Form: Copy assignment operator constructor called" << std::endl;
    throw Form::Copyexception();
    return (*this);
}

const char* Form::AlreadySigned::what() const throw()
{
    return ("Form: Already Signed!");
}

const char* Form::Copyexception::what() const throw()
{
    return ("Form: Copy would be incomplete!");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form: Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form: Grade too low!");
}

bool    Form::getIssigned() const
{
    return (this->_issigned);
}

int     Form::getGradexec() const
{
    return (this->_gradeexec);
}

int     Form::getGradesigned() const
{
    return (this->_gradesign);
}

std::string Form::getNameForm() const
{
    return (this->_name);
}

Form::Form() : _name("Unknown Form"), _issigned(false), _gradesign(150), _gradeexec(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradesigned, int gradeexec) : _name(name), _gradesign(gradesigned), _gradeexec(gradeexec)
{
    this->_issigned = false;
    if (gradesigned < 1 || gradeexec < 1)
        throw Form::GradeTooHighException();
    if (gradeexec > 150 || gradesigned > 150)
        throw Form::GradeTooLowException();
    std::cout << getNameForm() << "'s Form constructor called with gradesigne: " << getGradesigned() << ", and gradeexec: " << getGradexec() << "!" << std::endl;
}

Form::~Form()
{
    std::cout << "Form default destructor called" << std::endl;
}

void    Form::beSigned(Bureaucrat & brc)
{
    if (this->_issigned == false)
    {
        if (brc.getGrade() > this->_gradesign)
            throw Form::GradeTooLowException();
        else
            this->_issigned = true;
    }
    else
        throw Form::AlreadySigned();
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
    out << f.getNameForm() << "::grade signed: " << f.getGradesigned() << ", grade exec: " << f.getGradexec() << ", signe status: " << f.getIssigned() << "." << std::endl;
    return (out);
}