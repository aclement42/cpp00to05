#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout <<  getType() << ": Default constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::~Cat()
{
    delete (this->_brain) ;
    std::cout <<   getType() << ": Default destructor called" << std::endl;
}

Cat::Cat( Cat const & obj) : Animal(obj)
{
    std::cout <<   getType() << ": Copy constructor called" << std::endl;
    // delete (this->_brain);
    this->_brain = new Brain();
    for (int i = 0; i <= 99; i++)
        this->_brain->add_idea(obj._brain->getIdea(i), i);

}

Cat & Cat::operator=( Cat const & rhs)
{
    std::cout <<   getType() << ": Assignation operator called" << std::endl;
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

void    Cat::makeSound() const
{
    std::cout << getType() << ": MEEEOOOOWWWWW" << std::endl;
}

Brain* Cat::getBrain()
{
    return (this->_brain);
}
