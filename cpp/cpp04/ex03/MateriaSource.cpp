#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _index(0)
{}

MateriaSource::~MateriaSource()
{}

MateriaSource::MateriaSource( MateriaSource const & obj)
{
    *this = obj;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs)
{
    (void)rhs;
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* materiasource)
{
    // AMateria* newmater;

    if (this->_index >= 4)
        return ;
    std::cout << "Want to Copy " << materiasource->getType() << std::endl;
    if (materiasource->getType() == "ice")
        (this->_materiasource[this->_index++]) = new Ice();
    else if (materiasource->getType() == "cure")
        (this->_materiasource[this->_index++]) = new Cure();
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    int index_cpy = this->_index - 1;
    while (index_cpy > -1)
    {
        if (this->_materiasource[index_cpy]->getType() == type)
            return (this->_materiasource[index_cpy]->clone());
        index_cpy--;
    }
    return (0);
    
}
