#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal: " << getType() << ", default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal: " << getType() << ", type constructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs)
{
    std::cout << "WrongAnimal: " << getType() << ", assignation operator called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: " <<  getType() << ", default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & obj)
{
    std::cout << "WrongAnimal: " << getType() << ", copy constructo called" << std::endl;
    *this = obj;
}

void        WrongAnimal::makeSound() const
{
    std::cout << getType() << ": GRGRGRGRGRGRGRGR" << std::endl;
}

std::string const & WrongAnimal::getType() const
{
    return (this->_type);
}
