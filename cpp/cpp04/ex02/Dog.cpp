#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << getType() << ": Default constructor called" << std::endl;
    this->_brain = new Brain();
}

Dog::~Dog()
{
    delete (this->_brain);
    std::cout <<  getType() << ": Default destructor called" << std::endl;
}

Dog::Dog( Dog const & obj) : AAnimal(obj)
{
    std::cout <<   getType() << ": Copy constructor called" << std::endl;
    this->_brain = new Brain();
    for (int i = 0; i <= 99; i++)
        this->_brain->add_idea(obj._brain->getIdea(i), i);
}

Dog & Dog::operator=( Dog const & rhs)
{
    std::cout << getType() << ": Assignation operator called" << std::endl;
    if (&rhs != this)
    {
        delete (this->_brain);
        this->_type = rhs._type;
        this->_brain = new Brain();
        for (int i = 0; i <= 99; i++)
            this->_brain->add_idea(rhs._brain->getIdea(i), i);
    }
    return (*this);
}

void       Dog::makeSound() const
{
    std::cout << getType() << ": WAAOOOUUUUFFFFF" << std::endl;
}

Brain* Dog::getBrain()
{
    return (this->_brain);
}
