#include "AAnimal.hpp"

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "AAnimal: " << getType() << " ,type constructor called" << std::endl;
    return ;
}

std::string const & AAnimal::getType() const
{
    return (this->_type);
}

AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "AAnimal: " << getType() << ", default constructor called" << std::endl;
    return ;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal: " << getType() << ", default destructor called" << std::endl;
    return ;
}

AAnimal::AAnimal( AAnimal const & obj)
{
    *this = obj;
    std::cout << "AAnimal: " << getType() << ", copy constructor called" << std::endl;
}

AAnimal & AAnimal::operator=( AAnimal const & rhs)
{
    this->_type = rhs._type;
    std::cout << "AAnimal: " << getType() << ", assignation operator called" << std::endl;
    return (*this);
}

