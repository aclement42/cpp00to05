#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pmergeme;
    if (ac < 2)
        std::cout << "Error: Votre programme doit prendre une séquence d’entiers positif en argument" << std::endl;
    else if (ac == 2)
        std::cout << "Error: nothing to sort" << std::endl;
    else
        pmergeme.parse(ac, av);   
    return (0);
}