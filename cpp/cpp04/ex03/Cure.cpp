#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::~Cure()
{}

Cure::Cure( Cure const & obj)
{
    *this = obj;
}

Cure & Cure::operator=( Cure const & rhs)
{
    this->_type = rhs.getType();
    return (*this);
}

void Cure::use(ICharacter& target)
{
    (void)target;
}

AMateria*    Cure::clone() const
{
    return (new Cure());
}
