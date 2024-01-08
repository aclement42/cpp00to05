#pragma once

# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_materiasource[4];
        int       _index;
    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource( MateriaSource const & obj);
        MateriaSource & operator=( MateriaSource const & rhs);
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};
