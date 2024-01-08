#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    std::cout << "default Weapon's constructor has been created" << std::endl;
    setType(str);
}

Weapon::~Weapon()
{
    return;
}

std::string const & Weapon::getType()
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}
