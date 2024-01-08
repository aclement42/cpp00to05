#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << getType() << ": Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << getType() << ": Default destructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & obj) : WrongAnimal(obj)
{
    std::cout << getType() << ": copy constructor called" << std::endl;
}

WrongCat & WrongCat::operator=( WrongCat const & rhs)
{
    std::cout << getType() << ": assignation operator called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << getType() << ": Wrong MEEEOOOOWWWWW" << std::endl;
}
