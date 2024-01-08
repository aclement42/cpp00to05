#include "Weapon.hpp"
#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon &weapon)
{
    std::cout << "default HumanB's constructor has been created" << std::endl;
    this->_weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
    this->_name = name;
}

void    HumanB::attack(void)
{

    std::cout << this->_name << ": attack with " << this->_weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
    return;
}
