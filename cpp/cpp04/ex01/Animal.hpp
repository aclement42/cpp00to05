#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        Animal( Animal const & obj);
        Animal(std::string type);
        Animal & operator=( Animal const & rhs);
        virtual void    makeSound(void) const;
        std::string const & getType() const;
};

#endif