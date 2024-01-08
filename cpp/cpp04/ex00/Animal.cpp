#include "Animal.hpp"

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal: " << getType() << " ,type constructor called" << std::endl;
    return ;
}

std::string const & Animal::getType() const
{
    return (this->_type);
}

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal: " << getType() << ", default constructor called" << std::endl;
    return ;
}

Animal::~Animal()
{
    std::cout << "Animal: " << getType() << ", default destructor called" << std::endl;
    return ;
}

Animal::Animal( Animal const & obj)
{
    std::cout << "Animal: " << getType() << ", copy constructor called" << std::endl;
    *this = obj;
}

Animal & Animal::operator=( Animal const & rhs)
{
    std::cout << "Animal: " << getType() << ", assignation operator called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << getType() << ": GRGRGRGRGRGRGR" << std::endl;
}