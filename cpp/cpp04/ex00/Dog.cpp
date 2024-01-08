#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout <<   getType() << ": Default constructor called" << std::endl;
    return ;
}

Dog::~Dog()
{
    std::cout <<  getType() << ": Default destructor called" << std::endl;
    return ;
}

Dog::Dog( Dog const & obj) : Animal(obj)
{
    std::cout <<   getType() << ": Copy constructor called" << std::endl;
}

Dog & Dog::operator=( Dog const & rhs)
{
    std::cout <<   getType() << ": Assignation operator called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}

void       Dog::makeSound() const
{
    std::cout << getType() << ": WAAOOOUUUUFFFFF" << std::endl;
}