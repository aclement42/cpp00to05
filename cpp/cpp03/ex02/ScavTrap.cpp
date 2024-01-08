#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_name = "";
    this->_HP = 100;
    this->_EP = 50;
    this->_AD = 20;
    std::cout << "NONAMED: SCAVTRAP constructor starts with " << this->_HP << " hit points, " << this->_EP << " energy points, and " << this->_AD << " attack damage!" << std::endl;
    return ;
}

ScavTrap::~ScavTrap()
{
    if (_name == "")
        std::cout << "Default destructor SCAVTRAP called NONAMED!" << std::endl;
    else
        std::cout << "Default " << this->_name << "'s SCAVTRAP destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
    this->_HP = 100;
    this->_EP = 50;
    this->_AD = 20;
    std::cout << this->_name << "'s: SCAVTRAP constructor starts with " << this->_HP << " hit points, " << this->_EP << " energy points, and " << this->_AD << " attack damage!" << std::endl;
    return ;
}

ScavTrap::ScavTrap( ScavTrap const & src) : ClapTrap(src)
{
    std::cout << "Copy SCAVTRAP constructor called" << std::endl;
    *this = src;
    return ;
}

ScavTrap    & ScavTrap::operator=( ScavTrap const & rhs)
{
    std::cout << "SCAVTRAP Copy assignement operator called for " << rhs._name << std::endl;
    this->_name = rhs._name;
    this->_HP = rhs._HP;
    this->_EP = rhs._EP;
    this->_AD = rhs._AD;
    return (*this);
}

void    ScavTrap::attack(const std::string & target)
{
    if (this->_EP <= 0 || this->_HP <= 0)
    {
        if (this->_name  == "")
            std::cout << "NONAMED: SCAVTRAP is no longer able to attack!" << std::endl;
        else
            std::cout << _name << ":SCAVTRAP is no longer able to attack!" << std::endl;
    }
    else
    {
        this->_EP--;
        if (this->_name  == "")
            std::cout  << "NONAMED: SCAVTRAP attacks " << target << ", causing " <<  this->_AD << " points of damage." << std::endl;
        else
            std::cout << this->_name << ":SCAVTRAP attacks " << target << ", causing " <<  this->_AD << " points of damage." << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (getname() == "")
        std::cout <<  "NONAMED: SCAVTRAP is now in Gate keeper mode" << std::endl;
    else
        std::cout << getname() << ": SCAVTRAP is now in Gate keeper mode" << std::endl;
}
