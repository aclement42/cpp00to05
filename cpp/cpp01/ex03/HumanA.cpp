#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
    std::cout << "default HumanA's constructor has been created" << std::endl;
    this->_name = name;
}

HumanA::~HumanA()
{
    return;
}

void    HumanA::attack(void)
{
    std::cout << this->_name << ": attack with " << this->_weapon.getType() << std::endl;
}

