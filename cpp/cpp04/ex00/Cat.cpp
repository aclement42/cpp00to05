#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout <<  getType() << ": Default constructor called" << std::endl;
    return ;
}

Cat::~Cat()
{
    std::cout <<   getType() << ": Default destructor called" << std::endl;
    return ;
}

Cat::Cat( Cat const & obj) : Animal(obj)
{
    std::cout <<   getType() << ": Copy constructor called" << std::endl;
    return ;
}

Cat & Cat::operator=( Cat const & rhs)
{
    std::cout <<   getType() << ": Assignation operator called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << getType() << ": MEEEOOOOWWWWW" << std::endl;
}