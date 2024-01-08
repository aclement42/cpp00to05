#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        int         _HP;
        int         _EP;
        int         _AD;
    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap & operator=( ClapTrap const & rhs);
        ClapTrap(ClapTrap const & src);
        ClapTrap(std::string name);

        void    attack(const std::string & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        std::string     getname();
        int     get_AD();
        int     get_EP();
        int     get_HP();
};

#endif



