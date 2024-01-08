#include "Brain.hpp"

Brain::Brain() //: _index_ideas(0)
{
    std::cout << "Brain constructor called" << std::endl;
    // for (int i = 0; i < 100; i++)
        // this->_ideas[i].clear();
    // this->_index_ideas = 0;
}

// Brain::Brain(std::string idea)
// {
//     std::cout << "Brain constructor called" << std::endl;
//     for (i = 0; i <=99; i++)
        // this._ideas[i] = idea;
// }

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
    // int i = 0;
    // while (!this->_ideas[i].empty())
    // {
        // std::cout << "is not empty [i]" << !this->_ideas[i].empty() << std::endl;
        // i++;
    // }
// 
    //std::cout << "\t\tValue of i: " << index << std::endl;
    if (index <= 99)
        this->_ideas[index] = str;
}

void    Brain::print_idea()
{
    int i = 0;
    // while (i < 100 && !this->_ideas[i].empty())
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