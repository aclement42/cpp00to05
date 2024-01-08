#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain( Brain const & obj)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = obj;
}

Brain & Brain::operator=( Brain const & rhs)
{
    int i = 0;
    while (i <  100)
    {
        this->_ideas[i] = rhs._ideas[i];
        i++;
    }
    return (*this);
}

void    Brain::add_idea(std::string str, int index)
{
    if (index <= 99)
        this->_ideas[index] = str;
}

void    Brain::print_idea()
{
    int i = 0;
    //while (i < 100)
    //{
    //    std::cout << "idea " << i << ": " << this->_ideas[i] << std::endl;
    //    i++;
    //}
    while (i < 100)
    {
        if (i == 1 || i == 77 || i == 88 || i == 99)
            std::cout << "idea " << i << ": " << this->_ideas[i] << std::endl;
        i++;
    }    
}

std::string Brain::getIdea(int id)
{
    if (id < 0 || id > 99)
        return ("");
    return (this->_ideas[id]);
}