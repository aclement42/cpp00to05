#pragma once

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        AMateria();
        AMateria( AMateria const & obj);
        AMateria & operator=( AMateria const & rhs);
    public:
        AMateria(std::string const & type);
        virtual ~AMateria();
        std::string const & getType() const; //Returns the materia type
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

