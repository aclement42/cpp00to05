
#include "AForm.hpp"

AForm::AForm(AForm const & obj) : _name(obj._name), _issigned(false), _gradesign(obj._gradesign), _gradeexec(obj._gradeexec)
{
    *this = obj;
    std::cout << "AForm: Copy constructor called" << std::endl;
}

AForm & AForm::operator=(AForm const &)
{
    //if (this != &rhs)
    //    this->_issigned = rhs._issigned;
    std::cout << "AForm: Copy assignment operator constructor called" << std::endl;
    throw AForm::Copyexception();
    return (*this);
}

const char* AForm::AlreadySigned::what() const throw()
{
    return ("AForm: Already Signed!");
}

const char* AForm::Copyexception::what() const throw()
{
    return ("AForm: Copy would be incomplete!");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm: Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm: Grade too low!");
}

bool    AForm::getIssigned() const
{
    return (this->_issigned);
}

int     AForm::getGradexec() const
{
    return (this->_gradeexec);
}

int     AForm::getGradesigned() const
{
    return (this->_gradesign);
}

std::string AForm::getNameAForm() const
{
    return (this->_name);
}

AForm::AForm() : _name("Unknown AForm"), _issigned(false), _gradesign(150), _gradeexec(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradesigned, int gradeexec) : _name(name), _gradesign(gradesigned), _gradeexec(gradeexec)
{
    this->_issigned = false;
    if (gradesigned < 1 || gradeexec < 1)
        throw AForm::GradeTooHighException();
    if (gradeexec > 150 || gradesigned > 150)
        throw AForm::GradeTooLowException();
    std::cout << getNameAForm() << "'s AForm constructor called with gradesigne: " << getGradesigned() << ", and gradeexec: " << getGradexec() << "!" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm default destructor called" << std::endl;
}

void    AForm::beSigned(Bureaucrat & brc)
{
    if (this->_issigned == false)
    {
        if (brc.getGrade() > this->_gradesign)
            throw AForm::GradeTooLowException();
        else
            this->_issigned = true;
    }
    else
        throw AForm::AlreadySigned();
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
    out << f.getNameAForm() << "::grade signed: " << f.getGradesigned() << ", grade exec: " << f.getGradexec() << ", signe status: " << f.getIssigned() << "." << std::endl;
    return (out);
}

const char* AForm::ExecuteProblem::what() const throw()
{
    return ("the grade of the bureaucrat attempting to execute the form is not high enough!");
}

const char* AForm::Isnotsigned::what() const throw()
{
    return ("the form is not signed!");
}

const char* AForm::FileProblems::what() const throw()
{
    return ("something went wrong about opening file!");
}