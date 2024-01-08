
#include "Form.hpp"

Form::Form(Form const & obj) : _name(obj._name), _issigned(false), _gradesign(obj._gradesign), _gradeexec(obj._gradeexec)
{
    *this = obj;
    std::cout << "Form: Copy constructor called" << std::endl;
}

Form & Form::operator=(Form const & rhs)
{
    if (this != &rhs)
        this->_issigned = rhs._issigned;
    std::cout << "Form: Copy assignment operator constructor called" << std::endl;
    return (*this);
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

Form::Form() : _name("Unknown Form"), _issigned(false), _gradesign(1), _gradeexec(1)
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
    std::cout << "Form constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form default destructor called" << std::endl;
}

void    Form::beSigned(Bureaucrat & brc)
{
    if (this->_issigned == false)
    {
        if (brc.getGrade() >= this->_gradesign)
            throw Form::GradeTooLowException();
        else
            this->_issigned = true;
    }
    else
        throw Form::AlreadySigned();
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
    out << f.getNameForm() << "::grade signed: " << f.getGradesigned() << ", grade exec: " << f.getGradexec() << ", grade status: " << f.getIssigned() << "." << std::endl;
    return (out);
}