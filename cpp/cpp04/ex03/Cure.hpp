#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure( Cure const & obj);
        Cure & operator=( Cure const & rhs);
        ~Cure();
        Cure();
        virtual void use(ICharacter& target);
        virtual AMateria* clone() const;
};

