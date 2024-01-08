#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain* _brain;
    public:
        Cat();
        ~Cat();
        Cat( Cat const & obj);
        Cat & operator=( Cat const & rhs);
        void    makeSound(void) const;
        Brain*  getBrain();
};

#endif