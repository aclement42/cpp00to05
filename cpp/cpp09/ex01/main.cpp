#include "RPN.hpp"

int main(int ac, char **av)
{
    RPN rpn;
    try
    {
        if (ac != 2)
            throw RPN::RPN_exceptions("i need one arg[1]");
        else
        {
            rpn.parse(av[1]);
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}