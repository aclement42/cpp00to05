#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{}

void    AMateria::use(ICharacter& target)
{
    (void)target;
}

AMateria::AMateria()
{}

AMateria::~AMateria()
{}

AMateria::AMateria( AMateria const & obj)
{
    *this = obj;
}

AMateria & AMateria::operator=( AMateria const & rhs)
{
    this->_type = rhs._type;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}