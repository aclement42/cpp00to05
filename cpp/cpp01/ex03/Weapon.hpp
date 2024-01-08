#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string str);
        ~Weapon();
        std::string const & getType();
        void    setType(std::string type);
};

#endif