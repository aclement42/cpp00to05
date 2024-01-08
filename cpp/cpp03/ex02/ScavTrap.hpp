#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class   ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap & operator=( ScavTrap const & rhs);
        ScavTrap(ScavTrap const & src);
        ScavTrap(std::string name);

        void guardGate();
        void    attack(const std::string & target);
};

#endif