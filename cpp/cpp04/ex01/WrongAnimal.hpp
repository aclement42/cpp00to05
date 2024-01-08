#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal( WrongAnimal const & obj);
        WrongAnimal & operator=( WrongAnimal const & rhs);
        virtual ~WrongAnimal();
        virtual void    makeSound() const;
        std::string const & getType() const;
};

#endif