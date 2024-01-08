#pragma once

# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice( Ice const & obj);
        Ice & operator=( Ice const & rhs);
        virtual ~Ice();
        virtual void use(ICharacter& target);
        virtual AMateria* clone() const;
};
