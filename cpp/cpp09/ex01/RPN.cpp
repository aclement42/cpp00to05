#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(RPN const &src)
{
    (void)src;
}
		
RPN &RPN::operator=(RPN const & rhs)
{
    (void)rhs;
	return *this;
}


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


void    RPN::verify_occurence(std::string const & str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && !IsDigit(str[i]) && !IsOperand(str[i]))
            throw RPN::RPN_exceptions("Error: only digits, space, or operands are avaiable");
    }
}

void RPN::verify_space_position(std::string const & str)
{
    if (str[0] == ' ')
        throw RPN::RPN_exceptions("Error: bad input of arg");
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && !str[i + 1])
            throw RPN::RPN_exceptions("Error: bad input of arg");
        if (str[i] == ' ' && str[i + 1] == ' ')
            throw RPN::RPN_exceptions("Error: bad input of arg");
        if (str[i] != ' ' && (str[i + 1] && str[i + 1] != ' '))
            throw RPN::RPN_exceptions("Error: bad input of arg");
    }
}

bool RPN::case_operator(double  a,double  b, char ope)
{
    // std::cout << "a :" << a << "et b: " << b << std::endl; 
    if (ope == '+')
        _stack.push(a + b);
    else if (ope == '-')
        _stack.push(a - b);
    else if (ope == '*')
        _stack.push(a * b);
    else if (ope == '/')
    {
        if (b == 0)
            return (0);
        _stack.push(a / b);
    }
    else 
        return (0);
    return (1);
}

void    RPN::execute_algo(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (IsOperand(str[i]))
        {
            if (_stack.size() < 2)
                throw RPN::RPN_exceptions("Error: Incomplete expression");
            double b = _stack.top();
            _stack.pop();
            double a = _stack.top();
            _stack.pop();

            if (!case_operator(a, b, str[i]))
                throw RPN::RPN_exceptions("Error: Cannot divide X by 0");
        }
        if (IsDigit(str[i]))
            _stack.push(static_cast<double>(str[i]) - 48);
    }
    if (_stack.size() != 1)
        throw RPN::RPN_exceptions("Error: Incomplete expression");
    std::cout << _stack.top() << std::endl;
}

void    RPN::parse(std::string const & str)
{
    try
    {
        verify_occurence(str);
        verify_space_position(str);
        execute_algo(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}