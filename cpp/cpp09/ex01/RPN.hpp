#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class  RPN
{
    private:
        std::stack<double> _stack;
    public:
        RPN();
        ~RPN();

        void    parse(std::string const & str);
        bool    verify_occurence(std::string const & str);
        bool    IsDigit(char c);
        bool    IsOperand(char c);
        bool    verify_space_position(std::string const & str);
        bool    execute_algo(std::string str);
        void    case_operator(double a, double  b, char ope);




        class RPN_exceptions : public std::exception
        {
            private:
                std::string _errormsg;
            public:
                RPN_exceptions(std::string const & str);
                const char* get_errormsg() const;
                virtual const char* what() const throw()
                {
                    return (get_errormsg());
                }

                virtual ~RPN_exceptions() throw() {};
        };
};


#endif