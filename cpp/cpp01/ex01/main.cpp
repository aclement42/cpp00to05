#include "Zombie.hpp"

int main(int ac, char **av)
{
    if (ac == 2 && av[1])
    {
        int N = 5;
        std::string name = av[1];
        if (name.empty() || N <= 0)
        {
            std::cout << "zombie's name or number of zombies is missing" << std::endl;
            return(0);
        }
        Zombie* horde = zombieHorde(N, name); 

        delete [] horde;
    }
    else
        std::cout << "please give me a zombie's name" << std::endl;
    return (0);
}