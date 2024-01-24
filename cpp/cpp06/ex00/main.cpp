#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "Error: Parameter is missing!" << std::endl;
    else if (ac > 2)
        std::cout << "Error: One parameter is required!" << std::endl;
    else
        ScarlarConverter::convert(av[1]);
    return(0);
}