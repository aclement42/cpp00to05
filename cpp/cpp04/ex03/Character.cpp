#include "Character.hpp"


Character::Character()
{}

Character::~Character()
{}

Character::Character(std::string name) : _name(name)
{}

Character::Character( Character const & obj)
{
    *this = obj;
}

Character & Character::operator=( Character const & rhs)
{
    this->_name = rhs._name;

    // if (this->_materia)
    // {
        
    // }
    this->_materia[0] = rhs._materia[0];
    return (*this);
}