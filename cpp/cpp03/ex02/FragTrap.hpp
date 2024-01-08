#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class   FragTrap : public ClapTrap
{
    public:
        FragTrap();
        ~FragTrap();
        FragTrap & operator=( FragTrap const & rhs);
        FragTrap(FragTrap const & src);
        FragTrap(std::string name);

        void    highFivesGuys(void);
        void    attack(const std::string & target);
};

#endif
