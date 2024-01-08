#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_name = "";
    this->_HP = 100;
    this->_EP = 100;
    this->_AD = 30;
    std::cout << "NONAMED: FRAGTRAP constructor starts with " << this->_HP << " hit points, " << this->_EP << " energy points, and " << this->_AD << " attack damage!" << std::endl;
    return ;
}

FragTrap::~FragTrap()
{
    if (_name == "")
        std::cout << "Default destructor FRAGTRAP called NONAMED!" << std::endl;
    else
        std::cout << "Default " << this->_name << "'s FRAGTRAP destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
    this->_HP = 100;
    this->_EP = 100;
    this->_AD = 30;
    std::cout << this->_name << "'s: FRAGTRAP constructor starts with " << this->_HP << " hit points, " << this->_EP << " energy points, and " << this->_AD << " attack damage!" << std::endl;
    return ;
}

FragTrap::FragTrap( FragTrap const & src) : ClapTrap(src)
{
    std::cout << "Copy FRAGTRAP constructor called" << std::endl;
    *this = src;
    return ;
}

FragTrap    & FragTrap::operator=( FragTrap const & rhs)
{
    std::cout << "FRAGTRAP Copy assignement operator called for " << rhs._name << std::endl;
    this->_name = rhs._name;
    this->_HP = rhs._HP;
    this->_EP = rhs._EP;
    this->_AD = rhs._AD;
    return (*this);
}

void FragTrap::highFivesGuys()
{
    if (getname() == "")
        std::cout <<  "NONAMED: FRAGTRAP high fives guys!" << std::endl;
    else
        std::cout << getname() << ": FRAGTRAP high fives guys!" << std::endl;
}

void    FragTrap::attack(const std::string & target)
{
    if (this->_EP <= 0 || this->_HP <= 0)
    {
        if (this->_name  == "")
            std::cout << "NONAMED: FRAGTRAP is no longer able to attack!" << std::endl;
        else
            std::cout << _name << ":FRAGTRAP is no longer able to attack!" << std::endl;
    }
    else
    {
        this->_EP--;
        if (this->_name  == "")
            std::cout  << "NONAMED: FRAGTRAP attacks " << target << ", causing " <<  this->_AD << " points of damage." << std::endl;
        else
            std::cout << this->_name << ":FRAGTRAP attacks " << target << ", causing " <<  this->_AD << " points of damage." << std::endl;
    }
}

