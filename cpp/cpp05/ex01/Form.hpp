#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool              _issigned;
        int         const _gradesign;
        int         const _gradeexec;

    public:
        Form();
        ~Form();
        Form(Form const & obj);
        Form & operator=(Form const & rhs);
        Form(std::string name, int gradesigned, int gradeexec);

        std::string         getNameForm() const;
        bool                getIssigned() const;
        int                 getGradesigned() const;
        int                 getGradexec() const;

        void                beSigned(Bureaucrat & brc);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Form: Grade too high!");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Form: Grade too low!");
                }
        };
        class AlreadySigned : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Form: Already Signed!");
                }
        };
};

std::ostream &operator<<(std::ostream &out, Form const & src);
