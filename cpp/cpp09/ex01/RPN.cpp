#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}


RPN::RPN_exceptions::RPN_exceptions(std::string const & str)
{
    this->_errormsg = str;
}

const char* RPN::RPN_exceptions::get_errormsg() const
{
    return ((this->_errormsg).c_str());
}

bool RPN::IsDigit(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

bool RPN::IsOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (1);
    return (0);
}


bool    RPN::verify_occurence(std::string const & str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && !IsDigit(str[i]) && !IsOperand(str[i]))
            return (0);
    }
    return (1);
}

bool RPN::verify_space_position(std::string const & str)
{
    if (str[0] == ' ')
        return (0);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && !str[i + 1])
            return (0);
        if (str[i] == ' ' && str[i + 1] == ' ')
            return (0);
        if (str[i] != ' ' && (str[i + 1] && str[i + 1] != ' '))
            return (0);
    }
    return (1);
}

void RPN::case_operator(double  a,double  b, char ope)
{
    try
    {
        switch (ope)
        {
            case '+':  _stack.push(a + b);
                                    break;
            case '-': _stack.push(a - b);
                                    break;
            case '*': _stack.push(a * b);
                                    break;
            case '/':
                if (b == 0)
                {
                    throw RPN::RPN_exceptions("Error: Cannot divide X by 0");
                }
                _stack.push(a / b);
                            break;
            default:
                throw RPN::RPN_exceptions("Error: Operator gone wrong");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool    RPN::execute_algo(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (IsOperand(str[i]))
        {
            if (_stack.size() < 2)
                return (0);
            double b = _stack.top();
            _stack.pop();
            double a = _stack.top();
            _stack.pop();

            case_operator(a, b, str[i]);
        }
        if (IsDigit(str[i]))
            _stack.push(static_cast<double>(str[i]) - 48);
    }
    if (_stack.size() != 1)
        return (0);
    std::cout << _stack.top() << std::endl;
    return (1);
}

void    RPN::parse(std::string const & str)
{
    try
    {
        if (!verify_occurence(str))
            throw RPN::RPN_exceptions("Error: only digits, space, or operands are avaiable");
        if (!verify_space_position(str))
            throw RPN::RPN_exceptions("Error: bad input of arg");
        if (!execute_algo(str))
            throw RPN::RPN_exceptions("Error: Incomplete expression");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}