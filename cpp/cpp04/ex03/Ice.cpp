#include "Ice.hpp"


Ice::Ice() : AMateria("ice")
{}

Ice::~Ice()
{}

Ice::Ice(Ice const & obj)
{
    *this = obj;
}

Ice & Ice::operator=( Ice const & rhs)
{
    this->_type = rhs.getType();
    return (*this);
}

void    Ice::use(ICharacter& target)
{
    (void)target;
}

AMateria*    Ice::clone() const
{
    return (new Ice());
}