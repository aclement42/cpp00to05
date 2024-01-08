#include "Zombie.hpp"

int main(int ac, char **av)
{
    if (ac == 3 && av[1] && av[2])
    {
        std::string heapname = av[1];
        std::string stackname = av[2];
        if (heapname.empty() || stackname.empty())
            return(0);
        Zombie* heap = newZombie(heapname);
        randomChump(stackname);

        delete heap;
    }
    else
        std::cout << "please give me 2 zombie's name" << std::endl;
    return (0);
}