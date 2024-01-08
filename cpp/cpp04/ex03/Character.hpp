#pragma once

# include "ICharacter.hpp"
# include <iostream>
# include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_materia[4];
    public:
        Character();
        Character(std::string name);
        Character & operator=( Character const & rhs);
        Character( Character const & obj);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

std::string const & Character::getName() const
{
    return (this->_name);
}