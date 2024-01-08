#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _HP(10), _EP(10), _AD(0)
{
    std::cout << "NONAMED: constructor starts with " << this->_HP << " hit points, " << this->_EP << " energy points, and " << this->_AD << " attack damage!" << std::endl;
    return ;
}

ClapTrap::~ClapTrap()
{
    if (_name == "")
        std::cout << "Default destructor called without name!" << std::endl;
    else
        std::cout << "Default " << _name << "'s destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _EP(10), _AD(0)
{
    std::cout << this->_name << "'s: constructor starts with " << this->_HP << " hit points, " << this->_EP << " energy points, and " << this->_AD << " attack damage!" << std::endl;
    return ;
}

ClapTrap::ClapTrap( ClapTrap const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

ClapTrap    & ClapTrap::operator=( ClapTrap const & rhs)
{
    std::cout << "Copy assignement operator called for " << rhs._name << std::endl;
    this->_name = rhs._name;
    this->_HP = rhs._HP;
    this->_EP = rhs._EP;
    this->_AD = rhs._AD;
    return (*this);
}

void    ClapTrap::attack(const std::string & target)
{
    if (this->_EP <= 0 || this->_HP <= 0)
        std::cout << _name << ": is no longer able to attack!" << std::endl;
    else
    {
        this->_EP--;
        std::cout << this->_name << ": attacks " << target << ", causing " <<  this->_AD << " points of damage." << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
        if (this->_HP <= 0)
            std::cout << _name << ": is no longer able to take damage!" << std::endl;
        else
        {
            std::cout << this->_name << ": takes " << amount << " points of damage." << std::endl;
            this->_HP = this->_HP - amount;
        }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_EP <= 0 || this->_HP <= 0)
        std::cout << _name << ": is no longer able to repair!" << std::endl;
    else
    {
        this->_HP = this->_HP + amount;
        this->_EP--;
        std::cout << this->_name << ": repairs itself and regains " << amount << " points of HP." << std::endl;
    }
}

std::string     ClapTrap::getname()
{
    return (this->_name);
}

int         ClapTrap::get_AD()
{
    return (this->_AD);
}

int         ClapTrap::get_HP()
{
    return (this->_HP);
}

int         ClapTrap::get_EP()
{
    return (this->_EP);
}
