#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal( AAnimal const & obj);
        AAnimal(std::string type);
        AAnimal & operator=( AAnimal const & rhs);
        virtual void    makeSound(void) const = 0;
        std::string const & getType() const;
};

#endif