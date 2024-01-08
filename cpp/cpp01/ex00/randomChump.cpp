#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie stack = Zombie(name);
    stack.announce();
}
