#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool              _issigned;
        int         const _gradesign;
        int         const _gradeexec;

    public:
        AForm();
        virtual ~AForm();
        AForm(AForm const & obj);
        AForm & operator=(AForm const &);
        AForm(std::string name, int gradesigned, int gradeexec);

        std::string         getNameAForm() const;
        bool                getIssigned() const;
        int                 getGradesigned() const;
        int                 getGradexec() const;

        void                beSigned(Bureaucrat & brc);
        virtual void execute(Bureaucrat const & executor) const = 0;
        class Copyexception : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class AlreadySigned : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class   ExecuteProblem : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
};

std::ostream &operator<<(std::ostream &out, AForm const & src);
