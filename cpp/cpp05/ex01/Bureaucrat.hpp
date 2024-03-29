#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class    Bureaucrat
{
    private:
        std::string _name;
        int         _grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const & obj);
        Bureaucrat & operator=(Bureaucrat const & rhs);
        Bureaucrat(std::string name, int grade);

        std::string getName() const;
        int         getGrade() const;
        void        setGrade(int grade);

        void        IncrementGrade(void);
        void        DecrementGrade(void);
        void        signForm(Form & form);

        class       GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class       GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const & src);
